// ============================================
// Lesson 36: DFS Classic Problems
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Maze Path Count ----
// Given an n*m maze (0=path, 1=wall), count all paths
// from (0,0) to (n-1,m-1) using DFS with backtracking.
#include <iostream>
using namespace std;

int n, m;
int maze[10][10];
int vis[10][10];
int ans = 0;

// Direction arrays: right, left, down, up
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
    // Reached the destination, count this path
    if (x == n - 1 && y == m - 1) {
        ans++;
        return;
    }

    // Try all 4 directions
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Triple check: in bounds, not a wall, not visited
        if (nx >= 0 && nx < n && ny >= 0 && ny < m
            && maze[nx][ny] == 0
            && vis[nx][ny] == 0) {
            vis[nx][ny] = 1;   // Mark as visited
            dfs(nx, ny);       // Recurse to next cell
            vis[nx][ny] = 0;   // Backtrack: unmark
        }
    }
}

int main() {
    cin >> n >> m;

    // Read the maze
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    // Start DFS from (0,0)
    vis[0][0] = 1;  // Mark starting point as visited
    dfs(0, 0);

    cout << ans << endl;
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
 * Expected Output:
 * 4
 */

// ---- Example 2: 4-Queens Problem ----
// Place 4 queens on a 4x4 board so that no two queens
// attack each other (same row, column, or diagonal).
// Output all valid arrangements and the total count.
#include <iostream>
#include <cmath>
using namespace std;

int n = 4;
int queen[10];   // queen[i] = column of the queen in row i (1-indexed)
int ans = 0;

// Check if placing a queen at (row, col) conflicts with previous queens
bool check(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Same column conflict
        if (queen[i] == col) {
            return false;
        }
        // Diagonal conflict: |row_diff| == |col_diff|
        if (abs(i - row) == abs(queen[i] - col)) {
            return false;
        }
    }
    return true;
}

void dfs(int row) {
    // All n rows filled: found a valid arrangement
    if (row == n) {
        ans++;
        for (int i = 0; i < n; i++) {
            cout << queen[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
        return;
    }

    // Try each column for the current row
    for (int col = 1; col <= n; col++) {
        if (check(row, col)) {
            queen[row] = col;    // Place queen
            dfs(row + 1);        // Recurse to next row
            // queen[row] is overwritten in next iteration (natural backtrack)
        }
    }
}

int main() {
    dfs(0);
    cout << ans << endl;
    return 0;
}

/*
 * Expected Output:
 * 2 4 1 3
 * 3 1 4 2
 * 2
 */
