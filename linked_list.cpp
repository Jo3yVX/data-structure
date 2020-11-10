#include <iostream>

template <class T>
class Node {
	T* nextNode = nullptr;
	T key;
};

template <class T>
class LinkedList {
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList();
	~LinkedList();
	int length;
	bool isEmpty();
	
	void pushFront(T value);
	T topFront();
	void popFront();
	void pushBack(T value);
	T topBack();
	void popBack();
	bool find(T value);
	void erase(T value);
	void addBefore(Node node, T value);
	void addAfter(Node node, T value);
	
};

template <class T>
LinkedList<T>::LinkedList() {
	length = 0;
	head = nullptr;
	tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {

}

template <class T>
bool LinkedList<T>::isEmpty() {
	if (head == nullptr) return true;
	return false;
}

template <class T>
void LinkedList<T>::pushFront(T value) {
	Node* newNode = new Node;
	newNode->key = value;
	if (this->isEmpty()) {
		
	}
}

int main() {
	LinkedList<int> ll;
	std::cout << std::boolalpha << ll.isEmpty() << std::endl;
	return 0;
}