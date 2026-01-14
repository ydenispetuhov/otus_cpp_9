#pragma once

#include <cstddef>
#include <memory>

namespace async {

using handle_t = std::shared_ptr<void>;

handle_t connect(std::size_t bulk);
void receive(const handle_t &handle, const char *data, std::size_t size);
void disconnect(handle_t handle);

}
