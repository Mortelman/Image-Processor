//
// Created by mortelman on 24.03.24.
//

#include "bmp_utils.h"
#include <stdexcept>

void BmpReaderWriter::Open(const std::string &filename) {
    if (file_.is_open()) {
        throw std::logic_error("File is already open.");
    }

    if (filename.empty()) {
        throw std::invalid_argument("Filename is empty.");
    }

    filename_ = filename;
    file_.open(filename);

    if (!file_.is_open()) {
        throw std::runtime_error("Can`t open file");
    }
}

void BmpReaderWriter::Close() {
    file_.close();
    filename_.clear();
}

BmpReaderWriter::~BmpReaderWriter() {
    Close();
}

void BmpReaderWriter::ReadBmp() {
    if (!IsOpen()) {
        throw std::logic_error("File is not open.");
    }

    // Всегда читаем с начала файла

    file_.seekg(0);

    ReadBmpHeader();
    ReadDibHeader();
    ReadPixelMap();
}

void BmpReaderWriter::ReadBmpHeader() {
    if (!file_) {
        throw std::runtime_error("Can`t read file.");
    }
    file_.read(reinterpret_cast<char *>(&bmp_header_), sizeof(bmp_header_));
    if (!file_) {
        throw std::runtime_error("Can`t read file.");
    }

    // Проверяем корректность bmp_header_ прямо здесь
    if (bmp_header_.signature != BMP_SIGNATURE) {
        throw std::runtime_error("BMP file not correct.");
    }
}

void BmpReaderWriter::ReadDibHeader() {
    if (!file_) {
        throw std::runtime_error("Can`t read file.");
    }
    file_.read(reinterpret_cast<char *>(&dib_header_), sizeof(dib_header_));
    if (!file_) {
        throw std::runtime_error("Can`t read file.");
    }

    // Проверяем корректность dib_header_ прямо здесь....
    if (dib_header_.header_size != DIB_HEADER_SIZE) {
        throw std::runtime_error("BMP file not correct.");
    }
}

void BmpReaderWriter::ReadPixelMap() {
    if (!file_) {
        throw std::runtime_error("Can`t read file.");
    }
    std::vector<std::vector<IntegerPixel>> pixel_map(dib_header_.height, std::vector<IntegerPixel>(dib_header_.width));
    padding_amount_ = static_cast<uint32_t>((4 - (dib_header_.width * sizeof(IntegerPixel)) % 4) % 4);
    uint32_t current_file_pos = sizeof(bmp_header_) + sizeof(dib_header_);
    for (int32_t i = 0; i < dib_header_.height; ++i) {
        for (int32_t j = 0; j < dib_header_.width; ++j) {
            file_.read(reinterpret_cast<char *>(&pixel_map[i][j]), sizeof(IntegerPixel));
        }
        current_file_pos += dib_header_.width * sizeof(IntegerPixel) + padding_amount_;
        file_.seekg(current_file_pos);
    }
    image_ = Image(pixel_map);
}

void BmpReaderWriter::WriteBmp() {
    if (!IsOpen()) {
        throw std::logic_error("File is not open.");
    }

    // Всегда пишем с начала файла
    file_.seekg(0);
    char padding = '0';
    dib_header_.height = static_cast<int32_t>(image_.GetHeight());
    dib_header_.width = static_cast<int32_t>(image_.GetWidth());
    padding_amount_ = static_cast<uint32_t>((4 - (dib_header_.width * sizeof(IntegerPixel)) % 4) % 4);
    bmp_header_.size = sizeof(bmp_header_) + sizeof(dib_header_) +
                       (dib_header_.width + padding_amount_) * dib_header_.height * sizeof(IntegerPixel);
    file_.write(reinterpret_cast<char *>(&bmp_header_), sizeof(bmp_header_));
    file_.write(reinterpret_cast<char *>(&dib_header_), sizeof(dib_header_));
    for (int32_t i = 0; i < dib_header_.height; ++i) {
        for (int32_t j = 0; j < dib_header_.width; ++j) {
            IntegerPixel pixel = IntegerPixel(image_.GetPixel(i, j));
            file_.write(reinterpret_cast<char *>(&pixel), sizeof(IntegerPixel));
        }
        for (int32_t j = 0; j < padding_amount_; ++j) {
            file_.write(reinterpret_cast<char *>(&padding), sizeof(char));
        }
    }
}