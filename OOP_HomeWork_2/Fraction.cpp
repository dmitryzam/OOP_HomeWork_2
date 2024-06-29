#include<iostream>
#include "Fraction.hpp"

// Параметрический конструктор:
Fraction::Fraction(unsigned int num, unsigned int denom, bool isPositive)
	: num(num), denom(denom), isPositive(isPositive) 
{
	if (denom == 0) { throw std::exception("message"); }
	Reduction(); 
}

// Конструктор по умолчанию с делегированием ч/з параметрический конструктор:
Fraction::Fraction() : Fraction(1, 1, true) { }

// Конструктор копирования с делегированием ч/з параметрический конструктор:
Fraction::Fraction(const Fraction& other)
	: Fraction(other.num, other.denom, other.isPositive) { };

// Сеттеры и геттеры:
int Fraction::GetNum() const { return num; }
int Fraction::GetDenom() const { return denom; }
bool Fraction::GetPos() const { return isPositive; }
void Fraction::SetNum(unsigned int num) { this->num = num; }
void Fraction::SetDenom(unsigned int denom) { this->denom = denom; }
void Fraction::SetPos(bool isPositive) { this->isPositive = isPositive; }

// Метод вывода дроби в консоль:
void Fraction::Print()const {
	if (GetPos()) {
		std::cout << '(' << GetNum() << '/' << GetDenom() << ')' << std::endl;
		return;
	}
	std::cout << "-(" << GetNum() << '/' << GetDenom() << ')' << std::endl;
}
// Метод сложения дроби с другой дробью:
Fraction Fraction::Sum(const Fraction fr1, const Fraction fr2){	
	int minCommonDen = 0;	// наименьший общий знаменатель (НОК)
	int fr1_num = fr1.GetNum(), fr2_num = fr2.GetNum();	// числители проимежуточные

	// нахождение НОК:	
	if (fr1.GetDenom() == fr2.GetDenom()) {
		minCommonDen = fr1.GetDenom();		
	}	
	else if (fr1.GetDenom() > fr2.GetDenom()) {		
		if (fr2.GetDenom() == 1) {
			minCommonDen = fr1.GetDenom();
			fr2_num *= fr1.GetDenom();			
		}
		else {
			for (int i = 2; i <= fr2.GetDenom(); i++) {
				if ((fr1.GetDenom() * i) % fr2.GetDenom() == 0) {
					minCommonDen = fr1.GetDenom() * i;					
					fr1_num = fr1.GetNum() * i;
					fr2_num = fr2.GetNum() * minCommonDen / fr2.GetDenom();
					break;
				}
			}
		}
	}
	else {		
		if (fr1.GetDenom() == 1) {
			minCommonDen = fr2.GetDenom();
			fr1_num *= fr2.GetDenom();			
		}
		else {
			for (int i = 2; i <= fr1.GetDenom(); i++) {
				if ((fr2.GetDenom() * i) % fr1.GetDenom() == 0) {
					minCommonDen = fr2.GetDenom() * i;					
					fr1_num = fr2.GetNum() * i;
					fr2_num = fr1.GetNum() * minCommonDen / fr1.GetDenom();
					break;
				}
			}
		}
	}
	this->SetDenom(minCommonDen);
	
	// сложение числителей:
	if (fr1.GetPos() == true && fr2.GetPos() == true) {
		this->SetNum(fr1_num + fr2_num);		
	}
	else if (fr1.GetPos() == false && fr2.GetPos() == true) {		
		if (fr1_num > fr2_num) {
			this->SetPos(false);
			this->SetNum(fr1_num - fr2_num);			
		}
		else { 
			this->SetPos(true); 
			this->SetNum(fr2_num - fr1_num);			
		}
	}
	else if (fr1.GetPos() == true && fr2.GetPos() == false) {		
		if (fr2_num > fr1_num) {
			this->SetPos(false);
			this->SetNum(fr2_num - fr1_num);
		}
		else { 
			this->SetPos(true); 
			this->SetNum(fr1_num - fr2_num);
		}
	}
	else {		
		this->SetPos(false);
		this->SetNum(fr1_num + fr2_num);
	}	
	Reduction();	// сокращаем дробь	
	return *this;
}
// Метод вычитания дробей:
Fraction Fraction::Sub(const Fraction fr1, const Fraction fr2) {	
	int minCommonDen = 0;	// наименьший общий знаменатель (НОК)
	int fr1_num = fr1.GetNum(), fr2_num = fr2.GetNum();	// числители проимежуточные

	// нахождение НОК:	
	if (fr1.GetDenom() == fr2.GetDenom()) {
		minCommonDen = fr1.GetDenom();		
	}
	else if (fr1.GetDenom() > fr2.GetDenom()) {		
		if (fr2.GetDenom() == 1) {
			minCommonDen = fr1.GetDenom();
			fr2_num *= fr1.GetDenom();			
		}
		else {
			for (int i = 2; i <= fr2.GetDenom(); i++) {
				if ((fr1.GetDenom() * i) % fr2.GetDenom() == 0) {
					minCommonDen = fr1.GetDenom() * i;					
					fr1_num = fr1.GetNum() * i;
					fr2_num = fr2.GetNum() * minCommonDen / fr2.GetDenom();
					break;
				}
			}
		}
	}
	else {		
		if (fr1.GetDenom() == 1) {
			minCommonDen = fr2.GetDenom();
			fr1_num *= fr2.GetDenom();			
		}
		else {
			for (int i = 2; i <= fr1.GetDenom(); i++) {
				if ((fr2.GetDenom() * i) % fr1.GetDenom() == 0) {
					minCommonDen = fr2.GetDenom() * i;					
					fr1_num = fr2.GetNum() * i;
					fr2_num = fr1.GetNum() * minCommonDen / fr1.GetDenom();
					break;
				}
			}
		}
	}
	this->SetDenom(minCommonDen);
	
	// вычитание числителей:
	if (fr1.GetPos() == true && fr2.GetPos() == true) {
		if (fr2_num > fr1_num) {
			this->SetPos(false);
			this->SetNum(fr2_num - fr1_num);
			}
		else {			
			this->SetNum(fr1_num - fr2_num);			
		}		
	}
	else if (fr1.GetPos() == false && fr2.GetPos() == true) {
		this->SetNum(fr2_num + fr1_num);
		this->SetPos(false);				
	}
	else if (fr1.GetPos() == true && fr2.GetPos() == false) {			
		this->SetNum(fr1_num + fr2_num);
		
	}
	else {
		if (fr1_num > fr2_num) {
			this->SetPos(false);
			this->SetNum(fr1_num - fr2_num);
		}
		else {			
			this->SetNum(fr2_num - fr1_num);
		}			
	}	
	Reduction();	// сокращаем дробь	
	return *this;
}

// Метод сложения дроби с целым числом:
Fraction Fraction::SumNum(const Fraction fr1, int number){		
	Fraction fr2;
	if (number < 0) { fr2.SetPos(false); }
	number = number > 0 ? number : -number;
	fr2.SetNum(fr1.GetDenom() * number);
	fr2.SetDenom(fr1.GetDenom());	
	this->Sum(fr1, fr2);	// вызываем метод сложения двух дробей
	return *this;
}

// Метод вычитания из дроби целого числа:
Fraction Fraction::SubNum(const Fraction fr1, int number) {
	Fraction fr2;
	if (number < 0) { fr2.SetPos(false); }
	number = number > 0 ? number : -number;
	fr2.SetNum(fr1.GetDenom() * number);
	fr2.SetDenom(fr1.GetDenom());
	this->Sub(fr1, fr2);	// вызываем метод вычитания двух дробей
	return *this;
}

// Метод сокращения дроби:
void Fraction::Reduction(){
	for (int i = 2; i <= 9; i++) {
		if (i == 4 || i == 6 || i == 8) { continue; }	// исключаем четные цифры от 4 до 8 включительно.
		if (num % i == 0 && denom % i == 0) {
			num /= i;
			denom /= i;
			i = 1;
			continue;
		}
	}
}
