#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <control/control.hpp>

namespace rc {
    template<typename Precision>
    struct Arbitrary<ventilation::Flow<Precision>> {
        static Gen<ventilation::Flow<Precision>>
        arbitrary() {
            return gen::construct<ventilation::Flow<Precision>>(
                    gen::cast<Precision>(gen::inRange(-100, 100))
                    );
        }
    };

    template<typename Precision>
    struct Arbitrary<ventilation::Pressure<Precision>> {
        static Gen<ventilation::Pressure<Precision>>
        arbitrary() {
            return gen::construct<ventilation::Pressure<Precision>>(
                    gen::cast<Precision>(gen::inRange(-100, 100))
                    );
        }
    };

    template<typename Precision>
    struct Arbitrary<ventilation::PEEP<Precision>> {
        static Gen<ventilation::PEEP<Precision>>
        arbitrary() {
            return gen::construct<ventilation::PEEP<Precision>>(
                    gen::arbitrary<ventilation::Pressure<Precision>>()
                    );
        }
    };

    template<typename Precision>
    struct Arbitrary<ventilation::Volume<Precision>> {
        static Gen<ventilation::Volume<Precision>>
        arbitrary() {
            return gen::construct<ventilation::Volume<Precision>>(
                    gen::cast<Precision>(gen::inRange(-100, 100))
                    );
        }
    };
} // namespace rc

namespace f32 {
    using Flow      = ventilation::Flow<float>;
    using Pressure  = ventilation::Pressure<float>;
    using Volume    = ventilation::Volume<float>;
    using Time      = control::Time<float>;
    using namespace std::chrono_literals;

    RC_GTEST_PROP(Zero, Flow, (const Flow& xs)) {
        Time duration = 1s;
        control::Gain<Flow>     gain(1.0f);
        control::Integral<Flow> integral(gain, xs);
        control::Process<Flow>  process{Flow(0.0f), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Flow expected   = static_cast<float>(i + 1) * xs * gain;
            Flow actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Scaled, Flow, (const Flow& xs)) {
        Time duration = 1ms;
        control::Gain<Flow>     gain(1.0f);
        control::Integral<Flow> integral(gain, xs);
        control::Process<Flow>  process{Flow(0.0f), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Flow expected   = 1e-3 * static_cast<float>(i + 1) * xs * gain;
            Flow actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        Time duration = 1s;
        control::Gain<Pressure>     gain(1.0f);
        control::Integral<Pressure> integral(gain, xs);
        control::Process<Pressure>  process{Pressure(0.0f), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Pressure expected   = static_cast<float>(i + 1) * xs * gain;
            Pressure actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Scaled, Pressure, (const Pressure& xs)) {
        Time duration = 1ms;
        control::Gain<Pressure>     gain(1.0f);
        control::Integral<Pressure> integral(gain, xs);
        control::Process<Pressure>  process{Pressure(0.0f), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Pressure expected   = 1e-3 * static_cast<float>(i + 1) * xs * gain;
            Pressure actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        Time duration = 1s;
        control::Gain<Volume>     gain(1.0f);
        control::Integral<Volume> integral(gain, xs);
        control::Process<Volume>  process{Volume(0.0f), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Volume expected   = static_cast<float>(i + 1) * xs * gain;
            Volume actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Scaled, Volume, (const Volume& xs)) {
        Time duration = 1ms;
        control::Gain<Volume>     gain(1.0f);
        control::Integral<Volume> integral(gain, xs);
        control::Process<Volume>  process{Volume(0.0f), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Volume expected   = 1e-3 * static_cast<float>(i + 1) * xs * gain;
            Volume actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }
} // namespace f32
namespace f64  {
    using Flow      = ventilation::Flow<double>;
    using Pressure  = ventilation::Pressure<double>;
    using Volume    = ventilation::Volume<double>;
    using Time      = control::Time<double>;
    using namespace std::chrono_literals;

    RC_GTEST_PROP(Zero, Flow, (const Flow& xs)) {
        Time duration = 1s;
        control::Gain<Flow>     gain(1.0);
        control::Integral<Flow> integral(gain, xs);
        control::Process<Flow>  process{Flow(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Flow expected   = static_cast<float>(i + 1) * xs * gain;
            Flow actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Scaled, Flow, (const Flow& xs)) {
        Time duration = 1ms;
        control::Gain<Flow>     gain(1.0);
        control::Integral<Flow> integral(gain, xs);
        control::Process<Flow>  process{Flow(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Flow expected   = 1e-3 * static_cast<float>(i + 1) * xs * gain;
            Flow actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        Time duration = 1s;
        control::Gain<Pressure>     gain(1.0);
        control::Integral<Pressure> integral(gain, xs);
        control::Process<Pressure>  process{Pressure(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Pressure expected   = static_cast<float>(i + 1) * xs * gain;
            Pressure actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Scaled, Pressure, (const Pressure& xs)) {
        Time duration = 1ms;
        control::Gain<Pressure>     gain(1.0);
        control::Integral<Pressure> integral(gain, xs);
        control::Process<Pressure>  process{Pressure(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Pressure expected   = 1e-3 * static_cast<float>(i + 1) * xs * gain;
            Pressure actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        Time duration = 1s;
        control::Gain<Volume>     gain(1.0);
        control::Integral<Volume> integral(gain, xs);
        control::Process<Volume>  process{Volume(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Volume expected   = static_cast<float>(i + 1) * xs * gain;
            Volume actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Scaled, Volume, (const Volume& xs)) {
        Time duration = 1ms;
        control::Gain<Volume>     gain(1.0);
        control::Integral<Volume> integral(gain, xs);
        control::Process<Volume>  process{Volume(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Volume expected   = 1e-3 * static_cast<float>(i + 1) * xs * gain;
            Volume actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }
}// namespace f64
namespace f128 {
    using Flow      = ventilation::Flow<long double>;
    using Pressure  = ventilation::Pressure<long double>;
    using Volume    = ventilation::Volume<long double>;
    using Time      = control::Time<long double>;
    using namespace std::chrono_literals;

    RC_GTEST_PROP(Zero, Flow, (const Flow& xs)) {
        Time duration = 1s;
        control::Gain<Flow>     gain(1.0);
        control::Integral<Flow> integral(gain, xs);
        control::Process<Flow>  process{Flow(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Flow expected   = static_cast<float>(i + 1) * xs * gain;
            Flow actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Scaled, Flow, (const Flow& xs)) {
        Time duration = 1ms;
        control::Gain<Flow>     gain(1.0);
        control::Integral<Flow> integral(gain, xs);
        control::Process<Flow>  process{Flow(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Flow expected   = 1e-3 * static_cast<float>(i + 1) * xs * gain;
            Flow actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        Time duration = 1s;
        control::Gain<Pressure>     gain(1.0);
        control::Integral<Pressure> integral(gain, xs);
        control::Process<Pressure>  process{Pressure(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Pressure expected   = static_cast<float>(i + 1) * xs * gain;
            Pressure actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Scaled, Pressure, (const Pressure& xs)) {
        Time duration = 1ms;
        control::Gain<Pressure>     gain(1.0);
        control::Integral<Pressure> integral(gain, xs);
        control::Process<Pressure>  process{Pressure(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Pressure expected   = 1e-3 * static_cast<float>(i + 1) * xs * gain;
            Pressure actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        Time duration = 1s;
        control::Gain<Volume>     gain(1.0);
        control::Integral<Volume> integral(gain, xs);
        control::Process<Volume>  process{Volume(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Volume expected   = static_cast<float>(i + 1) * xs * gain;
            Volume actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Scaled, Volume, (const Volume& xs)) {
        Time duration = 1ms;
        control::Gain<Volume>     gain(1.0);
        control::Integral<Volume> integral(gain, xs);
        control::Process<Volume>  process{Volume(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Volume expected   = 1e-3 * static_cast<float>(i + 1) * xs * gain;
            Volume actual     = integral(process);

            RC_ASSERT(expected == actual);
        }
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
