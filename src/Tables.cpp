#include "Tables.h"
#include <iostream>
using namespace std ;

Tables::Tables()
{

    Status=true;
    //ctor
}
Tables::~Tables()
{
    //dtor
}
        int Table_no ;
        int Seats_no ;
        bool Status ;
void Tables::Update()
{
    cout <<"Enter table status: "<<"(0 for available)"<<endl;
    cin>> Status;
}
void Tables::Display()
{
    cout <<"Table Number: "<<Table_no<<endl;
    cout <<"Seats Number: "<<Seats_no<<endl;
    if(Status==true)
    {
        cout <<"Table Status: "<<"Not Available"<<endl<<endl;
    }
    else
    cout <<"Table Status: "<<"Available"<<endl<<endl;

}
