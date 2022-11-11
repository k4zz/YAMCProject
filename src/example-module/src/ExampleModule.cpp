#include "ExampleModule/ExampleModule.h"

#include <iostream>

namespace ExampleModule
{

    void printHello()
    {
        std::cout << "Hello World from ExampleModule" << std::endl;
    }

    int addition(int a, int b)
    {
        return a + b;
    }

}