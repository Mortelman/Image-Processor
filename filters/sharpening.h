//
// Created by mortelman on 28.03.24.
//

#ifndef CPP_HSE_SHARPENING_H
#define CPP_HSE_SHARPENING_H

#include "base_filter.h"
#include "../Image.h"

class SharpeningFilter : public MatrixFilter {
public:
    SharpeningFilter();

    void Apply(Image& image) override;
};

#endif  // CPP_HSE_SHARPENING_H
