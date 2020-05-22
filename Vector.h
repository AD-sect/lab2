#pragma once
#include <cmath>
#include "Sequence.h"
#include "ArraySequence.h"
#include <stdlib.h>

template <typename T>
class Vector
{
private:
	Sequence<T>* vector{ nullptr };
public:
	Vector() = default;

	Vector(int size)
	{
		this->vector = new ArraySequence<T>(size);

	}

	Vector(T* items, int size)
	{
		this->vector = new ArraySequence<T>(items, size);
	}

	~Vector()
	{
		if (this->vector != nullptr)
		{
			delete this->vector;
			this->vector = nullptr;
		}
	}

	Vector(const Vector<T>* vector)
	{
		Vector<T> newVector = new Vector<T>{ 0, 0 };

		for (int i(0); i < &(vector).GetLength(); ++i)
			newVector->vector->Prepend(&(vector).Get(i));
	}

	int GetLength()
	{
		return this->vector->GetLength();
	}

	T Get(int i)
	{
		return this->vector->Get(i);
	}

	/*friend Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2)
	{
		Vector<T> subVec = new Vector<T>(0);

		for (size_t i(0); i < v1.Size(); ++i)
			subVec->vector->Prepend(v1->Get(i) + v2.Get(i));

		return subVec;
	}*/

	Vector<T>* Add(Vector<T>& v)
	{
		if (this->vector->GetLength() != v.GetLength())
			throw IndexOutOfRange();

		Vector<T>* addVec = new Vector<T>{ 0 };

		for (int i(0); i < this->vector->GetLength(); ++i)
			addVec->vector->Prepend(this->vector->Get(i) + v.Get(i));

		return addVec;
	}

	Vector<T>* SkalMultipy(T skalar)
	{
		Vector<T>* skalVec = new Vector<T>{ 0 };
		for (int i(0); i < this->vector->GetLength(); ++i)
			skalVec->vector->Prepend(this->vector->Get(i) * skalar);

		return skalVec;
	}

	double Norma()
	{
		double norma{ 0 };

		for (int i(0); i < this->vector->GetLength(); ++i)
			norma += pow(this->vector->Get(i), 2);

		if (norma == 0)
			return norma;
		else
			return sqrt(norma);
	}

	T Multipy(Vector<T>& v)
	{
		if (this->vector->GetLength() != v.GetLength())
			throw IndexOutOfRange();

		T rez{ 0 };

		for (int i(0); i < this->vector->GetLength(); ++i)
			rez += this->vector->Get(i) * v.Get(i);

		return rez;
	}

	void Print()
	{
		for (int i(0); i < this->vector->GetLength(); ++i)
			std::cout << this->vector->Get(i) << " ";
	}
};

