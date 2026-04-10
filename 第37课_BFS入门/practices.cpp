// ============================================
// Lesson 37: BFS Introduction
// Practice solutions
// ============================================

// ---- Practice 1: Flood Spreading (Multi-source BFS) ----
// On an n*m village map, '.' is open land, '*' is a house,
// 'W' is an initial flood cell. Each minute, flood spreads to
// adjacent open land (not houses). Output the time until flood
// stops spreading.
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 105;

int n, m;
char grid[N][N];
int dist[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Point {
    int x, y;
};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(dist, -1, sizeof(dist));

    queue<Point> q;

    // Multi-source BFS: enqueue all initial flood cells
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'W') {
                Point p;
                p.x = i;
                p.y = j;
                q.push(p);
                dist[i][j] = 0;
            }
        }
    }

    int ans = 0;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            // In bounds, is open land, not yet flooded
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
                && grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                if (dist[nx][ny] > ans) ans = dist[nx][ny];
                Point next;
                next.x = nx;
                next.y = ny;
                q.push(next);
            }
        }
    }

    cout << ans << endl;
    return 0;
}

/*
 * Sample Input:
 * 3 3
 * W . *
 * . . .
 * . . *
 *
 * Expected Output:
 * 3
 */

// ---- Practice 2: Maze Shortest Path (Custom Start/End) ----
// Given n*m maze (0=path, 1=wall), find shortest path from
// (r1,c1) to (r2,c2). Output -1 if unreachable.
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 105;

int n, m;
int a[N][N];
int dist[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Point {
    int x, y;
};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(dist, -1, sizeof(dist));

    queue<Point> q;
    Point start;
    start.x = r1;
    start.y = c1;
    q.push(start);
    dist[r1][c1] = 0;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        if (cur.x == r2 && cur.y == c2) {
            cout << dist[r2][c2] << endl;
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
                && a[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                Point next;
                next.x = nx;
                next.y = ny;
                q.push(next);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}

/*
 * Sample Input:
 * 5 5
 * 0 0 1 0 0
 * 0 1 0 0 0
 * 0 0 0 1 1
 * 1 0 0 0 0
 * 0 0 1 0 0
 * 1 1 5 5
 *
 * Expected Output:
 * 8
 */

// ---- Practice 3: Character Matrix Shortest Path (Optional) ----
// Given n*m character matrix: 'S'=start, 'T'=end, '.'=path, '#'=wall.
// Find shortest path from S to T. Output -1 if unreachable.
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 205;

int n, m;
char grid[N][N];
int dist[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Point {
    int x, y;
};

int main() {
    cin >> n >> m;

    int sx, sy, tx, ty;

    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= m; j++) {
            grid[i][j] = row[j - 1];
            if (grid[i][j] == 'S') { sx = i; sy = j; }
            if (grid[i][j] == 'T') { tx = i; ty = j; }
        }
    }

    memset(dist, -1, sizeof(dist));

    queue<Point> q;
    Point start;
    start.x = sx;
    start.y = sy;
    q.push(start);
    dist[sx][sy] = 0;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        if (cur.x == tx && cur.y == ty) {
            cout << dist[tx][ty] << endl;
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
                && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                Point next;
                next.x = nx;
                next.y = ny;
                q.push(next);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}

/*
 * Sample Input:
 * 5 5
 * S..#.
 * .#...
 * ...#.
 * .#..T
 * .....
 *
 * Expected Output:
 * 8
 */
