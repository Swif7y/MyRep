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
	string model;
	int godina;


public:
	CAuto() {} //Подразбиращ конструктор
	CAuto(const string& reg_num, const string& brand, const string& m_odel, const int& year)//Експлицитен конструктор
	{
		reg_nom = reg_num;
		marka = brand;
		model = m_odel;
		godina = year;

	}
	CAuto(const CAuto& c)//копиращ конструктор
	{
		reg_nom = c.reg_nom;
		marka = c.marka;
		model = c.model;
		godina = c.godina;

	}
	const string& GetRegN()const
	{
		return reg_nom;
	}
	const string& GetBrand()const
	{
		return marka;
	}
	const string& GetModel()const
	{
		return model;
	}

	const int GetYear()const
	{
		return godina;
	}
	void SetRegN(const string& reg_num)
	{
		reg_nom = reg_num;
	}
	void SetBrand(const string& brand)
	{
		marka = brand;
	}
	void SetModel(const string& m_odel)
	{
		model = m_odel;
	}
	void SetYear(const int& year)
	{
		godina = year;
	}

	virtual void Output(ostream& toStream) // Функция за отпечатване
	{
		toStream << "Registracionen nomer: " << GetRegN() << endl;
		toStream << "Marka: " << GetBrand() << endl;
		toStream << "Model: " << GetModel() << endl;
		toStream << "Godina na proizvodstvo: " << GetYear() << endl;
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
	static int carAge(CAuto age)//Функция за пресмятане на годините на колата
	{
		return curYear - age.GetYear();
	}
	ostream& print(ostream& toStream)//Функция за извеждане в програмата
	{
		toStream << " Reg.Nom: " << reg_nom << " Marka: " << marka << " Model: " << model <<
			" Godina: " << godina << endl;
		return toStream;
	}
	CAuto operator=(const CAuto& c)//оператор за присвояване
	{
		reg_nom = c.reg_nom;
		marka = c.marka;
		model = c.model;
		godina = c.godina;
		return *this;
	}

	friend istream& operator >> (istream& fromStream, CAuto& c) // оператор за въвеждане
	{
		fromStream >> c.reg_nom;
		fromStream >> c.marka;
		fromStream >> c.model;
		fromStream >> c.godina;
		return fromStream;
	}
	friend ostream& operator<<(ostream& toStream, CAuto& c)//оператор за извеждане който използва вече съществуващата функция
	{
		c.print(toStream);
		return toStream;
	}


};

class Cars
{
private:
	vector<CAuto>cars;
public:
	const vector<CAuto>& getCars()const
	{
		return cars;
	}
	Cars()// Подразбиращ конструктор
	{
	}
	Cars(vector<CAuto>&c)//Експлицитен конструктор
	{
		cars = c;
	}

	Cars(const Cars& c)//Копиращ конструктор
	{

		cars = c.cars;
	}
	void Output(ostream& toStream)// Функция за извеждане на информацията
	{

		for (int i = 0; i <cars.size(); i++)
		{
			cars[i].print(toStream);
		}
	}
	friend ostream& operator<<(ostream& toStream, Cars& c)// Оператор за извеждане
	{
		c.Output(toStream);
		return toStream;
	}
	void CreateNew(Cars & c)//Функция за създавене на обект чрез друг обект
	{
		c.cars = cars;
	}
	friend istream& operator >> (istream& fromStream, Cars& c)//оператор за въвеждане
	{
		c.cars.clear();
		CAuto a;
		for (int i = 0; i < 6; i++)
		{
			fromStream >> a;
			c.cars.push_back(a);
		}
		return fromStream;
	}

};