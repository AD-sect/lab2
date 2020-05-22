#pragma once

#include "Vector.h"
#include <assert.h>


void TestVectorAdd()
{
	// тест для int
	int items1[5]{ 1, 2, 3, 4, 5 };
	int s1(5);

	int items2[4]{ 0 , 0, 0, 0 };
	int s2(4);

	int items3[6]{ 6, 7, 8, 9, 10, 11 };
	int s3(6);

	int items4[4]{ -15, 0, -99, -62 };
	int s4(4);

	int items5[5]{ 3, 0, 99, 62, 1 };
	int s5(5);

	int items6[4]{ 3, 7, 99, 73 };
	int s6(4);


	Vector<int> v1{ items1, s1 };
	Vector<int> v2{ items2, s2 };
	Vector<int> v3{ items3, s3 };
	Vector<int> v4{ items4, s4 };
	Vector<int> v5{ items5, s5 };
	Vector<int> v6{ items6, s6 };

	assert(v1.GetLength() == s1);
	assert(v2.GetLength() == s2);
	assert(v3.GetLength() == s3);
	assert(v4.GetLength() == s4);
	assert(v5.GetLength() == s5);
	assert(v6.GetLength() == s6);

	assert(v1.Get(0) == 1);
	assert(v1.Get(1) == 2);
	assert(v1.Get(2) == 3);
	assert(v1.Get(3) == 4);
	assert(v1.Get(4) == 5);
	assert(v2.Get(0) == 0);
	assert(v4.Get(0) == -15);
	assert(v4.Get(1) == 0);
	assert(v4.Get(2) == -99);
	assert(v4.Get(3) == -62);

	Vector<int>* add1{ v1.Add(v5) }; //2 положительных
	Vector<int>* add2{ v4.Add(v6) };// полож и отр 
	Vector<int>* add3{ v4.Add(v4) };//2 отр
	Vector<int>* add4{ v2.Add(v6) };//0 + положит
	Vector<int>* add5{ v2.Add(v4) };// 0 + отриц
	Vector<int>* add6{ v2.Add(v2) };//0 + 0

	//тест сложения

	//2 положительных
	assert(add1->GetLength() == s1);
	assert(add1->Get(0) == 4);
	assert(add1->Get(1) == 2);
	assert(add1->Get(2) == 102);
	assert(add1->Get(3) == 66);
	assert(add1->Get(4) == 6);

	//2 отридцательных
	assert(add2->GetLength() == s4);
	assert(add2->Get(0) == -12);
	assert(add2->Get(1) == 7);
	assert(add2->Get(2) == 0);
	assert(add2->Get(3) == 11);

	//положительное и отридцательное 
	assert(add3->GetLength() == s4);
	assert(add3->Get(0) == -30);
	assert(add3->Get(1) == 0);
	assert(add3->Get(2) == -198);
	assert(add3->Get(3) == -124);

	//0 + положитeльное
	assert(add4->GetLength() == s4);
	assert(add4->Get(0) == 3);
	assert(add4->Get(1) == 7);
	assert(add4->Get(2) == 99);
	assert(add4->Get(3) == 73);

	// 0 + отрицательное
	assert(add5->GetLength() == s4);
	assert(add5->Get(0) == -15);
	assert(add5->Get(1) == 0);
	assert(add5->Get(2) == -99);
	assert(add5->Get(3) == -62);

	// 0 + 0
	assert(add6->GetLength() == s2);
	assert(add6->Get(0) == 0);
	assert(add6->Get(1) == 0);
	assert(add6->Get(2) == 0);
	assert(add6->Get(3) == 0);

	std::cout << "Test add (int): success." << std::endl;

	// тест для double
	double items1D[5]{ 1.1, 2.2, 3.3, 4.4, 5.5 };
	int s1D(5);

	double items2D[4]{ 0 , 0, 0, 0 };
	int s2D(4);

	double items3D[6]{ 6.11, 7.11, 8.11, 9.11, 10.11, 11.11 };
	int s3D(6);

	double items4D[4]{ -15.5, 0, -99.9, -62.2 };
	int s4D(4);

	double items5D[5]{ 3.1, 0, 99.1, 62.1, 1.1 };
	int s5D(5);

	double items6D[4]{ 3.3, 7.4, 99.58, 73.03 };
	int s6D(4);


	Vector<double> v1D{ items1D, s1D };
	Vector<double> v2D{ items2D, s2D };
	Vector<double> v3D{ items3D, s3D };
	Vector<double> v4D{ items4D, s4D };
	Vector<double> v5D{ items5D, s5D };
	Vector<double> v6D{ items6D, s6D };

	assert(v1D.GetLength() == s1D);
	assert(v2D.GetLength() == s2D);
	assert(v3D.GetLength() == s3D);
	assert(v4D.GetLength() == s4D);
	assert(v5D.GetLength() == s5D);
	assert(v6D.GetLength() == s6D);

	assert(v1D.Get(0) == 1.1);
	assert(v1D.Get(1) == 2.2);
	assert(v1D.Get(2) == 3.3);
	assert(v1D.Get(3) == 4.4);
	assert(v1D.Get(4) == 5.5);
	assert(v2D.Get(0) == 0);
	assert(v4D.Get(0) == -15.5);
	assert(v4D.Get(1) == 0);
	assert(v4D.Get(2) == -99.9);
	assert(v4D.Get(3) == -62.2);

	Vector<double>* add1D{ v1D.Add(v5D) }; //2 положительных
	Vector<double>* add2D{ v4D.Add(v6D) };// полож и отр 
	Vector<double>* add3D{ v4D.Add(v4D) };//2 отр
	Vector<double>* add4D{ v2D.Add(v6D) };//0 + положит
	Vector<double>* add5D{ v2D.Add(v4D) };// 0 + отриц
	Vector<double>* add6D{ v2D.Add(v2D) };//0 + 0

	//тест сложения

	//2 положительных
	assert(add1D->GetLength() == s1D);
	assert((add1D->Get(0) - 4.2) <= 0.001);
	assert((add1D->Get(1) - 2.2) <= 0.001);
	assert((add1D->Get(2) - 102.4) <= 0.001);
	assert((add1D->Get(3) - 66.5) <= 0.001);
	assert((add1D->Get(4) - 6.6) <= 0.001);

	// положит и отриц
	assert(add2D->GetLength() == s4D);
	assert((add2D->Get(0) - (-12.2)) <= 0.001);
	assert((add2D->Get(1) - 7.4) <= 0.001);
	assert((add2D->Get(2) - (-0.32)) <= 0.001);
	assert((add2D->Get(3) - 10.83) < 0.001);

	//2 отридцат
	assert(add3D->GetLength() == s4D);
	assert((add3D->Get(0) - (-31)) <= 0.001);
	assert(add3D->Get(1) == 0);
	assert((add3D->Get(2) - (-199.8)) <= 0.001);
	assert((add3D->Get(3) - (-124.4)) <= 0.001);

	//0 + положитeльное
	assert(add4D->GetLength() == s4D);
	assert((add4D->Get(0) - 3.3) <= 0.001);
	assert((add4D->Get(1) - 7.4) <= 0.001);
	assert((add4D->Get(2) - 99.58) <= 0.001);
	assert((add4D->Get(3) - 73.03) <= 0.001);

	// 0 + отрицательное
	assert(add5D->GetLength() == s4D);
	assert((add5D->Get(0) - (-15 / 5)) <= 0.001);
	assert(add5D->Get(1) == 0);
	assert((add5D->Get(2) - (-99.9)) <= 0.001);
	assert((add5D->Get(3) - (-62.2)) <= 0.001);

	// 0 + 0
	assert(add6D->GetLength() == s2D);
	assert(add6D->Get(0) == 0);
	assert(add6D->Get(1) == 0);
	assert(add6D->Get(2) == 0);
	assert(add6D->Get(3) == 0);

	std::cout << "Test add (double): success." << std::endl;

}


void TestVectorSkalMultyply()
{
	int items1[5]{ 1, 2, 3, 4, 5 };
	int s1(5);

	int items2[4]{ 0 , 0, 0, 0 };
	int s2(4);

	int items3[4]{ -15, 0, -99, -62 };
	int s3(4);

	Vector<int> v1{ items1, s1 };
	Vector<int> v2{ items2, s2 };
	Vector<int> v3{ items3, s3 };

	int skal1(5);
	int skal2(-5);
	int skal3(0);

	Vector<int>* skalMul1{ v1.SkalMultipy(skal1) };//положит на положит
	Vector<int>* skalMul2{ v1.SkalMultipy(skal2) };// положит на отриц
	Vector<int>* skalMul3{ v1.SkalMultipy(skal3) };// на ноль

	Vector<int>* skalMul4{ v3.SkalMultipy(skal1) };//отриц на положит
	Vector<int>* skalMul5{ v3.SkalMultipy(skal2) };// отриц на отриц
	Vector<int>* skalMul6{ v3.SkalMultipy(skal3) };// на ноль
	Vector<int>* skalMul7{ v2.SkalMultipy(skal3) };// ноль на ноль

	//положит на положит
	assert(skalMul1->Get(0) == 5);
	assert(skalMul1->Get(1) == 10);
	assert(skalMul1->Get(2) == 15);
	assert(skalMul1->Get(3) == 20);
	assert(skalMul1->Get(4) == 25);

	// положит на отриц
	assert(skalMul2->Get(0) == -5);
	assert(skalMul2->Get(1) == -10);
	assert(skalMul2->Get(2) == -15);
	assert(skalMul2->Get(3) == -20);
	assert(skalMul2->Get(4) == -25);

	// на ноль
	assert(skalMul3->Get(0) == 0);
	assert(skalMul3->Get(1) == 0);
	assert(skalMul3->Get(2) == 0);
	assert(skalMul3->Get(3) == 0);
	assert(skalMul3->Get(4) == 0);

	//отриц на положит
	assert(skalMul4->Get(0) == -75);
	assert(skalMul4->Get(1) == 0);
	assert(skalMul4->Get(2) == -495);
	assert(skalMul4->Get(3) == -310);

	// отриц на отриц
	assert(skalMul5->Get(0) == 75);
	assert(skalMul5->Get(1) == 0);
	assert(skalMul5->Get(2) == 495);
	assert(skalMul5->Get(3) == 310);

	// на ноль
	assert(skalMul6->Get(0) == 0);
	assert(skalMul6->Get(1) == 0);
	assert(skalMul6->Get(2) == 0);
	assert(skalMul6->Get(3) == 0);

	// ноль на ноль
	assert(skalMul7->Get(0) == 0);
	assert(skalMul7->Get(1) == 0);
	assert(skalMul7->Get(2) == 0);
	assert(skalMul7->Get(3) == 0);

	std::cout << "Test skalar (int) : success." << std::endl;

	double items1D[5]{ 1.1, 2.2, 3.3, 4.4, 5.5 };
	int s1D(5);

	double items2D[4]{ 0 , 0, 0, 0 };
	int s2D(4);

	double items3D[4]{ -15.5, 0, -99.9, -62.2 };
	int s3D(4);

	Vector<double> v1D{ items1D, s1D };
	Vector<double> v2D{ items2D, s2D };
	Vector<double> v3D{ items3D, s3D };

	double skal1D(5.1);
	double skal2D(-5.1);
	double skal3D(0);

	Vector<double>* skalMul1D{ v1D.SkalMultipy(skal1D) };//положит на положит
	Vector<double>* skalMul2D{ v1D.SkalMultipy(skal2D) };// положит на отриц
	Vector<double>* skalMul3D{ v1D.SkalMultipy(skal3D) };// на ноль

	Vector<double >* skalMul4D{ v3D.SkalMultipy(skal1D) };//отриц на положит
	Vector<double>* skalMul5D{ v3D.SkalMultipy(skal2D) };// отриц на отриц
	Vector<double>* skalMul6D{ v3D.SkalMultipy(skal3D) };// на ноль
	Vector<double>* skalMul7D{ v2D.SkalMultipy(skal3D) };// ноль на ноль

	//положит на положит
	assert((skalMul1D->Get(0) - 5.61) <= 0.001);
	assert((skalMul1D->Get(1) - 11.22) <= 0.001);
	assert((skalMul1D->Get(2) - 16.86) <= 0.001);
	assert((skalMul1D->Get(3) - 22.44) <= 0.001);
	assert((skalMul1D->Get(4) - 28.05) <= 0.001);

	// положит на отриц
	assert((skalMul2D->Get(0) - (-5.61)) <= 0.001);
	assert((skalMul2D->Get(1) - (-11.21)) <= 0.001);
	assert((skalMul2D->Get(2) - (-16.83)) <= 0.001);
	assert((skalMul2D->Get(3) - (-22.44)) <= 0.001);
	assert((skalMul2D->Get(4) - (-28.05)) <= 0.001);

	// на ноль
	assert(skalMul3D->Get(0) == 0);
	assert(skalMul3D->Get(1) == 0);
	assert(skalMul3D->Get(2) == 0);
	assert(skalMul3D->Get(3) == 0);
	assert(skalMul3D->Get(4) == 0);

	//отриц на положит
	assert((skalMul4D->Get(0) - (-79.05)) <= 0.001);
	assert(skalMul4D->Get(1) == 0);
	assert((skalMul4D->Get(2) - (-509.49)) <= 0.001);
	assert((skalMul4D->Get(3) - (-317.22)) <= 0.001);

	// отриц на отриц
	assert((skalMul5D->Get(0) - 79.05) <= 0.001);
	assert(skalMul5D->Get(1) == 0);
	assert((skalMul5D->Get(2) - 509.49) <= 0.001);
	assert((skalMul5D->Get(3) - 317.22) <= 0.001);


	// на ноль
	assert(skalMul6D->Get(0) == 0);
	assert(skalMul6D->Get(1) == 0);
	assert(skalMul6D->Get(2) == 0);
	assert(skalMul6D->Get(3) == 0);

	// ноль на ноль
	assert(skalMul7D->Get(0) == 0);
	assert(skalMul7D->Get(1) == 0);
	assert(skalMul7D->Get(2) == 0);
	assert(skalMul7D->Get(3) == 0);

	std::cout << "Test skalar (double) : success." << std::endl;

}

void TestVectorNorma()
{

	int items1[5]{ 1, 2, 3, 4, 5 };
	int s1(5);

	int items2[4]{ 0 , 0, 0, 0 };
	int s2(4);

	int items3[4]{ -15, 0, -99, -62 };
	int s3(4);

	int items4[1]{ 6 };
	int s4(1);

	Vector<int> v1{ items1, s1 };
	Vector<int> v2{ items2, s2 };
	Vector<int> v3{ items3, s3 };
	Vector<int> v4{ items4, s4 };

	double norma1{ v1.Norma() };// положительного вектора
	double norma2{ v2.Norma() };//нулевого вектора
	double norma3{ v3.Norma() };//отридцательного вектора
	double norma4{ v4.Norma() };//единичного вектора

	assert((norma1 - 7.4162) <= 0.0001);
	assert(norma2 == 0);
	assert((norma3 - 117.7709) <= 0.0001);
	assert(norma4 == 6);

	std::cout << "Test norma (int) : success." << std::endl;

	double items1D[5]{ 1.1, 2.2, 3.3, 4.4, 5.5 };
	int s1D(5);

	double items2D[4]{ 0 , 0, 0, 0 };
	int s2D(4);

	double items3D[4]{ -15.5, 0, -99.1, -62.2 };
	int s3D(4);

	double items4D[1]{ 6.1 };
	int s4D(1);

	Vector<double> v1D{ items1D, s1D };
	Vector<double> v2D{ items2D, s2D };
	Vector<double> v3D{ items3D, s3D };
	Vector<double> v4D{ items4D, s4D };

	double norma1D{ v1D.Norma() };// положительного вектора
	double norma2D{ v2D.Norma() };//нулевого вектора
	double norma3D{ v3D.Norma() };//отридцательного вектора
	double norma4D{ v4D.Norma() };//единичного вектора

	assert((norma1D - 8.157) <= 0.001);
	assert(norma2D == 0);
	assert((norma3D - 118.697) <= 0.001);
	assert(norma4D == 6.1);

	std::cout << "Test norma (double) : success." << std::endl;
}

void TestVectorMultipy()
{
	int items1[4]{ 1, 2, 3, 4 };
	int s1(4);

	int items2[4]{ 0 , 0, 0, 0 };
	int s2(4);

	int items3[4]{ -15, 0, -99, -62 };
	int s3(4);

	int items4[1]{ 6 };
	int s4(1);

	Vector<int> v1{ items1, s1 };
	Vector<int> v2{ items2, s2 };
	Vector<int> v3{ items3, s3 };
	Vector<int> v4{ items4, s4 };

	int mulV1{ v1.Multipy(v1) };// положит на положит
	int mulV2{ v1.Multipy(v3) };// положит на отриц
	int mulV3{ v3.Multipy(v3) };// отриц на отриц
	int mulV4{ v4.Multipy(v4) };// единичный вектор
	int mulV5{ v3.Multipy(v2) };// на нулевой вектор 
	int mulV6{ v2.Multipy(v2) };// нулевой на нулевой 

	assert(mulV1 == 30);
	assert(mulV2 == -560);
	assert(mulV3 == 13870);
	assert(mulV4 == 36);
	assert(mulV5 == 0);
	assert(mulV6 == 0);

	std::cout << "Test multipy (int) : success." << std::endl;

	double items1D[4]{ 1.1, 2.2, 3.3, 4.4 };
	int s1D(4);

	double items2D[4]{ 0 , 0, 0, 0 };
	int s2D(4);

	double items3D[4]{ -15.5, 0, -99.9, -62.2 };
	int s3D(4);

	double items4D[1]{ 6.1 };
	int s4D(1);

	Vector<double> v1D{ items1D, s1D };
	Vector<double> v2D{ items2D, s2D };
	Vector<double> v3D{ items3D, s3D };
	Vector<double> v4D{ items4D, s4D };

	double mulV1D{ v1D.Multipy(v1D) };// положит на положит
	double mulV2D{ v1D.Multipy(v3D) };// положит на отриц
	double mulV3D{ v3D.Multipy(v3D) };// отриц на отриц
	double mulV4D{ v4D.Multipy(v4D) };// единичный вектор
	double mulV5D{ v3D.Multipy(v2D) };// на нулевой вектор 
	double mulV6D{ v2D.Multipy(v2D) };// нулевой на нулевой 

	assert((mulV1D - 36.3) <= 0.0001);
	assert((mulV2D - (-620.4)) <= 0.0001);
	assert((mulV3D - 14089.1) <= 0.0001);
	assert((mulV4D - 37.21) <= 0.0001);
	assert(mulV5D == 0);
	assert(mulV6D == 0);

	std::cout << "Test multipy (double) : success." << std::endl;
}



