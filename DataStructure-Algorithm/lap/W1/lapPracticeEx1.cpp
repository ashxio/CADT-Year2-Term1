#include <iostream>
#include <chrono>
#include "operation.hpp"

using namespace std;
using clk = chrono::high_resolution_clock;
volatile int sink_int = 0; 

int main (){
    const int MAX_CAP = 100000;  // fixed buffer cap
    int n = 1;
    int* arr = new int[n];

    auto t0 = clk::now();
    // testing on each operation 
    deleteElement (arr, n, 0);
    auto t1 = clk::now();
    cout << chrono::duration_cast<chrono::microseconds>(t1-t0).count() << endl;

    delete[] arr;
    return 0;
}