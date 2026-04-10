// ============================================
// Lesson 24: Phase 2 Review and Test
// Reference answers for programming problems in the test
// ============================================

// ---- Problem 1 (Test Q8): Sum of Range ----
// Define a function sumRange(a, b) that returns the sum of all integers from a to b.
// Input: two integers a and b (1 <= a <= b <= 1000)
// Output: the sum from a to b (inclusive)
#include <iostream>
using namespace std;

int sumRange(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << sumRange(a, b) << endl;
    return 0;
}

/*
 * Sample Input:
 * 3 7
 *
 * Expected Output:
 * 25
 *
 * Explanation: 3 + 4 + 5 + 6 + 7 = 25
 */

// ---- Problem 2 (Test Q9): Sort Descending and Find Range ----
// Read n integers, sort them from largest to smallest using sort,
// print the sorted array, then print the difference between max and min.
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[110];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, greater<int>());  // Sort descending

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;

    cout << a[0] - a[n - 1] << endl;  // Max - Min

    return 0;
}
*/

/*
 * Sample Input:
 * 5
 * 3 -1 8 5 2
 *
 * Expected Output:
 * 8 5 3 2 -1
 * 9
 */

// ---- Problem 3 (Test Q10): High-Precision Addition ----
// Read two non-negative big integers (up to 200 digits), print their sum.
// int and long long cannot hold numbers this large, so we use array simulation.
/*
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int a[210] = {0}, b[210] = {0}, c[210] = {0};
    int len1 = s1.length();
    int len2 = s2.length();

    // Reverse store: units digit at index 0
    for (int i = 0; i < len1; i++) {
        a[i] = s1[len1 - 1 - i] - '0';
    }
    for (int i = 0; i < len2; i++) {
        b[i] = s2[len2 - 1 - i] - '0';
    }

    // Add digit by digit with carry
    int len = max(len1, len2);
    for (int i = 0; i < len; i++) {
        c[i] += a[i] + b[i];
        c[i + 1] += c[i] / 10;  // Carry to next digit
        c[i] %= 10;              // Keep only the ones digit
    }
    if (c[len] > 0) len++;       // Check carry at the highest digit

    // Print result in reverse order
    for (int i = len - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 99999999999999999999
 * 1
 *
 * Expected Output:
 * 100000000000000000000
 */
