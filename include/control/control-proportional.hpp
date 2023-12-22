#ifndef CONTROL_PROPORTIONAL_HPP__
#define CONTROL_PROPORTIONAL_HPP__

#include <ostream>
#include <ventilation/ventilation.hpp>

#include "control-gain.hpp"
#include "control-process.hpp"
#include "control-value.hpp"

namespace control {
    template <typename Target>
    class Proportional {
        static_assert(ventilation::is_airway_type<Target>::value);
        using Precision = typename ventilation::precision<Target>::type;
        public:
            Proportional(const Gain<Target>& gain, const Target& target)
                : gain_(gain)
                , target_(target)
            {}

            control::Value<Precision>
            operator()(const control::Process<Target>& current) {
                return control::Value<Precision>(gain_ * current.error(target_));
            }
        private:
            Gain<Target> gain_;
            Target       target_;
    };
} // namespace control

#endif // CONTROL_PROPORTIONAL_HPP__
