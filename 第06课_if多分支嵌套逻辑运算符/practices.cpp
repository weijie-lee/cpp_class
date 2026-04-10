// ============================================
// Lesson 06: if Multi-branch, Nesting & Logical Operators
// Practice solutions
// ============================================

// ---- Practice 1: BMI Health Indicator (Multi-branch) ----
// Input weight w (kg) and height h (cm), compute BMI = w / (h/100) / (h/100).
// Output: BMI < 18 -> "Underweight"; 18 <= BMI < 24 -> "Normal";
//         24 <= BMI < 28 -> "Overweight"; BMI >= 28 -> "Obese".
#include <iostream>
using namespace std;

int main() {
    double w, h;
    cin >> w >> h;

    double bmi = w / (h / 100) / (h / 100);

    if (bmi < 18) {
        cout << "Underweight" << endl;
    } else if (bmi < 24) {
        cout << "Normal" << endl;
    } else if (bmi < 28) {
        cout << "Overweight" << endl;
    } else {
        cout << "Obese" << endl;
    }

    return 0;
}

/*
 * Sample Input: 60 170
 *
 * Expected Output:
 * Normal
 *
 * (BMI = 60 / 1.7 / 1.7 ≈ 20.76)
 */

// ---- Practice 2: Can I Go Out to Play? (Logical Operators) ----
// Input three integers:
//   homework (0=not done, 1=done)
//   rain (0=no rain, 1=raining)
//   weekend (0=weekday, 1=weekend)
// Rule: homework done AND (no rain OR weekend) -> can go out.
#include <iostream>
using namespace std;

int main() {
    int homework, rain, weekend;
    cin >> homework >> rain >> weekend;

    if (homework == 1 && (rain == 0 || weekend == 1)) {
        cout << "You can go out to play!" << endl;
    } else {
        cout << "You cannot go out to play" << endl;
    }

    return 0;
}

/*
 * Sample Input: 1 0 0
 *
 * Expected Output:
 * You can go out to play!
 *
 * Sample Input: 1 1 1
 *
 * Expected Output:
 * You can go out to play!
 *
 * Sample Input: 0 0 1
 *
 * Expected Output:
 * You cannot go out to play
 */

// ---- Practice 3: Express Delivery Fee (Multi-branch + Nesting) ----
// Pricing rules:
//   Local: weight <= 1 kg -> 8 yuan; each extra kg adds 2 yuan.
//   Non-local: weight <= 1 kg -> 12 yuan; each extra kg adds 5 yuan.
// Input type (1=local, 2=non-local) and weight w (integer, kg).
// Output the delivery fee.
#include <iostream>
using namespace std;

int main() {
    int type, w;
    cin >> type >> w;

    if (type == 1) {
        // Local delivery
        if (w <= 1) {
            cout << 8 << endl;
        } else {
            cout << 8 + (w - 1) * 2 << endl;
        }
    } else if (type == 2) {
        // Non-local delivery
        if (w <= 1) {
            cout << 12 << endl;
        } else {
            cout << 12 + (w - 1) * 5 << endl;
        }
    }

    return 0;
}

/*
 * Sample Input: 1 3
 *
 * Expected Output:
 * 12
 *
 * (Local, 3 kg: 8 + (3-1)*2 = 8 + 4 = 12)
 *
 * Sample Input: 2 5
 *
 * Expected Output:
 * 32
 *
 * (Non-local, 5 kg: 12 + (5-1)*5 = 12 + 20 = 32)
 */
