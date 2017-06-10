#ifndef TABLES_H
#define TABLES_H


class Tables
{
    public:

        int Table_no ;
        int Seats_no ;
        bool Status ;
        void Update();
        void Display();
        Tables();
        virtual ~Tables();
    protected:
    private:
};

#endif // TABLES_H
