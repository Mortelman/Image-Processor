#include <iostream>
#include "in_out/bmp_utils.h"
#include <cassert>
#include "filters/all_filters.h"
#include "parsing/parsing_command_line.h"
#include "help.h"

// F10 to Toggle .cpp/.h

// const std::string LENNA_FILENAME =
// "/home/mortelman/ami-2310-2-Stepan-Fokin-StepkaFokin/tasks/image_processor/test_script/data/lenna.bmp"; const
// std::string OUTPUT_FILENAME =
// "/home/mortelman/ami-2310-2-Stepan-Fokin-StepkaFokin/tasks/image_processor/test_script/data/lena_output.bmp";

int main(int argc, char** argv) {
    std::vector<Filter*> filters_list;
    std::string path_in;
    std::string path_out;
    try {
        filters_list = Parsing(argc, argv);
        if (argc < 3) {
            PrintHelp();
            return 0;
        }
        path_in = argv[1];
        path_out = argv[2];
        BmpReaderWriter bmp;
        bmp.Open(path_in);
        bmp.ReadBmp();
        bmp.Close();
        for (Filter* filter : filters_list) {
            filter->Apply(bmp.GetImage());
            delete filter;
        }
        bmp.Open(path_out);
        bmp.WriteBmp();
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}