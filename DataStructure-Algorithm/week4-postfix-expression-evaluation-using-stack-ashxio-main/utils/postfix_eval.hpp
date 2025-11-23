#include "../utils/stack.hpp"
#include <string>
#include <cmath>


#ifndef POSFIX
#define POSFIX

class PostfixEval{
    private:
        bool isOperator(char c){
            return (
                c == '+' ||
                c == '-' ||
                c == '*' ||
                c == '/' ||
                c == '^'
            );
        }

        float calculate(float op1, float op2, char op){
            if (op == '+') return op1 + op2;
            else if (op == '-') return op1 - op2;
            else if (op == '*') return op1 * op2;
            else if (op == '/') return op1 / op2;
            else if (op == '^') return pow(op1, op2);
            else return 0;
        }

    public:

        float evaluate(string s){
            // complete the logic here
        }
};

#endif