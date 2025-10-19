#include <iostream>
#include <string>

using namespace std;

class Hero{

    private:
        // Define all the attributes here...
        // [ your code ]
        
        
    public:
        // Define the constructor and methods here ...
        Hero(string name, int health, int armor, int power, string weapon){
            // assign each attributes' value from constructor param here...
            // [ your code ]

        }
    
        void info(){
            // process display hero info here...
            // [ your code ]
        }

        void strike(Hero& enemy){
            // process the strike logic here...
            // you can add the narative text as well (optional)
            // [ your code ]

        }

        string getName() {
            // this won't eerror when you create the name attribute
            return name;
        }

        // getter methods
        int getHealth() {
            // this won't error when you create the health attribute
            return health;
        }

        int getArmor() {
            // this won't error when you create the armor attribute
            return armor;
        }

        int getPower() {
            // this won't error when you create the power attribute
            return power;
        }
};