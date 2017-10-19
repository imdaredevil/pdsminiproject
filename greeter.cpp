#include<iostream>
#include"functions.h"
using namespace std;
int main()
{
	Heap all,current;
	int ch,i,j;
	all.fileread(0);
	hashfile();
	time_t now = time(0);
	tm *today  = gmtime(&now);
	cout<<"\n"<<setw(30)<<"**************************\n";
	int hashcheck = hash(today->tm_mon+1,today->tm_mday);
	current.fileread(hashcheck);
	bdaycheckdisplay(hashcheck,current,all);
	cout<<"\n";
	all.filewrite();
	cout<<"\n"<<setw(30)<<"*******Thank you*******\n";

	return 0;
}
	