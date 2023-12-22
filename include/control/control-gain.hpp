#ifndef CONTROL_GAIN_HPP__
#define CONTROL_GAIN_HPP__

#include <ostream>
#include <ventilation/ventilation.hpp>

namespace control {
    template <typename T>
    class Gain {
        static_assert(ventilation::is_airway_type<T>::value);
        using Precision = typename ventilation::precision<T>::type;
        public:
            explicit Gain() : value_(Precision()) {}
            explicit Gain(Precision value) : value_(value) {}

            friend std::ostream&
            operator<<(std::ostream& os, const Gain& p) {
                os << p.value_;
                return os;
            }

            friend T
            operator*(const Gain<T>& lhs, const T& rhs) {
                return lhs.value_ * rhs;
            }

            friend T
            operator*(const T& lhs, const Gain<T>& rhs) {
                return lhs * rhs.value_;
            }
        private:
            T value_;
    };
} // namespace control

#endif // CONTROL_GAIN_HPP__
