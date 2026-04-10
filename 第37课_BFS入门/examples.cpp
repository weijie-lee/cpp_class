// ============================================
// Lesson 37: BFS Introduction
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Grid BFS — Garden Exploration ----
// Given an n*m grid (0=grass, 1=fence), find the minimum
// steps from (1,1) to (n,m). Output -1 if unreachable.
#include <iostream>
#include <queue>
using namespace std;

const int N = 105;

int n, m;
int a[N][N];      // Map: 0=grass, 1=fence
int vis[N][N];    // Visited marker
int dist[N][N];   // Distance from start

// Direction arrays: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Point {
    int x, y;
};

int bfs() {
    queue<Point> q;

    // Step 1: Enqueue the start point and mark it
    Point start;
    start.x = 1;
    start.y = 1;
    q.push(start);
    vis[1][1] = 1;
    dist[1][1] = 0;

    // Step 2: Loop while queue is not empty
    while (!q.empty()) {
        // Step 3: Dequeue front element
        Point cur = q.front();
        q.pop();

        // Check if we reached the destination
        if (cur.x == n && cur.y == m) {
            return dist[n][m];
        }

        // Step 4: Expand in 4 directions
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // Check: in bounds, not a fence, not visited
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
                && a[nx][ny] == 0 && vis[nx][ny] == 0) {
                // Step 5: Enqueue, mark, record distance
                Point next;
                next.x = nx;
                next.y = ny;
                q.push(next);
                vis[nx][ny] = 1;                        // Mark on enqueue!
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
            }
        }
    }

    // Queue empty and destination not reached
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}

/*
 * Sample Input:
 * 5 5
 * 0 0 1 0 0
 * 0 0 0 0 1
 * 1 0 1 0 0
 * 0 0 0 1 0
 * 0 1 0 0 0
 *
 * Expected Output:
 * 8
 */

// ---- Example 2: Knight Traversal (8-direction BFS) ----
// On an n*m chessboard, a knight starts at (sx,sy). The knight
// moves in an "L" shape (8 directions). Output the minimum steps
// to reach every cell. Output -1 for unreachable cells.
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 405;

int n, m, sx, sy;
int dist[N][N];

// Knight moves in "L" shape: 8 directions
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

struct Point {
    int x, y;
};

void bfs() {
    // Initialize all distances to -1 (not reached)
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

        // Expand 8 directions
        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // In bounds and not visited
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
                && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                Point next;
                next.x = nx;
                next.y = ny;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m >> sx >> sy;

    bfs();

    // Output results
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j > 1) cout << " ";
            cout << dist[i][j];
        }
        cout << endl;
    }

    return 0;
}

/*
 * Sample Input:
 * 3 3 1 1
 *
 * Expected Output:
 * 0 3 2
 * 3 -1 1
 * 2 1 -1
 */
