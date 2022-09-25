#include "iostream"
#include "../linked_lists/LinkedListTail.cpp"

template <class T>

class QueueLinked{
private:
    LinkedListTailed<T> queue;

public:
    QueueLinked(){
        queue = LinkedListTailed<T>();
    }
    void print_queue(){
        queue.print_list();
    }
    void enqueue(T value){
        queue.push_back(value);
    }
    T dequeue(){
        return queue.pop_front();
    }
    void is_empty(){
        return queue.is_empty();
    }
};
