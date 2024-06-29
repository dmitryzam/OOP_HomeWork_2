#ifndef _FRACTION_HPP
#define _FRACTION_HPP

class Fraction {
public:
	// Конструкторы:
	Fraction(unsigned int num, unsigned int denom, bool isPositive);	// параметрический конструктор
	Fraction();		// конструктор по умолчанию
	Fraction(const Fraction& other);	// конструктор копирования
	// Сеттеры и геттеры:
	int GetNum()const;
	int GetDenom()const;
	bool GetPos()const;
	void SetNum(unsigned int num);
	void SetDenom(unsigned int denom);
	void SetPos(bool isPositive);
	// Методы:
	void Print()const;		// метод вывода дроби в консоль.
	Fraction Sum(const Fraction fr1, const Fraction fr2);		// метод сложения дроби с другой дробью.
	Fraction Sub(const Fraction fr1, const Fraction fr2);		// метод вычитания из дроби другой дроби.
	Fraction SumNum(const Fraction fr1, int number);		// метод сложения дроби с целым числом.
	Fraction SubNum(const Fraction fr1, int number);		// метод вычитания из дроби целого числа.

private:
	unsigned int num;		// numerator
	unsigned int denom;		// denominator
	bool isPositive;		// true - положительная дробь, false - отрицательная дробь.
	void Reduction();		// метод сокращения дроби
};

#endif // !_FRACTION_HPP
