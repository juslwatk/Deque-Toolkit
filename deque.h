#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Deque {
private:
    static const int BLOCK_SIZE = 64;
    static const int INITIAL_MAP_SIZE = 8;

    T** blockmap;
    int map_size;
    int front_block, back_block;
    int front_index, back_index;
    int count;

    void allocate_map(int new_map_size) {
        T** new_map = new T*[new_map_size];
        for (int i = 0; i < new_map_size; ++i)
            new_map[i] = nullptr;

        int offset = (new_map_size - map_size) / 2;
        for (int i = 0; i < map_size; ++i)
            new_map[i + offset] = blockmap[i];

        delete[] blockmap;
        blockmap = new_map;
        front_block += offset;
        back_block += offset;
        map_size = new_map_size;
    }

    void allocate_block(int index) {
        if (!blockmap[index]) {
            blockmap[index] = new T[BLOCK_SIZE];
        }
    }
public:
    Deque() {
        map_size = INITIAL_MAP_SIZE;
        blockmap = new T*[map_size];
        for (int i = 0; i < map_size; ++i)
            blockmap[i] = nullptr;

        front_block = back_block = map_size / 2;
        allocate_block(front_block);

        front_index = BLOCK_SIZE / 2;
        back_index = front_index - 1;
        count = 0;
    }

    ~Deque() {
        for (int i = 0; i < map_size; ++i)
            delete[] blockmap[i];
        delete[] blockmap;
    }

    void push_front(const T& value) {
        if (front_index == 0) {
            if (front_block == 0)
                allocate_map(map_size * 2);
            allocate_block(--front_block);
            front_index = BLOCK_SIZE;
        }
        blockmap[front_block][--front_index] = value;
        ++count;
    }

    void push_back(const T& value) {
        if (back_index == BLOCK_SIZE - 1) {
            if (back_block == map_size - 1)
                allocate_map(map_size * 2);
            allocate_block(++back_block);
            back_index = -1;
        }
        blockmap[back_block][++back_index] = value;
        ++count;
    }

    void pop_front() {
        if (empty())
            throw std::out_of_range("Deque is empty");

        ++front_index;
        if (front_index == BLOCK_SIZE) {
            delete[] blockmap[front_block];
            blockmap[front_block++] = nullptr;
            front_index = 0;
        }
        --count;
    }

    void pop_back() {
        if (empty())
            throw std::out_of_range("Deque is empty");

        --back_index;
        if (back_index < 0) {
            delete[] blockmap[back_block];
            blockmap[back_block--] = nullptr;
            back_index = BLOCK_SIZE - 1;
        }
        --count;
    }

    T front() const {
        if (empty()) throw std::out_of_range("Deque is empty");
        return blockmap[front_block][front_index];
    }

    T back() const {
        if (empty()) throw std::out_of_range("Deque is empty");
        return blockmap[back_block][back_index];
    }

    bool empty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    T operator[](int index) const {
        if (index < 0 || index >= count) throw std::out_of_range("Index out of bounds");

        int abs_index = front_index + index;
        int block_offset = abs_index / BLOCK_SIZE;
        int idx_in_block = abs_index % BLOCK_SIZE;

        return blockmap[front_block + block_offset][idx_in_block];
    }

};

#endif
