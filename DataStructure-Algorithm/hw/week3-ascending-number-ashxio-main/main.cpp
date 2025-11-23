#include "utils/Exercise.hpp"
#include <string>
#include <vector>

using namespace std; 

int main(){
    Solution solution;
    // test your solution here ...
    vector <string> test { "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s",
        "1 box has 3 blue 4 red 6 green and 12 yellow marbles",
        "hello world 5 x 5"
    };
    for (int i = 0; i < test.size(); i++) {
        cout << solution.areNumAscending(test[i]) << endl;
    }
    return 0;
}