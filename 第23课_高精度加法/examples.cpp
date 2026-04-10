// ============================================
// Lesson 23: Big Number Addition (High Precision)
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Basic High-Precision Addition (Standard Template) ----
// Read two non-negative integers (up to 500 digits) and print their sum.
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // Step 1: Read two large numbers as strings
    string s1, s2;
    cin >> s1 >> s2;

    // Arrays to store digits: a for first number, b for second, c for result
    // Size 510 is enough (500 digits + possible carry)
    int a[510] = {0};
    int b[510] = {0};
    int c[510] = {0};

    int len1 = s1.size();  // Number of digits in first number
    int len2 = s2.size();  // Number of digits in second number

    // Step 2: Store string digits into arrays in reverse order
    // e.g., s1 = "386" -> a[0]=6, a[1]=8, a[2]=3 (units digit first)
    for (int i = 0; i < len1; i++) {
        a[i] = s1[len1 - 1 - i] - '0';
    }
    for (int i = 0; i < len2; i++) {
        b[i] = s2[len2 - 1 - i] - '0';
    }

    // Step 3: Add digit by digit
    int len = max(len1, len2);  // Use the longer length
    int carry = 0;              // Carry starts at 0

    for (int i = 0; i < len; i++) {
        int sum = a[i] + b[i] + carry;  // Current digit sum + carry
        c[i] = sum % 10;                // Keep the ones digit
        carry = sum / 10;               // New carry
    }

    // Step 4: Don't forget the final carry!
    if (carry > 0) {
        c[len] = carry;
        len++;  // Result has one more digit
    }

    // Step 5: Print result in reverse order
    for (int i = len - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 9876
 * 2345
 *
 * Expected Output:
 * 12221
 */

// ---- Example 2: Two Numbers with Very Different Lengths ----
// Compute 100000000000000000000 (1 followed by 20 zeros) + 1.
// This uses the same code as Example 1. The shorter number's higher
// digits are automatically 0 because the array is initialized to 0.
/*
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int a[510] = {0}, b[510] = {0}, c[510] = {0};
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
 * Sample Input:
 * 100000000000000000000
 * 1
 *
 * Expected Output:
 * 100000000000000000001
 */

// ---- Example 3: Consecutive Carries (999999 + 1) ----
// This tests the cascade carry scenario: every digit produces a carry.
// Uses the same code template. Walk through the loop:
//   i=0: 9+1+0=10, c[0]=0, carry=1
//   i=1: 9+0+1=10, c[1]=0, carry=1
//   ... (all digits produce carry)
//   After loop: carry=1, c[6]=1, len=7
//   Output: 1000000
/*
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int a[510] = {0}, b[510] = {0}, c[510] = {0};
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
 * Sample Input:
 * 999999
 * 1
 *
 * Expected Output:
 * 1000000
 */
