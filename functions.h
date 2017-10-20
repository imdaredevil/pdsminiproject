#include<iostream>
#include<ctime>
#include<iomanip>
#include"heap.h"
void dele(Heap& hashheap)
	{
		string s;
		int i=0;
		list<bdaybaby> delelist;
		cout<<"enter name to be deleted\n";
		cin>>s;
		searchbyname(delelist,s);
		list<bdaybaby>::iterator it;
		if(delelist.size()==0)
		{
			cout<<"no such name\n";
			return;
		}
		if(delelist.size()>1)
		{
		for(it = delelist.begin(); it != delelist.end();it++)
		{
			cout<<++i<<" for ";(*it).display();
		}
		cin>>i;
		}
		for(it = delelist.begin();i>1;i--,it++);
		int hashe = (*it).hashv();
		hashstore[hashe].remove(*it);
		if(hashstore[hashe].size()==0)
			hashheap.dele_ele(hashe);
	}
void insert(Heap& hashheap)
{
		bdaybaby* temp = new bdaybaby();
		int hashe = temp->hashv();
		//cout<<hashe;
		if(hashstore[hashe].size() == 0)
			hashheap.insert(hashe);
		hashstore[hashe].push_back((const bdaybaby&)(*temp));
}
void bdaycheckdisplay(int hashcheck,Heap& current,Heap& all)
{
	//cout<<current.peep();
	if(current.peep() == hashcheck)
	{
		cout<<"          Today is birthday of          \n";
	}
	else if(current.peep()!=-1)
	{
		hashcheck = current.peep();
		cout<<"            "<<current.peep()%31<<"/"<<current.peep()/31<<" is birthday of          \n";
	}
	else if(all.peep()!=-1)
	{
			hashcheck  = all.peep();
			cout<<"          "<<all.peep()%31<<"/"<<all.peep()/31<<" is birthday of          \n";
	}
	else
		   	cout<<"          "<<"no birthdays stored"<<"                       \n";         
	hashstore[hashcheck].display();
}

	
	
