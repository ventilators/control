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
    Time DURATION   = Time(0.0f);

    RC_GTEST_PROP(Zero, Flow, (const Flow& xs)) {
        control::Gain<Flow>         gain(1.0f);
        control::Proportional<Flow> proportional(gain, xs);
        control::Process<Flow>      process{xs, DURATION};

        RC_ASSERT(Flow(0.0f) == proportional(process));
    }

    RC_GTEST_PROP(Unity, Flow, (const Flow& xs)) {
        control::Gain<Flow>         gain(1.0f);
        control::Proportional<Flow> proportional(gain, xs);
        control::Process<Flow>      process{Flow(0.0f), DURATION};

        RC_ASSERT(xs == proportional(process));
    }

    RC_GTEST_PROP(Half, Flow, (const Flow& xs)) {
        control::Gain<Flow>         gain(0.5f);
        control::Proportional<Flow> proportional(gain, xs);
        control::Process<Flow>      process{Flow(0.0f), DURATION};

        RC_ASSERT(0.5f * xs == proportional(process));
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure>         gain(1.0f);
        control::Proportional<Pressure> proportional(gain, xs);
        control::Process<Pressure>      process{xs, DURATION};

        RC_ASSERT(Pressure() == proportional(process));
    }

    RC_GTEST_PROP(Unity, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure>         gain(1.0f);
        control::Proportional<Pressure> proportional(gain, xs);
        control::Process<Pressure>      process{Pressure(0.0f), DURATION};

        RC_ASSERT(xs == proportional(process));
    }

    RC_GTEST_PROP(Half, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure>         gain(0.5f);
        control::Proportional<Pressure> proportional(gain, xs);
        control::Process<Pressure>      process{Pressure(0.0f), DURATION};

        RC_ASSERT(0.5f * xs == proportional(process));
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        control::Gain<Volume>         gain(1.0f);
        control::Proportional<Volume> proportional(gain, xs);
        control::Process<Volume>      process{xs, DURATION};

        RC_ASSERT(Volume() == proportional(process));
    }

    RC_GTEST_PROP(Unity, Volume, (const Volume& xs)) {
        control::Gain<Volume>         gain(1.0f);
        control::Proportional<Volume> proportional(gain, xs);
        control::Process<Volume>      process{Volume(0.0f), DURATION};

        RC_ASSERT(xs == proportional(process));
    }

    RC_GTEST_PROP(Half, Volume, (const Volume& xs)) {
        control::Gain<Volume>         gain(0.5f);
        control::Proportional<Volume> proportional(gain, xs);
        control::Process<Volume>      process{Volume(0.0f), DURATION};

        RC_ASSERT(0.5f * xs == proportional(process));
    }
} // namespace f32
namespace f64 {
    using Flow      = ventilation::Flow<double>;
    using Pressure  = ventilation::Pressure<double>;
    using Volume    = ventilation::Volume<double>;
    using Time      = control::Time<double>;
    Time DURATION   = Time(0.0);

    RC_GTEST_PROP(Zero, Flow, (const Flow& xs)) {
        control::Gain<Flow>         gain(1.0);
        control::Proportional<Flow> proportional(gain, xs);
        control::Process<Flow>      process{xs, DURATION};

        RC_ASSERT(Flow() == proportional(process));
    }

    RC_GTEST_PROP(Unity, Flow, (const Flow& xs)) {
        control::Gain<Flow>         gain(1.0);
        control::Proportional<Flow> proportional(gain, xs);
        control::Process<Flow>      process{Flow(0.0), DURATION};

        RC_ASSERT(xs == proportional(process));
    }

    RC_GTEST_PROP(Half, Flow, (const Flow& xs)) {
        control::Gain<Flow>         gain(0.5);
        control::Proportional<Flow> proportional(gain, xs);
        control::Process<Flow>      process{Flow(0.0), DURATION};

        RC_ASSERT(0.5 * xs == proportional(process));
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure>         gain(1.0);
        control::Proportional<Pressure> proportional(gain, xs);
        control::Process<Pressure>      process{xs, DURATION};

        RC_ASSERT(Pressure() == proportional(process));
    }

    RC_GTEST_PROP(Unity, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure>         gain(1.0);
        control::Proportional<Pressure> proportional(gain, xs);
        control::Process<Pressure>      process{Pressure(0.0), DURATION};

        RC_ASSERT(xs == proportional(process));
    }

    RC_GTEST_PROP(Half, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure>         gain(0.5);
        control::Proportional<Pressure> proportional(gain, xs);
        control::Process<Pressure>      process{Pressure(0.0), DURATION};

        RC_ASSERT(0.5 * xs == proportional(process));
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        control::Gain<Volume>         gain(1.0);
        control::Proportional<Volume> proportional(gain, xs);
        control::Process<Volume>      process{xs, DURATION};

        RC_ASSERT(Volume() == proportional(process));
    }

    RC_GTEST_PROP(Unity, Volume, (const Volume& xs)) {
        control::Gain<Volume>         gain(1.0);
        control::Proportional<Volume> proportional(gain, xs);
        control::Process<Volume>      process{Volume(0.0), DURATION};

        RC_ASSERT(xs == proportional(process));
    }

    RC_GTEST_PROP(Half, Volume, (const Volume& xs)) {
        control::Gain<Volume>         gain(0.5);
        control::Proportional<Volume> proportional(gain, xs);
        control::Process<Volume>      process{Volume(0.0), DURATION};

        RC_ASSERT(0.5 * xs == proportional(process));
    }
} // namespace f64
namespace f128 {
    using Flow      = ventilation::Flow<long double>;
    using Pressure  = ventilation::Pressure<long double>;
    using Volume    = ventilation::Volume<long double>;
    using Time      = control::Time<long double>;
    Time DURATION   = Time(0.0);

    RC_GTEST_PROP(Zero, Flow, (const Flow& xs)) {
        control::Gain<Flow>         gain(1.0);
        control::Proportional<Flow> proportional(gain, xs);
        control::Process<Flow>      process{xs, DURATION};

        RC_ASSERT(Flow() == proportional(process));
    }

    RC_GTEST_PROP(Unity, Flow, (const Flow& xs)) {
        control::Gain<Flow>         gain(1.0);
        control::Proportional<Flow> proportional(gain, xs);
        control::Process<Flow>      process{Flow(0.0), DURATION};

        RC_ASSERT(xs == proportional(process));
    }

    RC_GTEST_PROP(Half, Flow, (const Flow& xs)) {
        control::Gain<Flow>         gain(0.5);
        control::Proportional<Flow> proportional(gain, xs);
        control::Process<Flow>      process{Flow(0.0), DURATION};

        RC_ASSERT(0.5 * xs == proportional(process));
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure>         gain(1.0);
        control::Proportional<Pressure> proportional(gain, xs);
        control::Process<Pressure>      process{xs, DURATION};

        RC_ASSERT(Pressure() == proportional(process));
    }

    RC_GTEST_PROP(Unity, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure>         gain(1.0);
        control::Proportional<Pressure> proportional(gain, xs);
        control::Process<Pressure>      process{Pressure(0.0), DURATION};

        RC_ASSERT(xs == proportional(process));
    }

    RC_GTEST_PROP(Half, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure>         gain(0.5);
        control::Proportional<Pressure> proportional(gain, xs);
        control::Process<Pressure>      process{Pressure(0.0), DURATION};

        RC_ASSERT(0.5 * xs == proportional(process));
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        control::Gain<Volume>         gain(1.0);
        control::Proportional<Volume> proportional(gain, xs);
        control::Process<Volume>      process{xs, DURATION};

        RC_ASSERT(Volume() == proportional(process));
    }

    RC_GTEST_PROP(Unity, Volume, (const Volume& xs)) {
        control::Gain<Volume>         gain(1.0);
        control::Proportional<Volume> proportional(gain, xs);
        control::Process<Volume>      process{Volume(0.0), DURATION};

        RC_ASSERT(xs == proportional(process));
    }

    RC_GTEST_PROP(Half, Volume, (const Volume& xs)) {
        control::Gain<Volume>         gain(0.5);
        control::Proportional<Volume> proportional(gain, xs);
        control::Process<Volume>      process{Volume(0.0), DURATION};

        RC_ASSERT(0.5 * xs == proportional(process));
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
