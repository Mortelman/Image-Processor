//
// Created by mortelman on 28.03.24.
//

#include "parsing_command_line.h"

std::vector<Filter*> Parsing(int argc, char** argv) {
    std::vector<Filter*> filter_list;

    if (argc < 2) {
        return filter_list;
    }

    for (int i = 3; i < argc; ++i) {
        std::string argument = argv[i];
        if (argument == "-crop") {
            if (i > argc - 3) {
                throw std::runtime_error("Reading command line parameters was failed");
            }
            std::vector<std::string> parameters = {argv[i + 1], argv[i + 2]};
            try {
                uint32_t width = std::stoi(parameters[0]);
                uint32_t height = std::stoi(parameters[1]);
                CropFilter* filter_crop_ptr = new CropFilter(height, width);
                filter_list.push_back(filter_crop_ptr);
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Invalid command line argument");
            }
            ++ ++i;
        } else if (argument == "-gs") {
            GrayscaleFilter* filter_grayscale_ptr = new GrayscaleFilter;
            std::vector<std::string> parameters = {};
            filter_list.push_back(filter_grayscale_ptr);
        } else if (argument == "-neg") {
            NegativeFilter* filter_negative_ptr = new NegativeFilter;
            std::vector<std::string> parameters = {};
            filter_list.push_back(filter_negative_ptr);
        } else if (argument == "-sharp") {
            SharpeningFilter* filter_sharp_ptr = new SharpeningFilter;
            std::vector<std::string> parameters = {};
            filter_list.push_back(filter_sharp_ptr);
        } else if (argument == "-edge") {
            if (i > argc - 2) {
                throw std::runtime_error("Reading command line parameters was failed");
            }
            std::vector<std::string> parameters = {argv[i + 1]};
            try {
                std::stof(parameters[0]);
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Invalid command line argument");
            }
            ++i;
            EdgedetectionFilter* filter_edge_ptr = new EdgedetectionFilter(std::stof(parameters[0]));
            filter_list.push_back(filter_edge_ptr);
        } else if (argument == "-blur") {
            if (i > argc - 2) {
                throw std::runtime_error("Reading command line parameters was failed");
            }
            std::vector<std::string> parameters = {argv[i + 1]};
            try {
                std::stof(parameters[0]);
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Invalid command line argument");
            }
            ++i;
            BlurFilter* filter_blur_ptr = new BlurFilter(std::stof(parameters[0]));
            filter_list.push_back(filter_blur_ptr);
        } else {
            throw std::runtime_error("Reading command line parameters was failed");
        }
    }
    return filter_list;
}