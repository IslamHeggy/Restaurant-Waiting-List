#ifndef WAITINGLIST_H
#define WAITINGLIST_H
#include <string>
using namespace std ;

class WaitingList
{
    public:

        string Name;
        int Group;
        string Stat;
        void Update();
        void Display();
        WaitingList();
        virtual ~WaitingList();
    protected:
    private:
};

#endif // WAITINGLIST_H
