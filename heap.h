#include<iostream>
#include"hash.h"
using namespace std;
class Heap
{
	int size;
	int a[400];
	public:Heap()
	{
		size = 0;
	}
	void insert(int x)
	{
		int hole=++size;
		for(;hole>1&&x<a[hole/2];hole/=2)
			a[hole]=a[hole/2];
		a[hole] = x;
	}
	int dele(int j)
	{
		int x=a[j],child;
		int t=a[size--];
		//cout<<t;
		for(child=2*j;child<=size;child*=2)
		{
			if(child+1<=size&&a[child+1]<a[child])
				child++;
			//<<a[child];
			if(a[child]>t)
				break;
			else
			a[child/2]=a[child];
		}
		a[child/2] = t;
		return x;
	}
	void display()
	{
		for(int i=1;i<=size;i++)
			cout<<a[i]<<" ";
		cout<<"\n";
	}
	int peep()
	{
		if(size==0)
			return -1;
		return a[1];
	}
	void fileread(int hashed)
	{
	ifstream file;
	file.open("bdays.txt");
		int isize,j,c;
	file>>j;
	//cout<<j;
		for(int i=1;i<=j;i++)
		{
		file>>c;
		if(c>=hashed)
		{
			//cout<<c<<hashed<<" ";
			insert(c);
		}
		file>>isize;
		for(;isize>0;isize--)
			bdaybaby temp(file);
		}
		file.close();
	}
	void filewrite()
	{
		ofstream file;
		file.open("bdays.txt");
		file<<size<<"\n";
		for(int i=1;i<=size;i++)
		{
		file<<a[i]<<" ";
		hashstore[a[i]].fwrite(file);
		}
		file.close();
	}
	void dele_ele(int x)
	{
		for(int i=1;i<=size;i++)
		{
			if(x == a[i])
			{
				dele(i);
				return;
			}
		}
	}
};