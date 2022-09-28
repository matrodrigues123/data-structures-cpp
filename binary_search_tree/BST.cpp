#include "iostream"
#include "../queue/QueueLinked.cpp"

class BinarySearchTree{
private:
    struct Node{
        int value;
        struct Node* left;
        struct Node* right;
    };
    struct Node* root;

    static struct Node* createNode(int newValue){
        auto* newNode = new Node;
        newNode->value = newValue;
        newNode->left = nullptr; newNode->right = nullptr;

        return newNode;
    }

public:
    BinarySearchTree(int rootValue){
        root = nullptr;
    }

    struct Node* getRoot(){
        return root;
    }

    struct Node* insert(int newValue, struct Node* rt){
        struct Node* newNode = createNode(newValue);
        if (rt == nullptr) {
            rt = newNode;
            if (root == nullptr) root = rt;
        }
        else if(newValue > rt->value) rt->right = insert(newValue, rt->right);
        else if(newValue <= rt->value) rt->left = insert(newValue, rt->left);

        return rt;
    }

    bool isInTree(int searchedValue, struct Node* rt){
        if (rt == nullptr) return false;

        if(rt->value == searchedValue) return true;
        else if(searchedValue > rt->value) return isInTree(searchedValue, rt->right);
        else return isInTree(searchedValue, rt->left);
    }

    int getMin(struct Node* rt){
        if (rt->left == nullptr) return rt->value;
        else return getMin(rt->left);
    }

    int getMax(struct Node* rt){
        if(rt->right == nullptr) return rt->value;
        else return getMax(rt->right);
    }

    int getHeight(struct Node* rt){
        if (rt == nullptr) return -1;
        int hLeft = getHeight(rt->left);
        int hRight = getHeight(rt->right);

        if (hLeft > hRight) return 1 + getHeight(rt->left);
        else return 1 + getHeight(rt->right);
    }

    int getNodeCount(struct Node* rt){
        if(rt == nullptr) return 0;
        return rt->value + getNodeCount(rt->right) + getNodeCount(rt->left);
    }
    
    void deleteValue(int valueToDelete, struct Node* rt){
        if (rt->left->value == valueToDelete){
            struct Node* nodeToDelete = rt->left;
        }
    }

    // To print values from min to max, inorder traversal is suitable
    void printValues(struct Node* rt){
        if (rt == nullptr) return;
        printValues(rt->left);
        std::cout<<rt->value<<" ";
        printValues(rt->right);
   }

   // min,max is (-inf,inf) at root
   bool isBST(struct Node* rt, int minValue, int maxValue){
        if (rt == nullptr) return true;

        if (rt->value > minValue
            and rt->value < maxValue
            and isBST(rt->left, minValue, rt->value)
            and isBST(rt->right, rt->value, maxValue)) return true;
        else return false;
    }

   struct Node* find(int data, struct Node* rt){
        if (rt == nullptr or rt->value == data) return rt;
        else if (rt->value > data) return find(data, rt->left);
        else return find(data, rt->right);
    }

   int getSuccessor(int data, struct Node* rt){
       // search the node
       struct Node* current = find(data, rt);
       if (current == nullptr) return 0;

       // Case 1: node has right subtree
       if (current->right != nullptr) return getMin(current->right);

       // Case 2: no right subtree - walk from root to curr and find deepest ancestor for which curr will be in its left subtree
       else {
            struct Node* successor = nullptr;
            struct Node* ancestor = rt;
            while (ancestor != current){
                if (current->value < ancestor->value){
                    successor = ancestor;
                    ancestor = ancestor->left;
                }
                else {
                    ancestor = ancestor->right;
                }
            }
            return successor->value;
       }


    }

    struct Node* deleteNode(int valueToDelete, struct Node* rt){
        if (rt == nullptr) return rt;
        else if (rt->value > valueToDelete) rt->left = deleteNode(valueToDelete, rt->left);
        else if (rt->value < valueToDelete) rt->right = deleteNode(valueToDelete,rt->right);

        else{
            struct Node* temp;
            // case 1 - delete leaf node
            if (rt->left == nullptr and rt->right == nullptr){
                delete rt;
                return nullptr;
            }
            // case 2.1 - has 1 left child
            else if(rt->right == nullptr){
                temp = rt->left;
                delete rt;
                return temp;
            }
            // case 2.2 - has 1 right child
            else if(rt->left == nullptr){
                temp = rt->right;
                delete rt;
                return temp;
            }
            // case 3 - has 2 children
            else{
                int minRight = getMin(rt->right);
                rt->value = minRight;
                rt->right = deleteNode(minRight, rt->right);
                return rt;
            }
        }


    }
};
