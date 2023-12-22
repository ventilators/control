#ifndef CONTROL_TIME_HPP__
#define CONTROL_TIME_HPP__

#include <chrono>

namespace control {
    template <typename T> using Time = std::chrono::duration<T>;
} // namespace control

#endif // CONTROL_TIME_HPP__
