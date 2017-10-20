#include"functions.h"
#include<iostream>
using namespace std;
int main()
{
	Heap all;
	int ch,i,j;
	all.fileread(0);
	hashfile();
	cout<<"***********************************************************************************************\n";
	ca:
	cout<<"1 to insert\n2 to delete\n3 to update\nany other key to exit\n";
	cin>>ch;
	if(ch==1)
		insert(all);
	else if(ch==2)
	{
		if(dele(all,0))
			cout<<"Deleted";
	}
	else if(ch == 3)
	{
		if(dele(all,1))
		{
			insert(all);
		}
	}	
	else
		goto la;
	cout<<"***********************************************************************************************\n";
	goto ca;
	la:
	all.filewrite();
	cout<<"***************************thank you***********************************************************\n";
	return 0;
}
	
