//
// Created by mortelman on 27.03.24.
//

#ifndef CPP_HSE_GRAYSCALE_H
#define CPP_HSE_GRAYSCALE_H

#include "base_filter.h"

class GrayscaleFilter : public virtual Filter {
public:
    void Apply(Image& image) override;
};

#endif  // CPP_HSE_GRAYSCALE_H
