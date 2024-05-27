//
// Created by mortelman on 27.03.24.
//

#include "negative.h"

void NegativeFilter::Apply(Image &image) {
    uint32_t n = image.GetHeight();
    uint32_t m = image.GetWidth();
    Image new_image(n, m);
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < m; ++j) {
            Image::Pixel pixel = image.GetPixel(i, j);
            new_image.SetPixel(i, j, Image::Pixel(1. - pixel.r, 1. - pixel.g, 1. - pixel.b));
        }
    }
    image = new_image;
}