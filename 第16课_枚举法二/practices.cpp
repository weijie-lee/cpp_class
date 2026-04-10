// ============================================
// Lesson 16: Enumeration (Part II) - Nested Loops & Smart Enumeration
// Practice solutions
// ============================================

// ---- Practice 1: Buying Stationery (Double Loop) ----
// Xiao Ming has 20 yuan. Pencils cost 2 yuan, erasers cost 3 yuan.
// He wants to spend exactly 20 yuan. Output all possible combinations.

#include <iostream>
using namespace std;

int main() {
    int count = 0;

    // Pencils: at most 20/2 = 10, erasers: at most 20/3 = 6
    for (int pencil = 0; pencil <= 10; pencil++) {
        for (int eraser = 0; eraser <= 6; eraser++) {
            if (pencil * 2 + eraser * 3 == 20) {
                cout << pencil << " pencils, " << eraser << " erasers" << endl;
                count++;
            }
        }
    }

    cout << "Total: " << count << " ways" << endl;

    return 0;
}

/*
 * Expected Output:
 * 1 pencils, 6 erasers
 * 4 pencils, 4 erasers
 * 7 pencils, 2 erasers
 * 10 pencils, 0 erasers
 * Total: 4 ways
 */


// ---- Practice 2: Hundred Coins Hundred Chickens (Classic Double Loop) ----
// Rooster: 5 yuan, hen: 3 yuan, chick: 1 yuan for 3.
// Spend 100 yuan to buy exactly 100 chickens. Find all solutions.

/*
#include <iostream>
using namespace std;

int main() {
    // Rooster: at most 100/5 = 20
    // Hen: at most 100/3 = 33
    // Chick count = 100 - x - y (derived)
    for (int x = 0; x <= 20; x++) {
        for (int y = 0; y <= 33; y++) {
            int z = 100 - x - y;  // Derive chick count
            // Check: z >= 0, z is multiple of 3, total cost = 100
            if (z >= 0 && z % 3 == 0 && x * 5 + y * 3 + z / 3 == 100) {
                cout << "Rooster: " << x << ", Hen: " << y << ", Chick: " << z << endl;
            }
        }
    }

    return 0;
}
*/

/*
 * Expected Output:
 * Rooster: 0, Hen: 25, Chick: 75
 * Rooster: 4, Hen: 18, Chick: 78
 * Rooster: 8, Hen: 11, Chick: 81
 * Rooster: 12, Hen: 4, Chick: 84
 */


// ---- Practice 3: Two Sum (Enumerate + Filter) ----
// Given n integers and a target, find two elements that sum to target.
// Output their indices (0-based). If not found, output "No".

/*
#include <iostream>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    int a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool found = false;
    // Enumerate all pairs (i, j) where j > i
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == target) {
                cout << i << " " << j << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "No" << endl;
    }

    return 0;
}
*/

/*
 * Sample Input:
 * 5 9
 * 2 7 11 15 1
 *
 * Expected Output:
 * 0 1
 */


// ---- Practice 4: Three-digit Narcissistic Numbers (Triple Loop Challenge) ----
// A narcissistic number: sum of cubes of each digit equals the number itself.
// e.g. 153 = 1^3 + 5^3 + 3^3. Find all 3-digit narcissistic numbers.

/*
#include <iostream>
using namespace std;

int main() {
    // Enumerate hundreds (1-9), tens (0-9), units (0-9)
    for (int h = 1; h <= 9; h++) {
        for (int t = 0; t <= 9; t++) {
            for (int u = 0; u <= 9; u++) {
                int num = h * 100 + t * 10 + u;
                int cubeSum = h * h * h + t * t * t + u * u * u;
                if (cubeSum == num) {
                    cout << num << endl;
                }
            }
        }
    }

    return 0;
}
*/

/*
 * Expected Output:
 * 153
 * 370
 * 371
 * 407
 */
