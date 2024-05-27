//
// Created by mortelman on 26.03.24.
//

#ifndef CPP_HSE_IMAGE_H
#define CPP_HSE_IMAGE_H

#include <cstdint>
#include <vector>

struct IntegerPixel;

class Image {
public:
    struct Pixel {
        double r;
        double g;
        double b;

        Pixel() : r(0), g(0), b(0) {
        }

        Pixel(double r, double g, double b) : r(r), g(g), b(b) {
        }

        explicit Pixel(IntegerPixel pixel);
    };

    Image() : image_({}) {
    }

    Image(uint32_t h, uint32_t w) {
        image_.assign(h, std::vector<Pixel>(w));
    }

    explicit Image(std::vector<std::vector<IntegerPixel>>& bit_map);

    const Pixel GetPixel(uint32_t i, uint32_t j) const {
        return image_[i][j];
    };

    void SetPixel(uint32_t i, uint32_t j, const Pixel& pixel) {
        image_[i][j] = pixel;
    }

    uint32_t GetHeight() const {
        return image_.size();
    }

    uint32_t GetWidth() const {
        return image_[0].size();
    }

private:
    std::vector<std::vector<Pixel>> image_;
};

struct IntegerPixel {
    static const uint8_t MAX_VALUE = 255;
    uint8_t b;
    uint8_t g;
    uint8_t r;
    explicit IntegerPixel(Image::Pixel pixel);

    IntegerPixel() : b(0), g(0), r(0) {
    }

} __attribute__((packed));

#endif  // CPP_HSE_IMAGE_H
