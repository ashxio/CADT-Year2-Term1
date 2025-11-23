#include "../Solution.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

void setup_case1(){ // invalid
    fs::create_directories("root1");
}

int main(){

    setup_case1();
    assert(isFolderValid("root1") == 0);

    // clean up 
    fs::remove_all("root1");

    return 0;
}