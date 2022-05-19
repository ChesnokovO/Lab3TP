#pragma once
#include <iostream>
#include <fstream>
#include "correct.h"

class Vector
{
public:
	Vector();
	Vector(std::ifstream& in);
	Vector(const Vector& v);
	~Vector();

	void append();

	unsigned int getCount();

	virtual void show();
	virtual void save(std::ofstream& out);
	void redact();

protected:
	static unsigned int _count;
	int* _values;
	int _length;

private:
	static unsigned int _type;


};

