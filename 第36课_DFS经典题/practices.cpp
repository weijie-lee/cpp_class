// ============================================
// Lesson 36: DFS Classic Problems
// Practice solutions
// ============================================

// ---- Practice 1: Maze Shortest Path Length (DFS version) ----
// Given a 5x5 maze (0=path, 1=wall), find the shortest path
// from (0,0) to (4,4) using DFS. Output -1 if unreachable.
#include <iostream>
#include <climits>
using namespace std;

int n, m;
int maze[10][10];
int vis[10][10];
int ans = INT_MAX;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int step) {
    // Reached destination, update minimum steps
    if (x == n - 1 && y == m - 1) {
        if (step < ans) ans = step;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m
            && maze[nx][ny] == 0 && vis[nx][ny] == 0) {
            vis[nx][ny] = 1;
            dfs(nx, ny, step + 1);
            vis[nx][ny] = 0;  // Backtrack
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    vis[0][0] = 1;
    dfs(0, 0, 0);

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}

/*
 * Sample Input:
 * 5 5
 * 0 0 1 0 0
 * 0 0 0 0 1
 * 1 0 1 0 0
 * 0 0 1 1 0
 * 0 0 0 0 0
 *
 * Expected Output:
 * 8
 */

// ---- Practice 2: Maze Print Path ----
// Find one path from (0,0) to (n-1,m-1) and print the
// coordinates of each cell along the path, then stop immediately.
#include <iostream>
#include <cstdlib>
using namespace std;

int n, m;
int maze[10][10];
int vis[10][10];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// Store path coordinates
int pathX[100], pathY[100];
int pathLen = 0;

void dfs(int x, int y) {
    // Record current position in path
    pathX[pathLen] = x;
    pathY[pathLen] = y;
    pathLen++;

    // Reached destination: print path and exit
    if (x == n - 1 && y == m - 1) {
        for (int i = 0; i < pathLen; i++) {
            if (i > 0) cout << "->";
            cout << "(" << pathX[i] << "," << pathY[i] << ")";
        }
        cout << endl;
        exit(0);  // Stop immediately after finding one path
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m
            && maze[nx][ny] == 0 && vis[nx][ny] == 0) {
            vis[nx][ny] = 1;
            dfs(nx, ny);
            vis[nx][ny] = 0;
        }
    }

    pathLen--;  // Backtrack: remove current cell from path
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    vis[0][0] = 1;
    dfs(0, 0);

    // If no path found
    cout << "No path found" << endl;
    return 0;
}

/*
 * Sample Input:
 * 4 4
 * 0 0 1 0
 * 0 0 0 0
 * 1 0 1 0
 * 0 0 0 0
 *
 * Expected Output (one possible path):
 * (0,0)->(0,1)->(1,1)->(1,2)->(1,3)->(2,3)->(3,3)->(3,2)->(3,1)->(3,0)
 * (The answer is not unique; any valid path is acceptable)
 */

// ---- Practice 3: N-Queens Count ----
// Read n (1 <= n <= 8), output the total number of valid
// arrangements for the N-Queens problem.
#include <iostream>
#include <cmath>
using namespace std;

int n;
int queen[10];
int ans = 0;

bool check(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queen[i] == col) return false;
        if (abs(i - row) == abs(queen[i] - col)) return false;
    }
    return true;
}

void dfs(int row) {
    if (row == n) {
        ans++;
        return;
    }
    for (int col = 1; col <= n; col++) {
        if (check(row, col)) {
            queen[row] = col;
            dfs(row + 1);
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << ans << endl;
    return 0;
}

/*
 * Sample Input:
 * 8
 *
 * Expected Output:
 * 92
 *
 * Verification: n=1->1, n=4->2, n=5->10, n=6->4, n=7->40, n=8->92
 */
