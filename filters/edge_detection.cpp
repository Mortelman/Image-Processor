//
// Created by mortelman on 28.03.24.
//

#include "edge_detection.h"
#include "grayscale.h"

EdgedetectionFilter::EdgedetectionFilter(double threashold) : threashold_(threashold) {
    matrix_ = {std::array<double, 3>({0, -1, 0}), std::array<double, 3>({-1, 4, -1}),  // NOLINT
               std::array<double, 3>({0, -1, 0})};
}

void EdgedetectionFilter::Apply(Image &image) {
    GrayscaleFilter f;
    f.Apply(image);
    uint32_t n = image.GetHeight();
    uint32_t m = image.GetWidth();
    Image new_image(n, m);
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < m; ++j) {
            ApplyMatrix(i, j, image, new_image);
            Image::Pixel pixel = new_image.GetPixel(i, j);
            if (pixel.r >= threashold_) {
                pixel = Image::Pixel(1, 1, 1);
            } else {
                pixel = Image::Pixel(0, 0, 0);
            }
            new_image.SetPixel(i, j, pixel);
        }
    }
    image = new_image;
}
