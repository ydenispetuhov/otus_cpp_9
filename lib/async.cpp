#include "async.h"

#include <algorithm>
#include <memory>
#include <mutex>
#include <vector>

#include "../src/StringReader.cpp"
#include "../src/FileWriter.cpp"
#include "../src/ConsolWriter.cpp"
#include "../src/MultiThreadCommandProcessor.cpp"

namespace async {
    std::vector<std::shared_ptr<MultiThreadCommandProcessor> > connected;
    std::mutex m_Mutex;


    handle_t connect(const std::size_t bulk) {
        std::lock_guard<std::mutex> locker(m_Mutex);
        auto stringReader = std::make_shared<StringReader>();
        std::shared_ptr<FileWriter> fileWriter1 = std::make_shared<FileWriter>("bulk1", ".log");
        std::shared_ptr<FileWriter> fileWriter2 = std::make_shared<FileWriter>("bulk2", ".log");
        std::shared_ptr<ConsolWriter> consolWriter = std::make_shared<ConsolWriter>();
        auto processor = std::make_shared<MultiThreadCommandProcessor>(bulk, stringReader, fileWriter1, fileWriter2, consolWriter);
        connected.push_back(processor);
        return processor;
    }

    void receive(const handle_t &handle, const char *data, std::size_t size) {
        std::lock_guard<std::mutex> locker(m_Mutex);
        auto found = std::find(connected.begin(), connected.end(), handle);
        if (connected.end() != found) {
             std::remove_extent<MultiThreadCommandProcessor>::type* commandProcessor = found->get();
             std::shared_ptr<IReader> iReader = commandProcessor->get_reader();
            iReader->add_data(data, size);
            (commandProcessor)->process_data();
        }
    }

    void disconnect(handle_t handle) {
        auto found = std::find(connected.begin(), connected.end(), handle);
        if (connected.end() != found) {
            connected.erase(found);
        }
    }
}
