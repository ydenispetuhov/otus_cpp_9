#include <iostream>
#include <memory>
#include "lib/async.h"

int main(int argc, char *argv[]) {
    std::istream &input = std::cin;
    int bulk = std::stoi(argv[1]);
    std::string line;
    auto h = async::connect(bulk);
    // auto h2 = async::connect(bulk);
    // async::receive(h, "1", 1);
    // async::receive(h2, "1\n", 2);
    // async::receive(h, "\n2\n3\n4\n5\n6\n{\na\n", 15);
    // async::receive(h, "b\nc\nd\n}\n89\n", 11);
    while (std::getline(input, line)) {
            async::receive(h, line.c_str(), line.length());
        }
    async::disconnect(h);
    // async::disconnect(h2);

    return 0;
}