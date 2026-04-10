// ============================================
// Lesson 33: Introduction to Structs
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Personal Card (Warm-up) ----
// Define a struct Person with name and age. Read input and print formatted output.
#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    Person p;
    cin >> p.name >> p.age;
    cout << p.name << " is " << p.age << " years old." << endl;
    return 0;
}

/*
 * Sample Input:
 * Alice 12
 *
 * Expected Output:
 * Alice is 12 years old.
 */

// ---- Example 2: Class Roster — Filter High Scores ----
// Read n students (name and score), output names of those with score >= 90.

/*
#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int score;
};

int main() {
    int n;
    cin >> n;
    Student stu[105];

    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].score;
    }

    cout << "Honor Roll:" << endl;
    for (int i = 0; i < n; i++) {
        if (stu[i].score >= 90) {
            cout << stu[i].name << endl;
        }
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 4
 * Alice 88
 * Bob 95
 * Carol 72
 * David 91
 *
 * Expected Output:
 * Honor Roll:
 * Bob
 * David
 */

// ---- Example 3: Score Ranking (Struct + sort) ----
// Read n students (name and score). Sort by score descending;
// if scores are equal, sort by name in ascending lexicographic order.

/*
#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int score;
};

bool cmp(Student a, Student b) {
    if (a.score != b.score) return a.score > b.score;  // Higher score first
    return a.name < b.name;  // Same score: smaller name first
}

int main() {
    int n;
    cin >> n;
    Student stu[105];

    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].score;
    }

    sort(stu, stu + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << stu[i].name << " " << stu[i].score << endl;
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 4
 * Alice 88
 * Bob 95
 * Carol 88
 * David 72
 *
 * Expected Output:
 * Bob 95
 * Alice 88
 * Carol 88
 * David 72
 */
