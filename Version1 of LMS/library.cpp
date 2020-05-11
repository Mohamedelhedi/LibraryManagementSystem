#include"library.h"
#include"compte.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
library::library()
{
    strcpy(bookname,"");
    strcpy(author_name,"");
    strcpy(Id_book,"");
    strcpy(publication,"");
    quantity=0;
    price=0;
}
void library::get()
{
   int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Students\n\n\t\t2.Administrator\n\n\t\t3.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            compte a;
        }
        else if(i==2)
            password();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option :";
            getch();
            system("CLS");
           get();
        }
}
void library::student()
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                booklist(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tPlease enter correct option :";
                getch();
                system("cls");
                student();
            }
}
void library::password()
{
    int i=0;
    char ch,st[21],ch1[21]={"ENSI"};
    cout<<"\n\t\tEnter Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        administrator();

    }
    else
    {
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        get();
    }
}
void library::booklist(int i)
{
    int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.\a";
                else
                {
                    cout<<"\n\t    ************ Book List ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(quantity==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show_book(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    administrator();
}
void library::see(int i)
{
    int j,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(i);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n\a";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(i==1)
            student();
            else
            administrator();
        }

      system("cls");
      cout<<"\n\t\tPlease Choose one option :-\n";
      cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
      cout<<"\n\t\tEnter Your Choice : ";
      cin>>j;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(j==1)
      {
          cout<<"\n\t\tEnter Book's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(j=0;b==B&&quantity!=0&&bookname[j]!='\0'&&ch[j]!='\0'&&(ch[j]==bookname[j]||ch[j]==bookname[j]+32);j++);
            if(bookname[j]=='\0'&&ch[j]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        show_book(i);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(j==2)
          {
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(j=0;b==B&&quantity!=0&&Id_book[j]!='\0'&&ch[j]!='\0'&&ch[j]==Id_book[j];j++);
              if(Id_book[j]=='\0'&&ch[j]=='\0')
                {
                            cout<<"\n\t\tBook Found :-\n";
                            show_book(i);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPlease enter correct option :(\a";
             getch();
             system("cls");
             see(i);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available :( \n\a";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(i==1)
    student();
    else
    administrator();
  }
void library::administrator()
{
    int i;
    cout<<"\t\t *-*-*-*-*-*-Welecome Administrator *-*-*-*-*-*-\n"<<endl;
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Modify/Add Book\n\n\t\t4.Go to main menu\n\n\t\t5.Change Password\n\n\t\t6.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>i;
     switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:modify();
                     break;
            case 4:system("cls");
                     get();
                     break;
            case 5:password_change();
                    break;
            case 6:exit(0);
            default:cout<<"\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            administrator();
}
}
void library::modify()
{
   int j;
    system("cls");
    cout<<"\t\tYou can't neither modify nor add a book .there is maintenance\n";
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\t\t1.Return\n\n\t\t2.Go to main menu\n\n\t\t3.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>j;
    if (j==1)
    {
        system("cls");
        administrator();
    }
    else if (j==2)
    {
         system("cls");
        get();
    }
    else if (j==3)
    {
        system("cls");
        exit(0);
    }
    else
    {
        cout<<"\n\t\tYour choice is wrong :\n ";
        getch();
        modify();
    }

}
void library::password_change()
{
    int j;
    system("cls");
    cout<<"\t\tYou can't change your password now.there is maintenance\n";
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\t\t1.Return\n\n\t\t2.Go to main menu\n\n\t\t3.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>j;
    if (j==1)
    {
        system("cls");
        administrator();
    }
    else if (j==2)
    {
         system("cls");
        get();
    }
    else if (j==3)
    {
        system("cls");
        exit(0);
    }
    else
    {
        cout<<"\n\t\tYour choice is wrong :\n ";
        getch();
        password_change();
    }
}

int library::branch(int i)
{
    int j;
      cout<<"\n\t\t>>Please Choose one Branch :-\n";
      cout<<"\n\t\t1.Mathematics\n\n\t\t2.Physics\n\n\t\t3.Developpement\n\n\t\t4.Civil\n\n\t\t5.Mechanical\n\n\t\t6.Marketing\n\n\t\t7.History\n\n\t\t8.Philosophy\n\n\t\t9.Biology\n\n\t\t10.Go to menu\n";
      cout<<"\n\t\tEnter youur choice : ";
      cin>>j;
      switch(j)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: return 7;
                  break;
          case 8: return 8;
                  break;
          case 9: return 9;
                  break;
          case 10: system("cls");
                  if(i==1)
                  student();
                  else
                    administrator();
          default : cout<<"\n\t\tPlease enter correct option :(\a";
                    getch();
                    system("cls");
                    branch(i);
        }
}
void library::show_book(int i)
{
    cout<<"\n\t\tBook Name : "<<bookname<<endl;
    cout<<"\n\t\tBook's Author Name : "<<author_name<<endl;
    cout<<"\n\t\tBook's ID : "<<Id_book<<endl;
    cout<<"\n\t\tBook's Publication : "<<publication<<endl;
    if(i==2)
    {
        cout<<"\n\t\tBook's Price : "<<price<<endl;
        cout<<"\n\t\tBook's Quantity : "<<quantity<<endl;
    }
}
