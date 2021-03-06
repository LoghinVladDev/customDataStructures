//
// Created by loghin on 26.01.2021.
//

#ifndef CDS_OPTIONAL_HPP
#define CDS_OPTIONAL_HPP

#include <CDS/Pointer>

template <class T>
class Optional final : public Object {
public:
    using Value                 = T;
    using ValueReference        = T &;
    using ValueConstReference   = T const &;

private:
    UniquePointer<T> pObj;

public:
    Optional() noexcept = default;
    Optional(Optional const & o) noexcept {
        * this = o;
    }
    ~Optional() noexcept final = default;

    Optional ( ValueConstReference v ) noexcept : pObj ( new Value( v ) ) { } // NOLINT(google-explicit-constructor)
    Optional & operator = ( ValueConstReference v ) noexcept {
        this->pObj.reset(new Value ( v ));
        return * this;
    }

    auto operator -> () const noexcept -> UniquePointer<T> const & { return this->pObj; }
    auto operator -> () noexcept -> UniquePointer<T> & { return this->pObj; }
    auto operator * () const noexcept (false) -> ValueReference { return * this->pObj; }

    [[nodiscard]] inline auto hasValue () const noexcept -> bool { return ! pObj.isNull(); }

    inline auto value () const noexcept(false) -> ValueConstReference { return * this->pObj; }
    inline auto value () noexcept(false) -> ValueReference { return * this->pObj; }
    inline auto valueOr (ValueReference v) noexcept -> ValueReference { return this->hasValue() ? this->value() : v; }
    inline auto valueOr (ValueConstReference v) noexcept -> ValueConstReference { return this->hasValue() ? this->value() : v; }

    inline explicit operator bool () const noexcept { return this->hasValue(); }

    inline auto clear () noexcept -> Optional & {
        this->pObj.reset();
        return * this;
    }

    Optional & operator = (Optional const & o) noexcept {
        if ( this == & o )
            return * this;

        if ( ! o.hasValue() ) {
            if ( hasValue() )
                pObj.reset();
            return * this;
        }

        pObj.reset( new Value ( * o.pObj ) );

        return * this;
    }

    auto operator == ( Object const & o ) const noexcept -> bool final {
        if ( & o == this ) return true;
        auto p = dynamic_cast < Optional < T > const * > ( & o );
        if ( p == nullptr ) return false;
        return this->value() == p->value();
    }

    [[nodiscard]] auto toString() const noexcept -> String final {
        std::stringstream oss;
        oss << "| ";
        if ( this->hasValue() )
            oss << this->value();
        else
            oss << "none";
        oss << " |";
        return String(oss.str());
    }

    [[nodiscard]] auto copy () const noexcept -> Optional * override {
        return new Optional( * this );
    }
};


#endif //CDS_OPTIONAL_HPP
