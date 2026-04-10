// ============================================
// Lesson 33: Introduction to Structs
// Practice solutions
// ============================================

// ---- Practice 1: Fruit Info Card ----
// Read a fruit's name, color, and price. Output formatted info.
// Price should have 2 decimal places.
#include <bits/stdc++.h>
using namespace std;

struct Fruit {
    string name;
    string color;
    double price;
};

int main() {
    Fruit f;
    cin >> f.name >> f.color >> f.price;

    cout << "Fruit: " << f.name << endl;
    cout << "Color: " << f.color << endl;
    cout << "Price: " << fixed << setprecision(2) << f.price << endl;

    return 0;
}

/*
 * Sample Input:
 * apple red 5.5
 *
 * Expected Output:
 * Fruit: apple
 * Color: red
 * Price: 5.50
 */

// ---- Practice 2: Find the Top Student ----
// Read n students (name and score). Output the student with the highest score.
// (Guaranteed unique highest score.)

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

    // Find the student with the maximum score
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (stu[i].score > stu[maxIdx].score) {
            maxIdx = i;
        }
    }

    cout << stu[maxIdx].name << " " << stu[maxIdx].score << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 3
 * Alice 88
 * Bob 95
 * Carol 72
 *
 * Expected Output:
 * Bob 95
 */

// ---- Practice 3: Sort by Height ----
// Read n students (name and height in cm). Sort by height ascending;
// if heights are equal, sort by name in ascending lexicographic order.

/*
#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int height;
};

bool cmp(Student a, Student b) {
    if (a.height != b.height) return a.height < b.height;  // Shorter first
    return a.name < b.name;  // Same height: alphabetical order
}

int main() {
    int n;
    cin >> n;
    Student stu[105];

    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].height;
    }

    sort(stu, stu + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << stu[i].name << " " << stu[i].height << endl;
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 4
 * Tom 150
 * Jerry 140
 * Amy 150
 * Bob 135
 *
 * Expected Output:
 * Bob 135
 * Jerry 140
 * Amy 150
 * Tom 150
 */

// ---- Practice 4: Selection Contest (Challenge) ----
// n contestants, each with name, written score, and coding score.
// Total = written + coding. Sort by total descending and output top 3.
// (Guaranteed no ties.)

/*
#include <bits/stdc++.h>
using namespace std;

struct Player {
    string name;
    int s1;  // Written score
    int s2;  // Coding score
};

bool cmp(Player a, Player b) {
    return (a.s1 + a.s2) > (b.s1 + b.s2);  // Higher total first
}

int main() {
    int n;
    cin >> n;
    Player p[105];

    for (int i = 0; i < n; i++) {
        cin >> p[i].name >> p[i].s1 >> p[i].s2;
    }

    sort(p, p + n, cmp);

    // Output top 3
    for (int i = 0; i < 3 && i < n; i++) {
        cout << p[i].name << " " << (p[i].s1 + p[i].s2) << endl;
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 5
 * Alice 80 90
 * Bob 70 95
 * Carol 85 88
 * David 90 80
 * Eve 75 85
 *
 * Expected Output:
 * Carol 173
 * Alice 170
 * David 170
 */
