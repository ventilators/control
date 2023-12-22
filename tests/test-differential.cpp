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
        control::Gain<Flow>         gain(1.0f);
        control::Differential<Flow> differential(gain, xs);
        control::Process<Flow>      process{Flow(0.0f), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Flow expected   = (i == 0) ? xs : Flow(0.0f);
            Flow actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Progress, Flow, (const Flow& xs)) {
        Time duration = 1s;
        control::Gain<Flow>         gain(1.0f);
        control::Differential<Flow> differential(gain, xs);

        for (std::size_t i = 0; i < 100; i++) {
            float scale     = static_cast<float>(i) / 100.0f;
            Flow current    = scale * xs;

            control::Process<Flow> process{current, duration};
            Flow expected   = (i == 0) ? xs : (-1.0f / 100.0f) * xs;
            Flow actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        Time duration = 1s;
        control::Gain<Pressure>         gain(1.0f);
        control::Differential<Pressure> differential(gain, xs);
        control::Process<Pressure>      process{Pressure(0.0f), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Pressure expected   = (i == 0) ? xs : Pressure(0.0f);
            Pressure actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Progress, Pressure, (const Pressure& xs)) {
        Time duration = 1s;
        control::Gain<Pressure>         gain(1.0f);
        control::Differential<Pressure> differential(gain, xs);

        for (std::size_t i = 0; i < 100; i++) {
            float scale         = static_cast<float>(i) / 100.0f;
            Pressure current    = scale * xs;

            control::Process<Pressure> process{current, duration};
            Pressure expected   = (i == 0) ? xs : (-1.0f / 100.0f) * xs;
            Pressure actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        Time duration = 1s;
        control::Gain<Volume>         gain(1.0f);
        control::Differential<Volume> differential(gain, xs);
        control::Process<Volume>      process{Volume(0.0f), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Volume expected   = (i == 0) ? xs : Volume(0.0f);
            Volume actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Progress, Volume, (const Volume& xs)) {
        Time duration = 1s;
        control::Gain<Volume>         gain(1.0f);
        control::Differential<Volume> differential(gain, xs);

        for (std::size_t i = 0; i < 100; i++) {
            float scale     = static_cast<float>(i) / 100.0f;
            Volume current  = scale * xs;

            control::Process<Volume> process{current, duration};
            Volume expected = (i == 0) ? xs : (-1.0f / 100.0f) * xs;
            Volume actual   = differential(process);

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
        control::Gain<Flow>         gain(1.0);
        control::Differential<Flow> differential(gain, xs);
        control::Process<Flow>      process{Flow(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Flow expected   = (i == 0) ? xs : Flow(0.0);
            Flow actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Progress, Flow, (const Flow& xs)) {
        Time duration = 1s;
        control::Gain<Flow>         gain(1.0);
        control::Differential<Flow> differential(gain, xs);

        for (std::size_t i = 0; i < 100; i++) {
            double scale    = static_cast<double>(i) / 100.0;
            Flow current    = scale * xs;

            control::Process<Flow> process{current, duration};
            Flow expected   = (i == 0) ? xs : (-1.0 / 100.0) * xs;
            Flow actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        Time duration = 1s;
        control::Gain<Pressure>         gain(1.0);
        control::Differential<Pressure> differential(gain, xs);
        control::Process<Pressure>      process{Pressure(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Pressure expected   = (i == 0) ? xs : Pressure(0.0);
            Pressure actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Progress, Pressure, (const Pressure& xs)) {
        Time duration = 1s;
        control::Gain<Pressure>         gain(1.0);
        control::Differential<Pressure> differential(gain, xs);

        for (std::size_t i = 0; i < 100; i++) {
            double scale        = static_cast<double>(i) / 100.0;
            Pressure current    = scale * xs;

            control::Process<Pressure> process{current, duration};
            Pressure expected   = (i == 0) ? xs : (-1.0 / 100.0) * xs;
            Pressure actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        Time duration = 1s;
        control::Gain<Volume>         gain(1.0);
        control::Differential<Volume> differential(gain, xs);
        control::Process<Volume>      process{Volume(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Volume expected   = (i == 0) ? xs : Volume(0.0);
            Volume actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Progress, Volume, (const Volume& xs)) {
        Time duration = 1s;
        control::Gain<Volume>         gain(1.0);
        control::Differential<Volume> differential(gain, xs);

        for (std::size_t i = 0; i < 100; i++) {
            double scale    = static_cast<double>(i) / 100.0;
            Volume current  = scale * xs;

            control::Process<Volume> process{current, duration};
            Volume expected = (i == 0) ? xs : (-1.0 / 100.0) * xs;
            Volume actual   = differential(process);

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
        control::Gain<Flow>         gain(1.0);
        control::Differential<Flow> differential(gain, xs);
        control::Process<Flow>      process{Flow(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Flow expected   = (i == 0) ? xs : Flow(0.0);
            Flow actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Progress, Flow, (const Flow& xs)) {
        Time duration = 1s;
        control::Gain<Flow>         gain(1.0);
        control::Differential<Flow> differential(gain, xs);

        for (std::size_t i = 0; i < 100; i++) {
            long double scale   = static_cast<double>(i) / 100.0;
            Flow current        = scale * xs;

            control::Process<Flow> process{current, duration};
            Flow expected   = (i == 0) ? xs : (-1.0 / 100.0) * xs;
            Flow actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        Time duration = 1s;
        control::Gain<Pressure>         gain(1.0);
        control::Differential<Pressure> differential(gain, xs);
        control::Process<Pressure>      process{Pressure(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Pressure expected   = (i == 0) ? xs : Pressure(0.0);
            Pressure actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Progress, Pressure, (const Pressure& xs)) {
        Time duration = 1s;
        control::Gain<Pressure>         gain(1.0);
        control::Differential<Pressure> differential(gain, xs);

        for (std::size_t i = 0; i < 100; i++) {
            long double scale   = static_cast<double>(i) / 100.0;
            Pressure current    = scale * xs;

            control::Process<Pressure> process{current, duration};
            Pressure expected   = (i == 0) ? xs : (-1.0 / 100.0) * xs;
            Pressure actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        Time duration = 1s;
        control::Gain<Volume>         gain(1.0);
        control::Differential<Volume> differential(gain, xs);
        control::Process<Volume>      process{Volume(0.0), duration};

        for (std::size_t i = 0; i < 100; i++) {
            Volume expected   = (i == 0) ? xs : Volume(0.0);
            Volume actual     = differential(process);

            RC_ASSERT(expected == actual);
        }
    }

    RC_GTEST_PROP(Progress, Volume, (const Volume& xs)) {
        Time duration = 1s;
        control::Gain<Volume>         gain(1.0);
        control::Differential<Volume> differential(gain, xs);

        for (std::size_t i = 0; i < 100; i++) {
            long double scale   = static_cast<double>(i) / 100.0;
            Volume current      = scale * xs;

            control::Process<Volume> process{current, duration};
            Volume expected = (i == 0) ? xs : (-1.0 / 100.0) * xs;
            Volume actual   = differential(process);

            RC_ASSERT(expected == actual);
        }
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
