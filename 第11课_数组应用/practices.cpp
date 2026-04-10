// ============================================
// Lesson 11: Array Applications - Max/Min, Average, Counting
// Practice solutions
// ============================================

// ---- Practice 1: Find the Minimum Value ----
// Input n integers, find and output the minimum value.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Arena method reversed: the smaller one takes the stage
    int minVal = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < minVal) {
            minVal = a[i];
        }
    }

    cout << minVal << endl;
    return 0;
}

/*
 * Sample Input:
 * 4
 * 12 5 8 3
 *
 * Expected Output:
 * 3
 */

// ---- Practice 2: Count Positive Numbers ----
// Input n integers (may include positive, negative, and zero),
// count how many are positive.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}

/*
 * Sample Input:
 * 6
 * -3 5 0 -1 8 2
 *
 * Expected Output:
 * 3
 */

// ---- Practice 3: Search for an Element ----
// Input n integers and a target x. If x exists in the array,
// output its first occurrence position (1-based). Otherwise output -1.
#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << i + 1 << endl;  // 1-based position
            return 0;  // found, exit immediately
        }
    }

    // If we reach here, x was not found
    cout << -1 << endl;
    return 0;
}

/*
 * Sample Input 1:
 * 5 7
 * 3 7 2 7 5
 *
 * Expected Output 1:
 * 2
 *
 * Sample Input 2:
 * 5 6
 * 3 7 2 7 5
 *
 * Expected Output 2:
 * -1
 */

// ---- Practice 4: Enhanced Grade Statistics ----
// Input n scores. Output:
// Line 1: highest and lowest score (space separated)
// Line 2: average (1 decimal place)
// Line 3: number of failing students (< 60)
// Line 4: number of excellent students (>= 90)
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

    int maxVal = a[0];
    int minVal = a[0];
    int sum = 0;
    int countFail = 0;   // failing (< 60)
    int countA = 0;      // excellent (>= 90)

    for (int i = 0; i < n; i++) {
        if (a[i] > maxVal) maxVal = a[i];
        if (a[i] < minVal) minVal = a[i];
        sum += a[i];
        if (a[i] < 60) countFail++;
        if (a[i] >= 90) countA++;
    }

    double avg = 1.0 * sum / n;

    cout << maxVal << " " << minVal << endl;
    cout << fixed << setprecision(1) << avg << endl;
    cout << countFail << endl;
    cout << countA << endl;

    return 0;
}

/*
 * Sample Input:
 * 6
 * 95 42 88 60 73 55
 *
 * Expected Output:
 * 95 42
 * 68.8
 * 2
 * 1
 */
