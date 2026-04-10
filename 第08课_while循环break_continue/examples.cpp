// ============================================
// Lesson 08: while Loop, break & continue
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Sum 1 to 100 Using while (Compare with for) ----
// Compute 1 + 2 + 3 + ... + 100 using a while loop.
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int i = 1;            // Step 1: Initialize before while
    while (i <= 100) {    // Step 2: Condition in parentheses
        sum += i;
        i++;              // Step 3: Update inside the loop body (don't forget!)
    }
    cout << "Sum from 1 to 100: " << sum << endl;
    return 0;
}

/*
 * Expected Output:
 * Sum from 1 to 100: 5050
 */

// ---- Example 2: Keep Reading Until 0 (Sentinel Value) ----
// Simulate a cashier: read prices one by one, input 0 to checkout.
// Output the total price.
#include <iostream>
using namespace std;

int main() {
    int price;
    int total = 0;

    cout << "Enter prices (0 to checkout):" << endl;
    cin >> price;              // Read the first price

    while (price != 0) {      // Continue as long as it's not 0
        total += price;        // Add to total
        cin >> price;          // Read next price
    }

    cout << "Total: " << total << endl;
    return 0;
}

/*
 * Sample Input:
 * 10
 * 25
 * 8
 * 0
 *
 * Expected Output:
 * Enter prices (0 to checkout):
 * Total: 43
 */

// ---- Example 3: Find First Number Divisible by Both 3 and 7 (break) ----
// Starting from 1, find the first number divisible by both 3 and 7.
#include <iostream>
using namespace std;

int main() {
    int n = 1;

    while (true) {                       // Keep searching
        if (n % 3 == 0 && n % 7 == 0) {
            cout << "Found: " << n << endl;
            break;                       // Exit immediately
        }
        n++;
    }
    return 0;
}

/*
 * Expected Output:
 * Found: 21
 */

// ---- Example 4: Print 1 to 20 but Skip Multiples of 3 (continue) ----
// Output numbers from 1 to 20, skipping all multiples of 3.
#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (i < 20) {
        i++;                   // Update BEFORE continue to avoid infinite loop!
        if (i % 3 == 0) {
            continue;          // Skip this iteration, go back to condition check
        }
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*
 * Expected Output:
 * 1 2 4 5 7 8 10 11 13 14 16 17 19 20
 */
