//=============================================================
// 실습 1: 메모리 누수 탐지 (leak_example.cpp)
//
// 이 파일에는 메모리 누수 버그가 있습니다.
// 1) 먼저 컴파일하고 Valgrind로 실행해서 누수를 확인하세요.
//    g++ -std=c++17 -Wall -g -o leak_example leak_example.cpp
//    valgrind --leak-check=full ./leak_example
//
// 2) "definitely lost" 메시지를 확인하세요.
// 3) 버그를 찾아 수정한 후 다시 Valgrind를 실행하세요.
// 4) "All heap blocks were freed" 가 나오면 성공!
//=============================================================

#include <iostream>
#include <string>

// ── 부모 클래스 ──
class Content {
protected:
    std::string title;

public:
    Content(const std::string& t) : title(t) {
        std::cout << "[Content 생성] " << title << std::endl;
    }

    virtual ~Content() {
        std::cout << "[Content 소멸] " << title << std::endl;
    }

    std::string getTitle() const { return title; }
};

// ── 자식 클래스 ──
class Movie : public Content {
private:
    int* runtime;  // 동적 할당 멤버

public:
    Movie(const std::string& t, int rt)
        : Content(t) {
        runtime = new int(rt);
        std::cout << "[Movie  생성] runtime=" << *runtime << std::endl;
    }

    ~Movie() {
        std::cout << "[Movie  소멸]" << std::endl;

        // ============================================
        // 🐛 버그: 아래 두 줄의 주석을 해제하면 수정됩니다.
        //    수정 전에 먼저 Valgrind로 누수를 확인하세요!
        // ============================================
        delete runtime;
        runtime = nullptr;
    }

    int getRuntime() const { return *runtime; }
};

// ── main ──
int main() {
    std::cout << "--- 객체 생성 ---" << std::endl;
    Movie* m = new Movie("Parasite", 132);

    std::cout << std::endl;
    std::cout << m->getTitle() << " (" << m->getRuntime() << "분)" << std::endl;

    std::cout << std::endl;
    std::cout << "--- 객체 소멸 ---" << std::endl;
    delete m;

    std::cout << std::endl;
    std::cout << "프로그램 종료" << std::endl;

    return 0;
}
