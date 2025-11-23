// Evaluate your solution here
// Evaluate your solution here
#include "utils/stack.hpp" 
#include <iostream>
#include "./utils/postfix_eval.hpp"
#include <cassert>

using namespace std;

void case1(PostfixEval calc){
    assert(calc.evaluate("2 3 +") == 5);
    assert(calc.evaluate("2 3 -") == -1);
    assert(calc.evaluate("2 3 *") == 6);
    assert(calc.evaluate("6 3 /") == 2);
    assert(calc.evaluate("2 3 ^") == 8);
}

void case2(PostfixEval calc){
    assert(calc.evaluate("2 3 4 + *") == 14);
    assert(calc.evaluate("2 3 4 + * 15 - 3 +") == 2);
}

void case3(PostfixEval calc){
    assert(calc.evaluate("10 50 + 2.5 -") == 57.5);
}

int main() {

    Stack stack;
    stack.push(2);
    stack.push(2);
    stack.push(9.18);
    stack.print();
    cout << stack.peek() << endl; 
    stack.pop();

    stack.print();
    cout << stack.peek() << endl;


    PostfixEval calc;

    case1(calc);
    case2(calc);
    case3(calc);

    cout << "correct" << endl;

    return 0;
}