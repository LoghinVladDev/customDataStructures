//
// Created by loghin on 15.01.2021.
//

#ifndef CDS_LIST_HPP
#define CDS_LIST_HPP

#include <CDS/Collection>
#if defined(__cpp_concepts) && !defined(_MSC_VER)
#include <concepts>
#endif

template <class T>
class List : public Collection <T> {
protected:
    Size _size { 0ull };

    List () noexcept = default;
public:
    class ListOutOfBounds: public Collection <T>::CollectionOutOfBounds {
    public:
        [[nodiscard]] auto what () const noexcept -> StringLiteral override {
            return "List Access Out of Bounds";
        }
    };

    virtual auto index ( T const & ) const noexcept -> Index = 0;

    virtual auto get ( Index ) noexcept (false) -> T & = 0;
    virtual auto get ( Index ) const noexcept (false) -> const T & = 0;

    virtual auto set ( const T &, Index ) noexcept (false) -> T & = 0;

    virtual auto sub ( List &, Index, Index = UINT64_MAX ) const noexcept (false) -> void = 0;

    inline auto operator [] ( const Index & index ) noexcept -> T & {
        return this->get( index );
    }

    inline auto operator [] ( const Index & index ) const noexcept -> const T & {
        return this->get( index );
    }

    virtual auto remove ( const typename Collection<T>::Iterator & ) noexcept (false) -> T = 0;
    virtual auto replace( const typename Collection<T>::Iterator &, const T & ) noexcept -> void = 0;
    virtual auto insertBefore( const typename Collection<T>::Iterator &, const T & ) noexcept -> void = 0;
    virtual auto insertAfter( const typename Collection<T>::Iterator &, const T & ) noexcept -> void = 0;

    virtual auto popFront ( ) noexcept (false) -> T = 0;
    virtual auto popBack ( ) noexcept (false) -> T = 0;

    virtual auto pushFront ( const T & ) noexcept -> void = 0;
    virtual auto pushBack ( const T & ) noexcept -> void = 0;

    virtual auto pushFront ( T && ) noexcept -> void = 0;
    virtual auto pushBack ( T && ) noexcept -> void = 0;

#define GEN_SORT_FUNC(_paramType, _exceptSpec) \
    virtual auto sort ( dataTypes::_paramType ) _exceptSpec -> void = 0;
/*
    GEN_SORT_FUNC(ValueCompareFunction<T>, noexcept)
    GEN_SORT_FUNC(ReferenceCompareFunction<T>, noexcept)
    GEN_SORT_FUNC(ConstReferenceCompareFunction<T> = [](const T & a, const T & b) noexcept -> bool { return a < b; }, noexcept)

    GEN_SORT_FUNC(ThrowValueCompareFunction<T>, noexcept (false) )
    GEN_SORT_FUNC(ThrowReferenceCompareFunction<T>, noexcept (false) )
    GEN_SORT_FUNC(ThrowConstReferenceCompareFunction<T>, noexcept (false) )
*/
#undef GEN_SORT_FUNC




#if defined(__cpp_concepts) && !defined(_MSC_VER)
    virtual auto sort ( const Comparator < T > & ) noexcept -> void = 0;
//    virtual auto sort ( auto ) noexcept -> void = 0;
#else
    virtual auto sort ( bool (*) (T const &, T const &) noexcept ) noexcept -> void = 0;
#endif

    [[nodiscard]] inline auto size () const noexcept -> Size override { return this->_size; }

    ~List () noexcept override = default;
};


#endif //CDS_LIST_HPP
