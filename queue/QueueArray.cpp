#include "iostream"

template <class T>

class QueueArray{
private:
    int headIdx;
    int tailIdx;
    int capacity;
    T queue[];

public:
    explicit QueueArray(int cap){
        capacity = cap;
        queue = new T[capacity];
        headIdx = -1;
        tailIdx = -1;

    }
    void print_queue(){
        for (int i = 0; i < tailIdx; ++i) {
            std::cout<<queue[i]<< " -> ";
        }
    }
    void enqueue(T value){
        if (!is_full()){
            tailIdx = (tailIdx+1)%capacity ;
            queue[tailIdx] = value;
        }
        else std::cout<<"Queue is full!"<<std::endl;

    }
    T dequeue(){
        if(!is_empty()){
            int temp = queue[headIdx];
            headIdx = (headIdx+1)%capacity;
            return temp;
        }
        else std::cout<<"Queue is empty!"<<std::endl;
    }
    bool is_empty(){
        if (tailIdx,headIdx == -1 || headIdx > tailIdx){
            tailIdx, headIdx = -1;
            return true;
        }
        return false;
    }
    bool is_full(){
        if ((tailIdx+1)%capacity == headIdx) return true;
        return false;
    }
};
