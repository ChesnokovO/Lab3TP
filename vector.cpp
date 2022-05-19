#include "vector.h"

unsigned int Vector::_count = 0;
unsigned int Vector::_type = 2;

Vector::Vector() {

	do {
		std::cout << "Enter the length" << std::endl;
		_length = correct<int>();
	} while (_length <= 0);

	_values = new int[_length];
	for (int i = 0; i < _length; i++) {
		std::cout << i << ". ";
		_values[i] = correct<int>();
	}
	_count++;
}
Vector::Vector(std::ifstream& in) {
	in >> _length;
	_values = new int[_length];
	for (int i = 0; i < _length; i++) {
		in >> _values[i];
	}
	_count++;
}

Vector::Vector(const Vector& v) {
	_length = v._length;
	_values = new int[_length];
	for (int i = 0; i < _length; i++) {
		_values[i] = v._values[i];
	}
	_count++;
}

Vector::~Vector() {
	delete[] _values;
	_length = 0;
	_count--;
}

void Vector::save(std::ofstream& out) {
	out << _type << std::endl;
	out << _length << std::endl;;
	for (int i = 0; i < _length; i++) {
		out << _values[i] << std::endl;
	}
}

void Vector::redact() {
	std::cout << "Now: " << std::endl;
	Vector::show();

	std::cout << "\n\n\nWill: " << std::endl;
	for (int i = 0; i < _length; i++) {
		std::cout << i + 1 << ". ";
		_values[i] = correct<int>();
	}
}

void Vector::show() {
	std::cout << "Decimal: " << std::endl;
	for (int i = 0; i < _length; i++)	{
		std::cout << _values[i] << "\t";
	}
	std::cout << "\n";
}


unsigned int Vector::getCount() {
	return _count;
}

void Vector::append() {
	if (_length > 0) {
		std::cout << "\n\n\nNow: " << std::endl;


		for (int i = 0; i < _length; i++) {
			std::cout << _values[i] << "\t";
		}
		std::cout << "\n\n";
	}
	

	std::cout << "Enter the element" << std::endl;
	int val = correct<int>();
	if (_length == 0) {
		_values = new int[1];
		_values[0] = val;
		_length++;
	}
	else {
		_values = static_cast<int*>(std::realloc(_values, ++_length * sizeof(int)));
		if (_values == NULL) {
			std::cout << "Data is corrupted" << std::endl;
			return;
		}
		_values[_length - 1] = val;
	}
	
}