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


#endif // INTERFACE_H
