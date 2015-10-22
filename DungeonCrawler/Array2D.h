#pragma once
#include "Room.h"
#include <iostream>

class Array2D
{
public:
	Array2D();
	Array2D(); // default constructor
	Array2D(size_t x_size, size_t y_size); // preferred constructor
	Array2D(const Array2D& other); // copy constructor
	Array2D(Array2D&& other); // move constructor

	~Array2D(); // destructor (not virtual because this class is not meant to be subclassed)

	Array2D& operator=(const Array2D& other); // copy assignment
	Array2D& operator=(Array2D&& other); // move assignment
	void initArray2D(size_t x_size1, size_t y_size1);
										 // storing & retrieving values
	void put(const Room room, size_t x, size_t y) { p[index(x, y)] = room; }
	Room get(size_t x, size_t y) const { return p[index(x, y)]; }

	bool operator==(const Array2D& other); // equality comparison

	// number of elements
	size_t size() const { return x_size * y_size; }

	// accessors
	size_t get_x_size() const { return x_size; }
	size_t get_y_size() const { return y_size; }
private:
	size_t x_size, y_size;
	Room* p;

	// translation from (x, y) to flat index
	size_t index(size_t x, size_t y) const { return x + y * x_size; }

	// copy initializer, used by copy constructor and copy assignment
	void init_storage(const Array2D& other);

	// cleanup, used by destructor and copy assignment
	void cleanup_storage();
};

