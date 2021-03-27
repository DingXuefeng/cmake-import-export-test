#ifndef newfunctions_H
#define newfunctions_H
#include <thrust/detail/config.h>
struct my_functor
{
    const float a;

    my_functor(float _a);

    __host__ __device__
	float operator()(const float& x, const float& y) const;
};
#endif
