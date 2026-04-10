// ============================================
// Lesson 26: String Operations II
// Practice solutions
// ============================================

// ---- Practice 1: Greeting with Concatenation ----
// Read a name, output "Hello, <name>!"
#include <iostream>
using namespace std;

int main() {
    string name;
    cin >> name;
    cout << "Hello, " + name + "!" << endl;
    return 0;
}

/*
 * Sample Input:
 * Alice
 *
 * Expected Output:
 * Hello, Alice!
 */

// ---- Practice 2: Extract Prefix ----
// Read a string s and an integer k,
// output the first k characters of s.
#if 0
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << s.substr(0, k) << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * abcdefg
 * 3
 *
 * Expected Output:
 * abc
 */

// ---- Practice 3: Count Vowels ----
// Read a lowercase string, count the number of vowels
// (a, e, i, o, u).
#if 0
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * helloworld
 *
 * Expected Output:
 * 3
 */

// ---- Practice 4: Swap Case (Challenge) ----
// Read a string containing only English letters,
// convert uppercase to lowercase and vice versa.
#if 0
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;   // lowercase -> uppercase
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;   // uppercase -> lowercase
        }
    }
    cout << s << endl;
    return 0;
}
#endif

/*
 * Sample Input:
 * Hello
 *
 * Expected Output:
 * hELLO
 */
