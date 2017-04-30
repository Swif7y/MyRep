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

class CAutopark
{
private:
	string ak_ime;
	string ak_Kompaniq;
	int ak_avto_k;
	int ak_prodajbi;
	vector<CAuto>cars;
public:
	const string& getName()const
	{
		return ak_ime;
	}
	const int& getSells()const
	{
		return ak_prodajbi;
	}
	const vector<CAuto>& getCars()const
	{
		return cars;
	}
	CAutopark()// Подразбиращ конструктор
	{
	}
	CAutopark(const string& name, const string& comp, const int& autosalons, const int& sells, vector<CAuto>&c)//Експлицитен конструктор
	{
		ak_ime = name;
		ak_Kompaniq = comp;
		ak_avto_k = autosalons;
		ak_prodajbi = sells;
		cars = c;
	}

	CAutopark(const CAutopark& c)//Копиращ конструктор
	{
		ak_ime = c.ak_ime;
		ak_Kompaniq = c.ak_Kompaniq;
		ak_avto_k = c.ak_avto_k;
		ak_prodajbi = c.ak_prodajbi;
		cars = c.cars;
	}
	void Output(ostream& toStream)// Функция за извеждане на информацията
	{
		toStream << "Ime: " << ak_ime << endl << "Kompaniq: " << ak_Kompaniq << endl << "Broi Avtosaloni: "
			<< ak_avto_k << endl << "Broi prodajbi: " << ak_prodajbi << endl;
		for (int i = 0; i <cars.size(); i++)
		{
			cars[i].print(toStream);
		}
	}
	friend ostream& operator<<(ostream& toStream, CAutopark& c)// Оператор за извеждане
	{
		c.Output(toStream);
		return toStream;
	}
	void CreateNew(CAutopark & c)//Функция за създавене на обект чрез друг обект
	{
		c.ak_ime = ak_ime;
		c.ak_Kompaniq = ak_Kompaniq;
		c.ak_avto_k = ak_avto_k;
		c.ak_prodajbi = ak_prodajbi;
		c.cars = cars;
	}
	friend istream& operator >> (istream& fromStream, CAutopark& c)//оператор за въвеждане
	{
		c.cars.clear();
		CAuto a;
		fromStream >> c.ak_ime;
		fromStream >> c.ak_Kompaniq;
		fromStream >> c.ak_avto_k;
		fromStream >> c.ak_prodajbi;
		for (int i = 0; i < 6; i++)
		{
			fromStream >> a;
			c.cars.push_back(a);
		}
		return fromStream;
	}

};

void Zapisvane(vector<CAutopark>cars)// Глобална функция за запис във текстов файл
{
	ofstream os;
	for (int i = 0; i<cars.size(); i++)
	{
		char buffer[100] = { 0 };
		string str = _itoa(i, buffer, 10);//Преобразование от тип int към тип string
		string filename = "Avtokushti" + str;//Името на новия текстов файл(След всеки запис се създава нов файл)
		os.open(filename + ".txt");//Отваряме текстовия файл
		os << cars[i];//Запис на автокъщата
		os.close();//Затваряме файла
	}
}

void More_Than_1_SALES(vector<CAutopark>cars) // функция за намиране на автокъщи с повече от 1 продажба
{
	for (int i = 0; i<cars.size(); i++)//Цикъл за преминаване през вектора
	{
		if (cars[i].getSells()>1)//Ако има повече от 1 продажба
		{
			cout << cars[i];//изписва името на фирмата
		}
	}
}

void Bez_LADA_DACIA(string marka1, string marka2, vector<CAutopark>cars)//функция за изписване на името на фирмите които нямат Лада и Дачии
{
	vector<CAutopark>::iterator iter1;
	vector<CAuto>::const_iterator iter2;
	for (vector<CAutopark>::iterator iter1 = cars.begin(); iter1 != cars.end(); iter1++)//Обикаля фирмите
	{
		for (iter2 = iter1->getCars().begin(); iter2 != iter1->getCars().end(); iter2++)//Обикаля колите
		{
			if (iter2->GetBrand() != marka1 && iter2->GetBrand() != marka2)//Ако няма Лади и Дачии
			{
				cout << iter1->getName() << endl;//Изписване на името на фирмата
			}
		}
	}
}

void Max_SALES(vector<CAutopark>cars)// Функция за най-много продажби
{
	int max = 0;//Променлива която съхранява продажбите
	CAutopark s;//tuka prisvoqvame firmata 
	for (vector<CAutopark>::iterator iter = cars.begin(); iter != cars.end(); iter++)//Обикаля фирмите
	{
		if (iter->getSells()>max)//Проверява максималните продажби
		{
			max = iter->getSells();// Присвоява максимална продажба ако числото е по-голямо от предишното
			s = *iter;//Присвоява се името на фирмата
		}
	}
	cout << s;//Извежда името на фирмата
}
void Cvqt_Marka_Probeg(string Cvqt_Marka_Probeg, vector<CAutopark>cars) //функция за търсено по цвят, марка и пробег над 150000
{
	for (vector<CAutopark>::iterator iter = cars.begin(); iter != cars.end(); iter++) // Вектора на автокъщите се обикаля
	{
		for (vector<CAuto>::const_iterator it = iter->getCars().begin(); it != iter->getCars().end(); it++)//Вектора с колите се обикаля
		{
			if (it->GetColor() == Cvqt_Marka_Probeg)//Ако има съвпадение в цвета
			{
				if ((it->GetBrand() == "RENAUT" || it->GetBrand() == "PEGAUT") && it->GetKm() > 150000)//Проверка дали марката и пробега отговарят на изискванията
				{
					cout << iter->getName();//Извежда се името на фирмата
				}
			}
		}
	}
}

void main()
{
	fstream fp("autopark.txt");
	CAutopark s;
	vector<CAutopark>CAuto;
	int n;
	string clr;
	while (fp >> s)
	{
		CAuto.push_back(s);
	}
	do
	{

		cout << "________________________________________________________________________________" << endl;
		cout << "			1.Pokazvane na avtokushtite" << endl;
		cout << "			2.Avtokushti s pove4e ot 1 prodajba" << endl;
		cout << "			3.Vsi4ki osven LADA i DACIA            " << endl;
		cout << "			4.Naj-mnogo prodajbi  " << endl;
		cout << "			5.Tursene po cvqt(pejo i reno >150000     " << endl;
		cout << "			6.Zapazvane na informaciqta vuv file    " << endl;
		cout << "			7.Exit               " << endl;
		do
		{
			cout << "			Vashiqt izbor: ";
			cin >> n;
			cout << endl;
		} while (n>7);
		switch (n)
		{
		case 1: for (int i = 0; i<CAuto.size(); i++)
		{
			CAuto[i].Output(cout);
			cout << endl;
		}
				break;
		case 2: More_Than_1_SALES(CAuto);
			break;
		case 3: Bez_LADA_DACIA("LADA", "DACIA", CAuto);
			break;
		case 4: Max_SALES(CAuto);
			break;
		case 5: cout << "Vuvedete turseniqt ot vas cvqt: ";
			cin >> clr;
			transform(clr.begin(), clr.end(), clr.begin(), ::toupper);
			cout << endl;
			Cvqt_Marka_Probeg(clr, CAuto);
			cout << endl;
			break;
		case 6: Zapisvane(CAuto);
			cout << "Zapazeno! " << endl << endl;
			break;
		case 7: exit(1);
		}
	} while (n<7);
	system("pause");
}