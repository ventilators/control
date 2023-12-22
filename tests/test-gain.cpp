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

    RC_GTEST_PROP(Zero, Flow, (const Flow& xs)) {
        control::Gain<Flow> gain(0.0f);
        RC_ASSERT(Flow() == (gain * xs));
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure> gain(0.0f);
        RC_ASSERT(Pressure() == (gain * xs));
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        control::Gain<Volume> gain(0.0f);
        RC_ASSERT(Volume() == (gain * xs));
    }

    RC_GTEST_PROP(Identity, Flow, (const Flow& xs)) {
        control::Gain<Flow> gain(1.0f);
        RC_ASSERT(xs == (gain * xs));
    }

    RC_GTEST_PROP(Identity, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure> gain(1.0f);
        RC_ASSERT(xs == (gain * xs));
    }

    RC_GTEST_PROP(Identity, Volume, (const Volume& xs)) {
        control::Gain<Volume> gain(1.0f);
        RC_ASSERT(xs == (gain * xs));
    }
} // namespace f32
namespace f64 {
    using Flow      = ventilation::Flow<double>;
    using Pressure  = ventilation::Pressure<double>;
    using Volume    = ventilation::Volume<double>;

    RC_GTEST_PROP(Zero, Flow, (const Flow& xs)) {
        control::Gain<Flow> gain(0.0);
        RC_ASSERT(Flow() == (gain * xs));
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure> gain(0.0);
        RC_ASSERT(Pressure() == (gain * xs));
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        control::Gain<Volume> gain(0.0);
        RC_ASSERT(Volume() == (gain * xs));
    }

    RC_GTEST_PROP(Identity, Flow, (const Flow& xs)) {
        control::Gain<Flow> gain(1.0);
        RC_ASSERT(xs == (gain * xs));
    }

    RC_GTEST_PROP(Identity, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure> gain(1.0);
        RC_ASSERT(xs == (gain * xs));
    }

    RC_GTEST_PROP(Identity, Volume, (const Volume& xs)) {
        control::Gain<Volume> gain(1.0);
        RC_ASSERT(xs == (gain * xs));
    }
} // namespace f64
namespace f128 {
    using Flow      = ventilation::Flow<long double>;
    using Pressure  = ventilation::Pressure<long double>;
    using Volume    = ventilation::Volume<long double>;

    RC_GTEST_PROP(Zero, Flow, (const Flow& xs)) {
        control::Gain<Flow> gain(0.0);
        RC_ASSERT(Flow() == (gain * xs));
    }

    RC_GTEST_PROP(Zero, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure> gain(0.0);
        RC_ASSERT(Pressure() == (gain * xs));
    }

    RC_GTEST_PROP(Zero, Volume, (const Volume& xs)) {
        control::Gain<Volume> gain(0.0);
        RC_ASSERT(Volume() == (gain * xs));
    }

    RC_GTEST_PROP(Identity, Flow, (const Flow& xs)) {
        control::Gain<Flow> gain(1.0);
        RC_ASSERT(xs == (gain * xs));
    }

    RC_GTEST_PROP(Identity, Pressure, (const Pressure& xs)) {
        control::Gain<Pressure> gain(1.0);
        RC_ASSERT(xs == (gain * xs));
    }

    RC_GTEST_PROP(Identity, Volume, (const Volume& xs)) {
        control::Gain<Volume> gain(1.0);
        RC_ASSERT(xs == (gain * xs));
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
