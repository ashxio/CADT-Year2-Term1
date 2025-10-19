#include <cassert>
#include "../sorting_array.hpp"
#include <iostream>

int main(){
    int a[5] = {5, 3, 4, 1, 2};
    sorting_array(a, 5);
    int expected[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++){
        assert(a[i] == expected[i]);
    }

    std::cout << "[PASS] All tests passed!" << std::endl;

    return 0;
}