// ============================================
// Lesson 30: Recursion II - Factorial, Fibonacci, Hanoi
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Factorial (Recursive) ----
// Input a non-negative integer n (0 <= n <= 20),
// output n! using recursion.
// Formula: n! = n * (n-1)!, base case: 0! = 1
#include <iostream>
using namespace std;

long long factorial(int n) {
    // base case: 0! = 1
    if (n == 0) {
        return 1;
    }
    // recursive formula: n! = n * (n-1)!
    return (long long)n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}

/*
 * Sample Input:
 * 5
 *
 * Expected Output:
 * 120
 *
 * Sample Input:
 * 0
 *
 * Expected Output:
 * 1
 */

// ---- Example 2: Fibonacci Sequence (Recursive) ----
// Input a positive integer n (1 <= n <= 30),
// output the n-th Fibonacci number.
// Formula: fib(n) = fib(n-1) + fib(n-2)
// Base cases: fib(1) = 1, fib(2) = 1
#if 0
#include <iostream>
using namespace std;

int fib(int n) {
    // base cases
    if (n == 1 || n == 2) {
        return 1;
    }
    // recursive formula
    return fib(n - 1) + fib(n - 2);
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

// ---- Example 3: Tower of Hanoi ----
// Input n (1 <= n <= 10), the number of disks.
// Output each move to transfer all disks from peg A to peg C,
// then output the total number of moves.
// Strategy: move top n-1 to aux, move largest to target,
//           move n-1 from aux to target.
#if 0
#include <iostream>
using namespace std;

int cnt = 0;  // total move counter

// n: number of disks
// from: source peg
// aux: auxiliary peg
// to: destination peg
void hanoi(int n, char from, char aux, char to) {
    // base case: only 1 disk, move it directly
    if (n == 1) {
        cout << from << " -> " << to << endl;
        cnt++;
        return;
    }

    // step 1: move top n-1 disks from source to auxiliary (using dest as helper)
    hanoi(n - 1, from, to, aux);

    // step 2: move the largest disk from source to destination
    cout << from << " -> " << to << endl;
    cnt++;

    // step 3: move n-1 disks from auxiliary to destination (using source as helper)
    hanoi(n - 1, aux, from, to);
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    cout << "Total: " << cnt << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 3
 *
 * Expected Output:
 * A -> C
 * A -> B
 * C -> B
 * A -> C
 * B -> A
 * B -> C
 * A -> C
 * Total: 7
 */

// ---- Example 4: Factorial - Recursion vs Loop ----
// Compare recursive and iterative implementations of factorial.
#if 0
#include <iostream>
using namespace std;

// Method 1: Recursion
long long factorial_rec(int n) {
    if (n == 0) return 1;
    return (long long)n * factorial_rec(n - 1);
}

// Method 2: Loop
long long factorial_loop(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << "Recursive: " << factorial_rec(n) << endl;
    cout << "Iterative: " << factorial_loop(n) << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * 10
 *
 * Expected Output:
 * Recursive: 3628800
 * Iterative: 3628800
 */
