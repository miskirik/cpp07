#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T *arr;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		Array &operator=(Array const &other);
		~Array();
		T &operator[](unsigned int i);
		unsigned int size() const;
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};


template <typename T>
Array<T>::Array() : arr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &other) : arr(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		delete [] arr;
		arr = new T[other._size];
		_size = other._size;
		for (unsigned int i = 0; i < _size; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete [] arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfRangeException();
	return arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
	return "Index out of range";
}

#endif