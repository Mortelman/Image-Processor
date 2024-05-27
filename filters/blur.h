//
// Created by mortelman on 28.03.24.
//

#ifndef CPP_HSE_BLUR_H
#define CPP_HSE_BLUR_H

#include "base_filter.h"
#include "../Image.h"

class BlurFilter : public virtual Filter {
private:
    double sigma_;
public:
    explicit BlurFilter(double sigma) : sigma_(sigma) {
    }

    void Apply(Image& image) override;
};

#endif  // CPP_HSE_BLUR_H
