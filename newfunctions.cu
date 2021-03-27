#include "newfunctions.h"

my_functor::my_functor(float _a) : a(_a) {}

__host__ __device__
float my_functor::operator()(const float& x, const float& y) const { 
    return (a + x) * y;
}
