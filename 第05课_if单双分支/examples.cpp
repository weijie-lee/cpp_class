// ============================================
// Lesson 05: if Single and Double Branch
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Check Positive Number (if single branch) ----
// Input an integer; if it is positive, output "positive"
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 0) {
        cout << "positive" << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * positive
 *
 * (If input is 0 or negative, there is no output)
 */

// ---- Example 2: Odd or Even (if-else double branch) ----
// Input an integer, determine whether it is odd or even
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 7
 *
 * Expected Output:
 * odd
 */

// ---- Example 3: Pass or Fail (double branch + real-life scenario) ----
// Input a test score (0-100). If >= 60, output "PASS"; otherwise output "FAIL"
#include <iostream>
using namespace std;

int main() {
    int score;
    cin >> score;
    if (score >= 60) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 75
 *
 * Expected Output:
 * PASS
 */

// ---- Example 4: Find the Larger of Two Numbers ----
// Input two integers a and b, output the larger one
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << a << endl;
    } else {
        cout << b << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 3 8
 *
 * Expected Output:
 * 8
 */

// ---- Example 5: Password Verification (== vs = distinction) ----
// The password is 123456. If the user input matches, print "Welcome!"; otherwise "Wrong password!"
#include <iostream>
using namespace std;

int main() {
    int password = 123456;
    int input;
    cin >> input;
    if (input == password) {
        cout << "Welcome!" << endl;
    } else {
        cout << "Wrong password!" << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 123456
 *
 * Expected Output:
 * Welcome!
 *
 * ---
 *
 * Sample Input:
 * 111111
 *
 * Expected Output:
 * Wrong password!
 */
