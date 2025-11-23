#include "../utils/stack.hpp"
#include <cassert>

void test_push(Stack st, float val){
    st.push(val);

    assert(st.peek() == val);
    assert(st.isEmpty() == 0);
}

void test_pop(Stack st){
    st.push(1);
    assert(st.pop() == 1);
    assert(st.isEmpty() == 1);
}

void test_peek(Stack st){
    st.push(1);
    assert(st.peek() == 1);
    assert(st.isEmpty() == 0);
}

int main(){
    Stack st;

    test_push(st, 1);
    test_pop(st);
    test_peek(st);

    return 0;
}