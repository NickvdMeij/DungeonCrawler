#pragma once
#include "Room.h"
#include <iostream>

class Array2D
{
public:
	Array2D(); // default constructor
	Array2D(int x_size, int y_size); // preferred constructor
	Array2D(const Array2D& other); // copy constructor
	Array2D(Array2D&& other); // move constructor

	~Array2D(); // destructor (not virtual because this class is not meant to be subclassed)

	Array2D& operator=(const Array2D& other); // copy assignment
	Array2D& operator=(Array2D&& other); // move assignment
	void initArray2D(int x_size1, int y_size1);
										 // storing & retrieving values
	void put(const Room room, int x, int y) { p[index(x, y)] = room; }
	Room get(int x, int y) const { return p[index(x, y)]; }

	bool operator==(const Array2D& other); // equality comparison

	// number of elements
	int size() const { return x_size * y_size; }

	// accessors
	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
private:
	int x_size, y_size;
	Room* p;

	// translation from (x, y) to flat index
	int index(int x, int y) const { return x + y * x_size; }

	// copy initializer, used by copy constructor and copy assignment
	void init_storage(const Array2D& other);

	// cleanup, used by destructor and copy assignment
	void cleanup_storage();
};

