#include <iostream>
#include "Container.h"
#include <time.h>

class ParentClass {
protected: 
	int field;
public:
	ParentClass() {
		field = 0;
	}
	int getter() {
		return field;
	}
	void setter(int field) {
		this->field = field;
	}
};

class ChildClass: public ParentClass {
public:
	ChildClass() : ParentClass() {
		field = 1;
	}
};

int main() {
	Container <ParentClass> container;
	srand(time(0));
	int count = 100;
	double timer = 0;
	clock_t start = clock();
	
	while (count < 10001){
		for (int i = 0; i < count; i++) {
			switch (rand() % 4) {
			case 0:
				container.addObject(rand() % container.getSize(), new ChildClass()); // добавление элемента
				std::cout << "addObject" << "\n";
				break;
			case 1:
				container.deleteObject(rand() % container.getSize()); // удаление
				std::cout << "deleteObject" << "\n";
				break;
			case 2:
				container.setObject(rand() % container.getSize(), new ChildClass()); // setter
				std::cout << "setObject" << "\n";
				break;
			case 3:
				container.getObject(rand() % container.getSize()); // getter
				std::cout << "getObject" << "\n";
				break;
			}
		}
		clock_t end = clock();
		timer += (double)(end - start) / CLOCKS_PER_SEC;
		std::cout.precision(15);
		std::cout.setf(std::ios::showpoint);
		std::cout << count << "		" << timer << "\n";
		system("pause");
		count *= 10;
	}
	return 0;
}


