//
// Created by mortelman on 27.03.24.
//

#include "base_filter.h"
#include "../Image.h"

void MatrixFilter::ApplyMatrix(uint32_t x, uint32_t y, Image &image, Image &new_image) const {
    Image::Pixel res(0, 0, 0);
    for (int32_t i = -1; i <= 1; ++i) {
        for (int32_t j = -1; j <= 1; ++j) {
            uint32_t px =
                std::min(image.GetHeight() - 1, static_cast<uint32_t>(std::max(0, static_cast<int32_t>(x) + i)));
            uint32_t py =
                std::min(image.GetWidth() - 1, static_cast<uint32_t>(std::max(0, static_cast<int32_t>(y) + j)));
            Image::Pixel tmp = image.GetPixel(px, py);
            res.r += matrix_[i + 1][j + 1] * tmp.r;
            res.g += matrix_[i + 1][j + 1] * tmp.g;
            res.b += matrix_[i + 1][j + 1] * tmp.b;
        }
    }
    res.r = std::min(1., std::max(0., res.r));
    res.g = std::min(1., std::max(0., res.g));
    res.b = std::min(1., std::max(0., res.b));
    new_image.SetPixel(x, y, res);
}