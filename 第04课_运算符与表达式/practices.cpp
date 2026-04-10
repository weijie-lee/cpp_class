// ============================================
// Lesson 04: Operators and Expressions
// Practice exercises with reference answers
// ============================================

// ---- Practice 1: Swap Two Variables (Basic) ----
// Input two integers a and b, swap their values and output them
// Hint: use a temporary variable "temp"
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int temp = a;
    a = b;
    b = temp;

    cout << a << " " << b << endl;
    return 0;
}

/*
 * Sample Input:
 * 3 5
 *
 * Expected Output:
 * 5 3
 */

// ---- Practice 2: Total Price and Change (Application) ----
// Pencils cost 3 yuan each, erasers cost 2 yuan each.
// Input pencil count, eraser count, and amount paid. Output total and change.
#include <iostream>
using namespace std;

int main() {
    int a, b, money;
    cin >> a >> b >> money;

    int total = a * 3 + b * 2;
    int change = money - total;

    cout << total << " " << change << endl;
    return 0;
}

/*
 * Sample Input:
 * 4 3 20
 *
 * Expected Output:
 * 18 2
 */

// ---- Practice 3: Convert Seconds to Hours, Minutes, Seconds (Advanced) ----
// Input a number of seconds, output the equivalent hours, minutes, and seconds
#include <iostream>
using namespace std;

int main() {
    int s;
    cin >> s;

    int hours = s / 3600;
    int mins  = s % 3600 / 60;
    int secs  = s % 60;

    cout << hours << " " << mins << " " << secs << endl;
    return 0;
}

/*
 * Sample Input:
 * 3661
 *
 * Expected Output:
 * 1 1 1
 */

// ---- Practice 4: Odd or Even - Output Remainder (Warm-up) ----
// Input an integer n, output n % 2 (0 means even, 1 means odd)
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n % 2 << endl;
    return 0;
}

/*
 * Sample Input:
 * 7
 *
 * Expected Output:
 * 1
 */
