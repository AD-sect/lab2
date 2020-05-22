#pragma once
#include "Dynamic_Array.h"
#include "Sequence.h"

template <typename T>
class ArraySequence : public Sequence<T>
{
protected:
	DynamicArray<T>* m_mas{ nullptr };
	int m_size{ 0 };
public:
	ArraySequence() : Sequence<T>()
	{
		m_mas = new DynamicArray<T>();
		this->m_size = 0;
	}

	ArraySequence(int size) : Sequence<T>()
	{
		m_mas = new DynamicArray<T>(size);
		this->m_size = size;
	}

	ArraySequence(T* items, int size) : Sequence<T>()
	{
		m_mas = new DynamicArray<T>(items, size);
		this->m_size = size;
	}

	virtual ~ArraySequence()
	{
		delete this->m_mas;
		this->m_mas = nullptr;
	}

	ArraySequence(Sequence<T>* seq)
	{
		this->m_mas = new DynamicArray(seq->GetLength());
		for (size_t i(0); i < this->m_mas->GetSize(); ++i)
			this->m_mas->Set(i, seq->Get(i));
	}

	virtual T GetFirst() const override
	{
		if (this->m_size == 0)
			throw IndexOutOfRange();

		return m_mas->Get(0);
	}

	virtual T GetLast() const override
	{

		if (this->m_size == 0)
			throw IndexOutOfRange();

		return m_mas->Get(this->m_size - 1);
	}

	virtual T Get(int index) const override
	{
		if (index < 0 || index == this->m_size || index > this->m_size)
			throw IndexOutOfRange();

		return m_mas->Get(index);
	}

	virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override
	{
		if (startIndex < 0 || endIndex < 0 || startIndex == this->m_size)
			throw IndexOutOfRange();
		if (endIndex == this->m_size || startIndex > this->m_size)
			throw IndexOutOfRange();
		if (endIndex > this->m_size || startIndex > endIndex)
			throw IndexOutOfRange();

		int index(endIndex - startIndex + 1);
		Sequence<T>* getSub = new ArraySequence(0);
		for (int i = 0; i < index; ++i)
			getSub->Prepend(this->m_mas->Get(i + startIndex));

		return getSub;
	}

	virtual int GetLength() const override
	{

		return this->m_size;

	}

	virtual void Append(T item) override
	{
		this->m_mas->Resize(this->m_size + 1);
		T item1 = this->m_mas->Get(0);
		T item2 = 0;
		for (int i(0); i < this->m_size; ++i)
		{
			item2 = item1;
			item1 = this->m_mas->Get(i + 1);
			this->m_mas->Set(i + 1, item2);
		}
		this->m_mas->Set(0, item);




		/*	T* newMas = new ArraySequence(this->m_size + 1);
		newMas[0] = item;
		for (int i = 1; i < this->m_size + 1; ++i)
			newMas[i] = m_mas[i];*/
			//this->m_mas->Write();
	}

	virtual void Prepend(T item) override
	{


		this->m_mas->Resize(this->m_size + 1);
		this->m_size = this->m_size + 1;
		this->m_mas->Set(this->m_size - 1, item);

		//this->m_mas->Write();

	}

	virtual void InsertAt(T item, int index) override
	{
		if (index < 0 || index == this->m_size || index > this->m_size)
			throw IndexOutOfRange();

		ArraySequence<T>* leftMas = new ArraySequence{ 0 };
		for (int i = 0; i < index; ++i)
			leftMas->Prepend(this->m_mas->Get(i));

		leftMas->Prepend(item);


		ArraySequence<T>* rightMas = new ArraySequence(0);
		for (int i = index; i < this->m_size; ++i)
			rightMas->Prepend(m_mas->Get(i));

		ArraySequence<T>* newMas = new ArraySequence(0);
		for (int i = 0; i < leftMas->m_size; ++i)
			newMas->Prepend(leftMas->Get(i));


		for (int i = 0; i < rightMas->m_size; ++i)
			newMas->Prepend(rightMas->Get(i));

		++this->m_size;
		this->m_mas = newMas->m_mas;
	}


	virtual ArraySequence <T>* Concat(Sequence<T>* mas) const override
	{
		int masSize = mas->GetLength();

		ArraySequence <T>* newMas = new ArraySequence(0);
		for (int i = 0; i < this->m_size; ++i)
			newMas->Prepend(this->m_mas->Get(i));

		for (int i = 0; i < masSize; ++i)
			newMas->Prepend(mas->Get(i));

		return newMas;
	}

};
