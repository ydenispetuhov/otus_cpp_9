//
// Created by PetukhovDG on 07.11.2025.
//

#include <chrono>
#include <fstream>
#include "writer.h"

class FileWriter : public IWriter {
public:

    explicit FileWriter(const std::string filename_prefix_, const std::string filename_suffix_) : filename_prefix(filename_prefix_), filename_suffix(filename_suffix_) {}

    void write(const std::string &str) override {
        makeofstream() << str;
    }

    virtual ~FileWriter() = default;

private:

    std::ofstream makeofstream(){
        std::ofstream of(
        filename_prefix + std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(
                        std::chrono::high_resolution_clock::now().time_since_epoch()).count()) + filename_suffix, std::ios::app);
        return of;
    }

    std::string filename_prefix;
    std::string filename_suffix;
};

