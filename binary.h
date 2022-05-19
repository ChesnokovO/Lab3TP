#pragma once
#include "vector.h"

class Binary : public Vector
{
public:
	Binary();

	Binary(std::ifstream& in) : Vector(in) {};
	~Binary();

	void show() override;
	void save(std::ofstream& out) override;

private:
	static unsigned int _type;

};
