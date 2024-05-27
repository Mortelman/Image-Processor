//
// Created by mortelman on 27.03.24.
//

#include "crop.h"

void CropFilter::Apply(Image &image) {
    uint32_t n = std::min(image.GetHeight(), height_);
    uint32_t m = std::min(image.GetWidth(), width_);
    Image new_image(n, m);
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < m; ++j) {
            new_image.SetPixel(i, j, image.GetPixel(image.GetHeight() - n + i, j));
        }
    }
    image = new_image;
}