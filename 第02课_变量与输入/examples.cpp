// ============================================
// Lesson 02: Variables and Input
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Input an Integer and Output It ----
// The simplest "one in, one out" program: cin -> variable -> cout
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
 * 42
 *
 * Expected Output:
 * 42
 */

// ---- Example 2: Sum of Two Integers ----
// Read two integers and output their sum
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}

/*
 * Sample Input:
 * 3 5
 *
 * Expected Output:
 * 8
 */

// ---- Example 3: Greet by Name ----
// Ask for the user's name and print a greeting (using string type)
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "请输入你的名字：";
    cin >> name;
    cout << "你好，" << name << "！很高兴认识你！" << endl;
    return 0;
}

/*
 * Sample Input:
 * Tom
 *
 * Expected Output:
 * 请输入你的名字：你好，Tom！很高兴认识你！
 */

// ---- Example 4: Total Score of Three Subjects ----
// Input Chinese, Math, and English scores, then output the total
#include <iostream>
using namespace std;

int main() {
    int yu, shu, ying;
    cout << "请输入语文、数学、英语成绩：" << endl;
    cin >> yu >> shu >> ying;
    int total = yu + shu + ying;
    cout << "总分是：" << total << endl;
    return 0;
}

/*
 * Sample Input:
 * 95 100 88
 *
 * Expected Output:
 * 请输入语文、数学、英语成绩：
 * 总分是：283
 */
