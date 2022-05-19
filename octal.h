#pragma once
#include "vector.h"


class Octal : public Vector
{
public:
	Octal();
	Octal(std::ifstream& in) : Vector(in) {};

	~Octal();

	void show() override;
	void save(std::ofstream& out) override;

private:
	static unsigned int _type;

};

