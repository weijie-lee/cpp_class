// ============================================
// Lesson 23: Big Number Addition (High Precision)
// Practice solutions
// ============================================

// ---- Practice 1: Type the Template (Warm-up) ----
// Type the high-precision addition template from scratch and test it.
// Same code as Example 1 — practice by rewriting it yourself.
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int a[510] = {0}, b[510] = {0}, c[510] = {0};
    int len1 = s1.size(), len2 = s2.size();

    // Reverse store: units digit at index 0
    for (int i = 0; i < len1; i++)
        a[i] = s1[len1 - 1 - i] - '0';
    for (int i = 0; i < len2; i++)
        b[i] = s2[len2 - 1 - i] - '0';

    // Add digit by digit with carry
    int len = max(len1, len2);
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int sum = a[i] + b[i] + carry;
        c[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) {
        c[len] = carry;
        len++;
    }

    // Print result in reverse
    for (int i = len - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;

    return 0;
}

/*
 * Test 1:
 * Sample Input:
 * 123
 * 456
 * Expected Output:
 * 579
 *
 * Test 2:
 * Sample Input:
 * 999
 * 999
 * Expected Output:
 * 1998
 *
 * Test 3:
 * Sample Input:
 * 0
 * 0
 * Expected Output:
 * 0
 */

// ---- Practice 2: Large Number Addition (up to 200 digits) ----
// Same template, works for numbers up to 200 digits.
/*
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int a[210] = {0}, b[210] = {0}, c[210] = {0};
    int len1 = s1.size(), len2 = s2.size();

    for (int i = 0; i < len1; i++)
        a[i] = s1[len1 - 1 - i] - '0';
    for (int i = 0; i < len2; i++)
        b[i] = s2[len2 - 1 - i] - '0';

    int len = max(len1, len2);
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int sum = a[i] + b[i] + carry;
        c[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) {
        c[len] = carry;
        len++;
    }

    for (int i = len - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;

    return 0;
}
*/

/*
 * Test 1:
 * Sample Input:
 * 11111111111111111111
 * 22222222222222222222
 * Expected Output:
 * 33333333333333333333
 *
 * Test 2:
 * Sample Input:
 * 99999999999999999999
 * 1
 * Expected Output:
 * 100000000000000000000
 */

// ---- Practice 3: Sum of Three Large Numbers (Advanced) ----
// Read three non-negative integers (up to 100 digits), print a + b + c.
// Strategy: compute temp = a + b, then compute result = temp + c.
/*
#include <iostream>
#include <cstring>
using namespace std;

// Helper function: add two big numbers stored in arrays, return result length
int bigAdd(int x[], int xlen, int y[], int ylen, int res[]) {
    int len = max(xlen, ylen);
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int sum = x[i] + y[i] + carry;
        res[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) {
        res[len] = carry;
        len++;
    }
    return len;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int a[210] = {0}, b[210] = {0}, c[210] = {0};
    int temp[210] = {0}, result[210] = {0};

    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();

    for (int i = 0; i < len1; i++) a[i] = s1[len1 - 1 - i] - '0';
    for (int i = 0; i < len2; i++) b[i] = s2[len2 - 1 - i] - '0';
    for (int i = 0; i < len3; i++) c[i] = s3[len3 - 1 - i] - '0';

    // First: temp = a + b
    int tempLen = bigAdd(a, len1, b, len2, temp);

    // Then: result = temp + c
    int resLen = bigAdd(temp, tempLen, c, len3, result);

    // Print in reverse
    for (int i = resLen - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 99999999999999999999
 * 1
 * 100000000000000000000
 *
 * Expected Output:
 * 200000000000000000000
 */

// ---- Practice 4: Compare and Add (Thinking Problem) ----
// Read two big integers a and b (up to 500 digits).
// Line 1: Print a + b.
// Line 2: Print "a" if a > b, "b" if a < b, "same" if equal.
// Comparison: first compare lengths, then compare digit by digit from highest.
/*
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // --- Part 1: High-precision addition ---
    int a[510] = {0}, b[510] = {0}, c[510] = {0};
    int len1 = s1.size(), len2 = s2.size();

    for (int i = 0; i < len1; i++) a[i] = s1[len1 - 1 - i] - '0';
    for (int i = 0; i < len2; i++) b[i] = s2[len2 - 1 - i] - '0';

    int len = max(len1, len2);
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int sum = a[i] + b[i] + carry;
        c[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) {
        c[len] = carry;
        len++;
    }

    for (int i = len - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;

    // --- Part 2: Compare a and b ---
    if (len1 > len2) {
        cout << "a" << endl;
    } else if (len1 < len2) {
        cout << "b" << endl;
    } else {
        // Same length: compare from highest digit (original string order)
        bool found = false;
        for (int i = 0; i < len1; i++) {
            if (s1[i] > s2[i]) {
                cout << "a" << endl;
                found = true;
                break;
            } else if (s1[i] < s2[i]) {
                cout << "b" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "same" << endl;
        }
    }

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
 * a
 */
