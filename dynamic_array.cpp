#include <iostream>
#include <iomanip>

const int initSize = 5;
const int growth = 2;

template <class T>
class Array {
public:
	T* array;
	int size;
	int capacity;
	Array();
	~Array();
	T Append(T element);   //return appended element
	int getSize();
	bool isFull();
	int Insert(T element, int index);      // insert element to index. Returns 1 if success, 0 if fails (out of index)
	int Delete(int index); //return 1 if success, 0 if fail
	T get(int index);
	bool isEmpty();
	void print();
};

template <class T>
Array<T>::Array() {
	array = new T[initSize];
	size = 0; 
	capacity = initSize;
}

template <class T>
Array<T>::~Array() {
	delete[] array;
}

template <class T>
T Array<T>::Append(T element) {
	if (size < capacity) {                            //array is not full
		*(array + size) = element;
	}
	else {                                           // array is full
		capacity = initSize * growth;
		T* newArray = new T[capacity];
		for (int i = 0; i < size; i++) {
			*(newArray + i) = *(array + i);          //copy all elements to new array
		}
		*(newArray + size) = element;
		array = newArray;
	}
	size++;
	return element;
}

template <class T>
int Array<T>::getSize() {
	return size;
}

template<class T>
bool Array<T>::isFull() {
	if (size == capacity) return true;
	return false;
}


template<class T>
int Array<T>::Insert(T element, int index) {
	if (index >= capacity) return 0;
	if (index >= size) *(array + index) = element;
	for (int i = size; i > index; i--) {
		*(array + i) = *(array + i - 1);
	}
	*(array + index) = element;
	size++;
}


template<class T>
T Array<T>::get(int index) {
	return *(array + index);
}

template<class T>
bool Array<T>::isEmpty() {
	if (size == 0) return true;
	return false;
}

template<class T>
void Array<T>::print() {
	for (int i = 0; i < size; i++) {
		std::cout << *(array + i) << std::endl;
	}
}

template<class T>
int Array<T>::Delete(int index) {
	if (index >= size) return 0;
	for (int i = index; i < size - 1; i++) {
		*(array + i) = *(array + i + 1);
	}
	size--;
	return 1;
}

int main()
{
	Array<int> arr;
	for (int i = 0; i < 7; i++) {
		int t; std::cin >> t;
		arr.Append(t);
	}
	arr.Insert(4, 3);
	arr.print();
	std::cout << "Array size: " <<arr.getSize() << std::endl;	
	std::cout << "Is Empty: " << arr.isEmpty() << std::endl;
	std::cout << "Is full: " << arr.isFull() << std::endl;
	std::cout << "Element at index 4: " << arr.get(4) << std::endl;
	arr.Delete(4);
	arr.print();
	return 0;
}

 