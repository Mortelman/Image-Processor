//
// Created by mortelman on 24.03.24.
//

#ifndef CPP_HSE_BMP_UTILS_H
#define CPP_HSE_BMP_UTILS_H

#include <cstdint>
#include <string>
#include <fstream>
#include "../Image.h"

// Предполагаем, что работаем с GCC

struct BmpHeader {
    uint16_t signature;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} __attribute__((packed));

struct DIBHeader {
    DIBHeader()
        : header_size(0),
          width(0),
          height(0),
          color_planes_num(0),
          bits_per_pixel(0),
          compression(0),
          image_size(0),
          hor_res(0),
          ver_res(0),
          colors_num(0),
          important_colors_num(0) {
    }
    uint32_t header_size;
    int32_t width;
    int32_t height;
    uint16_t color_planes_num;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    int32_t hor_res;
    int32_t ver_res;
    uint32_t colors_num;
    uint32_t important_colors_num;
} __attribute__((packed));

class BmpReaderWriter {
public:
    static const uint16_t BMP_SIGNATURE = 0x4D42;
    static const uint16_t DIB_HEADER_SIZE = 40;
    static const uint16_t BITS_PER_PIXEL = 24;

    BmpReaderWriter(){};

    ~BmpReaderWriter();

    // Открывает файл с переданным именем файла
    void Open(const std::string& filename);

    // Закрывает файл
    void Close();

    /// Читает открытый BMP файл
    void ReadBmp();

    bool IsOpen() const {
        return file_.is_open();
    }

    const std::string& GetFilename() const {
        return filename_;
    }

    /// Записываем бмп в открытый файлик
    void WriteBmp();

    Image& GetImage() {
        return image_;
    }

private:
    /// Читает BMP заголовок не задавая текущую позицию чтения.
    /// Не выполняет никаких проверок открытия файла (т.к. закрытый метод)
    void ReadBmpHeader();

    /// Читает BMP заголовок не задавая текущую позицию чтения.
    /// Не выполняет никаких проверок открытия файла (т.к. закрытый метод)
    void ReadDibHeader();

    /// Считывает сами пикслеи картинки, не задавая текущую позицию чтения
    /// Не выполняет проверок открытия файла (т.к. закрытый метод)
    void ReadPixelMap();

protected:
    std::string filename_;
    std::fstream file_;
    BmpHeader bmp_header_;
    DIBHeader dib_header_;
    Image image_;
    uint8_t padding_amount_;
};

#endif  // CPP_HSE_BMP_UTILS_H
