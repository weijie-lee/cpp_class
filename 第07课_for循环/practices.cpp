// ============================================
// Lesson 07: for Loop
// Practice solutions
// ============================================

// ---- Practice 1: Print Even Numbers from 1 to N ----
// Input a positive integer N, output all even numbers from 1 to N.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i = i + 2) {
        cout << i << endl;
    }
    return 0;
}

/*
 * Sample Input: 10
 *
 * Expected Output:
 * 2
 * 4
 * 6
 * 8
 * 10
 */

// ---- Practice 2: Sum of Odd Numbers up to N ----
// Input a positive integer N, compute the sum of all odd numbers <= N.
// i.e., 1 + 3 + 5 + 7 + ...
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i = i + 2) {
        sum = sum + i;
    }
    cout << sum << endl;
    return 0;
}

/*
 * Sample Input: 10
 *
 * Expected Output:
 * 25
 *
 * (1 + 3 + 5 + 7 + 9 = 25)
 */

// ---- Practice 3: Print Star Triangle (Method 1: string constructor) ----
// Input a positive integer N, print N rows of stars forming a right triangle.
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        // Use string constructor to repeat '*' i times
        cout << string(i, '*') << endl;
    }
    return 0;
}

/*
 * Sample Input: 5
 *
 * Expected Output:
 * *
 * **
 * ***
 * ****
 * *****
 */

// ---- Practice 3 (Method 2): Print Star Triangle (Nested Loop) ----
// Same problem, solved with nested loops.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

/*
 * Sample Input: 5
 *
 * Expected Output:
 * *
 * **
 * ***
 * ****
 * *****
 */

// ---- Practice 4: Factorial (Challenge) ----
// Input a positive integer N, compute N! = 1 * 2 * 3 * ... * N.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 1;  // For multiplication, start from 1 (not 0!)
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    cout << result << endl;
    return 0;
}

/*
 * Sample Input: 5
 *
 * Expected Output:
 * 120
 *
 * (1 * 2 * 3 * 4 * 5 = 120)
 */
