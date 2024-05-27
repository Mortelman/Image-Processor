//
// Created by mortelman on 27.03.24.
//

#include "grayscale.h"

const double R_RATIO = 0.299;
const double G_RATIO = 0.587;
const double B_RATIO = 0.114;

void GrayscaleFilter::Apply(Image &image) {
    uint32_t n = image.GetHeight();
    uint32_t m = image.GetWidth();
    Image new_image(n, m);
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < m; ++j) {
            Image::Pixel pixel = image.GetPixel(i, j);
            double res = pixel.r * R_RATIO + pixel.g * G_RATIO + pixel.b * B_RATIO;
            new_image.SetPixel(i, j, Image::Pixel(res, res, res));
        }
    }
    image = new_image;
}
