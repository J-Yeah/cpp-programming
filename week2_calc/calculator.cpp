#include <iostream>
using namespace std;
// 함수 정의
int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiply(int a, int b) {
    return a * b;
}
double divide(int a, int b) {
    if (b == 0) {
        cout << "Error: 0으로 나눌 수 없습니다!" << endl;
        return 0;
    }
    return static_cast<double>(a) / b;
}
