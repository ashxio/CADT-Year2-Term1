#include "../Solution.hpp"
#include <iostream>
#include <fstream>
#include <cassert>

void setup_case5(){ // valid
    fs::create_directories("root5");
    std::cout<<"root5/ created!"<<std::endl;

    fs::create_directories("root5/sub1");
    std::cout<<"root5/sub1 created!"<<std::endl;

    fs::create_directories("root5/sub2");
    std::cout<<"root5/sub2 created!"<<std::endl;

    fs::create_directories("root5/sub2/subsub1");
    std::cout<<"root5/sub2/subsub1/ created!"<<std::endl;


    std::ofstream("root5/sub1/text1.txt") << "content";
    std::ofstream("root5/sub2/text1.txt") << "content";
    std::ofstream("root5/sub2/subsub1/text1.txt") << "content";
}

int main(){

    setup_case5();
    assert(isFolderValid("root5") == 1);

    // clean up 
    fs::remove_all("root5");
    

    return 0;
}