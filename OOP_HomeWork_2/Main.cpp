#include<iostream>
#include"Fraction.hpp"
// Домашняя работа 2 на тему "Дроби".

int main() {
	setlocale(LC_ALL, "RU");
	int n;
	Fraction fr1(1, 5, true);
	std::cout << "Дробь fr1: ";
	fr1.Print();

	Fraction fr2(2, 3, true);
	std::cout << "Дробь fr2: ";
	fr2.Print();

	Fraction fr3;
	std::cout << "Сумма дроби fr1 с дробью fr2: ";
	fr3.Sum(fr1, fr2);
	fr3.Print();

	Fraction fr4;
	n = 2;
	std::cout << "Сумма дроби fr1 с числом - " << n << ": ";
	fr4.SumNum(fr1, n);
	fr4.Print();

	Fraction fr5(2, 3, true);
	Fraction fr6(1, 3, true);
	std::cout << "\nДробь fr5: ";
	fr5.Print();
	std::cout << "Дробь fr6: ";
	fr6.Print();
	Fraction fr7;
	std::cout << "Вычитание из дроби fr5 дробь fr6: ";
	fr7.Sub(fr5, fr6);
	fr7.Print();

	Fraction fr8(5, 3, true);
	std::cout << "\nДробь fr8: ";
	fr8.Print();
	Fraction fr9;
	n = 3;
	std::cout << "Вычитание из дроби fr8 числа - " << n << ": ";
	fr9.SubNum(fr8, n);
	fr9.Print();

	return 0;
}