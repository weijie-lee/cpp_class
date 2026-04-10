// ============================================
// Lesson 11: Array Applications - Max/Min, Average, Counting
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Find the Maximum Value (Arena Method) ----
// Input n integers, find and output the maximum value.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Arena method: let a[0] be the initial champion
    int maxVal = a[0];
    for (int i = 1; i < n; i++) {  // start from 1, a[0] is already the champion
        if (a[i] > maxVal) {
            maxVal = a[i];  // challenger wins, replace champion
        }
    }

    cout << maxVal << endl;
    return 0;
}

/*
 * Sample Input:
 * 5
 * 3 7 2 9 5
 *
 * Expected Output:
 * 9
 */

// ---- Example 2: Calculate the Average ----
// Input n integers, compute their average (keep 2 decimal places).
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    int sum = 0;  // accumulator, starts at 0

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];  // accumulate while reading
    }

    // Multiply by 1.0 to convert to floating point before division
    double avg = 1.0 * sum / n;
    cout << fixed << setprecision(2) << avg << endl;

    return 0;
}

/*
 * Sample Input:
 * 4
 * 80 90 70 85
 *
 * Expected Output:
 * 81.25
 */

// ---- Example 3: Count Passing Students ----
// Input n scores (0~100), count how many are passing (>= 60).
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;  // counter, starts at 0
    for (int i = 0; i < n; i++) {
        if (a[i] >= 60) {
            count++;  // found a passing score, increment
        }
    }

    cout << count << endl;
    return 0;
}

/*
 * Sample Input:
 * 6
 * 55 80 42 60 99 38
 *
 * Expected Output:
 * 3
 */

// ---- Example 4: Comprehensive Grade Analysis ----
// Input n scores, find max, min, average (2 decimals), and passing count.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Four tasks running simultaneously
    int maxVal = a[0];   // track highest score
    int minVal = a[0];   // track lowest score
    int sum = 0;          // accumulate total
    int count = 0;        // count passing students

    for (int i = 0; i < n; i++) {
        // Task 1: arena method for max
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
        // Task 2: arena method for min
        if (a[i] < minVal) {
            minVal = a[i];
        }
        // Task 3: accumulate sum
        sum += a[i];
        // Task 4: count passing scores
        if (a[i] >= 60) {
            count++;
        }
    }

    double avg = 1.0 * sum / n;

    cout << "max=" << maxVal << endl;
    cout << "min=" << minVal << endl;
    cout << "avg=" << fixed << setprecision(2) << avg << endl;
    cout << "pass=" << count << endl;

    return 0;
}

/*
 * Sample Input:
 * 5
 * 88 55 92 60 73
 *
 * Expected Output:
 * max=92
 * min=55
 * avg=73.60
 * pass=3
 */
