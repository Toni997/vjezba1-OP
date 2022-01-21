#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> stack;

    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.pop();
    stack.pop();

    std::cout << "size: " << stack.size() << std::endl;

}
