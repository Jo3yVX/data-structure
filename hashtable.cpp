#include <iostream>

using namespace std;

const int MAX = 20;

template <class K, class V>
class HashNode {
public:
	K key;
	V value;
	// constructor for node
	HashNode(K key, V value) {
		this->key = key;
		this->value = value;
	}
};

template <class K, class V>
class HashTable {
public:
	int currentSize;  
	int maxSize;
	HashNode<K, V>** array;  // array of pointers to node(represented by a pointer), so it's a pointer to pointer (2-level pointer)
	HashTable() {
		currentSize = 0;
		maxSize = MAX;
		array = new HashNode<K, V>*[maxSize]; // init an array of HashNode, set all elements to nullptr
		for (int i = 0; i < maxSize; i++) {
			array[i] = nullptr;
		}
	}
	~HashTable() {
		delete[] array;
	}
	HashNode<K, V>* markDelete = new HashNode<K, V>(-1, -1);
	void insert(K key, V value);
	void del(K key);
	V get(K key);
	bool isEmpty();
	bool isFull();
	void print();


private:
	int hash(K key);
};

template <class K, class V>
int HashTable<K, V>::hash(K key) {
	std::hash<K> hashObj;  //init a hash func for type K
	auto res = hashObj(key);
	return res;
}

template <class K, class V>
V HashTable<K, V>::get(K key) {
	int index = hash(key);
	while (array[index] != nullptr) {
		if (array[index]->key == key) {
			return array[index]->value;
		}
		index++;
		index = index % maxSize;
	}
	throw "Key doesnt exist";
}

template <class K, class V>
bool HashTable<K, V>::isEmpty() {
	return (currentSize == 0) ? true : false;
}

template <class K, class V>
bool HashTable<K, V>::isFull() {
	return (currentSize == maxSize) ? true : false;
}

template <class K, class V>
void HashTable<K, V>::print() {
	for (int i = 0; i < maxSize; i++) {
		if (array[i] != nullptr && array[i]->key != -1) {  //check if empty(null) or an deleted one
			cout << array[i]->key << "		:		" << array[i]->value << endl;
		}
	}
	return;
}

template <class K, class V>
void HashTable<K, V>::insert(K key, V value) {
	if (isFull()) throw "Unable to insert. Table is full.";
	int count = 0;
	int index = hash(key);
	HashNode<K, V>* newNode = new HashNode<K, V>(key, value);
	while (array[index] != nullptr && array[index]->key != -1 && count < maxSize) {
		index = (++index) % maxSize;
		count++;
	}
	array[index] = newNode;
	currentSize++;
	return;
}

template <class K, class V>
void HashTable<K, V>::del(K key) {
	int index = hash(key);
	while (array[index] != nullptr) {
		if (array[index]->key == key) {
			array[index] = markDelete;
			currentSize--;
			return;
		}
		index = (++index) % maxSize;
	}
	throw "Not exist!";
}

int main() {
	HashTable<int, int>* table = new HashTable<int, int>;
	cout << boolalpha << table->isEmpty() << "		" << table->isFull() << endl;
	table->insert(2, 2);
	table->insert(17, 4);
	table->insert(143, 6);
	table->insert(123, 78);
	table->print();
	cout << boolalpha << table->isEmpty();
	return 0;
}