#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include "library.h"

using namespace std;

void intro();
//***************************************************************
//        THE MAIN FUNCTION OF PROGRAM
//****************************************************************
int main()
{
    intro();
    library objet;
    objet.Start();
    return 0;
}
//***************************************************************
//                END OF PROJECT
//***************************************************************


//***************************************************************
//                THE INTRODUCTION OF THE PROJECT
//***************************************************************
void intro()
{
    system("cls");

    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
    cout<<"\n\n\t\t\t\t\t\t*****  MADE BY  *****";
    cout<<"\n\n\n\t\t\t\t\t\tMohamed El Hedi Limem\n";
    cout<<"\n\n\t\t\tHalima Maghraoui\t\t\t\t\tAziz Jaidi\n";
    cout<<"\n\n\t\t\tPress any key to continue.....";
    getch();
    system("cls");
}


