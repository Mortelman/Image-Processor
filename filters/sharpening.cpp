#include "sharpening.h"

SharpeningFilter::SharpeningFilter() {
    matrix_ = {std::array<double, 3>({0, -1, 0}), std::array<double, 3>({-1, 5, -1}),  // NOLINT
               std::array<double, 3>({0, -1, 0})};
}

void SharpeningFilter::Apply(Image &image) {
    uint32_t n = image.GetHeight();
    uint32_t m = image.GetWidth();
    Image new_image(n, m);
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < m; ++j) {
            ApplyMatrix(i, j, image, new_image);
        }
    }
    image = new_image;
}