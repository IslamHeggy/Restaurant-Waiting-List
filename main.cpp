#include <iostream>
#include <Tables.h>
#include <WaitingList.h>
#include <vector>
using namespace std;

int Add(vector<WaitingList>& Waiting)
{
    WaitingList x ;
    cout <<"Enter the name:"<<endl ;
    cin.ignore();
    getline(cin,x.Name);
    for(int i =0; i<Waiting.size(); i++)
    {
        if(Waiting[i].Name==x.Name)
        {
            cout<<"Error: This name already exists in the waiting list !"<<endl<<endl;
            return 0;
        }
    }

    cout <<"Enter your group size: "<<endl ;
    cin>>x.Group;
    cout <<"Enter your waiting status:(in/out)"<<endl ;
    cin >>x.Stat;
    Waiting.push_back(WaitingList(x));
}
void run()
{
    vector<WaitingList> Waiting ;
    vector<Tables> Table(10);
    char cont;
    int operation, tableno, guestno ;

    cout <<"                      Welcome to Restauraunt Waiting List System"<<endl<<endl;
    cout <<"Enter 10 tables data "<<endl<<endl;

    for(int i =0; i<10; i++)
    {
        Table[i].Table_no=i+1;
        cout <<"Table number "<< Table[i].Table_no<<endl;
        cout<<"Enter Seats number: "<<endl;
        cin>>Table[i].Seats_no;

    }
    cout<<"The restauraunt has 10 full tables now, you are directed to waiting list!"<<endl ;
    while(cont!='N')
    {
        Add(Waiting);
        cout <<"Do you want to continue adding ? (Y/N)"<<endl ;
        cin>>cont ;

    }
    while(operation!=8)
    {
        cout<<endl;
        cout <<"Note:: You can choose by typing 1, 2 or 3 ...."<<endl;
        cout<<"If you want to edit tables: "<<endl;
        cout <<"1-Edit a table status"<<endl;
        cout<<"2-Display all tables"<<endl<<endl;
        cout<<"If you want to edit the waiting list: "<<endl;
        cout<<"3-Add new entry."<<endl;
        cout<<"4-Edit an entry."<<endl;
        cout<<"5-Remove an entry."<<endl;
        cout<<"6-Display an entry."<<endl;
        cout<<"7-Display the waiting list."<<endl;
        cout<<"8-Exit."<<endl;
        cin>>operation;
        if (operation==1)
        {
            cout<<"Write the table number you want to edit"<<endl;
            cin>>tableno;
            Table[tableno-1].Update();
            cout<<"Table no "<<tableno<<" is updated"<<endl;
            for(int i =0 ; i<Waiting.size(); i++)
            {
                if (Table[tableno-1].Status==false && Table[tableno-1].Seats_no>=Waiting[i].Group && Waiting[i].Stat[0]=='i')
                {

                    cout<<"Guest "<<Waiting[i].Name<<" is removed from waiting list and took table number "<<Table[tableno-1].Table_no <<endl ;
                    Waiting.erase(Waiting.begin()+i);
                    Table[tableno-1].Status=true ;
                }
            }
        }
        else if(operation==2)
        {
            for(int i =0; i<10; i++)
            {
                Table[i].Display();
            }
        }
        else if (operation==3)
        {
            Add(Waiting);
        }
        else if(operation==4)
        {
            cout<<"Enter guest number:"<<endl;
            cin>>guestno;
            Waiting[guestno-1].Update();
        }
        else if(operation==5)
        {
            cout<<"Enter guest number:"<<endl;
            cin>>guestno;
            Waiting.erase(Waiting.begin()+guestno-1);
            cout<<"Guest number"<<guestno <<" is removed from waiting list"<<endl;
        }
        else if(operation==6)
        {
            cout<<"Enter guest number you want to display"<<endl;
            cin>>guestno;
            Waiting[guestno-1].Display();
        }
        else if(operation==7)
        {
            for(int i =0 ; i<Waiting.size(); i++)
            {
                Waiting[i].Display();
            }
        }

        cout<<endl;

    }

    cout<<"Thank You :D"<<endl;

}
int main()
{

    run();


    return 0;
}
