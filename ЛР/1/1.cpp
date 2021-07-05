#include <iostream>
#include <string>

using namespace std;

class Harbinger
{
	string h_name, CatchPhrase;
	int h_age;
public:
	Harbinger(string name = "", int age = 0, string phrase = "") :h_name(name), h_age(age), CatchPhrase(phrase) {}
	void setName(string name) { h_name = name; }
	void setAge(int age) { h_age = age; }
	void setPhrase(string phrase) { CatchPhrase = phrase; }
	string getName() { return h_name; }
	int getAge() { return h_age; }
	string getPhrase() { return CatchPhrase; }
};

class Prophet :public Harbinger
{
	string MagnumOpus[3];
	string ph_name;
	int ph_age;
	string ph_call;
public:
	Prophet(string name = "Steve", int age = 35) :Harbinger(), ph_name(name), ph_age(age), ph_call("")
	{
		for (int i = 0; i < 3; i++)
			MagnumOpus[i] = "";
	}
	void setName(string name) { ph_name = name; }
	void setAge(int age) { ph_age = age; }
	void setMO(string* Magnum)
	{
		int len = 0;
		for (int i = 0; i < 3; i++)
		{
			if (Magnum[i].length() > 25)
			{
				cout << "Присутствует строка длиной больше 25 символов\n";
				return;
			}
			MagnumOpus[i] = Magnum[i];
			if (MagnumOpus[i].length() > len)
			{
				ph_call = MagnumOpus[i];
				len = MagnumOpus[i].length();
			}
		}
	}
	string getName() { return ph_name; }
	int getAge() { return ph_age; }
	string getCall() { return ph_call; }
	string* getMO() { return MagnumOpus; }
};

class DeusEx :public Prophet
{
	string gd_name;
	int gd_year;
public:
	DeusEx(string name = "Alex", int year = 1500) :Prophet(), gd_name(name), gd_year(year) {}
	string getName() { return gd_name; }
	int getAge() { return gd_year; }
	void get()
	{
		int i = 0;
		string* Magnum;
		Magnum = new string[3];
		Magnum = getMO();
		cout << Harbinger::getName() << " в возрасте " << Harbinger::getAge() << " говорил, что " << Harbinger::getPhrase() << endl;
		for (i; i < 3; i++)
		{
			if (Magnum[i] != getCall())
				cout << "Первое пророчество: " << Magnum[i] << endl;
		}
		for (i; i < 3; i++)
		{
			if (Magnum[i] != getCall())
				cout << "Второе пророчество: " << Magnum[i] << endl;
		}
		cout << "Главное пророчество: " << getCall() << endl;
		cout << "Так говорил " << Prophet::getName() << " в возрасте " << Prophet::getAge() << endl;
		cout << "В год " << gd_year << " пришёл " << gd_name << ", которого предрекали " << Harbinger::getName() << " и " << Prophet::getName() << endl;
	}
};

class Believer :private DeusEx
{
	string bv_name;
	int bv_age;
public:
	Believer(string name, int age) :DeusEx()
	{
		bv_name = name;
		bv_age = age;
	}
	void setName(string name) { bv_name = name; }
	void setAge(int age) { bv_age = age; }
	string getName() { return bv_name; }
	int getAge() { return bv_age; }
	void get()
	{
		cout << "Верующий " << bv_name << " молится " << DeusEx::getName() << " именем " << Prophet::getName() << ". ";
		cout << "С " << DeusEx::getAge() << " и по сей день" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	DeusEx A("Stan", 1200);
	A.Harbinger::setName("Paul");
	A.Harbinger::setAge(25);
	A.Prophet::setName("John");
	A.Prophet::setAge(40);
	string* str;
	str = new string[3];
	str[0] = "Don't kill";
	str[1] = "Don't fornicate";
	str[2] = "Don't steal";
	A.setMO(str);
	A.get();
	Believer B("Matt", 60);
	B.get();
	system("pause");
}