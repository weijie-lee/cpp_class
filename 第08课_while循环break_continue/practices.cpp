// ============================================
// Lesson 08: while Loop, break & continue
// Practice solutions
// ============================================

// ---- Practice 1: Countdown Launch (Basic while) ----
// Use while to print a countdown from 10 to 1, then print "Launch!".
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    while (n >= 1) {
        cout << n << " ";
        n--;
    }
    cout << "Launch!" << endl;
    return 0;
}

/*
 * Expected Output:
 * 10 9 8 7 6 5 4 3 2 1 Launch!
 */

// ---- Practice 2: Average Score (Sentinel Value) ----
// Keep reading student scores (positive integers). Input -1 to stop.
// Output the average score (integer division is fine).
#include <iostream>
using namespace std;

int main() {
    int score;
    int sum = 0, count = 0;

    cin >> score;
    while (score != -1) {
        sum += score;
        count++;
        cin >> score;
    }

    if (count > 0) {
        cout << "Average score: " << sum / count << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 90 85 92 78 -1
 *
 * Expected Output:
 * Average score: 86
 *
 * (90 + 85 + 92 + 78 = 345, 345 / 4 = 86)
 */

// ---- Practice 3: Guess the Number (break) ----
// The secret number is 42. Keep guessing until correct.
// Wrong guess -> print "Try again"; correct -> print "Congratulations!" and stop.
#include <iostream>
using namespace std;

int main() {
    int secret = 42;
    int guess;

    while (true) {
        cin >> guess;
        if (guess == secret) {
            cout << "Congratulations! You got it!" << endl;
            break;
        }
        cout << "Try again" << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 10
 * 30
 * 42
 *
 * Expected Output:
 * Try again
 * Try again
 * Congratulations! You got it!
 */

// ---- Practice 4: Print Odd Numbers 1-30 (continue) ----
// Use while and continue to print all odd numbers from 1 to 30.
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    while (i < 30) {
        i++;
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*
 * Expected Output:
 * 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29
 */
