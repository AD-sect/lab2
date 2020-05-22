#pragma once
#include "vector.h"

template <typename T>
Vector<T>* InputVector()
{
	T* items(0);
	int length(0);

	std::cout << "Write the length of vector : ";
	std::cin >> length;

	if (length < 0)
	{
		std::cout << "Length can't be negative!";
		exit(1);
	}

	items = new T[length];
	std::cout << "Write the elements of vector :" << " ";
	for (int i(0); i < length; ++i)
		std::cin >> items[i];
	std::cout << "" << std::endl;

	Vector<T>* vector = new Vector<T>{ items, length };
	delete[] items;

	return vector;
}

void Menu()
{
	std::cout << "" << std::endl;
	std::cout << " Choose the operation:  " << std::endl;
	std::cout << "" << std::endl;
	std::cout << " 1.Addition" << std::endl;
	std::cout << " 2.Multiplication" << std::endl;
	std::cout << " 3.Multiplication on scalar" << std::endl;
	std::cout << " 4.Norma" << std::endl;
	std::cout << " 5.Test result" << std::endl;
	std::cout << "" << std::endl;
}



template<typename T>
void Interface()
{
	Vector<T>* vector1 = new Vector<T>{ 0 };
	Vector<T>* vector2 = new Vector<T>{ 0 };
	T scalar(0);

	Menu();
	std::cout << "Choose : ";
	int choose(0);
	std::cin >> choose;
	std::cout << " " << std::endl;

	if ((choose > 5) || (choose < 1))
	{
		std::cout << "Choosed number is wrong";
		exit(5);
	}

	switch (choose)
	{
	case 1:

		std::cout << "The first vector: " << std::endl << "" << std::endl;
		vector1 = InputVector<T>();
		std::cout << "The second vector: " << std::endl << "" << std::endl;
		vector2 = InputVector<T>();

		std::cout << "The rezult of the addition : ";
		vector1->Add(*(vector2))->Print();
		std::cout << "" << std::endl;
		break;

	case 2:

		std::cout << "The first vector: " << std::endl << "" << std::endl;
		vector1 = InputVector<T>();
		std::cout << "The second vector: " << std::endl << "" << std::endl;
		vector2 = InputVector<T>();

		std::cout << "The rezult of the multiplication : ";
		std::cout << vector1->Multipy(*(vector2));
		std::cout << "" << std::endl;
		break;

	case 3:

		std::cout << "The first vector: " << std::endl << "" << std::endl;
		vector1 = InputVector<T>();

		std::cout << "Write the scalar: ";
		std::cin >> scalar;

		std::cout << "The rezult of the multiplication on scalar : ";
		vector1->SkalMultipy(scalar)->Print();
		std::cout << "" << std::endl;
		break;

	case 4:

		std::cout << "The first vector: " << std::endl << "" << std::endl;
		vector1 = InputVector<T>();

		std::cout << "The rezult of the norma : ";
		std::cout << vector1->Norma();
		std::cout << "" << std::endl;
		break;

	case 5:

		TestVectorAdd();
		TestVectorMultipy();
		TestVectorNorma();
		TestVectorSkalMultyply();
		break;

	default:

		std::cout << "Choosed number is wrong" << std::endl << "" << std::endl;
	}

}
