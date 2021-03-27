#include "executor.h"
#include "executor2.h"
#include "newfunctions.h"
#include <iostream>

int main(void)
{
    int sum = calculate();
    std::cout<<"sum is "<<sum<<std::endl;

    const my_functor &op = my_functor(4);
    sum = calculate2(op);
    std::cout<<"sum is "<<sum<<std::endl;

    return 0;
}
