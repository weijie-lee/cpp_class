// ============================================
// Lesson 07: for Loop
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Print 1 to 5 (Simplest Loop) ----
// Output numbers 1 through 5, each on a new line.
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {
        cout << i << endl;
    }
    return 0;
}

/*
 * Expected Output:
 * 1
 * 2
 * 3
 * 4
 * 5
 */

// ---- Example 2: Print 1 to N (Variable Endpoint) ----
// Input an integer N, output all integers from 1 to N.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << i << endl;
    }
    return 0;
}

/*
 * Sample Input: 7
 *
 * Expected Output:
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 */

// ---- Example 3: Sum from 1 to N (Accumulation) ----
// Input a positive integer N, compute 1 + 2 + 3 + ... + N.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;  // Initialize the "piggy bank" to 0
    for (int i = 1; i <= n; i++) {
        sum = sum + i;  // Add i to the piggy bank each round
    }
    cout << sum << endl;
    return 0;
}

/*
 * Sample Input: 5
 *
 * Expected Output:
 * 15
 */

// ---- Example 4: Countdown from N to 1 (Decrementing Loop) ----
// Input a positive integer N, count down from N to 1.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        cout << i << endl;
    }
    return 0;
}

/*
 * Sample Input: 5
 *
 * Expected Output:
 * 5
 * 4
 * 3
 * 2
 * 1
 */
