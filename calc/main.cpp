#include <iostream>
#include "calculator.h"
using namespace std;

int main() {
    int x = 10, y = 3;

    cout << "=== 계산기 테스트 ===" << endl;
    cout << x << " + " << y << " = " << add(x, y) << endl;
    cout << x << " - " << y << " = " << subtract(x, y) << endl;
    cout << x << " * " << y << " = " << multiply(x, y) << endl;
    cout << x << " / " << y << " = " << divide(x, y) << endl;

    return 0;
}
