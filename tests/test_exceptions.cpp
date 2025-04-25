#include <iostream>
#include <stdexcept>
#include "../deque.h"

void test_exceptions() {
    std::cout << "\n[Exception Test] Testing edge cases...\n";
    Deque<int> dq;

    try {
        dq.pop_back();
    } catch (std::out_of_range& e) {
        std::cout << "Caught expected pop_back error: " << e.what() << std::endl;
    }

    try {
        dq.pop_front();
    } catch (std::out_of_range& e) {
        std::cout << "Caught expected pop_front error: " << e.what() << std::endl;
    }

    try {
        dq[0];
    } catch (std::out_of_range& e) {
        std::cout << "Caught expected operator[] error: " << e.what() << std::endl;
    }
}
