#include "library.h"
#include"member.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>

using namespace std;

member a;
library::library()
{

    strcpy(bookname,"");
    strcpy(author_name,"");
    strcpy(Id_book,"");
    strcpy(publication,"");
    strcpy(nameStudent,"");
    strcpy(idStudent,"");
    quantity=0;
    B=0;
    price=0;
    day=0;
    month=0;
    year=0;
}
//***************************************************************
//                THE MAIN MENU
//***************************************************************
void library::Start()
{



   int i;
        cout<<"\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
        cout<<"\n\t\t>>Please Choose Any Option To login \n";
        cout<<"\n\t\t1.Students\n\n\t\t2.Administrator\n\n\t\t3.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch (i)
        {
            case 1:{system("cls");
                a.student();
                break;
            }

            case 2:password();
                    break;
            case 3:
                theEnd(3);
                break;
            default:
                {cout<<"\n\t\tPlease enter correct option :\a";
                getch();
                system("CLS");
                Start();}


        }
}
//***************************************************************
//           FUNCTION TO MAKE A PASSWORD FOR THE ADMINISTRATOR
//***************************************************************
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
        cout<<"\n\n\t\tWrong Password.\n\n\t\ttry again.....\n\a";
        getch();
        system("cls");
        Start();
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
                    a.student();
                else
                    administrator();
}
//***************************************************************
//                FUNCTION TO SEARCH A BOOK
//***************************************************************
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
            a.student();
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
    a.student();
    else
    administrator();
  }
  //***************************************************************
//        ADMINISTRATOR MENU FUNCTION
//****************************************************************
void library::administrator()
{
    int i;
    cout<<"\t\t *-*-*-*-*-*-Welecome Administrator *-*-*-*-*-*-\n"<<endl;
    cout<<"\n\t\t>>Please Choose One Option:\n";
    cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Modify/Add Book\n\n\t\t4.Issue book\n\n\t\t5.Go to main menu\n\n\t\t6.Change Password\n\n\t\t7.Close Application\n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>i;
     switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:modifyBook();
                     break;
            case 4:issue2();
                    break;
            case 5:system("cls");
                     Start();
                     break;
            case 6:password_change();
                    break;
            case 7:theEnd(2);
            default:cout<<"\n\t\tPlease enter correct option :(\a";
            getch();
            system("cls");
            administrator();
}
}
void library::modifyBook()
{
char st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Please Choose one option :-\n";
    cout<<"\n\t\t1.Modification in book's options\n\n\t\t2.Add New Book\n\n\t\t3.Delete A Book\n\n\t\t4.Go back\n";
    cout<<"\n\n\t\tEnter your choice : ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n\a";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        system("cls");
                        administrator();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPlease Choose One Option :-\n";
                        cout<<"\n\t\t1.Search By Book Name\n\n\t\t2.Search By Book's ID\n";
                        cout<<"\n\t\tEnter Your Choice : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book Name : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i++);
                                        if(bookname[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book's ID : ";
                                cin.getline(publication,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&Id_book[i]!='\0'&&publication[i]!='\0'&&publication[i]==Id_book[i];i++);
                                        if(Id_book[i]=='\0'&&publication[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input.....:(\n\a";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modifyBook();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n\a";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modifyBook();
                        }
                        else
                            cout<<"\n\t\tUpdate Successful.\n";


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(2);
                    system("cls");
                    getdata();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tBook added Successfully.\n";
    }
    else if(i==3)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tFile Not Found\n\a";
                        cout<<"\n\t\tPress any key to continue.....";
                        getch();
                        intf1.close();
                        system("cls");
                        administrator();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tPlease Choose One Option for deletion:-\n";
                        cout<<"\n\t\t1.By Book Name\n\n\t\t2.By Book's ID\n";
                        cout<<"\n\t\tEnter Your Choice : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tEnter Book Name : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i++);
                                        if(bookname[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tEnter Book's ID : ";
                                cin.getline(publication,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&Id_book[i]!='\0'&&publication[i]!='\0'&&publication[i]==Id_book[i];i++);
                                        if(Id_book[i]=='\0'&&publication[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                        }
                        else
                        {
                            cout<<"\n\t\tIncorrect Input.....:(\n\a";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modifyBook();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tBook Not Found.\n\a";
                            cout<<"\n\t\tPress any key to continue.....";
                            getch();
                            system("cls");
                            modifyBook();
                        }
                        else
                            cout<<"\n\t\tDeletion Successful.\n";

    }
    else if(i==4)
    {
    system("cls");
    administrator();
    }
    else
    {
    cout<<"\n\t\tWrong Input.\n\a";
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    modifyBook();
    }
    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    administrator();

}

void library::password_change()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"ENSI"};
    system("cls");
    cout<<"\n\n\t\tEnter Old Password : ";
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
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**The Password Should be less than 20 characters & don't use spaces**\n\n";
        cout<<"\n\t\tEnter New Password : ";
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tYou did't follow the instruction \n\n\t\tPress any key for try again.....";
                getch();
                system("cls");
                password();
                administrator();
            }
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
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tYour Password has been changed Successfully.";
        cout<<"\n\t\tPress any key to continue......";
        getch();
        system("cls");
        administrator();
    }
    else
    {
        cout<<"\n\n\t\tPassword is incorrect.....\n\a";
        cout<<"\n\t\tEnter 1 for retry or 2 for return";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            administrator();
        }
    }
}

int library::branch(int i)
{
    int j;
      cout<<"\n\t\t>>Please Choose one Branch :-\n";
      cout<<"\n\t\t1.Mathematics\n\n\t\t2.Physics\n\n\t\t3.Developpement\n\n\t\t4.Civil\n\n\t\t5.Mechanical\n\n\t\t6.Marketing\n\n\t\t7.History\n\n\t\t8.Philosophy\n\n\t\t9.Finance\n\n\t\t10.Go to menu\n";
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
                  a.student();
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
void library::getdata()
{
    int i;
                    fflush(stdin);
                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter Book's Name : ";
                    cin.getline(bookname,100);
                    for(i=0;bookname[i]!='\0';i++)
                    {
                    if(bookname[i]>='a'&&bookname[i]<='z')
                       bookname[i]-=32;
                    }
                    cout<<"\n\t\tEnter Author's Name : ";
                    cin.getline(author_name,50);
                    cout<<"\n\t\tEnter Publication name : ";
                    cin.getline(publication,50);
                    cout<<"\n\t\tEnter Book's ID : ";
                    cin.getline(Id_book,20);
                    cout<<"\n\t\tEnter Book's Price : ";
                    cin>>price;
                    cout<<"\n\t\tEnter Book's Quantity : ";
                    cin>>quantity;
}
//*****************************************************************************
//   FUNCTION TO REGULATE THE DISTRIBUTED QUANTITY OF BOOKS ISSUED OR RETURNED
//*****************************************************************************
void library::regulate(char st[],int b,int i)
{
    int j,cont=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(j=0;b==B&&Id_book[j]!='\0'&&st[j]!='\0'&&st[j]==Id_book[j];j++);
        if(Id_book[j]=='\0'&&st[j]=='\0')
        {
            cont++;
            if(i==1)
            {
                quantity--;
            }
            else
            {
                quantity++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tBook not found.\n\a";
        cout<<"\n\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        issue2();
    }
    intf.close();
}
//***************************************************************
//        FUNCTION TO CONTROL STUDENTS WHO ISSUED BOOKS
//****************************************************************
void library::issue2()
{
    char st[50],st1[20];
    int i,cont=0;
    system("cls");
    cout<<"\n\t\t->Please Choose one option :-\n";
    cout<<"\n\t\t1.View Issued Book\n\n\t\t2.Search student who issued books\n\n\t\t3.Return\n\n\t\t4.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin>>i;
    fflush(stdin);

    if(i==1)
    {
    ifstream intf("student.txt",ios::binary);
    system("cls");
    cout<<"\n\t\t->The Details are :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n\t\t********** "<<i<<". ********** \n";
    cout<<"\n\t\tStudent Name : "<<nameStudent<<"\n\t\t"<<"Student's ID : "<<idStudent<<"\n\t\t"<<"Book Name : "<<bookname<<"\n\t\t"<<"Book's ID : "<<Id_book<<"\n\t\t"<<"Date : "<<day<<"/"<<month<<"/"<<year<<"\n";
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();;
    }
    else if(i==2)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Please Enter Details :-\n";
        cout<<"\n\n\t\tEnter Student Name : ";
        cin.getline(st,50);
        cout<<"\n\n\t\tEnter Student's ID : ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("student.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              for(i=0;idStudent[i]!='\0'&&st1[i]!='\0'&&st1[i]==idStudent[i];i++);
              if(idStudent[i]=='\0'&&st1[i]=='\0')
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n\t\t->The Details are :-\n";
                      cout<<"\n\t\tStudent Name : "<<nameStudent;
                      cout<<"\n\t\tStudent's ID : "<<idStudent;
                  }
                  cout<<"\n\n\t\t******* "<<cont<<". Book details *******\n";
                  cout<<"\n\t\tBook Name : "<<bookname;
                  cout<<"\n\t\tBook's ID : "<<Id_book;
                  cout<<"\n\t\tDate : "<<day<<"/"<<month<<"/"<<year<<"\n";
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\n\t\tNo record found.";
    }
    else if(i==3)
    {
        system("cls");
        administrator();
    }
    else if(i==4)
    {
    system("cls");
    Start();
    }
    else
        cout<<"\n\t\tWrong Input.\n\a";

    cout<<"\n\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    administrator();
}
//***************************************************************
//        FUNCTION TO CALCULATE THE TOTAL FINE
//****************************************************************
void library::fine(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i];
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
    cout<<"\n\t\tThe Total Fine is : "<<n2;

}
//***************************************************************
//              ISSUED BOOK FROM THE LIBRARY
//****************************************************************
void library::issue1()
{
    char st[50],st1[20];
    int b,i,j,d,m,y,cont=0;
    system("cls");
    cout<<"\n\t\t->Please Choose one option :-\n";
    cout<<"\n\t\t1.Borrow a Book\n\n\t\t2.Reissue Book\n\n\t\t3.Return Book\n\n\t\t4.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=branch(1);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book Name : ";
    cin.getline(bookname,100);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(Id_book,20);
    regulate(Id_book,b,1);
    cout<<"\n\t\tEnter Student Name : ";
    cin.getline(nameStudent,100);
    cout<<"\n\t\tEnter Student's ID : ";
    cin.getline(idStudent,20);
    cout<<"\n\t\tEnter date : ";
    cin>>day>>month>>year;
    ofstream outf("student.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tIssue Successfully.\n";
    }
    else if(i==2)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,50);
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    fstream intf("student.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;Id_book[i]!='\0'&&st1[i]!='\0'&&st1[i]==Id_book[i];i++);
            for(j=0;idStudent[j]!='\0'&&st[j]!='\0'&&st[j]==idStudent[j];j++);
            if(Id_book[i]=='\0'&&idStudent[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0')
                {
                    d=day;
                    m=month;
                    y=year;
                    cout<<"\n\t\tEnter New Date : ";
                    cin>>day>>month>>year;
                    fine(d,m,y,day,month,year); //fn1
                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
                    intf.write((char*)this,sizeof(*this)); //fn5
                    cout<<"\n\n\t\tReissue successfully."; //fn3
                    break;
                }
                   intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }
    else if(i==3)
    {
         system("cls");
    b=branch(1);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Please Enter Details :-\n";
    cout<<"\n\t\tEnter Book's ID : ";
    cin.getline(st1,20);
    regulate(st1,b,2);
    cout<<"\n\n\t\tEnter Student's ID : ";
    cin.getline(st,20);
    cout<<"\n\t\tEnter Present date : ";
    cin>>d>>m>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("student.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;Id_book[i]!='\0'&&st1[i]!='\0'&&st1[i]==Id_book[i];i++);
            for(j=0;idStudent[j]!='\0'&&st[j]!='\0'&&st[j]==idStudent[j];j++);
            if(Id_book[i]=='\0'&&idStudent[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    fine(day,month,year,d,m,y);
                    cout<<"\n\t\tReturned successfully.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("student.txt");
    rename("temp.txt","student.txt");
    }
    else if(i==4)
    {
    system("cls");
    a.student();
    }
    else
        cout<<"\n\t\tWrong Input.\n\a";

    cout<<"\n\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    a.student();

}
//***************************************************************
//                FUNCTION TO GO OUT FROM THE LIBRARY
//***************************************************************
void library::theEnd(int y)
{
    system("cls");
    char* c =new char;
    cout<<"\n\n\n\n\n\n\t\tDo you want really to leave the library ?\n";
    cout<<"\n\n\t\tYour answer must be Y or N ,Y means Yes and N means No . \n";
    cout<<"\n\t\tEnter your choice : ";
    cin>>c;
    if (strcmp(c,"Y")==0)
    {
        system("cls");
        Smile();
        exit(0);
    }
    else if ((strcmp(c,"N")==0)&& (y==1))
    {
        system("cls");
        a.student();
    }
    else if ((strcmp(c,"N")==0) && (y==2))
    {
        system("cls");
        administrator();
    }
    else if ((strcmp(c,"N")==0) && (y==3))
    {
        system("cls");
        Start();
    }
    else
    {
        cout<<"\n\t\tWrong Input.\a\n";
        cout<<"\n\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        theEnd(y);
    }
    delete c;

}

void library::Smile()
{
    cout<<"\n\tThank you for visiting us and spending your time here.We look forward to see you again.\n";
    cout<<"\t\t\t\t***************Have a great day!***************\n";
    cout<<"\t\t\t\tEcole Nationale des Sciences de l'informatique\n\n";
    cout<<"\t\t\t\t\t\t     @@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t    @@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t  @@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t  @@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t @@@   @@@@@   @@@\n";
    cout<<"\t\t\t\t\t\t@@@@   @@@@@   @@@@\n";
    cout<<"\t\t\t\t\t\t@@@@   @@@@@   @@@@\n";
    cout<<"\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t@@@ @@@@@@@@@@@ @@@\n";
    cout<<"\t\t\t\t\t\t@@@  @@@@@@@@@  @@@\n";
    cout<<"\t\t\t\t\t\t@@@@           @@@@\n";
    cout<<"\t\t\t\t\t\t@@@@@@       @@@@@@\n";
    cout<<"\t\t\t\t\t\t @@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t  @@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t  @@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t    @@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t\t     @@@@@@@@@\n";

}
