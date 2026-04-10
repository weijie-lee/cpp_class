// ============================================
// Lesson 01: Hello C++
// Examples for classroom demonstration
// ============================================

// ---- Example 1: Hello World ----
// The very first C++ program: output "Hello World!" to the screen
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    return 0;
}

/*
 * Expected Output:
 * Hello World!
 */

// ---- Example 2: Multi-line Personal Info ----
// Print name, age, and school on separate lines using multiple cout statements
#include <iostream>
using namespace std;

int main() {
    cout << "姓名：小明" << endl;
    cout << "年龄：10" << endl;
    cout << "学校：阳光小学" << endl;
    return 0;
}

/*
 * Expected Output:
 * 姓名：小明
 * 年龄：10
 * 学校：阳光小学
 */

// ---- Example 3: Mixed Text and Number Output ----
// Combine text and arithmetic expressions in cout
#include <iostream>
using namespace std;

int main() {
    cout << "12 + 34 = " << 12 + 34 << endl;
    return 0;
}

/*
 * Expected Output:
 * 12 + 34 = 46
 */

// ---- Example 4: Draw a Little House ----
// Use asterisks and symbols to draw a house shape
#include <iostream>
using namespace std;

int main() {
    cout << "    *" << endl;
    cout << "   ***" << endl;
    cout << "  *****" << endl;
    cout << " *******" << endl;
    cout << "*********" << endl;
    cout << " |     |" << endl;
    cout << " |     |" << endl;
    cout << " |     |" << endl;
    cout << " +-----+" << endl;
    return 0;
}

/*
 * Expected Output:
 *     *
 *    ***
 *   *****
 *  *******
 * *********
 *  |     |
 *  |     |
 *  |     |
 *  +-----+
 */

// ---- Example 5: Draw a Little Tree ----
// Use asterisks and symbols to draw a tree shape
#include <iostream>
using namespace std;

int main() {
    cout << "    *" << endl;
    cout << "   ***" << endl;
    cout << "  *****" << endl;
    cout << " *******" << endl;
    cout << "*********" << endl;
    cout << "    |" << endl;
    cout << "    |" << endl;
    cout << "  -----" << endl;
    return 0;
}

/*
 * Expected Output:
 *     *
 *    ***
 *   *****
 *  *******
 * *********
 *     |
 *     |
 *   -----
 */

// ---- Example 6: Output Without endl ----
// Demonstrate what happens when endl is omitted
#include <iostream>
using namespace std;

int main() {
    cout << "AAA";
    cout << "BBB";
    cout << "CCC";
    return 0;
}

/*
 * Expected Output:
 * AAABBBCCC
 */

// ---- Example 7: Output Numbers ----
// Show that cout can print numbers and evaluate expressions
#include <iostream>
using namespace std;

int main() {
    cout << 100 << endl;
    cout << 3 + 5 << endl;
    cout << "3 + 5 = " << 3 + 5 << endl;
    return 0;
}

/*
 * Expected Output:
 * 100
 * 8
 * 3 + 5 = 8
 */
