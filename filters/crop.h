//
// Created by mortelman on 27.03.24.
//

#ifndef CPP_HSE_CROP_H
#define CPP_HSE_CROP_H

#include "base_filter.h"
#include "../Image.h"

class CropFilter : public Filter {
public:
    void Apply(Image& image) override;

    CropFilter(uint32_t height, uint32_t width) : width_(width), height_(height) {
    }

private:
    uint32_t width_;
    uint32_t height_;
};

#endif  // CPP_HSE_CROP_H
