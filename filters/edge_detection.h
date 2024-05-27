//
// Created by mortelman on 28.03.24.
//

#ifndef CPP_HSE_EDGE_DETECTION_H
#define CPP_HSE_EDGE_DETECTION_H

#include "base_filter.h"
#include "../Image.h"

class EdgedetectionFilter : public MatrixFilter {
public:
    explicit EdgedetectionFilter(double threashold);

    void Apply(Image& image) override;

private:
    double threashold_;
};

#endif  // CPP_HSE_EDGE_DETECTION_H
