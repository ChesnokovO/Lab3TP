#include "octal.h"

unsigned int Octal::_type = 1;

Octal::Octal() {
}

Octal::~Octal()
{
}

void Octal::save(std::ofstream& out) {
	out << _type << std::endl;
	out << _length << std::endl;
	for (size_t i = 0; i < _length; i++) {
		out << _values[i] << std::endl;
	}
}


void Octal::show() {
	std::cout << "Octal: " << std::endl;

	int temp;
	for (size_t j = 0; j < _length; j++) {
		temp = _values[j];
		
		int rem, i = 1, octalNumber = 0;
		while (temp != 0) {
			rem = temp % 8;
			temp /= 8;
			octalNumber += rem * i;
			i *= 10;
		}


		std::cout << octalNumber << "\t";
	}
	std::cout << "\n";

	

}