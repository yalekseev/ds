#include <iostream>
#include <cassert>

#include "ds.h"

int main() {
    util::disjoint_sets<> ds(10);

    assert(ds.find(1) == 1);
    assert(ds.size(1) == 1);

    assert(ds.find(8) == 8);
    assert(ds.size(8) == 1);

    ds.join(1, 8);

    assert(ds.find(1) == 1);
    assert(ds.size(1) == 2);
    assert(ds.find(8) == 1);
    assert(ds.size(8) == 2);

    ds.join(5, 8);

    assert(ds.find(1) == 1);
    assert(ds.size(1) == 3);
    assert(ds.find(5) == 1);
    assert(ds.size(5) == 3);
    assert(ds.find(8) == 1);
    assert(ds.size(8) == 3);

    return 0;
}
