//
// Created by mortelman on 28.03.24.
//

#ifndef CPP_HSE_PARSING_COMMAND_LINE_H
#define CPP_HSE_PARSING_COMMAND_LINE_H

#include <stdexcept>
#include "../Image.h"
#include "../in_out/bmp_utils.h"

#include "../filters/all_filters.h"

#endif  // CPP_HSE_PARSING_COMMAND_LINE_H

std::vector<Filter*> Parsing(int argc, char** argv);
