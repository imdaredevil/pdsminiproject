#include<iostream>
#include<fstream>
using namespace std;
class bdaybaby
{
	int mon,date;
	string name;
	public: bdaybaby()
	{
		cout<<setw(40)<<"Enter birthday baby's name: ";
		cin>>name;
		cout<<setw(40)<<"month: ";
		cin>>mon;
		cout<<setw(40)<<"day: ";
		cin>>date;
	}
	bdaybaby(string na,int mo,int da)
	{
		name = na;
		mon = mo;
		date = da;
	}
	int hashv()
	{
		return 31*mon + date;
	}
	string getname()
	{
		return name;
	}
	bdaybaby(ifstream& file)
	{
		file>>name;
		file>>mon;
		file>>date;
	}
	void fwrite(ofstream& file)
	{
		file<<name<<" ";
		file<<mon<<" ";
		file<<date<<" ";
		file<<"\n";
	}
	bool operator==(const bdaybaby& c)
	{
		return c.name==name&&date==c.date&&mon==c.mon;
	}
	void display()
	{
		cout<<name<<" "<<date<<"/"<<mon<<"\n";
	}
};
