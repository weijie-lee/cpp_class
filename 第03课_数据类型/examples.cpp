// ============================================
// Lesson 03: Data Types (int / double / char)
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Personal Info Card ----
// Input age (int), height (double), and initial (char), then display them
#include <iostream>
using namespace std;

int main() {
    int age;
    double height;
    char initial;

    cin >> age >> height >> initial;

    cout << "年龄：" << age << "岁" << endl;
    cout << "身高：" << height << "米" << endl;
    cout << "姓名首字母：" << initial << endl;

    return 0;
}

/*
 * Sample Input:
 * 10 1.42 L
 *
 * Expected Output:
 * 年龄：10岁
 * 身高：1.42米
 * 姓名首字母：L
 */

// ---- Example 2: Shop Calculator ----
// Input a product's unit price (double) and quantity (int), output total price
#include <iostream>
using namespace std;

int main() {
    double price;
    int count;

    cin >> price >> count;

    double total = price * count;
    cout << "总价：" << total << endl;

    return 0;
}

/*
 * Sample Input:
 * 3.5 4
 *
 * Expected Output:
 * 总价：14
 */

// ---- Example 3: Neighboring Characters ----
// Input a lowercase letter, output its previous and next letter using ASCII
#include <iostream>
using namespace std;

int main() {
    char ch;
    cin >> ch;

    char prev = ch - 1;
    char next = ch + 1;

    cout << ch << "的前一个字母是" << prev << endl;
    cout << ch << "的后一个字母是" << next << endl;

    return 0;
}

/*
 * Sample Input:
 * d
 *
 * Expected Output:
 * d的前一个字母是c
 * d的后一个字母是e
 */

// ---- Example 4: int Truncates Decimals ----
// Demonstrate that int truncates the fractional part (no rounding)
#include <iostream>
using namespace std;

int main() {
    int a = 3.9;
    cout << a << endl;
    return 0;
}

/*
 * Expected Output:
 * 3
 */

// ---- Example 5: char and ASCII Code ----
// Show that a character is stored as a number (ASCII value)
#include <iostream>
using namespace std;

int main() {
    char ch = 'A';
    cout << ch << endl;          // prints the character A
    cout << (int)ch << endl;     // prints the ASCII value 65
    return 0;
}

/*
 * Expected Output:
 * A
 * 65
 */

// ---- Example 6: Three Types Working Together ----
// Comprehensive demo using int, double, and char in one program
#include <iostream>
using namespace std;

int main() {
    int age;
    double height;
    char grade;

    cout << "请输入你的年龄：";
    cin >> age;
    cout << "请输入你的身高（米）：";
    cin >> height;
    cout << "请输入你的等级（A/B/C）：";
    cin >> grade;

    cout << "======== 个人信息卡 ========" << endl;
    cout << "年龄：" << age << " 岁" << endl;
    cout << "身高：" << height << " 米" << endl;
    cout << "等级：" << grade << endl;
    cout << "============================" << endl;

    return 0;
}

/*
 * Sample Input:
 * 10
 * 1.42
 * A
 *
 * Expected Output:
 * 请输入你的年龄：请输入你的身高（米）：请输入你的等级（A/B/C）：======== 个人信息卡 ========
 * 年龄：10 岁
 * 身高：1.42 米
 * 等级：A
 * ============================
 */
