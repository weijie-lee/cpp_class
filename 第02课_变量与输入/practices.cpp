// ============================================
// Lesson 02: Variables and Input
// Practice exercises with reference answers
// ============================================

// ---- Practice 1: Echo Program (Basic) ----
// Input an integer and output it as-is
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    cout << a << endl;
    return 0;
}

/*
 * Sample Input:
 * 7
 *
 * Expected Output:
 * 7
 */

// ---- Practice 2: Difference of Two Numbers (Basic) ----
// Input two integers a and b, output a - b
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a - b << endl;
    return 0;
}

/*
 * Sample Input:
 * 10 3
 *
 * Expected Output:
 * 7
 */

// ---- Practice 3: Self-Introduction (Fun) ----
// Input a name and an age, then output a self-introduction sentence
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;
    cin >> name >> age;
    cout << "我叫" << name << "，今年" << age << "岁！" << endl;
    return 0;
}

/*
 * Sample Input:
 * Tom
 * 10
 *
 * Expected Output:
 * 我叫Tom，今年10岁！
 */

// ---- Practice 4: Rectangle Area (Challenge) ----
// Input the length and width of a rectangle, output its area
#include <iostream>
using namespace std;

int main() {
    int length, width;
    cin >> length >> width;
    cout << length * width << endl;
    return 0;
}

/*
 * Sample Input:
 * 5 3
 *
 * Expected Output:
 * 15
 */
