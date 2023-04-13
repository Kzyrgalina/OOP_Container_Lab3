#pragma once
#include <iostream>

template <class T> class Container {
private:
	T* arr; // указатель на массив
	int size; // размер

public:
	Container() { // конструктор без параметров
		size = 1;
		arr = new T[size];
	}
	Container(int field) { // конструктор с параметром
		size = field;
		arr = new T[size];
	}
	Container(const Container& contCopy) { // конструктор дл€ копировани€
		size = contCopy.size;
		arr = new T[size];
		for (int i = 0; i < size; i++) {
			arr[i] = contCopy.arr[i];
		}
	}
	~Container() {
		delete[] arr;
	}

	void addObject(int index, T* field); // добавить новый объект
	T* deleteObject(int index); // удалить объект (возвращает объект)
	void setObject(int index, T* field); // присвоить значение объекту
	T* getObject(int index); // получить объект 
	int getSize(); // размер массива
};

template <class T> int Container<T> :: getSize() {
	return size;
}

template <class T> void Container<T> :: addObject(int index, T* field) {
	int ind = index;
	if (ind < 0){ // индекс меньше 0
		ind = 0;
	}
	if (ind > size){ // индекс больше размера контейнера
		ind = size;
	}

	T* newarr = new T[size + 1];
	for (int i = 0; i < ind; i++) {
		newarr[i] = arr[i];
	}
	newarr[ind] = *field;
	for (int i = ind; i < size; i++) {
		newarr[i + 1] = arr[i];
	}
	delete[] arr; // освобождаем пам€ть от старого массива
	arr = newarr;
	size++; // увеличиваем размер массива
}

template <class T> T* Container<T> ::deleteObject(int index) {
	int ind = index;
	if (ind < 0) { // индекс меньше 0
		ind = 0;
	}
	if (ind >= size) { // индекс больше размера контейнера
		ind = size - 1;
	}
	if (size == 1) { // контейнер пустой
		return nullptr;
	}

	T* newarr = new T[size - 1];
	T elt = arr[ind]; 
	for (int i = 0; i < ind; i++) {
		newarr[i] = arr[i];
	}
	for (int i = ind + 1; i < size; i++) {
		newarr[i - 1] = arr[i];
	}
	delete[] arr; // освобождаем пам€ть от старого массива
	arr = newarr;
	size--;
	return &elt;
}

template <class T> void Container<T> ::setObject(int index, T* field) {
	int ind = index;
	if (ind <= 0 ) {
		arr[0] = *field;
	} else if (ind >= size) {
		arr[size - 1] = *field;
	}
	else
		arr[ind] = *field;
}

template <class T> T* Container<T> ::getObject(int index) {
	int ind = index;
	if (ind <= 0) {
		return &arr[0];
	}
	if (ind >= size) {
		return &arr[size - 1];
	}
	return &arr[ind];
}


