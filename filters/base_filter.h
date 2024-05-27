//
// Created by mortelman on 27.03.24.
//

#ifndef CPP_HSE_BASE_FILTER_H
#define CPP_HSE_BASE_FILTER_H

#include <cstdint>
#include <array>
#include "../Image.h"

class Filter {
public:
    virtual void Apply(Image& image) = 0;

    virtual ~Filter() = default;
};

class MatrixFilter : public virtual Filter {
public:
    void Apply(Image& image) override = 0;

    ~MatrixFilter() override = default;

protected:
    void ApplyMatrix(uint32_t x, uint32_t y, Image& image, Image& new_image) const;

    std::array<std::array<double, 3>, 3> matrix_;
};

#endif  // CPP_HSE_BASE_FILTER_H
