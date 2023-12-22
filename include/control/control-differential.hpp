#ifndef CONTROL_DIFFERENTIAL_HPP__
#define CONTROL_DIFFERENTIAL_HPP__

#include <iostream>
#include <ostream>
#include <ventilation/ventilation.hpp>

#include "control-gain.hpp"
#include "control-process.hpp"
#include "control-value.hpp"

namespace control {
    template <typename Target>
    class Differential {
        static_assert(ventilation::is_airway_type<Target>::value);
        using Precision = typename ventilation::precision<Target>::type;
        public:
            Differential(const Gain<Target>& gain, const Target& target)
                : gain_(gain)
                , target_(target)
                , previous_(Target())
            {}

            control::Value<Precision>
            operator()(const control::Process<Target>& current) {
                Target error        = current.error(target_);
                Target differential = (error - previous_) * (1.0 / current.count());
                previous_           = error;

                return control::Value<Precision>(gain_ * differential);
            }
        private:
            Gain<Target>    gain_;
            Target          target_;
            Target          previous_;
    };
} // namespace control

#endif // CONTROL_DIFFERENTIAL_HPP__
