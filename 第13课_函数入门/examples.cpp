// ============================================
// Lesson 13: Introduction to Functions
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Sum of Two Numbers (Simplest Function) ----
// Define a function 'add' that takes two integers and returns their sum.
// Read two numbers in main, call the function, and print the result.
#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << add(x, y) << endl;
    return 0;
}

/*
 * Sample Input:
 * 3 5
 *
 * Expected Output:
 * 8
 */

// ---- Example 2: Maximum of Three Numbers ----
// Define a function 'maxTwo' that returns the larger of two integers.
// Use it in main to find the maximum of three numbers via nested calls.
#include <iostream>
using namespace std;

int maxTwo(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Nested call: compare first two, then compare winner with third
    int ans = maxTwo(maxTwo(a, b), c);
    cout << ans << endl;
    return 0;
}

/*
 * Sample Input:
 * 3 7 5
 *
 * Expected Output:
 * 7
 */

// ---- Example 3: Print Stars with a void Function ----
// Define a void function 'printStars' that prints n asterisks in one line.
// Call it in main to print a right triangle of stars.
#include <iostream>
using namespace std;

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;  // newline after each row
    // void function does not need a return statement
}

int main() {
    int rows;
    cin >> rows;
    for (int i = 1; i <= rows; i++) {
        printStars(i);  // row 1 has 1 star, row 2 has 2, ...
    }
    return 0;
}

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * *
 * **
 * ***
 * ****
 * *****
 */

// ---- Example 4: Print All Primes up to N ----
// Define a function 'isPrime' that returns 1 if x is prime, 0 otherwise.
// In main, input n and output all primes from 2 to n.
#include <iostream>
using namespace std;

// Check if x is a prime number
// Prime: greater than 1, divisible only by 1 and itself
int isPrime(int x) {
    if (x < 2) {
        return 0;  // not prime
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;  // divisible, not prime
        }
    }
    return 1;  // no divisor found, it is prime
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i) == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}

/*
 * Sample Input:
 * 20
 *
 * Expected Output:
 * 2 3 5 7 11 13 17 19
 */
