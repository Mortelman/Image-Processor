add_executable(
    image_processor
    image_processor.cpp
        in_out/bmp_utils.cpp
        in_out/bmp_utils.h
        Image.cpp
        Image.h
        filters/base_filter.cpp
        filters/base_filter.h
        filters/crop.cpp
        filters/crop.h
        filters/all_filters.h
        filters/grayscale.cpp
        filters/grayscale.h
        filters/negative.cpp
        filters/negative.h
        filters/sharpening.cpp
        filters/sharpening.h
        filters/edge_detection.cpp
        filters/edge_detection.h
        parsing/parsing_command_line.cpp
        parsing/parsing_command_line.h
        help.h
        help.cpp
        filters/blur.cpp
        filters/blur.h
)
