// ============================================
// Lesson 30: Recursion II - Factorial, Fibonacci, Hanoi
// Practice solutions
// ============================================

// ---- Practice 1: Recursive Sum 1+2+...+N ----
// Input a positive integer n (1 <= n <= 1000),
// use recursion to compute 1+2+3+...+n.
// Formula: sum(n) = n + sum(n-1), base case: sum(1) = 1
#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 1) return 1;         // base case
    return n + sum(n - 1);        // recursive formula
}

int main() {
    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}

/*
 * Sample Input:
 * 100
 *
 * Expected Output:
 * 5050
 */

// ---- Practice 2: Recursive Power (a^n) ----
// Input two non-negative integers a and n
// (1 <= a <= 10, 0 <= n <= 20),
// use recursion to compute a^n.
// Formula: power(a,n) = a * power(a,n-1)
// Base case: power(a,0) = 1
#if 0
#include <iostream>
using namespace std;

long long power(int a, int n) {
    if (n == 0) return 1;                    // base case: a^0 = 1
    return (long long)a * power(a, n - 1);   // recursive formula
}

int main() {
    int a, n;
    cin >> a >> n;
    cout << power(a, n) << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 2 10
 *
 * Expected Output:
 * 1024
 *
 * Sample Input:
 * 3 0
 *
 * Expected Output:
 * 1
 */

// ---- Practice 3: Hanoi Tower Move Count ----
// Input n (1 <= n <= 30), output the total number of moves
// needed for the Tower of Hanoi with n disks.
// Formula: moves(n) = 2 * moves(n-1) + 1
// Base case: moves(1) = 1
#if 0
#include <iostream>
using namespace std;

long long moves(int n) {
    if (n == 1) return 1;               // base case: 1 disk = 1 move
    return 2 * moves(n - 1) + 1;        // recursive formula
}

int main() {
    int n;
    cin >> n;
    cout << moves(n) << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 10
 *
 * Expected Output:
 * 1023
 *
 * Sample Input:
 * 3
 *
 * Expected Output:
 * 7
 */

// ---- Practice 4: Reverse Digits ----
// Input a positive integer n, use recursion to print
// its digits in reverse order, separated by spaces.
// Hint: print n%10 first, then recurse on n/10.
// Base case: n == 0 means stop.
#if 0
#include <iostream>
using namespace std;

bool first_digit = true;  // for formatting spaces

void reverseDigits(int n) {
    if (n == 0) return;           // base case: no more digits
    if (!first_digit) cout << " ";
    cout << n % 10;               // print last digit
    first_digit = false;
    reverseDigits(n / 10);        // recurse on remaining digits
}

int main() {
    int n;
    cin >> n;
    first_digit = true;
    reverseDigits(n);
    cout << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 12345
 *
 * Expected Output:
 * 5 4 3 2 1
 *
 * Sample Input:
 * 100
 *
 * Expected Output:
 * 0 0 1
 */
