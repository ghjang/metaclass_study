#include "catch.hpp"

#include <memory>
#include <iostream>

#include "interface.h"


TEST_CASE("interface", "[metaclass]")
{
    std::unique_ptr<Shape> shape = std::make_unique<Circle>();    
    REQUIRE(shape->area() == 1);
}
