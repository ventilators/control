#ifndef CONTROL_INTEGRAL_HPP__
#define CONTROL_INTEGRAL_HPP__

#include <ostream>
#include <ventilation/ventilation.hpp>

#include "control-gain.hpp"
#include "control-process.hpp"
#include "control-value.hpp"

namespace control {
    template <typename Target>
    class Integral {
        static_assert(ventilation::is_airway_type<Target>::value);
        using Precision = typename ventilation::precision<Target>::type;
        public:
            Integral(const Gain<Target>& gain, const Target& target)
                : gain_(gain)
                , target_(target)
                , accumulator_(Target{})
            {}

            control::Value<Precision>
            operator()(const control::Process<Target>& current) {
                accumulator_ += current.error(target_) * current.count();
                return control::Value<Precision>(gain_ * accumulator_);
            }
        private:
            Gain<Target>    gain_;
            Target          target_;
            Target          accumulator_;
    };
} // namespace control

#endif // CONTROL_INTEGRAL_HPP__
