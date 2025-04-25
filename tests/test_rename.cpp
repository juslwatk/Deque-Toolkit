#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../deque.h"

void test_random_operations() {
    std::srand(std::time(nullptr));
    Deque<int> dq;
    std::cout << "\n[Randomized Test] Running...\n";

    for (int i = 0; i < 10000; ++i) {
        if (std::rand() % 2)
            dq.push_back(i);
        else
            dq.push_front(i);

        if (i % 5 == 0 && !dq.empty()) {
            if (std::rand() % 2) dq.pop_back();
            else dq.pop_front();
        }
    }

    std::cout << "Random test final size: " << dq.size() << std::endl;
}
