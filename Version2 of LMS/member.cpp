#include "member.h"
#include"library.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
library lib;
member::member()
{

}
//***************************************************************
//        STUDENT MENU FUNCTION
//****************************************************************
void member::student()
{
    int i;
        cout<<"\n\t************ WELCOME STUDENT ************\n";
        cout<<"\n\t\t>>Please Choose One Option:\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Issue book\n\n\t\t4.Go to main menu\n\n\t\t5.Help\n\n\t\t6.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
            if(i==1)
                lib.booklist(1);
            else if(i==2)
                lib.see(1);
            else if (i==3)
                lib.issue1();
            else if(i==4)
            {
                system("cls");
                lib.Start();
            }
            else if (i==5)
            {
                system("cls");
                help();
            }
            else if(i==6)
                lib.theEnd(1);
            else
            {
                cout<<"\n\t\tPlease enter correct option :\a";
                getch();
                system("cls");
                student();
            }
}
void member::help()
{
      cout<<"\n\n\n\n\t\t\t\t************ YOU ARE WELCOME ALL THE STUDENTS ************\n\n";
      cout<<"\n\tThis L-M-S was made by a students' group of ENSI to make life easier and to facilitate tasks.\n\n";
      cout<<"\tThe Application permit you see or search a book in many fields that you want and to borrow,reissue or return\n\tbooks in a period of time .\n\n";
      cout<<"\tOnly the library's administrator who have the direct access to modify ,add or delete books and to see the \n\tstudents who issued books.\n\n";
      cout<<"\n\n\tPress any key to return.....";
      getch();
      system("cls");
      student();

}
