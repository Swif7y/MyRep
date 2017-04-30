#include <stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>
using namespace std;
#define curYear 2016

class CAuto
{
private:
	string reg_nom;
	string marka;
	int godina;
	string cvqt;
	long probeg;

public:
	CAuto() {} //Подразбиращ конструктор
	CAuto(const string& reg_num, const string& brand, const int& year, const string& color, const long km)//Експлицитен конструктор
	{
		reg_nom = reg_num;
		marka = brand;
		godina = year;
		cvqt = color;
		probeg = km;
	}
	CAuto(const CAuto& c)//копиращ конструктор
	{
		reg_nom = c.reg_nom;
		marka = c.marka;
		godina = c.godina;
		cvqt = c.cvqt;
		probeg = c.probeg;
	}
	const string& GetRegN()const
	{
		return reg_nom;
	}
	const string& GetBrand()const
	{
		return marka;
	}
	const string& GetColor()const
	{
		return cvqt;
	}
	const int GetYear()const
	{
		return godina;
	}
	const long GetKm()const
	{
		return probeg;
	}
	void SetRegN(const string& reg_num)
	{
		reg_nom = reg_num;
	}
	void SetBrand(const string& brand)
	{
		marka = brand;
	}
	void SetColor(const string& color)
	{
		cvqt = color;
	}
	void SetYear(const int& year)
	{
		godina = year;
	}
	void SetKm(const long& km)
	{
		probeg = km;
	}
	virtual void Output(ostream& toStream) // Функция за отпечатване
	{
		toStream << "Registracionen nomer: " << GetRegN() << endl;
		toStream << "Marka: " << GetBrand() << endl;
		toStream << "Godina na proizvodstvo: " << GetYear() << endl;
		toStream << "Cvqt: " << GetColor() << endl;
		toStream << "Probeg: " << GetKm() << endl;
	}
	virtual bool comp(CAuto b)//Функция за сравняване на пробеците
	{
		if (probeg == b.probeg)
		{
			return true;
		}
		else return false;
	}
	static bool reg_num_validation(CAuto reg_num_validation)//Функция за валидация на регистрационен номер
	{
		while (reg_num_validation.GetRegN().length() != 8)
		{
			string s;
			cout << "Nevaliden nomer! Napravete promqna: ";
			cin >> s;
			reg_num_validation.SetRegN(s);
		}
		return true;
	}
	static int carAge(CAuto age)//Функция за пресмятане на функцията на колата
	{
		return curYear - age.GetYear();
	}
	ostream& print(ostream& toStream)//Функция за извеждане в програмата
	{
		toStream << "Kola: " << endl;
		toStream << "Reg.Nom: " << reg_nom << " Marka: " << marka << " Godina: " <<
			godina << " Cvqt: " << cvqt << " Probeg: " << probeg << endl;
		return toStream;
	}
	CAuto operator=(const CAuto& c)//оператор за присвояване
	{
		reg_nom = c.reg_nom;
		marka = c.marka;
		godina = c.godina;
		cvqt = c.cvqt;
		probeg = c.probeg;
		return *this;
	}
	bool operator<(CAuto &au)const//оператор за сравнение по пробег
	{
		return probeg < au.probeg;
	}
	bool operator==(CAuto &au)const//оператор за сравнение по цвят
	{
		return cvqt == au.cvqt;
	}
	bool operator!=(CAuto& au)const//Функция за извеждане на колиете металик
	{
		return !(au.GetColor() == "metalic");
	}
	friend istream& operator >> (istream& fromStream, CAuto& c) // оператор за въвеждане
	{
		fromStream >> c.reg_nom;
		fromStream >> c.marka;
		fromStream >> c.godina;
		fromStream >> c.cvqt;
		fromStream >> c.probeg;
		return fromStream;
	}
	friend ostream& operator<<(ostream& toStream, CAuto& c)//оператор за извеждане който използва вече съществуващата функция
	{
		c.print(toStream);
		return toStream;
	}


};