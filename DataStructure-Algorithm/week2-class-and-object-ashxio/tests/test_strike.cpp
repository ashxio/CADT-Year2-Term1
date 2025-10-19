// test.cpp
#include <iostream>
#include <cassert>
#include "../utils/Hero.hpp"

int main() {
    // Test Case 1: Create two Hero objects
    Hero k("Richard", 50, 50, 50, "Sword");
    Hero e("John", 100, 25, 25, "Gun");
    
    k.strike(e);
    assert(e.getArmor() == 0);
    assert(e.getHealth() == 75);

    cout<<"[Pass] Striking method"<<endl;

    return 0;
}
