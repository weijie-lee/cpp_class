// ============================================
// Lesson 29: Recursion I
// Practice solutions
// ============================================

// ---- Practice 1: Count Up (1 to N) ----
// Input a positive integer N, use recursion to print
// numbers from 1 to N in ascending order, one per line.
// Hint: recurse first, then print (reverse of countdown).
#include <iostream>
using namespace std;

void countUp(int n) {
    if (n == 0) return;
    countUp(n - 1);      // recurse first (handle smaller numbers)
    cout << n << endl;    // print on the way back
}

int main() {
    int n;
    cin >> n;
    countUp(n);
    return 0;
}

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * 1
 * 2
 * 3
 * 4
 * 5
 */

// ---- Practice 2: Recursive Factorial ----
// Input a positive integer N (1 <= N <= 15),
// use recursion to compute N! = 1*2*3*...*N.
#if 0
#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n == 1) return 1;             // base case
    return (long long)n * factorial(n - 1);  // recursive formula
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * 120
 */

// ---- Practice 3: Recursive Fibonacci ----
// Fibonacci sequence: 1, 1, 2, 3, 5, 8, 13, 21, ...
// Input a positive integer N (1 <= N <= 25),
// use recursion to compute the N-th Fibonacci number.
#if 0
#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 1 || n == 2) return 1;   // base cases
    return fib(n - 1) + fib(n - 2);   // recursive formula
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 10
 *
 * Expected Output:
 * 55
 */

// ---- Practice 4: Recursive Binary Representation (Challenge) ----
// Input a positive integer N (1 <= N <= 1000000),
// use recursion to output its binary representation
// (no leading zeros).
// Hint: similar to "print digits in order",
// replace /10 and %10 with /2 and %2.
#if 0
#include <iostream>
using namespace std;

void printBinary(int n) {
    if (n < 2) {          // base case: single binary digit
        cout << n;
        return;
    }
    printBinary(n / 2);   // recurse: handle higher bits first
    cout << n % 2;        // print current bit
}

int main() {
    int n;
    cin >> n;
    printBinary(n);
    cout << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 13
 *
 * Expected Output:
 * 1101
 *
 * Sample Input:
 * 255
 *
 * Expected Output:
 * 11111111
 */
