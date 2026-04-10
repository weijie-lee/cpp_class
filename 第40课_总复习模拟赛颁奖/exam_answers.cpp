// ============================================
// Lesson 40: Final Review + Mock Exam + Awards
// Reference answers for programming problems
// ============================================

// ---- Problem 1: Sweet Candies ----
// Xiao Ming has 'a' strawberry candies and 'b' mint candies.
// He wants to equally distribute all candies among n friends.
// Output: how many each friend gets, and how many are left over.
#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int total = a + b;
    cout << total / n << " " << total % n << endl;
    return 0;
}

/*
 * Sample Input:
 * 10 7 4
 *
 * Expected Output:
 * 4 1
 *
 * Explanation: 10+7=17, 17/4=4 remainder 1.
 */

// ---- Problem 2: Grade Classification ----
// Given n students' scores, classify them into grades:
// A (90-100), B (80-89), C (60-79), D (0-59).
// Output the count of each grade.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cntA = 0, cntB = 0, cntC = 0, cntD = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 90) {
            cntA++;
        } else if (x >= 80) {
            cntB++;
        } else if (x >= 60) {
            cntC++;
        } else {
            cntD++;
        }
    }
    cout << cntA << " " << cntB << " " << cntC << " " << cntD << endl;
    return 0;
}

/*
 * Sample Input:
 * 6
 * 95 82 76 55 100 60
 *
 * Expected Output:
 * 2 1 2 1
 */

// ---- Problem 3: Top Three ----
// Given n students with names and scores, output the top 3
// students sorted by score (descending). Ties are broken by
// input order (earlier input first).
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    int id;  // Input order for stable sorting
};

bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;  // Same score: earlier input first
}

int main() {
    int n;
    cin >> n;
    Student stu[105];
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].score;
        stu[i].id = i;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < 3; i++) {
        cout << stu[i].name << " " << stu[i].score << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 5
 * Alice 90
 * Bob 85
 * Cathy 95
 * David 90
 * Eve 88
 *
 * Expected Output:
 * Cathy 95
 * Alice 90
 * David 90
 */

// ---- Problem 4: Maze Shortest Path (BFS) ----
// Given an n*m maze ('.'=path, '#'=wall), find the minimum
// number of steps from (1,1) to (n,m). Output -1 if unreachable.
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
char maze[55][55];
int dist[55][55];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    }

    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m
                && maze[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[n][m] << endl;
    return 0;
}

/*
 * Sample Input:
 * 4 5
 * .....
 * .###.
 * ...#.
 * .#...
 *
 * Expected Output:
 * 8
 */
