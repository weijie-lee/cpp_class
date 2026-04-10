// ============================================
// Lesson 18: Simulation (Part II) - Array-based Simulation
// Practice solutions
// ============================================

// ---- Practice 1: Reverse Caesar Cipher (Decryption) ----
// Decryption is the reverse of encryption: shift each letter BACKWARD by k.
// Formula: (num + 26 - k) % 26 + 'a' (add 26 to avoid negative values).

#include <iostream>
#include <cstring>
using namespace std;

char s[105];

int main() {
    int k;
    cin >> s >> k;

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int num = s[i] - 'a';
        int newNum = (num + 26 - k) % 26;  // Shift backward by k
        cout << (char)(newNum + 'a');
    }
    cout << endl;

    return 0;
}

/*
 * Sample Input:
 * khoor
 * 3
 *
 * Expected Output:
 * hello
 */


// ---- Practice 2: Josephus Problem - Output Elimination Order ----
// n people in a circle, count to m, output the elimination order of all.

/*
#include <iostream>
using namespace std;

int alive[105];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        alive[i] = 1;
    }

    int left = n, cnt = 0, pos = 0;

    while (left > 0) {
        if (alive[pos] == 1) {
            cnt++;
            if (cnt == m) {
                alive[pos] = 0;
                left--;
                cnt = 0;
                cout << pos + 1 << " ";  // Output immediately upon elimination
            }
        }
        pos = (pos + 1) % n;
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 5 2
 *
 * Expected Output:
 * 2 4 1 5 3
 */


// ---- Practice 3: Four-Digit Number Encryptor ----
// Encryption rules for a 4-digit number:
// 1. Add 5 to each digit.
// 2. Replace each digit with (digit + 5) % 10.
// 3. Swap the 1st and 3rd digits, swap the 2nd and 4th digits.

/*
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    int a[4];
    // Extract digits (from low to high)
    a[3] = x % 10; x /= 10;
    a[2] = x % 10; x /= 10;
    a[1] = x % 10; x /= 10;
    a[0] = x % 10;

    // Add 5 and take mod 10 for each digit
    for (int i = 0; i < 4; i++) {
        a[i] = (a[i] + 5) % 10;
    }

    // Swap 1st and 3rd digits (index 0 and 2)
    int t = a[0]; a[0] = a[2]; a[2] = t;
    // Swap 2nd and 4th digits (index 1 and 3)
    t = a[1]; a[1] = a[3]; a[3] = t;

    // Output the encrypted number
    for (int i = 0; i < 4; i++) {
        cout << a[i];
    }
    cout << endl;

    return 0;
}
*/

/*
 * Sample Input:
 * 1234
 *
 * Expected Output:
 * 8967
 */
