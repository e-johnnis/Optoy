#include<optoy.hpp>
#include<cstdio>

int main() {
    optoy::Mat<2> m2 = optoy::eMat<2>();
    optoy::Vec<2> v2 = { 2, 3 };

    optoy::Vec<2> vo2 = m2 * v2;

    printf("\n*** test matrix.hpp ***\n\n");

    for(int r = 0; r < 2; r++) {
        std::printf("%lf\t", vo2[r]);
    }
    printf("\n\n");

    return 0;
}