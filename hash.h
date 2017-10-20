#include<iostream>
#include<fstream>
#include<list>
#include<iomanip>
#include"bday.h"
using namespace std;
class hashentry: public list<bdaybaby>
{
	public:
	void display()
	{
		list<bdaybaby>::iterator it;
		for(it = begin();it!= end();it++)
		{
			cout<<setw(30)<<(*it).getname()<<"\n";
		}
	}
	void fwrite(ofstream& file)
	{
		file<<size()<<"\n";
		list<bdaybaby>::iterator it;
		for(it = begin();it!=end();it++)
		{
			(*it).fwrite(file);
		}
	}
}hashstore[400];
int hashp(int mon,int day)
{
	return 31*mon + day;
}
void searchbyname(list<bdaybaby>& delelist,string s)
{
	for(int h=0;h<400;h++)
	{
		list<bdaybaby>:: iterator it;
		for(it=hashstore[h].begin();it!=hashstore[h].end();it++)
		{
			if((*it).getname()==s)
				delelist.push_back(*it);
		}
	}
}
void hashfile()
{
	int size,isize,hashkey;
	ifstream file;
	file.open("bdays.txt");
	file>>size;
	for(;size>0;size--)
	{
		file>>hashkey;
		file>>isize;
		for(;isize>0;isize--)
		{
			bdaybaby temp(file);
			hashstore[hashkey].push_back(temp);
		}
	}
}		
	
	
		
