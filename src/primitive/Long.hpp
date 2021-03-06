//
// Created by loghin on 25.02.2021.
//

#ifndef CDS_LONG_HPP
#define CDS_LONG_HPP

#include <CDS/Object>

#if __cpp_constepxr >= 201907
#define __long_constexpr constexpr
#else
#define __long_constexpr
#endif

class Long : public Object {
//    _G_OBJ(Long, long long int, v, 0llu)
private:
    long long int v{0llu};
public:
    constexpr Long() noexcept = default;
    constexpr Long(Long const&)noexcept=default;
    constexpr Long(Long &&)noexcept=default;
    __long_constexpr ~Long() noexcept override = default;
    constexpr Long(long long int value) noexcept: v(value) {}
    constexpr Long &operator=(Long const &o) noexcept {
        if (this == &o)return *this;
        this->v = o.v;
        return *this;
    }
    constexpr Long &operator=(long long int value) noexcept {
        this->v = value;
        return *this;
    }

    __long_constexpr auto operator+(Long const &o) const noexcept -> Long { return this->v + o.v; }
    __long_constexpr auto operator+(long long int value) const noexcept -> Long { return this->v + value; }
    __long_constexpr auto operator-(Long const &o) const noexcept -> Long { return this->v - o.v; }
    __long_constexpr auto operator-(long long int value) const noexcept -> Long { return this->v - value; }
    __long_constexpr auto operator*(Long const &o) const noexcept -> Long { return this->v * o.v; }
    __long_constexpr auto operator*(long long int value) const noexcept -> Long { return this->v * value; }
    __long_constexpr auto operator/(Long const &o) const noexcept -> Long { return this->v / o.v; }
    __long_constexpr auto operator/(long long int value) const noexcept -> Long { return this->v / value; }
    __long_constexpr auto operator%(Long const &o) const noexcept -> Long { return this->v % o.v; }
    __long_constexpr auto operator%(long long int value) const noexcept -> Long { return this->v % value; }

    constexpr auto operator+=(Long const &o) noexcept -> Long & {
        this->v += o.v;
        return *this;
    }
    constexpr auto operator+=(long long int value) noexcept -> Long & {
        this->v += value;
        return *this;
    }
    constexpr auto operator-=(Long const &o) noexcept -> Long & {
        this->v -= o.v;
        return *this;
    }
    constexpr auto operator-=(long long int value) noexcept -> Long & {
        this->v -= value;
        return *this;
    }
    constexpr auto operator*=(Long const &o) noexcept -> Long & {
        this->v *= o.v;
        return *this;
    }
    constexpr auto operator*=(long long int value) noexcept -> Long & {
        this->v *= value;
        return *this;
    }
    constexpr auto operator/=(Long const &o) noexcept -> Long & {
        this->v /= o.v;
        return *this;
    }
    constexpr auto operator/=(long long int value) noexcept -> Long & {
        this->v /= value;
        return *this;
    }
    constexpr auto operator%=(Long const &o) noexcept -> Long & {
        this->v %= o.v;
        return *this;
    }
    constexpr auto operator%=(long long int value) noexcept -> Long & {
        this->v %= value;
        return *this;
    }

    constexpr auto operator==(Long const &o) const noexcept -> bool { return this->v == o.v; }
    constexpr auto operator==(long long int value) const noexcept -> bool { return this->v == value; }
    constexpr auto operator!=(Long const &o) const noexcept -> bool { return this->v != o.v; }
    constexpr auto operator!=(long long int value) const noexcept -> bool { return this->v != value; }
    constexpr auto operator>(Long const &o) const noexcept -> bool { return this->v > o.v; }
    constexpr auto operator>(long long int value) const noexcept -> bool { return this->v > value; }
    constexpr auto operator<(Long const &o) const noexcept -> bool { return this->v < o.v; }
    constexpr auto operator<(long long int value) const noexcept -> bool { return this->v < value; }
    constexpr auto operator>=(Long const &o) const noexcept -> bool { return this->v >= o.v; }
    constexpr auto operator>=(long long int value) const noexcept -> bool { return this->v >= value; }
    constexpr auto operator<=(Long const &o) const noexcept -> bool { return this->v <= o.v; }
    constexpr auto operator<=(long long int value) const noexcept -> bool { return this->v <= value; }
    __long_constexpr auto operator&(Long const &o) const noexcept -> Long { return this->v & o.v; }
    __long_constexpr auto operator&(long long int value) const noexcept -> Long { return this->v & value; }
    __long_constexpr auto operator|(Long const &o) const noexcept -> Long { return this->v | o.v; }
    __long_constexpr auto operator|(long long int value) const noexcept -> Long { return this->v | value; }
    __long_constexpr auto operator^(Long const &o) const noexcept -> Long { return this->v ^ o.v; }
    __long_constexpr auto operator^(long long int value) const noexcept -> Long { return this->v ^ value; }
    constexpr auto operator&=(Long const &o) noexcept -> Long & {
        this->v &= o.v;
        return *this;
    }
    constexpr auto operator&=(long long int value) noexcept -> Long & {
        this->v &= value;
        return *this;
    }
    constexpr auto operator|=(Long const &o) noexcept -> Long & {
        this->v |= o.v;
        return *this;
    }
    constexpr auto operator|=(long long int value) noexcept -> Long & {
        this->v |= value;
        return *this;
    }
    constexpr auto operator^=(Long const &o) noexcept -> Long & {
        this->v ^= o.v;
        return *this;
    }
    constexpr auto operator^=(long long int value) noexcept -> Long & {
        this->v ^= value;
        return *this;
    }
    constexpr operator long long int() const noexcept { return this->v; }
    [[nodiscard]]constexpr inline auto get() const noexcept -> long long int { return this->v; }

public:
    [[nodiscard]] auto hash() const noexcept -> Index override {
        return static_cast < Index > (this->v);
    }

    [[nodiscard]] auto toString () const noexcept -> String override {
        return String().append(this->v);
    }

    static auto parse(String const & string) noexcept -> Long {
        if ( string.empty() ) return 0;

        auto it = string.begin();
        constexpr static auto isNumericChar = [] (char c) noexcept -> bool { return c >= '0' && c <= '9'; };
        constexpr static auto numericCharToInt = [] (char c) noexcept -> int { return static_cast < int > ( c ) - 48; };

        while( ! isNumericChar ( it.value() ) && it != string.end() )
            it.next();

        long long int numericValue = 0;

        while ( isNumericChar ( it.value() ) && it != string.end() ) {
            numericValue = numericValue * 10 + numericCharToInt ( it.value() );
            it.next();
        }

        return numericValue;
    }

    [[nodiscard]] auto copy () const noexcept -> Long * override {
        return new Long( * this );
    }
};

#endif //CDS_LONG_HPP
