// test.cpp
#include <iostream>
#include <cassert>
#include "../utils/Hero.hpp"

int main() {
    // Test Case 1: Create two Hero objects
    Hero k("Richard", 50, 50, 25, "Sword");
    
    assert(k.getHealth() == 50);
    assert(k.getArmor() == 50);
    assert(k.getPower() == 25);

    cout<<"[PASS] Object Contruction"<<endl;

    return 0;
}
