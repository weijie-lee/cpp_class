// ============================================
// Lesson 29: Recursion I
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Countdown (N to 1) ----
// Input a positive integer N, use recursion to print
// numbers from N down to 1, one per line.
#include <iostream>
using namespace std;

void countdown(int n) {
    if (n == 0) {       // base case: stop at 0
        return;
    }
    cout << n << endl;   // do: print current number
    countdown(n - 1);    // recurse: shrink by 1
}

int main() {
    int n;
    cin >> n;
    countdown(n);
    return 0;
}

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * 5
 * 4
 * 3
 * 2
 * 1
 */

// ---- Example 2: Recursive Sum 1+2+...+N ----
// Input a positive integer N, use recursion to compute
// and output 1+2+3+...+N.
#if 0
#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 1) {           // base case: only one number
        return 1;
    }
    return n + sum(n - 1);  // recursive formula
}

int main() {
    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * 15
 */

// ---- Example 3: Print Digits in Order ----
// Input a positive integer N, use recursion to print
// its digits from most significant to least significant,
// separated by spaces.
#if 0
#include <iostream>
using namespace std;

void printDigits(int n) {
    if (n < 10) {              // base case: single digit
        cout << n;
        return;
    }
    printDigits(n / 10);       // recurse: handle higher digits first
    cout << " " << n % 10;    // then print current last digit
}

int main() {
    int n;
    cin >> n;
    printDigits(n);
    cout << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 2048
 *
 * Expected Output:
 * 2 0 4 8
 */

// ---- Example 4: Recursive Palindrome Check ----
// Input a lowercase string, use recursion to determine
// if it is a palindrome. Output "Yes" or "No".
#if 0
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s, int left, int right) {
    if (left >= right) {        // base case: checked all pairs
        return true;
    }
    if (s[left] != s[right]) {  // mismatch found
        return false;
    }
    // recurse: strip head and tail, check inner part
    return isPalindrome(s, left + 1, right - 1);
}

int main() {
    string s;
    cin >> s;
    if (isPalindrome(s, 0, s.size() - 1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
#endif

/*
 * Sample Input:
 * abcba
 *
 * Expected Output:
 * Yes
 *
 * Sample Input:
 * hello
 *
 * Expected Output:
 * No
 */
