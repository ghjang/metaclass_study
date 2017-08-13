#include "catch.hpp"

#include <memory>

#include "interface.h"


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


TEST_CASE("interface", "[metaclass]")
{
    std::unique_ptr<Shape> shape = std::make_unique<Circle>();    
    REQUIRE(shape->area() == 1);
}
