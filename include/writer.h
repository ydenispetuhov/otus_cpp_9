//
// Created by PetukhovDG on 07.11.2025.
//

#ifndef OTUS_CPP_7_WRITER_H
#define OTUS_CPP_7_WRITER_H

#include <string>

class IWriter {
public:
    virtual void write(const std::string &str) = 0;

    virtual ~IWriter() = default;
};

#endif //OTUS_CPP_7_WRITER_H
