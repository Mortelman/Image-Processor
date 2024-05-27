//
// Created by mortelman on 28.03.24.
//

#include "help.h"

void PrintHelp() {  // NOLINT
    std::cout << "................................................................................" << std::endl;
    std::cout << " Гайд по использованию image_processor:" << std::endl;
    std::cout << "Первый вводимый параметр - путь, откуда будет взят файл BMP" << std::endl;
    std::cout << "Второй вводимый параметр - путь, куда будет сохранён результат обработки изображения" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Фильтры:" << std::endl;
    std::cout << "Для обрезки изображения используйте -crop и параметры (высота и ширина)" << std::endl;
    std::cout << "Для фильтра NEGATIVE используйте -neg без параметров" << std::endl;
    std::cout << "Для фильтра GRAYSCALE используйте -gs без параметров" << std::endl;
    std::cout << "Для фильтра SHARPENING используйте -sharp без параметров" << std::endl;
    std::cout << "Для фильтра EDGEDETECTION используйте -edge с параметром threshold" << std::endl;
    std::cout << "Для фильтра BLUR используйте -blur с параметром размытия sigma" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << ".................................................................................." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
}