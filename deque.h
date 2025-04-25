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


};

#endif
