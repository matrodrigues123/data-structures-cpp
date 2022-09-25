#include "iostream"

template <class T>

class LinkedList {
    private:
        struct Node{
            T data;
            struct Node* next;
        };
        struct Node* head;
        int size;


    public:
        LinkedList(){
            head = new Node;
            head->next = NULL;
            size = 0;
        };

        void print_list(){
            struct Node* p = head->next;
            while (p != NULL){
                std::cout<< p->data << " -> ";
                p = p->next;
            }
        }

        int get_size(){
            return size;
        };

        bool is_empty(){
            if (size == 0) return true;
            return false;
        };

        T value_at(int index){
            struct Node* p = head->next;
            int count = 0;

            while (count != index){
                p = p->next;
                count++;
            }

            return p->data;
        };

        void push_front(T value){
            auto* new_node = new Node;
            new_node->data = value;
            if (head->next == NULL){
                head->next = new_node;
                new_node->next = NULL;
            }
            else {
                new_node->next = head->next;
                head->next = new_node;
            }
            size++;
        };

        T pop_front(){
            struct Node* ex_node = head->next;
            if (ex_node == NULL){
                return NULL;
            }
            head->next = ex_node->next;
            T value = ex_node->data;
            delete ex_node;
            size--;
            return value;
        };

        void push_back(T value){
            struct Node* p = head;

            while (p->next != NULL){
                p = p->next;
            }

            auto* new_node = new Node;
            new_node->data = value;
            p->next = new_node;
            new_node->next = NULL;
            size++;
        }

        T pop_back(){
            struct Node* p = head;

            while (p->next->next != NULL){
                p = p->next;
            }

            struct Node* ex_node = p->next;
            p->next = NULL;
            T value = ex_node->data;
            delete ex_node;
            size--;
            return value;
        }

        T get_front(){
            return head->next->data;
        }

        T get_back(){
            struct Node* p = head;
            while (p->next != NULL){
                p = p->next;
            }

            return p->data;
        }

        void insert(int index, T value){
            struct Node* new_node = new Node;
            new_node->data = value;

            struct Node* p = head->next;
            int count = 0;

            while (count != index-1){
                p = p->next;
                count++;
            }

            struct Node* ex_node = p->next;
            p->next = new_node;
            new_node->next = ex_node->next;
            size++;
            delete ex_node;
        }

        void erase(int index){
            struct Node* p = head->next;
            int count = 0;

            while (count != index-1){
                p = p->next;
                count++;
            }

            struct Node* ex_node = p->next;
            p->next = ex_node->next;
            size--;
            delete ex_node;
        }

        T value_n_from_end(int n){
            int index = size - 1 - n;
            return value_at(index);
        }

        void reverse(){
            // Iterative solution
            struct Node* curr = head->next;
            struct Node* prev = NULL;
            struct Node* temp;
            while (curr != NULL){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            head->next = prev;
        }
};




