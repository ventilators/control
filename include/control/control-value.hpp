#ifndef CONTROL_VALUE_HPP__
#define CONTROL_VALUE_HPP__

#include <ostream>
#include <ventilation/ventilation.hpp>

namespace control {
    template <typename T>
    class Value {
        static_assert(std::is_floating_point<T>::value);
        public:
            Value(const ventilation::Flow<T>& p) : value_(p) {}
            Value(const ventilation::PEEP<T>& p) : value_(p) {}
            Value(const ventilation::Pressure<T>& p) : value_(p) {}
            Value(const ventilation::Volume<T>& p) : value_(p) {}

            friend std::ostream&
            operator<<(std::ostream& os, const Value<T>& v) {
                os << v.value_;
                return os;
            }

            operator ventilation::Flow<T>() const noexcept {
                return ventilation::Flow<T>(value_);
            }

            operator ventilation::PEEP<T>() const noexcept {
                return ventilation::PEEP<T>(value_);
            }

            operator ventilation::Pressure<T>() const noexcept {
                return ventilation::Pressure<T>(value_);
            }

            operator ventilation::Volume<T>() const noexcept {
                return ventilation::Volume<T>(value_);
            }
        private:
            T value_;
    };
} // namespace control

#endif // CONTROL_VALUE_HPP__
