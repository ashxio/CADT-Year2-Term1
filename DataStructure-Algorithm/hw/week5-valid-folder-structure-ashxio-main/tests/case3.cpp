#include "../Solution.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

void setup_case4(){ // invalid
    fs::create_directories("root4");
    fs::create_directories("root4/sub1");
    fs::create_directories("root4/sub2");
    fs::create_directories("root4/sub2/subsub1");


    std::ofstream("root4/sub1/text1.txt") << "content";
    std::ofstream("root4/sub2/text1.txt") << "content";
}


int main(){

    setup_case4();
    assert(isFolderValid("root4") == 0);

    // clean up 
    fs::remove_all("root4");

    

    return 0;
}