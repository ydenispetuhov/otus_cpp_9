//
// Created by PetukhovDG on 07.11.2025.
//

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cctype>
#include <locale>
#include "processor.h"
#include "reader.h"

class CommandProcessor : public IProcessor {
public:
    CommandProcessor(int block_size, std::shared_ptr<IReader> reader, std::shared_ptr<IWriter> writer)
        : c_block_size{block_size}, reader_{std::move(reader)}, writer_{std::move(writer)} {}

    std::shared_ptr<IReader> get_reader() {
        return reader_;
    }

    void process_data() override {
        std::string line;
        while (reader_->read(line)) {
            trim(line);
            if (line.empty()) continue;

            if (line == "{") {
                if (stack.empty() && !queue.empty()) {
                    flush_queue();
                }
                stack.push(line);
            } else if (line == "}") {
                if (!stack.empty()) {
                    stack.pop();
                    if (stack.empty()) {
                        flush_queue();
                    }
                }
            } else {
                queue.push(line);
                if (stack.empty() && static_cast<int>(queue.size()) >= c_block_size) {
                    flush_queue();
                }
            }
        }
    }

    ~CommandProcessor() = default;

private:
    void flush_queue() {
        if (queue.empty()) return;

        std::string result;
        while (!queue.empty()) {
            result += queue.front();
            queue.pop();
            if (!queue.empty()) result += " ";
        }
        result += "\n";
        writer_->write(result);
    }

    static void trim(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
        }));
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    std::shared_ptr<IWriter> writer_;
    std::shared_ptr<IReader> reader_;
    std::queue<std::string> queue;
    std::stack<std::string> stack;
    int c_block_size;
};