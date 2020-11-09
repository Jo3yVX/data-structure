#include <iostream>

template <class T>
class Node{
public:
    T data;
    T* nextNode;
};

template <class T>
class linkedList(){
public:
    int totalNodes;
    T* head = nullptr;
    T* tail = nullptr;
    linkedList();
    ~linkedList();
    void pushBack(Node n);
    void pushFront(Node n);
    void addAfter(Node origin, Node n);
    void popBack();
    void popFront();
    bool isEmpty();
    int Size();
};
int main()
{

    return 0;
}
