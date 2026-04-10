// ============================================
// Lesson 12: Phase 1 Review and Test
// Test Answers - Programming Problems (Problems 8, 9, 10)
// ============================================

// ---- Problem 1: Extract Digits of a 3-Digit Number ----
// Input a 3-digit positive integer, output its hundreds, tens,
// and ones digits on separate lines.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int hundreds = n / 100;       // hundreds digit
    int tens = n / 10 % 10;       // tens digit
    int ones = n % 10;            // ones digit

    cout << hundreds << endl;
    cout << tens << endl;
    cout << ones << endl;

    return 0;
}

/*
 * Sample Input:
 * 527
 *
 * Expected Output:
 * 5
 * 2
 * 7
 */

// ---- Problem 2: Score to Grade Conversion ----
// Input a score (0-100), output the corresponding grade letter.
// 90-100 -> A, 80-89 -> B, 70-79 -> C, 60-69 -> D, 0-59 -> E
#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score;

    if (score >= 90) {
        cout << "A" << endl;
    } else if (score >= 80) {
        cout << "B" << endl;
    } else if (score >= 70) {
        cout << "C" << endl;
    } else if (score >= 60) {
        cout << "D" << endl;
    } else {
        cout << "E" << endl;
    }

    return 0;
}

/*
 * Sample Input:
 * 85
 *
 * Expected Output:
 * B
 */

// ---- Problem 3: Difference Between Max and Min ----
// Input n integers, find the maximum and minimum values,
// then output their difference.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[110];  // array sized larger than needed
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxVal = a[0];
    int minVal = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
        if (a[i] < minVal) {
            minVal = a[i];
        }
    }

    cout << maxVal - minVal << endl;

    return 0;
}

/*
 * Sample Input:
 * 5
 * 3 -1 8 5 2
 *
 * Expected Output:
 * 9
 */
