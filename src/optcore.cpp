#include<optoy.hpp>
#include<cmath>

namespace optoy {

    double getRefractance(const Glass& g, double waveLength) {
        double r2 = 1;
        double wl2 = waveLength * waveLength;
        for(int i = 0; i < OPTOY_SELLMEIER_N; i++) {
            r2 += g.k[i] * wl2 / (wl2 - g.l[i]);
        }
        return std::sqrt(r2);
    }

}