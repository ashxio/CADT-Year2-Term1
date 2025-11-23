#include "../utils/postfix_eval.hpp"
#include <cassert>

void case1(PostfixEval pe){
    assert(pe.evaluate("2 3 +") == 5);
    assert(pe.evaluate("2 3 -") == -1);
    assert(pe.evaluate("2 3 *") == 6);
    assert(pe.evaluate("6 3 /") == 2);
    assert(pe.evaluate("2 3 ^") == 8);
}

void case2(PostfixEval pe){
    assert(pe.evaluate("2 3 4 + *") == 14);
    assert(pe.evaluate("2 3 4 + * 15 - 3 +") == 2);
}

void case3(PostfixEval pe){
    assert(pe.evaluate("10 50 + 2.5 -") == 57.5);
}

int main(){
    PostfixEval pe;

    case1(pe);
    case2(pe);
    case3(pe);

    return 0;
}