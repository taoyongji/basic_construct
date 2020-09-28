//
// Created by taoyongji on 2020/9/22.
//
#include "arraylist.h"

int main() {

    ArrayList<int> li;

    for (int i = 0; i < 10; ++i) {
        li.add(i);
    }

    // [0,1,2,3,4,5,6,7,8,9]
    std::cout << li;

    li.remove(1);
    li.remove(0);

    // [2,3,4,5,6,7,8,9]
    std::cout << li;

    return 0;
}
