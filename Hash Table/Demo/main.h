#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>

// size of hash map
#define SIZE 20
#define true 1;
#define false 0;

// define the hash table structure
struct dataItem {
    int key;
    int value;
    struct dataItem* next;
};

inline hashCode(int key) {return key % SIZE;};

#endif /* MAIN_H_ */