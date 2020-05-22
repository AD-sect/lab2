#pragma once
#include <iostream>
#include <exception>
#include <cmath>
#include <stdlib.h>

class IndexIsNegative : public std::exception
{
public:
	const char* what() const throw ()
	{
		return("Index is negative");
	}
};

class IndexOutOfRange : public std::exception
{
public:
	const char* what() const throw ()
	{
		return("Index out if range");
	}
};

class NodeIsEmpty : public std::exception
{
public:
	const char* what() const throw ()
	{
		return("Node is empty");
	}
};

template <typename T>
class DynamicArray
{
private:
	T* m_mas = nullptr;
	int m_size = 0;
public:

	DynamicArray() = default;

	DynamicArray(int size)
	{
		m_size = size;

		if (m_size < 0)
			throw IndexIsNegative();

		this->m_mas = new T[size];
	}

	DynamicArray(T* m_mas, int count) : DynamicArray(count)
	{
		std::memcpy(this->m_mas, m_mas, count * sizeof(T));
	}

	DynamicArray(DynamicArray<T> const& dynamicArray) : DynamicArray(dynamicArray->m_mas, dynamicArray->m_size) {}

	T Get(int index)
	{
		if (index < 0 || index >= m_size)
			throw IndexOutOfRange();
		//std::cout <<m_mas[index];
		return m_mas[index];
	}

	int GetSize()
	{
		//std::cout << m_size;
		return m_size;
	}

	void Set(int index, T& value)
	{

		if (index < 0 || index >= m_size)
			throw IndexOutOfRange();
		m_mas[index] = value;
	}

	void Resize(int newSize)
	{
		if (newSize < 0)
			throw IndexOutOfRange();

		T* newMas = new T[newSize];
		memcpy(newMas, m_mas, newSize * sizeof(T));
		delete[] m_mas;
		m_mas = newMas;
		m_size = newSize;


		/*for (int i = 0; i < m_size; ++i)
			std::cout << m_mas[i];*/

	}

	void Write()
	{
		for (int i = 0; i < m_size; ++i)
			std::cout << m_mas[i];

	}

	~DynamicArray()
	{
		delete[] m_mas;
		m_size = 0;
	}
};