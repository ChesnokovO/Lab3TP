#include <iostream>
#include "binary.h"
#include "octal.h"


enum Type {
	BINARY,
	OCTAL,
	DECIMAL
};

void init(Vector**& arrays);
void addElem(Vector**& arrays, Vector* temp);
void menu(Vector**& arrays);
void showObjects(Vector**& arrays);
Vector* chooseElem(Vector**& arrays);

Vector* createElem(Vector**& arrays);
void deleteElem(Vector**& arrays, Vector* elem);
void save(Vector**& arrays);


int main() {
	Vector** arrays = nullptr;

	init(arrays);
	menu(arrays);

	return 0;
}


void init(Vector**& arrays) {
	std::ifstream file("data.txt");

	if (!file.is_open() || file.eof() || file.peek() == EOF) {
		std::cout << "File is empty" << std::endl;
		return;
	}

	Vector* temp = nullptr;
	unsigned int len, type;

	file >> len;
	for (size_t i = 0; i < len; i++) {
		file >> type;
		switch (type)
		{
		case BINARY:
			temp = new Binary(file);
			break;

		case OCTAL:
			temp = new Octal(file);
			break;

		case DECIMAL:
			temp = new Vector(file);
			break;

		default:
			break;
		}
		addElem(arrays, temp);
	}
	file.close();
}

void addElem(Vector**& arrays, Vector* elem) {
	if (!elem)
		return;
	if (arrays == nullptr) {
		arrays = new Vector * [1];
		arrays[0] = elem;
	}
	else {
		Vector** newarrays = new Vector * [elem->getCount()];
		unsigned int count = elem->getCount();
		for (size_t i = 0; i < count - 1; i++) {
			newarrays[i] = arrays[i];
		}
		newarrays[count - 1] = elem;
		delete[] arrays;
		arrays = newarrays;
	}

}

void menu(Vector**& arrays) {
	int choice;
	do
	{
		std::cout << "\n\nSelect action:" << std::endl;
		std::cout << "1. Show arrays" << std::endl;
		std::cout << "2. Redact" << std::endl;
		std::cout << "3. Add new object" << std::endl;
		std::cout << "4. Delete object" << std::endl;
		std::cout << "5. Save data" << std::endl;
		std::cout << "6. Exit" << std::endl;


		choice = correct<int>();
		std::cout << "\n";

		switch (choice)
		{
		case 1:
		{
			showObjects(arrays);
		}
		break;

		case 2:
		{
			if (arrays == nullptr) {
				std::cout << "There are no objects to redact" << std::endl;
				break;
			}
			else {
				do {
					std::cout << "\n1. Redact vector\n2. Append element to vector" << std::endl;
					choice = correct<int>();
				} while (choice <= 0 || choice >= 3);
				if (choice == 1) {
					chooseElem(arrays)->redact();
				}
				else {
					chooseElem(arrays)->append();
				}

				
			}
		}
		break;

		case 3:
		{
			addElem(arrays, createElem(arrays));
		}
		break;

		case 4:
		{
			if (arrays == nullptr) {
				std::cout << "There are no objects to delete" << std::endl;
				break;
			}
			else {
				deleteElem(arrays, chooseElem(arrays));
			}
			break;
		}
		case 5:
		{
			if (arrays == nullptr) {
				std::cout << "There are no objects to save" << std::endl;
				break;
			}
			save(arrays);
		}
		break;

		case 6:

			return;
			break;
		default:
			break;
		}

	} while (true);
}

void showObjects(Vector**& arrays) {
	if (arrays == nullptr)
		std::cout << "There no Objects" << std::endl;

	else {
		std::cout << "\n\n";
		for (size_t i = 0; i < arrays[0]->getCount(); i++) {
			std::cout << "\n" << i + 1 << ". " << std::endl;
			arrays[i]->show();
		}
		std::cout << "\n";
	}

}

Vector* chooseElem(Vector**& arrays) {
	showObjects(arrays);

	std::cout << "Select Object" << std::endl;
	unsigned int num;
	do {
		num = correct<unsigned int>();
		num--;

	} while (num < 0 || num >= arrays[0]->getCount());
	return arrays[num];
}

Vector* createElem(Vector**& arrays) {
	int type;
	std::cout << "1. Binary\n2. Octal\n3. Decimal\n" << std::endl;
	type = correct<int>();
	while (type < 1 || type > 3) {
		std::cout << "Invalid value\nTry again" << std::endl;
		type = correct<int>();
	}
	type--;
	Vector* temp = nullptr;
	switch (type)
	{
	case BINARY:
		temp = new Binary();
		break;

	case OCTAL:
		temp = new Octal();
		break;

	case DECIMAL:
		temp = new Vector();
		break;

	default:
		break;
	}
	return temp;
}

void deleteElem(Vector**& arrays, Vector* elem) {
	if (!elem)
		return;
	else if (arrays[0]->getCount() == 1) {
		delete elem;
		delete[] arrays;
		arrays = nullptr;
	}
	else {
		Vector** newarrays = new Vector * [arrays[0]->getCount() - 1];
		Vector** temp = newarrays;
		unsigned int count = elem->getCount();
		for (size_t i = 0; i < count; i++) {
			if (!(arrays[i] == elem)) {
				*(temp++) = arrays[i];
			}

		}
		delete elem;
		delete[] arrays;
		arrays = newarrays;
	}
}

void save(Vector**& arrays) {
	std::ofstream file("data.txt", std::ios_base::trunc);

	if (!file.is_open())
		return;

	unsigned int count = arrays[0]->getCount();
	file << count << "\n";

	for (size_t i = 0; i < count; i++) {
		arrays[i]->save(file);
	}
}