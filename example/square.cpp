#include <control/control.hpp>
#include <cstdint>
#include <iostream>
#include <ventilation/ventilation.hpp>

using Pressure  = ventilation::Pressure<float>;
using Process   = control::Process<Pressure>;
using Time      = control::Time<float>;

const Pressure TARGET   = Pressure(1.0f);
const Time DURATION     = Time(1e-3f);

int
main(int, char**) {
    using Gain = control::Gain<Pressure>;

    std::vector<control::Control<Pressure>> controller = {
          control::Proportional<Pressure>(Gain(0.5f), TARGET)
        , control::Integral<Pressure>(Gain(5.0e1f), TARGET)
        , control::Differential<Pressure>(Gain(3e-4f), TARGET)
    };

    Process process{Pressure(0.0f), DURATION};
    for (std::size_t i = 0; i < 10; i++) {
        std::cout   << Pressure(0.0f) 
                    << ", "
                    << Pressure(0.0f)
                    << std::endl;
    }
    for (std::size_t i = 0; i < 100; i++) {
        Pressure p = process.measurement;
        control::Action<Pressure> action{process};
        for (control::Control<Pressure>& c : controller) {
            p += std::visit(action, c);
        }
        process.measurement = p;
        std::cout   << TARGET 
                    << ", "
                    << process.measurement
                    << std::endl;
    }
    return 0;
}
