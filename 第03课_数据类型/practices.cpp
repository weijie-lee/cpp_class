// ============================================
// Lesson 03: Data Types (int / double / char)
// Practice exercises with reference answers
// ============================================

// ---- Practice 1: Fruit Stand (Basic) ----
// Input a fruit's unit price and weight (both double), output the total cost
#include <iostream>
using namespace std;

int main() {
    double price, weight;
    cin >> price >> weight;
    double total = price * weight;
    cout << "应付：" << total << "元" << endl;
    return 0;
}

/*
 * Sample Input:
 * 6.5 2.3
 *
 * Expected Output:
 * 应付：14.95元
 */

// ---- Practice 2: My Pet Profile (Basic) ----
// Input pet's age (int), weight (double), and name initial (char)
#include <iostream>
using namespace std;

int main() {
    int age;
    double weight;
    char initial;

    cin >> age >> weight >> initial;

    cout << "=== 宠物档案 ===" << endl;
    cout << "年龄：" << age << "岁" << endl;
    cout << "体重：" << weight << "千克" << endl;
    cout << "名字首字母：" << initial << endl;

    return 0;
}

/*
 * Sample Input:
 * 3 4.2 M
 *
 * Expected Output:
 * === 宠物档案 ===
 * 年龄：3岁
 * 体重：4.2千克
 * 名字首字母：M
 */

// ---- Practice 3: Uppercase to Lowercase (Advanced) ----
// Input an uppercase letter, output its corresponding lowercase letter
// Hint: uppercase 'A' has ASCII 65, lowercase 'a' has ASCII 97, difference is 32
#include <iostream>
using namespace std;

int main() {
    char ch;
    cin >> ch;
    char lower = ch + 32;
    cout << ch << "对应的小写字母是" << lower << endl;
    return 0;
}

/*
 * Sample Input:
 * B
 *
 * Expected Output:
 * B对应的小写字母是b
 */

// ---- Practice 4: Digit Split (Challenge) ----
// Input a two-digit integer, output its tens digit and ones digit as characters
// Hint: tens = n / 10, ones = n % 10; digit + 48 gives ASCII character
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tens = n / 10;
    int ones = n % 10;

    char tens_ch = tens + 48;  // convert digit to its ASCII character
    char ones_ch = ones + 48;

    cout << "十位字符：" << tens_ch << endl;
    cout << "个位字符：" << ones_ch << endl;

    return 0;
}

/*
 * Sample Input:
 * 57
 *
 * Expected Output:
 * 十位字符：5
 * 个位字符：7
 */
