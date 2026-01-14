//
// Created by PetukhovDG on 07.11.2025.
//

#ifndef OTUS_CPP_7_STORAGE_H
#define OTUS_CPP_7_STORAGE_H

#include "processor.h"
#include <string>

class IStorage {
public:
    virtual void add_processor(IProcessor *processor) = 0;

    virtual void remove_processor(IProcessor *processor) = 0;

    virtual void new_input(const std::string &input) = 0;

    virtual void end_input() = 0;

    virtual ~IStorage() = default;
};

#endif //OTUS_CPP_7_STORAGE_H
