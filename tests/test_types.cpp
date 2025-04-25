#include <iostream>
#include "../deque.h"

void test_other_types() {
    Deque<double> d_dq;
    Deque<char> c_dq;

    for (int i = 0; i < 100; ++i) d_dq.push_back(i + 0.5);
    for (char ch = 'a'; ch <= 'z'; ++ch) c_dq.push_back(ch);

    std::cout << "\n[Other Types Test] double front: " << d_dq.front()
              << ", char back: " << c_dq.back() << std::endl;
}
