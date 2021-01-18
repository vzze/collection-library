#include <vector>
#include "coll/collection.h"

int main() {
    Collection<int, int> coll;

    coll.set(2, 6);
    coll.set(2, 4);

    coll.set(5, 3);

    coll.set(7, 7);

    coll.sort();

    std::vector<int> values = coll.valueArray();
    for(int value : values) {
        std::cout<<value<<" ";
    }
}