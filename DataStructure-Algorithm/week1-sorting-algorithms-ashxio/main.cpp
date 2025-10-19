#include <iostream>
#include "sorting_array.hpp"

using namespace std;

int main(){
    // testing your implementation
    int a[5] = {5, 3, 4, 1, 2};
    sorting_array(a, 5);

    for (int i = 0; i < 5; i++){
        cout << a[i];
    }

    return 0;
}