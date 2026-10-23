#include<optoy.hpp>
#include<cstdio>

int main() {
    optoy::Glass sBsl7 = {
        {   1.15150190e+0,  1.18583692e-1,  1.26301359e+0   },
        {   1.05984130e-2, -1.18225190e-2,  1.29617662e+2   },
        "S-BSL 7"
    };
    optoy::Glass sTim2 = {
        {   1.42193846e+0,  1.33827968e-1,  1.45060574e+0   },
        {   1.07291511e-2,  5.72587546e-2,  1.45381805e+2   },
        "S-TIM 2"
    };

    optoy::System sys;
    double zPos = 0;

    sys.add(new optoy::Refractor(102.0, zPos, sBsl7, 479.9824));
    zPos += 11.25;

    sys.add(new optoy::Refractor(102.0, zPos, optoy::air, -421.7763));
    zPos += 0.10;

    sys.add(new optoy::Refractor(102.0, zPos, sTim2, -411.7371));
    zPos += 6.25;

    sys.add(new optoy::Refractor(102.0, zPos, optoy::air, -3013.7675));

    optoy::NearAxisResult nar = sys.analyze_nearAxis(optoy::ray_d);

    std::printf("fl_d = %lf mm\n", nar.focalLength);
    std::printf("df_d = %lf mm\n", nar.frontToPrincipal);
    std::printf("dr_d = %lf mm\n", nar.rearToPricipal);
    std::printf("pr_d = %lf mm\n", 1.0 / nar.petzvarSum);

    nar = sys.analyze_nearAxis(optoy::ray_C);
    std::printf("fl_C = %lf mm\n", nar.focalLength);

    nar = sys.analyze_nearAxis(optoy::ray_F);
    std::printf("fl_F = %lf mm\n", nar.focalLength);

    nar = sys.analyze_nearAxis(optoy::ray_g);
    std::printf("fl_g = %lf mm\n", nar.focalLength);

    return 0;
}