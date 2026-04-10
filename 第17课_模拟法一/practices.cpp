// ============================================
// Lesson 17: Simulation (Part I)
// Practice solutions
// ============================================

// ---- Practice 1: Output Digits in Reverse Order ----
// Input a positive integer n (1 <= n <= 99999),
// output each digit from right to left, separated by spaces.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool first = true;
    while (n > 0) {
        int digit = n % 10;  // Extract the last digit
        if (!first) cout << " ";
        cout << digit;
        first = false;
        n = n / 10;          // Remove the last digit
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * 12345
 *
 * Expected Output:
 * 5 4 3 2 1
 */


// ---- Practice 2: Countdown Timer ----
// Input minutes m and seconds s (initial countdown time).
// Output the last 5 seconds before reaching zero (MM:SS format, zero-padded).
// If initial time is less than 5 seconds, output from the initial time.

/*
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int m, s;
    cin >> m >> s;

    // Convert to total seconds
    int total = m * 60 + s;

    // Determine how many seconds to display (at most 5)
    int start = total;
    if (start > 5) start = 5;

    // Output from 'start' down to 1
    for (int t = start; t >= 1; t--) {
        int mm = t / 60;
        int ss = t % 60;
        cout << setfill('0') << setw(2) << mm << ":"
             << setw(2) << ss << endl;
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 1 3
 *
 * Expected Output:
 * 00:05
 * 00:04
 * 00:03
 * 00:02
 * 00:01
 */


// ---- Practice 3: Pencil Problem ----
// Xiao Ming has n pencils. He uses 3 per day.
// Every 5 pencil stubs can be exchanged for 1 new pencil.
// How many days can he use pencils? (needs at least 3 per day)

/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int days = 0;
    int stubs = 0;  // Accumulated pencil stubs

    while (n >= 3) {
        // Use 3 pencils today
        n -= 3;
        stubs += 3;
        days++;

        // Exchange stubs for new pencils
        while (stubs >= 5) {
            stubs -= 5;
            n += 1;   // Get 1 new pencil
        }
    }

    cout << days << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 15
 *
 * Expected Output:
 * 7
 */


// ---- Practice 4: Ant on a Pole ----
// A pole is 100 cm long. An ant starts at position p (0 < p < 100).
// It moves 1 cm per second in a given direction (0 = left, 1 = right).
// How many seconds until the ant falls off?

/*
#include <iostream>
using namespace std;

int main() {
    int p, dir;
    cin >> p >> dir;

    int seconds = 0;

    // Simulate: move one step per second until off the pole
    while (p > 0 && p < 100) {
        if (dir == 0) {
            p--;   // Move left
        } else {
            p++;   // Move right
        }
        seconds++;
    }

    cout << seconds << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 30 0
 *
 * Expected Output:
 * 30
 */
