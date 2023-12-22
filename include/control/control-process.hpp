#ifndef CONTROL_PROCESS_HPP__
#define CONTROL_PROCESS_HPP__

#include <chrono>
#include <ventilation/ventilation.hpp>

#include "control-time.hpp"

namespace control {
    template <typename T> 
    struct Process {
        using Precision = typename ventilation::precision<T>::type;
        static_assert(ventilation::is_airway_type<T>::value);

        T                           measurement;
        control::Time<Precision>    duration;

        T
        error(const T& target) const {
            return target - measurement;
        }

        Precision
        count() const {
            return static_cast<Precision>(duration.count());
        }
    };
} // namespace control

#endif // CONTROL_PROCESS_HPP__
