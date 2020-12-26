//Tested in CodeBlock 20.03
#include <bits/stdc++.h>
#include <tr1/functional>
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
    HashNode<K, V>* markDelete;
	HashNode<K, V>** array;  // array of pointers to node(represented by a pointer), so it's a pointer to pointer (2-level pointer)
	HashTable() {
		currentSize = 0;
		maxSize = MAX;
		array = new HashNode<K, V>*[maxSize]; // init an array of HashNode, set all elements to nullptr
		for (int i = 0; i < maxSize; i++) {
			array[i] = NULL;
		}
		markDelete = new HashNode<K,V>(-1, -1);
	}
	~HashTable() {
		delete[] array;
	}

	void insert(K key, V value);
	void del(K key);
	V get(K key);
	bool isEmpty();
	bool isFull();
	void print();
	int hash(K key);
};

template <class K, class V>
int HashTable<K, V>::hash(K key) {
	std::tr1::hash<K> hashObj;  //init a hash func for type K
	int res = hashObj(key);
	res = res % maxSize;
	return res;
}

template <class K, class V>
V HashTable<K, V>::get(K key) {
	int index = hash(key);
	while (array[index] != NULL) {
		if (array[index]->key == key) {
			return array[index]->value;
		}
		index++;
		index = index % maxSize;
	}
	throw 0;
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
		if (array[i] != NULL && array[i]->key != -1) {  //check if empty(null) or an deleted one
			cout << "Index: " << i << "      " << array[i]->key << "		:		" << array[i]->value << endl;
		}
	}
	return;
}

template <class K, class V>
void HashTable<K, V>::insert(K key, V value) {
	if (isFull()) return;
	int count = 0;
	int index = hash(key);
	HashNode<K, V>* newNode = new HashNode<K, V>(key, value);
	while (array[index] != NULL && array[index]->key != -1 && count < maxSize) {
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
	while (array[index] != NULL) {
		if (array[index]->key == key) {
			array[index] = markDelete;
			currentSize--;
			return;
		}
		index = (++index) % maxSize;
	}
	return;
}


int h(int t) {
	std::tr1::hash<int> g;
	return g(t) % 20;
}
int main() {
	HashTable<int, int> table;
    cout << boolalpha << table.isFull() << "           " << table.isEmpty() << endl;
    table.insert(2,2);
    table.insert(34,14);
    table.insert(321, 6);
    table.insert(31, 9);
    table.insert(22, 43);
    table.print();
    table.del(2);
    cout << "----------------------------------------------------" << endl;
    table.print();
    cout << "----------------------------------------------------" << endl;
    cout << table.get(321) << endl;
    //cout << table.get(222) << endl;
    cout << table.currentSize << "   " << table.maxSize;
    table.~HashTable();
	return 0;
}
