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
	CAuto() {} //����������� �����������
	CAuto(const string& reg_num, const string& brand, const int& year, const string& color, const long km)//����������� �����������
	{
		reg_nom = reg_num;
		marka = brand;
		godina = year;
		cvqt = color;
		probeg = km;
	}
	CAuto(const CAuto& c)//������� �����������
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
	virtual void Output(ostream& toStream) // ������� �� �����������
	{
		toStream << "Registracionen nomer: " << GetRegN() << endl;
		toStream << "Marka: " << GetBrand() << endl;
		toStream << "Godina na proizvodstvo: " << GetYear() << endl;
		toStream << "Cvqt: " << GetColor() << endl;
		toStream << "Probeg: " << GetKm() << endl;
	}
	virtual bool comp(CAuto b)//������� �� ���������� �� ���������
	{
		if (probeg == b.probeg)
		{
			return true;
		}
		else return false;
	}
	static bool reg_num_validation(CAuto reg_num_validation)//������� �� ��������� �� �������������� �����
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
	static int carAge(CAuto age)//������� �� ���������� �� ��������� �� ������
	{
		return curYear - age.GetYear();
	}
	ostream& print(ostream& toStream)//������� �� ��������� � ����������
	{
		toStream << "Kola: " << endl;
		toStream << "Reg.Nom: " << reg_nom << " Marka: " << marka << " Godina: " <<
			godina << " Cvqt: " << cvqt << " Probeg: " << probeg << endl;
		return toStream;
	}
	CAuto operator=(const CAuto& c)//�������� �� �����������
	{
		reg_nom = c.reg_nom;
		marka = c.marka;
		godina = c.godina;
		cvqt = c.cvqt;
		probeg = c.probeg;
		return *this;
	}
	bool operator<(CAuto &au)const//�������� �� ��������� �� ������
	{
		return probeg < au.probeg;
	}
	bool operator==(CAuto &au)const//�������� �� ��������� �� ����
	{
		return cvqt == au.cvqt;
	}
	bool operator!=(CAuto& au)const//������� �� ��������� �� ������� �������
	{
		return !(au.GetColor() == "metalic");
	}
	friend istream& operator >> (istream& fromStream, CAuto& c) // �������� �� ���������
	{
		fromStream >> c.reg_nom;
		fromStream >> c.marka;
		fromStream >> c.godina;
		fromStream >> c.cvqt;
		fromStream >> c.probeg;
		return fromStream;
	}
	friend ostream& operator<<(ostream& toStream, CAuto& c)//�������� �� ��������� ����� �������� ���� �������������� �������
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
	CAutopark()// ����������� �����������
	{
	}
	CAutopark(const string& name, const string& comp, const int& autosalons, const int& sells, vector<CAuto>&c)//����������� �����������
	{
		ak_ime = name;
		ak_Kompaniq = comp;
		ak_avto_k = autosalons;
		ak_prodajbi = sells;
		cars = c;
	}

	CAutopark(const CAutopark& c)//������� �����������
	{
		ak_ime = c.ak_ime;
		ak_Kompaniq = c.ak_Kompaniq;
		ak_avto_k = c.ak_avto_k;
		ak_prodajbi = c.ak_prodajbi;
		cars = c.cars;
	}
	void Output(ostream& toStream)// ������� �� ��������� �� ������������
	{
		toStream << "Ime: " << ak_ime << endl << "Kompaniq: " << ak_Kompaniq << endl << "Broi Avtosaloni: "
			<< ak_avto_k << endl << "Broi prodajbi: " << ak_prodajbi << endl;
		for (int i = 0; i <cars.size(); i++)
		{
			cars[i].print(toStream);
		}
	}
	friend ostream& operator<<(ostream& toStream, CAutopark& c)// �������� �� ���������
	{
		c.Output(toStream);
		return toStream;
	}
	void CreateNew(CAutopark & c)//������� �� ��������� �� ����� ���� ���� �����
	{
		c.ak_ime = ak_ime;
		c.ak_Kompaniq = ak_Kompaniq;
		c.ak_avto_k = ak_avto_k;
		c.ak_prodajbi = ak_prodajbi;
		c.cars = cars;
	}
	friend istream& operator >> (istream& fromStream, CAutopark& c)//�������� �� ���������
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

void Zapisvane(vector<CAutopark>cars)// �������� ������� �� ����� ��� ������� ����
{
	ofstream os;
	for (int i = 0; i<cars.size(); i++)
	{
		char buffer[100] = { 0 };
		string str = _itoa(i, buffer, 10);//�������������� �� ��� int ��� ��� string
		string filename = "Avtokushti" + str;//����� �� ����� ������� ����(���� ����� ����� �� ������� ��� ����)
		os.open(filename + ".txt");//�������� ��������� ����
		os << cars[i];//����� �� ����������
		os.close();//��������� �����
	}
}

void More_Than_1_SALES(vector<CAutopark>cars) // ������� �� �������� �� �������� � ������ �� 1 ��������
{
	for (int i = 0; i<cars.size(); i++)//����� �� ����������� ���� �������
	{
		if (cars[i].getSells()>1)//��� ��� ������ �� 1 ��������
		{
			cout << cars[i];//������� ����� �� �������
		}
	}
}

void Bez_LADA_DACIA(string marka1, string marka2, vector<CAutopark>cars)//������� �� ��������� �� ����� �� ������� ����� ����� ���� � �����
{
	vector<CAutopark>::iterator iter1;
	vector<CAuto>::const_iterator iter2;
	for (vector<CAutopark>::iterator iter1 = cars.begin(); iter1 != cars.end(); iter1++)//������� �������
	{
		for (iter2 = iter1->getCars().begin(); iter2 != iter1->getCars().end(); iter2++)//������� ������
		{
			if (iter2->GetBrand() != marka1 && iter2->GetBrand() != marka2)//��� ���� ���� � �����
			{
				cout << iter1->getName() << endl;//��������� �� ����� �� �������
			}
		}
	}
}

void Max_SALES(vector<CAutopark>cars)// ������� �� ���-����� ��������
{
	int max = 0;//���������� ����� ��������� ����������
	CAutopark s;//tuka prisvoqvame firmata 
	for (vector<CAutopark>::iterator iter = cars.begin(); iter != cars.end(); iter++)//������� �������
	{
		if (iter->getSells()>max)//��������� ������������ ��������
		{
			max = iter->getSells();// ��������� ���������� �������� ��� ������� � ��-������ �� ����������
			s = *iter;//��������� �� ����� �� �������
		}
	}
	cout << s;//������� ����� �� �������
}
void Cvqt_Marka_Probeg(string Cvqt_Marka_Probeg, vector<CAutopark>cars) //������� �� ������� �� ����, ����� � ������ ��� 150000
{
	for (vector<CAutopark>::iterator iter = cars.begin(); iter != cars.end(); iter++) // ������� �� ���������� �� �������
	{
		for (vector<CAuto>::const_iterator it = iter->getCars().begin(); it != iter->getCars().end(); it++)//������� � ������ �� �������
		{
			if (it->GetColor() == Cvqt_Marka_Probeg)//��� ��� ���������� � �����
			{
				if ((it->GetBrand() == "RENAUT" || it->GetBrand() == "PEGAUT") && it->GetKm() > 150000)//�������� ���� ������� � ������� ��������� �� ������������
				{
					cout << iter->getName();//������� �� ����� �� �������
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