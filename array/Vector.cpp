#include "iostream"

template <class T>
class Vector {
    private:
        T* arrP;
        int size;
        int capacity;

        void resize(int new_capacity) {
            T* newArr;
            newArr = new T[new_capacity];
            for (int i = 0; i < size; ++i) {
                newArr[i] = arrP[i];
            }
            delete[] arrP;
            arrP = newArr;
            capacity = new_capacity;
        };

        bool is_valid_index(int index) {
            if (index < 0 || index >= size){
                std::cout << "Error: Index out of range";
                return false;
            }
        return true;
        };

    public:
        explicit Vector(int cap){
            capacity = cap;
            size = 0;
            arrP = new T[capacity];
        };

        void print_vector(){
            for (int i = 0; i < size; ++i) {
                std::cout<<arrP[i]<<" ";
            }
            std::cout<<"\n";
        }

        // returns number of items currently in the array
        int get_size(){
            return size;
        };

        // returns number of items it can hold
        int get_capacity(){
            return capacity;
        };

        bool is_empty(){
            if (size == 0)
                return true;
            return false;
        };

        // returns item at given index
        T get(int index){
            if (is_valid_index(index)){
                return arrP[index];
            }
        };

        // change item value at given index
        void set(int index, T new_item){
            if (is_valid_index(index)){
                arrP[index] = new_item;
            }
        };

        void push(T item){
            if (size == capacity){
                resize(capacity*2);
            }
            arrP[size] = item;
            size++;
        };

        // inserts item at index, shifts that index's value and trailing elements to the right
        void insert(int index, T item){
            if (is_valid_index(index)) {
                if (size == capacity) {
                    resize(capacity * 2);
                }

                T currValue, nextValue;
                T prevValue = arrP[index];
                arrP[index] = item;
                for (int i = index + 1; i <= size; ++i) {
                    currValue = arrP[i];
                    arrP[i] = prevValue;
                    prevValue = currValue;
                }
                size++;
            }
        };

        // remove from end, return value
        T pop(){
            T poppedItem = arrP[size-1];
            size--;
            if (size <= capacity/4){
                resize(capacity/2);
            }
            return poppedItem;
        };

        // delete item at index, shifting all trailing elements left
        void remove(int index){
            if (is_valid_index(index)){
                for (int i = index; i < size; ++i) {
                    arrP[i] = arrP[i+1];
                }
            }

            size--;
            if (size <= capacity/4){
                resize(capacity/2);
            }
        };

        // looks for value and returns first index with that value, -1 if not found
        int find(T item){
            for (int i = 0; i < size; ++i) {
                if (arrP[i] == item){
                    return i;
                }
            }
            return -1;
        };
};




