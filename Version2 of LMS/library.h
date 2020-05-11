#ifndef LIBRARY_H
#define LIBRARY_H
//***************************************************************
//                   CLASS1 "library" USED IN PROJECT
//****************************************************************
class library
{
    char bookname[100],author_name[50],Id_book[20],publication[50];
    int quantity,B,price;
    char nameStudent[50],idStudent[50];
    int day,month,year;
    public:
        library();
        void administrator();
        void Start();
        void password();
        void password_change();
        void get_data();
        void booklist(int);
        void modifyBook();
        void show_book(int);
        void see(int);
        int branch(int);
        void getdata();
        void issue2();
        void regulate(char[],int,int);
        void fine(int,int,int,int,int,int);
        void issue1();
        void theEnd(int );
        void Smile();
};

#endif // LIBRARY_H
