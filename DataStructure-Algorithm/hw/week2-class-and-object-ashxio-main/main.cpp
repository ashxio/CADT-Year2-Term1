#include <iostream>
#include "utils/Hero.hpp" // this is custom include header file

int main(){
    // implement your code to test the functional of Hero class here ...
    // [This will score by automate testing too.]
    Hero Knight("Johnson", 50, 50, 50, "Lightsaber");
    Hero Enemy("Ah ty", 40, 15, 10, "Spoon");

    cout<< "Hero Stats: "<< endl;
    Knight.info();
    cout << endl;
    cout<< "Enemy Stats: "<< endl;
    Enemy.info();
    cout<< endl;

    cout<<"the hero was on duty patrolling the area when suddenly he spotted a well known bandit named " << Enemy.getName() << "!"  << endl;
    cout<<"the bandit panicked and tried to attack first!" << endl;
    cout<<endl;
    Enemy.strike(Knight);
    cout<<endl;
    cout<<"Now Johnson's turn" << endl;
    cout<<endl;
    Knight.strike(Enemy);

    return 0;
}