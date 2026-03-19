#include <iostream>
#include <string.h>
using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;
    int price;
 
    void display() {
        // TODO: 책 정보 출력
        cout << "제목: " << title
            << ", 저자: " << author 
            << ", "<< pages << "쪽, "
            << price << "원" << endl;
    }
 
    bool isLong() {
        // TODO: 300쪽 이상?
        return pages>=300;
    }
 
    void applyDiscount(int percent) {
        // TODO: 할인 적용
        price -= price*percent/100;
        cout << percent << "% 할인 >"
            << price << "원" << endl;
    }
};

int main(){
    Book b1, b2;

    b1.title = "C++ Primer";
    b2.title = "C++ 수업 중";

    b1.author = "Lippman";
    b2.author = "하";

    b1.pages = 976;
    b2.pages = 499;

    b1.price = 35000;
    b2.price = 239857;

    b1.display();
    b2.display();

    if (b1.isLong())
        cout << "긴 책!" << endl;
    if (b1.isLong())
        cout << "긴 책!" << endl;
    
    b1.applyDiscount(10);
    b2.applyDiscount(100);
}
