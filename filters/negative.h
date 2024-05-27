//
// Created by mortelman on 27.03.24.
//

#ifndef CPP_HSE_NEGATIVE_H
#define CPP_HSE_NEGATIVE_H

#include "base_filter.h"

class NegativeFilter : public virtual Filter {
public:
    void Apply(Image& image) override;
};

#endif  // CPP_HSE_NEGATIVE_H
