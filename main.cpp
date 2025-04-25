#include <iostream>

// Include headers for each test
void test_integer_deque();
void test_random_operations();
void test_exceptions();
void test_string_deque();
void test_other_types();

int main() {
    std::cout << "[Deque Project] Starting all tests...\n";

    test_integer_deque();
    test_random_operations();
    test_exceptions();
    test_string_deque();
    test_other_types();

    std::cout << "\n✅ All tests completed successfully.\n";
    return 0;
}
