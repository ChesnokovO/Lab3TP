#include "binary.h"

unsigned int Binary::_type = 0;

Binary::Binary() {
}


Binary::~Binary() {

}

void Binary::save(std::ofstream& out) {
	out << _type << std::endl;
	out << _length << std::endl;
	for (size_t i = 0; i < _length; i++) {
		out << _values[i] << std::endl;
	}
}

void Binary::show() {
	std::cout << "Binary: " << std::endl;
	char* max_value = new char[33];
	int temp;
	
	for (size_t j = 0; j < _length; j++) {
		int i = 0;
		temp = _values[j];
		if (temp < 0) {
			temp *= -1;
			temp--;
			for (size_t i = 0; i < 32; i++)	{
				max_value[i] = '1';
			}
			max_value[32] = '\0';
			while (temp != 0)
			{
				if (temp % 2 == 0)
				{
					max_value[i] = '1';
					temp = temp / 2;
				}
				else
				{
					max_value[i] = '0';
					temp = temp / 2;
				}
				i++;
			}
			i = 31;
			for (; i >= 0; i--)
				std::cout << max_value[i];
			std::cout << "\t";
		}
		else {
			while (temp != 0)
			{
				if (temp % 2 == 0)
				{
					max_value[i] = '0';
					temp = temp / 2;
				}
				else
				{
					max_value[i] = '1';
					temp = temp / 2;
				}
				i++;
			}
			max_value[i] = '\0';
			i = i - 1;
			for (; i >= 0; i--)
				std::cout << max_value[i];
			std::cout << "\t";
		}
		max_value[0] = '\0';
		
	}
	std::cout << "\n";

	delete[] max_value;
}