#include <iostream>
#include "../deque.h"
#include <string>

void test_string_deque() {
    Deque<std::string> dq;
    dq.push_back("CSCI");
    dq.push_back("Deque");
    dq.push_front("Hello");
    dq.pop_back();

    std::cout << "\n[String Test] Front: " << dq.front()
              << " | Back: " << dq.back() << std::endl;
}
