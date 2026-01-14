//
// Created by PetukhovDG on 05.01.2026.
//
#include "../include/reader.h"

#include <string>
#include <sstream>

class StringReader : public IReader {
public:
    StringReader(): m_input{std::make_unique<std::istringstream>()}{};

void add_data(const char * data, std::size_t size) override {
        m_input->str(std::string(data, data + size));
        string_data.clear();
        std::string line;
        while (std::getline(*m_input, line)) {
            string_data.push_back(line);
        }
        m_input->clear(); // Reset EOF flag
        cur_pos = string_data.begin();
    };

    bool read(std::string &line) override {
        if (cur_pos != string_data.end()) {
            line = cur_pos.operator*();
            ++cur_pos;
            return true;
        } else {
            line = "";
            return false;
        }
    };

    ~StringReader() {};

private:
    void open_brace() {};

    void close_brace() {};

    void notify_end_input() {};

    void notify_new_line(const std::string &line) {};

    std::unique_ptr<std::istringstream> m_input;
    std::vector<std::string>::iterator cur_pos;
    std::vector<std::string> string_data;
};
