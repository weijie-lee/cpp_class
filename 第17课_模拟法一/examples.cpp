// ============================================
// Lesson 17: Simulation (Part I)
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Reverse a Number ----
// Input a positive integer n (1 <= n <= 99999), output its reversed form.
// Leading zeros are automatically removed.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int result = 0;       // Stores the reversed number
    while (n > 0) {       // Keep going until no digits left
        int digit = n % 10;           // Step 1: extract the last digit
        result = result * 10 + digit;  // Step 2: append digit to result
        n = n / 10;                    // Step 3: remove the last digit
    }

    cout << result << endl;
    return 0;
}

/*
 * Sample Input:
 * 1230
 *
 * Expected Output:
 * 321
 */


// ---- Example 2: Clock Time Calculation ----
// Given current time (h, m, s) and elapsed seconds t,
// compute the time after t seconds in HH:MM:SS format (24-hour, zero-padded).

/*
#include <iostream>
#include <iomanip>   // For setfill and setw to pad zeros
using namespace std;

int main() {
    int h, m, s, t;
    cin >> h >> m >> s >> t;

    // Step 1: Convert current time to total seconds
    int total = h * 3600 + m * 60 + s;

    // Step 2: Add elapsed seconds
    total = total + t;

    // Step 3: Handle overflow past 24 hours (86400 seconds per day)
    total = total % 86400;

    // Step 4: Convert total seconds back to hours, minutes, seconds
    h = total / 3600;
    m = (total % 3600) / 60;
    s = total % 60;

    // Step 5: Output in HH:MM:SS format with leading zeros
    cout << setfill('0') << setw(2) << h << ":"
         << setw(2) << m << ":"
         << setw(2) << s << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 23 59 45 20
 *
 * Expected Output:
 * 00:00:05
 */


// ---- Example 3: Day of Year to Month and Day ----
// Given a year y and day number d (1 <= d <= 365),
// output the month and day (no leap year handling).

/*
#include <iostream>
using namespace std;

int main() {
    int y, d;
    cin >> y >> d;

    // Days in each month (index 0 unused, 1-12 for Jan-Dec, no leap year)
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int month = 1;  // Start from January

    while (d > days[month]) {   // If remaining days exceed this month's total
        d = d - days[month];    // Subtract this month's days
        month++;                // Move to next month
    }

    // When loop ends, d is the day within the current month
    cout << month << " " << d << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 2024 60
 *
 * Expected Output:
 * 3 1
 */
