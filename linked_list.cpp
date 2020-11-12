#include <iostream>

template <class T>
class Node {
public:
	Node<T>* nextNode = nullptr;
	T key;
};

template <class T>
class LinkedList {
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList();
	~LinkedList();
	int length;               // could use
	bool isEmpty();
	void print();
	void pushFront(T value);
	T topFront();
	void popFront();
	void pushBack(T value);
	T topBack();
	void popBack();
	bool find(T value);
	//void erase(T value);
	void addBefore(Node node, T value);   // asume that node is existed, not begin or end of linked list (cause it's same as pushFront and pushBack)
	void addAfter(Node node, T value);		// asume that node is existed, not begin or end of linked list (cause it's same as pushFront and pushBack)
};

template <class T>
LinkedList<T>::LinkedList() {
	length = 0;
	head = nullptr;
	tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node<T>* current = head;
	while (current != nullptr){
		Node<T>* next = current->nextNode;
		delete current;
		current = next;
	}
}

template <class T>
bool LinkedList<T>::isEmpty() {
	if (head == nullptr) return true;
	return false;
}

template <class T>
void LinkedList<T>::pushFront(T value) {
	Node<T>* newNode = new Node<T>;
	newNode->key = value;
	newNode->nextNode = head;
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		head = newNode;
	}
	length++;
}

template <class T>
void LinkedList<T>::print() {
	Node<T>* temp = head;
	while (temp->nextNode != nullptr) {
		std::cout << temp->key << std::endl;
		temp = temp->nextNode;
	}
	std::cout << temp->key << std::endl;
}

template <class T>
void LinkedList<T>::pushBack(T value) {
	Node<T>* newNode = new Node<T>;
	newNode->key = value;
	newNode->nextNode = nullptr;
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->nextNode = newNode;
		tail = newNode;
	}
	length++;
}

template <class T>
T LinkedList<T>::topFront() {
	if (!isEmpty()) return head->key;
	return (T)0;
}

template <class T>
T LinkedList<T>::topBack() {
	if (!isEmpty()) return tail->key;
	return (T)0;
}

template <class T>
void LinkedList<T>::popFront() {
	if (isEmpty()) {
		std::cout << "Empty!"; return;
	}
	else {
		head = head->nextNode;
		if (head == nullptr) tail = nullptr;
	}
	length--;
	return;
}

template <class T>
void LinkedList<T>::popBack() {
	if (isEmpty()) {
		std::cout << "Empty!" << std::endl;
		return;
	}
	if (head == tail) {
		free(head);
		head = nullptr;
		tail = nullptr;
		length--;
		return;
	}
	Node<T>* tempNode = head;
	while (tempNode->nextNode->nextNode != nullptr) {
		tempNode = tempNode->nextNode;
	}
	delete tempNode->nextNode;
	tempNode->nextNode = nullptr;
	tail = tempNode;
	length--;
}

template <class T>
bool LinkedList<T>::find(T value) {
	Node<T>* tempNode = head;
	if (isEmpty()) return false;
	while (tempNode->nextNode != nullptr) {
		if (tempNode->key == value) return true;
	}
	if (tempNode->key == value) return true;
	return false;
}
/*
template <class T>
void LinkedList<T>::erase(T value) {
	Node<T>* tempNode = head;
	Node<T>* preNode;
	if (isEmpty()) return;
	while (tempNode->nextNode != nullptr) {
		preNode = tempNode;
		tempNode = tempNode->nextNode;
		if (tempNode->key == value) {

		}
	}

}
*/

template <class T>
void LinkedList<T>::addAfter(Node node, T value){
	Node<T>* newNode = new Node<T>;
	newNode->key = value;
	newNode->nextNode = node->nextNode;
	node->nextNode = newNode;
}

template<class T>
void LinkedList<T>::addBefore(Node node, T value){
	Node<T>* tempNode = head;
	while (tempNode->nextNode != node){
		tempNode = tempNode->nextNode;
	}
	Node<T>* newNode = new Node<T>;
	newNode->key = value;
	newNode->nextNode = node;
	tempNode->nextNode = newNode;
}


int main() {
	LinkedList<int> ll;
	ll.pushFront(4);
	ll.pushFront(5);
	ll.pushBack(6);
	ll.popBack();
	std::cout << std::boolalpha << ll.isEmpty() << std::endl;
	ll.print();
	std::cout << ll.topFront() << "   " << ll.topBack() << std::endl;
	ll.popFront();
	std::cout << std::boolalpha << ll.find(4) << std::endl;
	return 0;
}