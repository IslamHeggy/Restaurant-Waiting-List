#include "WaitingList.h"
#include <iostream>
#include <string>
using namespace std ;
WaitingList::WaitingList()
{
    //ctor
}

WaitingList::~WaitingList()
{
    //dtor
}

string Name;
int Group;
string Stat;


void WaitingList::Update()
{
    cout<<"Update group number: "<<endl;
    cin>>Group;
    cout<<"Update status: "<<endl;
    cin>>Stat;

}
void WaitingList::Display()
{
    cout <<"Name: "<<Name<<endl ;
    cout <<"Group number:"<<Group<<endl;
    cout <<"Status: "<<Stat<<endl;
}
