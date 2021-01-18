#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

template <typename Key, typename Value>
class Collection {
    private:
        std::vector<Key> keys;
        std::vector<Value> values;

        int part(std::vector<Value> &values, std::vector<Key> &keys, int low, int high);
        void quicksort(std::vector<Value> &values, std::vector<Key> &keys, int low, int high);
    public:
        void set(Key key, Value value);
        bool has(Key key);
        Value get(Key key);
        void clear();
        Key firstKey();
        Value firstValue();
        Key lastKey();
        Value lastValue();
        void del(Key key);

        std::vector<Key> firstKey(int size);
        std::vector<Value> firstValue(int size);
        std::vector<Key> lastKey(int size);
        std::vector<Value> lastValue(int size);

        void tap(std::function<Value (Value)> func);
        void sweep(std::function<bool (Value)> func);
        Value findValue(std::function<bool (Value)> func);
        Key findKey(std::function<bool (Key)> func);
        bool some(std::function<bool (Value)> func);
        bool every(std::function<bool (Value)> func);
        void partition(std::function<bool (Value)> func, Collection<Key, Value> &passedcoll, Collection<Key, Value> &failedcoll);

        Collection<Key, Value> filter(std::function<bool (Value)> func);
        Collection<Key, Value> clone();
        Collection<Key, Value> concat(Collection<Key, Value> coll);

        Value reduce();
        void sort();
        bool sorted();
        std::vector<Key> keyArray();
        std::vector<Value> valueArray();
};



template <typename Key, typename Value>
void Collection<Key, Value>::set(Key key, Value value) {
    for(int i = 0; i < keys.size(); i++) {
        if(keys[i] == key) {
            values[i] = value;
            return;
        }
    }
    keys.push_back(key);
    values.push_back(value);
}

template <typename Key, typename Value>
bool Collection<Key, Value>::has(Key key) {
    for(int i = 0; i < keys.size(); i++) {
        if(keys[i] == key) {
            return true;
        }
    }
    return false;
}

template <typename Key, typename Value>
Value Collection<Key, Value>::get(Key key) {
    for(int i = 0; i < keys.size(); i++) {
        if(keys[i] == key) {
            return values[i];
        }
    }
    return -1;
}

template <typename Key, typename Value>
void Collection<Key, Value>::clear() {
    keys.clear();
    values.clear();
}

template <typename Key, typename Value>
Key Collection<Key, Value>::firstKey() {
    return keys[0];
}

template <typename Key, typename Value>
Value Collection<Key, Value>::firstValue() {
    return values[0];
}

template <typename Key, typename Value>
Key Collection<Key, Value>::lastKey() {
    return keys[keys.size()-1];
}

template <typename Key, typename Value>
Value Collection<Key, Value>::lastValue() {
    return values[values.size()-1];
}

template <typename Key, typename Value>
void Collection<Key, Value>::del(Key key) {
    for(int i = 0; i < keys.size(); i++) {
        if(keys[i] == key) {
            keys.erase(keys.begin()+i);
            values.erase(values.begin()+i);
            break;
        }
    }
}



template <typename Key, typename Value>
std::vector<Key> Collection<Key, Value>::firstKey(int size) {
    try {

    if(keys.empty()) throw 2;
    if(size >= keys.size()) throw 1;

    std::vector <Key> spliced;

    for(int i = 0; i < size; i++) {
        spliced.push_back(keys[i]);
    }

    return spliced;

    } catch(int e) {
        (e==1) ? std::cerr<<"Size is bigger than collection." : std::cerr<<"Collection is empty.";
        std::vector <Value> spliced;
        return spliced;
    }
}

template <typename Key, typename Value>
std::vector<Value> Collection<Key, Value>::firstValue(int size) {
    try {

    if(values.empty()) throw 2;
    if(size >= values.size()) throw 1;

    std::vector <Value> spliced;

    for(int i = 0; i < size; i++) {
        spliced.push_back(values[i]);
    }

    return spliced;

    } catch (int e) {
        (e==1) ? std::cerr<<"Size is bigger than collection." : std::cerr<<"Collection is empty.";
        std::vector <Value> spliced;
        return spliced;
    }
    
}

template <typename Key, typename Value>
std::vector<Key> Collection<Key, Value>::lastKey(int size) {
    try {

    if(keys.empty()) throw 2;
    if(size >= keys.size()) throw 1;

    std::vector <Key> spliced;

    for(auto i = keys.end()-1; i >= keys.end()-size; i--) {
        spliced.push_back(*i);
    }

    return spliced;

    } catch(int e) {
        (e==1) ? std::cerr<<"Size is bigger than collection." : std::cerr<<"Collection is empty.";
        std::vector <Value> spliced;
        return spliced;
    }
}

template <typename Key, typename Value>
std::vector<Value> Collection<Key, Value>::lastValue(int size) {
    try {

    if(values.empty()) throw 2;
    if(size >= values.size()) throw 1;

    std::vector <Key> spliced;

    for(auto i = values.end()-1; i >= values.end()-size; i--) {
        spliced.push_back(*i);
    }

    return spliced;

    } catch(int e) {
        (e==1) ? std::cerr<<"Size is bigger than collection." : std::cerr<<"Collection is empty.";
        std::vector <Value> spliced;
        return spliced;
    }
}



template <typename Key, typename Value>
void Collection<Key, Value>::tap(std::function<Value (Value)> func) {
    for(auto i = values.begin(); i < values.end(); i++) {
        *i = func(*i);
    }
}

template <typename Key, typename Value>
void Collection<Key, Value>::sweep(std::function<bool (Value)> func) {
    for(int i = values.size()-1; i >= 0; i--) {
        if(func(values[i])==true) {
            values.erase(values.begin()+i);
            keys.erase(keys.begin()+i);
        }
    }
}

template <typename Key, typename Value>
Value Collection<Key, Value>::findValue(std::function<bool (Value)> func) {
    for(int i = 0; i < values.size(); i++) {
        if(func(values[i])) {
            return values[i];
        }
    }
    Value undef;
    return undef;
}

template <typename Key, typename Value>
Key Collection<Key, Value>::findKey(std::function<bool (Key)> func) {
    for(int i = 0; i < keys.size(); i++) {
        if(func(keys[i])) {
            return keys[i];
        }
    }
    Key undef;
    return undef;
}

template <typename Key, typename Value>
bool Collection<Key, Value>::some(std::function<bool (Value)> func) {
    for(int i = 0; i < values.size(); i++) {
        if(func(values[i])) return true;
    }
    return false;
}

template <typename Key, typename Value>
bool Collection<Key, Value>::every(std::function<bool (Value)> func) {
    for(int i = 0; i < values.size(); i++) {
        if(!func(values[i])) return false;
    }
    return true;
}

template <typename Key, typename Value>
void Collection<Key, Value>::partition(std::function<bool (Value)> func, Collection<Key, Value> &passedcoll, Collection<Key, Value> &failedcoll) {
    for(int i = 0; i < values.size(); i++) {
        (func(values[i])) ? passedcoll.set(keys[i], values[i]) : failedcoll.set(keys[i], values[i]);
    }
}

template <typename Key, typename Value>
Collection<Key, Value> Collection<Key, Value>::filter(std::function<bool (Value)> func) {
    Collection<Key, Value> filtered;
    for(int i = 0; i < values.size(); i++) {
        if(func(values[i])) filtered.set(keys[i], values[i]);
    }
    return filtered;
}

template <typename Key, typename Value>
Collection<Key, Value> Collection<Key, Value>::clone() {
    Collection<Key, Value> cloned;
    for(int i = 0; i < values.size(); i++) {
        cloned.set(keys[i], values[i]);
    }
    return cloned;
}

template <typename Key, typename Value>
Collection<Key, Value> Collection<Key, Value>::concat(Collection<Key, Value> coll) {
    Collection<Key, Value> combined;
    std::vector<Key> keys2 = coll.keyArray();
    std::vector<Value> values2 = coll.valueArray();
    for(int i = 0; i < values.size(); i++) {
        combined.set(keys[i], values[i]);
    }
    for(int i = 0; i < values2.size(); i++) {
        combined.set(keys2[i], values2[i]);
    }

    return combined;

}

template <typename Key, typename Value>
Value Collection<Key, Value>::reduce() {
    Value reduced;
    for(int i = 0; i < values.size(); i++) {
        reduced += values[i];
    }
    return reduced;
}

template <typename Key, typename Value>
int Collection<Key, Value>::part(std::vector<Value> &values, std::vector<Key> &keys, int low, int high) {
    int piv = values[high];
    int i = low - 1;

    for (int j = low; j <= high- 1; j++) 
    { 
        if (values[j] <= piv) 
        { 
            i++;
            std::swap(values[i], values[j]); 
            std::swap(keys[i], keys[j]);
        } 
    } 
    std::swap(values[i + 1], values[high]);
    std::swap(keys[i+1], keys[high]);
    return (i + 1); 
}

template <typename Key, typename Value>
void Collection<Key, Value>::quicksort(std::vector<Value> &values, std::vector<Key> &keys, int low, int high) {
    if(low < high) {
        int p = part(values, keys, low, high);

        quicksort(values, keys, low, p - 1);
        quicksort(values, keys, p + 1, high);
    }
}

template <typename Key, typename Value>
void Collection<Key, Value>::sort() {
    quicksort(values, keys, 0, values.size()-1);
}

template <typename Key, typename Value>
bool Collection<Key, Value>::sorted() {
    for(int i = 1; i < values.size(); i++) {
        if(values[i-1] > values[i]) return false;
    }
    return true;
}

template <typename Key, typename Value>
std::vector<Key> Collection<Key, Value>::keyArray() {
    return keys;
}

template <typename Key, typename Value>
std::vector<Value> Collection<Key, Value>::valueArray() {
    return values;
}

#endif