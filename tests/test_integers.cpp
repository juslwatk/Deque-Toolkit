#include <iostream>
#include "../deque.h"

void stress_test_operator_index(Deque<int>& dq) {
    for (int i = 0; i < dq.size(); ++i) {
        int val = dq[i];
        if (i % 100 == 0)
            std::cout << "At index " << i << ": " << val << std::endl;
    }
}

void test_integer_deque() {
    Deque<int> dq;
    std::cout << "\n[Integer Test] Starting...\n";

    for (int i = 0; i < 1000; ++i) dq.push_back(i);
    for (int i = 0; i < 500; ++i) dq.pop_front();
    for (int i = 0; i < 500; ++i) dq.push_front(i + 1000);
    for (int i = 0; i < 250; ++i) dq.pop_back();

    std::cout << "Final size (int): " << dq.size() << std::endl;
    std::cout << "Front: " << dq.front() << " | Back: " << dq.back() << std::endl;

    stress_test_operator_index(dq);
}

