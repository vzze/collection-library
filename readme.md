C++ JavaScript Map implementation with added functionality

Methods | Parameters | Notes
------- | -----------|-------
 set | Key, Value | Sets a key value pair, updates the value if the key already exists.
 get | Key | Returns the value for the specified key. 
 has | Key | Checks for a key, returns a boolean. 
 firstValue | / int | If no parameter specified returns first value, if specified returns the first X values. 
 firstKey | / int |  If no parameter specified returns first key, if specified returns the first X keys.
 lastKey | / int | If no parameter specified returns last key, if specified returns the last X keys.
 lastValue | / int | If no parameter specified returns last value, if specified returns the last X values. 
 del | Key | Deletes the key value pair.
 clear | / | Clears the collection.
 tap | Value function | Applies a function to each element, modifying it in the collection.
 sweep | bool function | Removes every element that checks for the given function.
 findValue | bool function | Returns the first value that passes the function.
 findKey | bool function | Returns the first key that passes the function.
 some | bool function | Returns true if any value passes the function.
 every | bool function | Return true if every value passes the function.
 partition | bool function, Collection passed, Collection failed | Splits the main collection into 2, the one where the values have passed the test, and contrary.
 filter | bool function | Returns a collection with the elements that have passed the function.
 clone | / | Returns a copy of the collection.
 concat | Collection coll | Returns a collection formed by the original collection and the parameter collection.
 reduce | / | Reduces the collection into a single Value.
 sort | / | Sorts the collection.
 sorted | / | Checks if the collection is sorted, returns boolean.
 keyArray | / | Returns a vector that has all the keys of the collection.
 valueArray | / | Returns a vector that has all the values of the collection.

**Usage Example**

```c++
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
```

