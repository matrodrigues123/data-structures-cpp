#include "iostream"
using namespace std;
template <class T>

class HashTable{
private:
    int capacity;
    struct HashObject{
        string objKey = "<Null>";
        T data;
    };
    HashObject* table;


public:
    explicit HashTable(int cap){
        capacity = cap;
        table = new HashObject[capacity];
    }

    int hash(string k) const{
        int h = 0;
        int key_length = static_cast<int>(k.length());
        for (int i = 0; i < key_length; ++i) {
            //k[i] as integer returns it's ASCII value
            h = h * 31 + k[i];
        }
        return abs(h % capacity);
    }

    void add(string key, T value){
        int index = hash(key);
//        int originalIndex = index;

        // this loop deals with collisions
//        while (exists(index)){
//            index = (index+1)%capacity;
//            if (index == originalIndex) break;
//        }
        table[index].objKey = key;
        table[index].data = value;
    }

    bool exists(string key){
        int idx = hash(key);
        if(table[idx].objKey == "<Null>") return false;
        return true;
    }

    T get(string key){
        int index = hash(key);
        if (exists(key)){
            return table[index].data;
        }
    }

    void remove(int key){
        int index = hash(key);
        table[index].objKey = "<Null>";
    }
};
