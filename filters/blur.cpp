//
// Created by mortelman on 28.03.24.
//

#include "blur.h"
#include <algorithm>
#include <cmath>

const double EPS = 1e-9;

void BlurFilter::Apply(Image &image) {
    std::vector<double> coefs;
    // add some coefs
    uint32_t n = image.GetHeight();
    uint32_t m = image.GetWidth();
    Image new_image(n, m);

    std::vector<std::vector<char>> used(n, std::vector<char> (m, 0));
}
