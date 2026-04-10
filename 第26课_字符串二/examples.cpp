// ============================================
// Lesson 26: String Operations II
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Longest Name ----
// Read n names, output the longest one.
// If lengths are equal, output the one read first.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string best = "";       // current longest name
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (name.size() > best.size()) {
            best = name;    // found a longer one, update
        }
    }
    cout << best << endl;
    return 0;
}

/*
 * Sample Input:
 * 3
 * Alice
 * Bob
 * Catherine
 *
 * Expected Output:
 * Catherine
 */

// ---- Example 2: Sum of Digits in a String ----
// Read a string containing letters and digits,
// compute the sum of all digit characters.
// e.g. "a1b2c3" -> 1+2+3 = 6
#if 0
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            sum += s[i] - '0';   // char to digit
        }
    }
    cout << sum << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * a1b2c3
 *
 * Expected Output:
 * 6
 */

// ---- Example 3: Palindrome Check ----
// Read a string, determine if it is a palindrome
// (reads the same forwards and backwards).
// Output "Yes" or "No".
#if 0
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool ok = true;     // assume palindrome first
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            ok = false;  // mismatch found
            break;
        }
        left++;
        right--;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
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

// ---- Example 4: Caesar Cipher Encryption ----
// Each lowercase letter is shifted forward by 3 positions.
// 'a'->'d', 'x'->'a', 'y'->'b', 'z'->'c'.
// Other characters remain unchanged.
#if 0
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] - 'a' + 3) % 26 + 'a';
        }
    }
    cout << s << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * xyz
 *
 * Expected Output:
 * abc
 *
 * Sample Input:
 * hello
 *
 * Expected Output:
 * khoor
 */
