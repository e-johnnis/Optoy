#ifndef __OPTOY_OPTCORE_HPP
#define __OPTOY_OPTCORE_HPP 0

#include<optoy/matrix.hpp>

#define OPTOY_SELLMEIER_N 3

namespace optoy {

    enum RayIndex {
        RAY_C,
        RAY_d,
        RAY_F,
        RAY_g
    };

    struct Ray {
        double  waveLength;
        Vec<3>  origin;
        Vec<3>  direction;
        int     valid = 1;
    };

    struct Glass {
        double  k[OPTOY_SELLMEIER_N];
        double  l[OPTOY_SELLMEIER_N];
        char    label[8];
    };

    const Glass     air = { { 0, 0, 0 }, { 0, 0, 0 }, "AIR" };

    const double    d_inf = 1.0 / 0.0;

    // Flaunhofer lines [um]
    const double    ray_C = 0.656281;
    const double    ray_d = 0.587562;
    const double    ray_e = 0.546073;
    const double    ray_F = 0.486134;
    const double    ray_g = 0.435835;

    double getRefractance(const Glass&, double);

}

#endif