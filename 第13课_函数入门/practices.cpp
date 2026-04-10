// ============================================
// Lesson 13: Introduction to Functions
// Practice solutions
// ============================================

// ---- Practice 1: Absolute Value Function ----
// Define function 'myAbs' that takes an integer and returns its absolute value.
// Input an integer in main, call the function, and print the result.
#include <iostream>
using namespace std;

int myAbs(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int main() {
    int n;
    cin >> n;
    cout << myAbs(n) << endl;
    return 0;
}

/*
 * Sample Input:
 * -7
 *
 * Expected Output:
 * 7
 */

// ---- Practice 2: Greeting with a void Function ----
// Define a void function 'greet' that takes a student ID and prints a greeting.
// In main, input 3 student IDs and call greet for each.
#include <iostream>
using namespace std;

void greet(int id) {
    cout << "Hello, student #" << id << "!" << endl;
}

int main() {
    int id1, id2, id3;
    cin >> id1 >> id2 >> id3;
    greet(id1);
    greet(id2);
    greet(id3);
    return 0;
}

/*
 * Sample Input:
 * 101 102 103
 *
 * Expected Output:
 * Hello, student #101!
 * Hello, student #102!
 * Hello, student #103!
 */

// ---- Practice 3: Factorial Function ----
// Define function 'factorial' that takes a positive integer n
// and returns n! (1 * 2 * 3 * ... * n).
// Input a positive integer (<= 12) in main and output its factorial.
#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
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
 */

// ---- Practice 4: Eliminate Repeated Code ----
// Define function 'sumTo' that returns the sum from 1 to n.
// Use it to compute 1+...+5, 1+...+10, and 1+...+100 without repeating code.
#include <iostream>
using namespace std;

int sumTo(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    cout << sumTo(5) << endl;
    cout << sumTo(10) << endl;
    cout << sumTo(100) << endl;
    return 0;
}

/*
 * Expected Output:
 * 15
 * 55
 * 5050
 */
