//
// Created by PetukhovDG on 07.11.2025.
//

#ifndef OTUS_CPP_7_PROCESSOR_H
#define OTUS_CPP_7_PROCESSOR_H

#include <cstdint>
#include "writer.h"

#include <memory>
#include <vector>
#include <string>

class IProcessor {
public:

    virtual void process_data() = 0;

    ~IProcessor() = default;
};


#endif //OTUS_CPP_7_PROCESSOR_H
