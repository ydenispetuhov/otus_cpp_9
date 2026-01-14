//
// Created by PetukhovDG on 08.11.2025.
//
#include "../include/reader.h"

#include <string>
#include <iostream>

class ConsoleReader : public IReader {
public:
    ConsoleReader(std::istream &input = std::cin) : m_input{input} {};

    bool read(std::string &line) override {
        return (bool) std::getline(m_input, line);
    };

    ~ConsoleReader() {};

private:
    void open_brace() {};

    void close_brace() {};

    void notify_end_input() {};

    void notify_new_line(const std::string &line) {};

    std::istream &m_input;
};