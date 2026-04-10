// ============================================
// Lesson 15: Enumeration Method (Part 1)
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Find All Perfect Squares from 1 to N ----
// Input a positive integer N (<= 10000), output all perfect squares
// from 1 to N, one per line.
// Method 1: Check each number from 1 to N.
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int s = (int)sqrt(i);       // integer square root
        if (s * s == i) {            // square it back to verify
            cout << i << endl;
        }
    }
    return 0;
}

/*
 * Sample Input:
 * 30
 *
 * Expected Output:
 * 1
 * 4
 * 9
 * 16
 * 25
 */

// ---- Example 1 (Method 2): Smarter Enumeration ----
// Instead of checking every number, enumerate the root directly.
// This runs in O(sqrt(N)) instead of O(N).
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
        cout << i * i << endl;
    }
    return 0;
}

/*
 * Sample Input:
 * 30
 *
 * Expected Output:
 * 1
 * 4
 * 9
 * 16
 * 25
 */

// ---- Example 2: Find All Narcissistic Numbers ----
// A narcissistic number is a 3-digit number where the sum of cubes
// of its digits equals the number itself. Output all such numbers.
#include <iostream>
using namespace std;

int main() {
    for (int i = 100; i <= 999; i++) {
        int a = i / 100;        // hundreds digit
        int b = i / 10 % 10;    // tens digit
        int c = i % 10;         // ones digit
        if (a * a * a + b * b * b + c * c * c == i) {
            cout << i << endl;
        }
    }
    return 0;
}

/*
 * Expected Output:
 * 153
 * 370
 * 371
 * 407
 */

// ---- Example 3: Hundred Coins for Hundred Chickens ----
// Rooster costs 5 yuan, hen costs 3 yuan, 3 chicks cost 1 yuan.
// Buy exactly 100 chickens with exactly 100 yuan, at least 1 of each.
// Output all possible combinations.
#include <iostream>
using namespace std;

int main() {
    int count = 0;  // count number of solutions
    for (int x = 1; x <= 19; x++) {           // enumerate roosters
        for (int y = 1; y <= 32; y++) {        // enumerate hens
            int z = 100 - x - y;               // chicks calculated directly
            if (z >= 1 && z % 3 == 0) {        // at least 1 chick, must be multiple of 3
                int cost = 5 * x + 3 * y + z / 3;  // total cost
                if (cost == 100) {
                    cout << "Rooster:" << x
                         << " Hen:" << y
                         << " Chick:" << z << endl;
                    count++;
                }
            }
        }
    }
    cout << "Total " << count << " solutions" << endl;
    return 0;
}

/*
 * Expected Output:
 * Rooster:4 Hen:18 Chick:78
 * Rooster:8 Hen:11 Chick:81
 * Rooster:12 Hen:4 Chick:84
 * Total 3 solutions
 */
