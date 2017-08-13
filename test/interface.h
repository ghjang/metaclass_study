#ifndef INTERFACE_H
#define INTERFACE_H


// include Metaclass related stuffs like 'compiler'.
#include <cppx/meta>


$class interface
{
    constexpr {
        compiler.require(
            $interface.variables().empty(),
            "interfaces may not contain data"
        );
        for... (auto f : $interface.functions()) {
            compiler.require(
                !f.is_copy() && !f.is_move(),
                "interfaces may not copy or move; consider a"
                " virtual clone() instead"
            );
            if (!f.has_access()) {
                f.make_public();
            }
            compiler.require(
                f.is_public(),
                "interface functions must be public"
            );
            f.make_pure_virtual();
        }
    }
    virtual ~interface() noexcept { }
};


interface Shape
{
    int area() const;
    void scale_by(double factor);
};


// print the compiler-generated final Shape class source codes
//  to the compiler console at compile time.
constexpr
{
    compiler.debug($Shape);
}


class Circle : public Shape
{
public:
    int area() const override { return 1; }
    void scale_by(double factor) override { }
};


#endif // INTERFACE_H
