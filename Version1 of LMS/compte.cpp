#include "compte.h"
#include"library.h"
#include<iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include<conio.h>
using namespace std;
library b;

   char user[10];
   ofstream username;
   char pass[10];
   ofstream password;
   ifstream readusername;
   char readuser[10];
   ifstream readpassword;
    char readpass[10];
compte::compte()
{
    int decision;
    cout<<"1.Create account\n2.Log in\n";
    cin>>decision;
    if (decision==1)
    {
        createaccount();
    }
    if (decision==2)
    {
        login();
    }
}
//il manque la saisie du nom et prenom du chaque utilisateur
void compte::login()
{
 readusername.open ("username.txt");

    readusername >> readuser;


    readpassword.open ("password2.txt");

    readpassword >> readpass;

    char userint[10],passint[10];
    e2:
    cout<<"Enter username : \n";
    cin>>userint;
    if (strcmp(userint,readuser)==0)
    {
        e1:
        cout<<"Enter password : \n";
        cin>>passint;
        if (strcmp(passint,readpass)==0)
        {
            cout<<"Logging in..."<<endl;
            system("cls");
            b.student();

        }
        else
        {
            cout<<"Incorrect password !"<<endl;
            goto e1;
        }
    }
    else
    {
        cout<<"This username does not exist !"<<endl;
        goto e2;
    }

}

void compte::createaccount()
{
     cout<<"Choose a username"<<endl;
    cin>>user;
    username.open ("username.txt");
    username << user;
    username.close();


    cout<<"Choose a password"<<endl;
    cin>>pass;
    password.open ("password2.txt");
    password << pass;
    password.close();
    cout<<"Account created succesfully !\nLog into your new account"<<endl;
    login();
}
