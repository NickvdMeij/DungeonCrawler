#include "stdafx.h"
#include "Array2D.h"

using namespace std;

Array2D::Array2D()
	: x_size{ 0 }, y_size{ 0 }, p{ nullptr }
{
	//cerr << "default construction\n";
}

Array2D::Array2D(int x_size, int y_size)
	: x_size{ x_size }, y_size{ y_size }, p{ nullptr }
{
	//cerr << "preferred construction\n";
	p = new Room[size()];
}

Array2D::Array2D(const Array2D& other)
	: x_size{ other.x_size }, y_size{ other.y_size }, p{ nullptr }
{
	//cerr << "copy construction\n";
	init_storage(other);
}

Array2D::Array2D(Array2D&& other)
	: x_size{ other.x_size }, y_size{ other.y_size }, p{ other.p }
{
	//cerr << "move construction\n";
	other.p = nullptr;
}

Array2D::~Array2D()
{
	cleanup_storage();
}

Array2D& Array2D::operator=(const Array2D& other)
{
	//cerr << "copy assignment\n";
	if (this != &other) {
		cleanup_storage();
		x_size = other.x_size;
		y_size = other.y_size;
		init_storage(other);
	}
	return *this;
}

Array2D& Array2D::operator=(Array2D&& other)
{
	//cerr << "move assignment\n";
	if (this != &other) {
		cleanup_storage();
		x_size = other.x_size;
		y_size = other.y_size;
		p = other.p;
		other.p = nullptr;
	}
	return *this;
}

void Array2D::initArray2D(int x_size1, int y_size1)
{
	x_size = x_size1;
	y_size = y_size1;
	p = new Room[size()];
}

bool Array2D::operator==(const Array2D& other)
{
	if (other.x_size != x_size || other.y_size != y_size ) return false;
	bool equal{ true };
	for (int i{ 0 }; i < size(); ++i) {
		if (other.p[i] != p[i]) {
			equal = false;
			break;
		}
	}
	return equal;
}

void Array2D::init_storage(const Array2D& other)
{
	int sz{ size() };
	p = new Room[sz];
	for (int i{ 0 }; i < sz; ++i) {
		p[i] = other.p[i];
	}
}

void Array2D::cleanup_storage()
{
	delete[] p;
	p = nullptr;
}
