#ifndef CONTROL_HPP__
#define CONTROL_HPP__

#include <variant>

#include "control-gain.hpp"
#include "control-process.hpp"
#include "control-time.hpp"

#include "control-proportional.hpp"
#include "control-integral.hpp"
#include "control-differential.hpp"

namespace control {
    template <typename Target>
    using Control = std::variant<
          control::Proportional<Target>
        , control::Integral<Target>
        , control::Differential<Target>
        >;

    template <typename Target>
    struct Action {
        using Precision = typename ventilation::precision<Target>::type;
        control::Process<Target> variable;

        control::Value<Precision>
        operator()(control::Proportional<Target>& p) const {
            return p(variable);
        }

        control::Value<Precision>
        operator()(control::Integral<Target>& p) const {
            return p(variable);
        }

        control::Value<Precision>
        operator()(control::Differential<Target>& p) const {
            return p(variable);
        }
    };
} // namespace control

#endif // CONTROL_HPP__
