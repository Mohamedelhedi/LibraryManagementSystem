#ifndef LIBRARY_H
#define LIBRARY_H


class library
{
    char bookname[100],author_name[50],Id_book[20],publication[50];
    int quantity,B,price;
    public:
        library();
          void student();
          void administrator();
          void get();
          void password();
          void password_change();
          void booklist(int);
          void modify();
          void show_book(int);
          void see(int);
          int branch(int);
          void Remove_member();
          void Create_member();
          void Modify_member ();

    protected:

    private:
};

#endif // LIBRARY_H
