//
// Created by mortelman on 26.03.24.
//
#include "Image.h"

Image::Image(std::vector<std::vector<IntegerPixel>> &pixel_map) {
    uint32_t n = pixel_map.size();
    uint32_t m = pixel_map[0].size();
    image_.assign(n, std::vector<Pixel>(m));
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < m; ++j) {
            image_[i][j] = Pixel(pixel_map[i][j]);
        }
    }
}

Image::Pixel::Pixel(IntegerPixel pixel)
    : r(static_cast<double>(pixel.r) / static_cast<double>(IntegerPixel::MAX_VALUE)),
      g(static_cast<double>(pixel.g) / static_cast<double>(IntegerPixel::MAX_VALUE)),
      b(static_cast<double>(pixel.b) / static_cast<double>(IntegerPixel::MAX_VALUE)) {
}

IntegerPixel::IntegerPixel(Image::Pixel pixel)
    : b(static_cast<uint8_t>(pixel.b * static_cast<double>(MAX_VALUE))),
      g(static_cast<uint8_t>(pixel.g * static_cast<double>(MAX_VALUE))),
      r(static_cast<uint8_t>(pixel.r * static_cast<double>(MAX_VALUE))) {
}