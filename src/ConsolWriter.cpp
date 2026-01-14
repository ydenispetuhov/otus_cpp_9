//
// Created by PetukhovDG on 03.01.2026.
//

#include <iostream>
#include "writer.h"


/**
 * @brief The ConsoleWriter class
 * Represents a dummy stdout writer
 */
class ConsolWriter : public IWriter {
public:
    ConsolWriter() = default;

    void write(const std::string &str) override {
        std::cout << str;
    };

    ~ConsolWriter() override = default;
};
