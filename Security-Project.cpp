#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include<vector>
using namespace std;

int ascii = 178;
char ch = ascii;

#define heading \
    cout << " ";\
    for (int i = 0; i < 25; i++) cout << ch;\
    cout << " Security Project ";\
    for (int i = 0; i < 25; i++) cout << ch;

#define registering \
    cout << " ";\
    for (int i = 0; i < 25; i++) cout << ch;\
    cout << " REGISTER YOUR ACCOUNT ";\
    for (int i = 0; i < 25; i++) cout << ch;

#define loggingIn \
    cout << " ";\
    for (int i = 0; i < 25; i++) cout << ch;\
    cout << " LOG INTO YOUR ACCOUNT ";\
    for (int i = 0; i < 25; i++) cout << ch;

#define forgotemail \
    cout << " ";\
    for (int i = 0; i < 25; i++) cout << ch;\
    cout << " FORGOT EMAIL ID ";\
    for (int i = 0; i < 25; i++) cout << ch;

#define forgotpassword \
    cout << " ";\
    for (int i = 0; i < 25; i++) cout << ch;\
    cout << " FORGOT PASSWORD ";\
    for (int i = 0; i < 25; i++) cout << ch;


int a = 0;
struct Register
{
    string id;
    string name, email, phone, password;
}R[25];

void registerAccount(){
    system("cls");
    registering;
    cout << "\n\n "<< ch << ch << " ENTER USER ID -> ";
    cin >> R[a].id;
    cout << "\n\n "<< ch << ch << " ENTER USERNAME -> ";
    cin >> R[a].name;
    cout << "\n\n "<< ch << ch << " ENTER EMAIL ID -> ";
    cin >> R[a].email;
    cout << "\n\n "<< ch << ch << " ENTER PHONE NO. -> ";
    cin >> R[a].phone;
    char d;
    cout << "\n\n "<< ch << ch << " ENTER PASSWORD -> ";
    while(R[a].password.empty()){
        do
        {
            d = getch();
            if(isdigit(d) || isalpha(d) || ispunct(d))
            {
                R[a].password.push_back(d);
                cout << "*";
            }
            if(d == '\b' && !R[a].password.empty())
            {
                R[a].password.pop_back();
                // cursor moves back 1 position
                cout << "\b";
            
            }
        } while (isdigit(d) || isalpha(d) || ispunct(d) || d == '\b' || d == '\t' || d == 32); // spacebar ASCII value 32
    }

    a++;
    cout << " \n\n\n " << ch << ch << " ACCOUNT REGISTERED SUCCESSFULLY " << ch << ch << "\n ";
    system("pause");
}

void loginAccount()
{
    system("cls");
    loggingIn;
    string t_email, t_password;
    if(a==0)
    {
        cout << " \n\n\n " << ch << ch << " NO RECORD FOUND " << ch << ch << "\n ";
        system("pause");
        return;
    }
    else
    {
        char d;
        cout << " \n\n "<< ch << ch << " ENTER EMAIL ID -> ";
        cin >> t_email;
        cout << " \n\n "<< ch << ch << " ENTER PASSWORD -> ";
        while(t_password.empty()){
            do
            {
                d = getch();
                if(isdigit(d) || isalpha(d) || ispunct(d))
                {
                    t_password.push_back(d);
                    cout << "*";
                }
                if(d == '\b' && !R[a].password.empty())
                {
                    t_password.pop_back();
                    cout << "_";
                }
            } while (isdigit(d) || isalpha(d) || ispunct(d) || d == '\b' || d == '\t' || d == 32);
        }

    }

    // match email and password
    int found = 0;
    for (int k = 0; k < a; k++)
    {
        if(t_email == R[k].email && t_password == R[k].password)
        {
            cout << "\n\n ";
            for (int i = 0; i < 25; i++)
                cout << ch;
            cout << "\n\n " << ch << ch << " USER ID -> " << R[k].id;
            cout << "\n\n " << ch << ch << " USER NAME -> " << R[k].name;
            cout << "\n\n " << ch << ch << " USER EMAIL -> " << R[k].email;
            cout << "\n\n " << ch << ch << " USER PASSWORD -> " << R[k].password;
            cout << "\n\n " << ch << ch << " USER PHONE NO. -> " << R[k].phone;
            found++;
            break;
        }
    }
    if(found == 0)
    {
        cout << " \n\n " << ch << ch << " EMAILID OR PASSWORD IS INCORRECT " << ch << ch<<"\n ";
        system("pause");
    }
    else
    {
        cout << " \n\n " << ch << ch << " LOGGED IN SUCCESSFULLY " << ch << ch<<"\n ";
        system("pause");
    }
}

void forgotEmail()
{
    system("cls");
    forgotemail;
    string uid, t_password;
    if(a==0)
    {
        cout << " \n\n\n " << ch << ch << " NO RECORD FOUND " << ch << ch << "\n ";
        system("pause");
        return;
    }
    else
    {
        cout << " \n\n "<< ch << ch << " ENTER USERID -> ";
        cin >> uid;
        char d;
        cout << " \n\n "<< ch << ch << " ENTER PASSWORD -> ";
        while(t_password.empty()){
            do
            {
                d = getch();
                if(isdigit(d) || isalpha(d) || ispunct(d))
                {
                    t_password.push_back(d);
                    cout << "*";
                }
                if(d == '\b' && !R[a].password.empty())
                {
                    t_password.pop_back();
                    cout << "_";
                }
            } while (isdigit(d) || isalpha(d) || ispunct(d) || d == '\b' || d == '\t' || d == 32);
        }

    }

    // match password and userid
    int found = 0;
    for (int k = 0; k < a; k++)
    {
        if(t_password == R[k].password && uid == R[k].id)
        {
            cout << "\n\n ";
            for (int i = 0; i < 25; i++)
                cout << ch;
            cout << "\n\n " << ch << ch << " USER ID -> " << R[k].id;
            cout << "\n\n " << ch << ch << " USER NAME -> " << R[k].name;
            cout << "\n\n " << ch << ch << " USER EMAIL -> " << R[k].email;
            cout << "\n\n " << ch << ch << " USER PASSWORD -> " << R[k].password;
            cout << "\n\n " << ch << ch << " USER PHONE NO. -> " << R[k].phone;
            found++;
            break;
        }
    }
    if(found == 0)
    {
        cout << " \n\n " << ch << ch << " USER DATA INCORRECT " << ch << ch<<"\n ";
        system("pause");
    }
    else
    {
        cout << " \n\n " << ch << ch << " INFORMATION RETRIEVED SUCCESSFULLY " << ch << ch<<"\n ";
        system("pause");
    }
}

void forgotPassword()
{
    system("cls");
    forgotpassword;
    string uid, t_email;
    if(a==0)
    {
        cout << " \n\n\n " << ch << ch << " NO RECORD FOUND " << ch << ch << "\n ";
        system("pause");
        return;
    }
    else
    {
        cout << " \n\n "<< ch << ch << " ENTER USERID -> ";
        cin >> uid;
        cout << " \n\n "<< ch << ch << " ENTER EMAIL ID -> ";
        cin >> t_email;
    }

    // match email and userid
    int found = 0;
    for (int k = 0; k < a; k++)
    {
        if(t_email == R[k].email && uid == R[k].id)
        {
            cout << "\n\n ";
            for (int i = 0; i < 25; i++)
                cout << ch;
            cout << "\n\n " << ch << ch << " USER ID -> " << R[k].id;
            cout << "\n\n " << ch << ch << " USER NAME -> " << R[k].name;
            cout << "\n\n " << ch << ch << " USER EMAIL -> " << R[k].email;
            cout << "\n\n " << ch << ch << " USER PASSWORD -> " << R[k].password;
            cout << "\n\n " << ch << ch << " USER PHONE NO. -> " << R[k].phone;
            found++;
            break;
        }
    }
    if(found == 0)
    {
        cout << " \n\n " << ch << ch << " USER DATA INCORRECT " << ch << ch<<"\n ";
        system("pause");
    }
    else
    {
        cout << " \n\n " << ch << ch << " INFORMATION RETRIEVED SUCCESSFULLY " << ch << ch<<"\n ";
        system("pause");
    }
}



int main()
{
    p:
        system("cls");
        cout << endl;
        heading;
        cout << "\n\n\n " << ch << ch << " 1.   REGISTER ACCOUNT ";
        cout << "\n\n " << ch << ch << " 2.   ACCOUNT LOGIN ";
        cout << "\n\n " << ch << ch << " 3.   FORGOT EMAIL ";
        cout << "\n\n " << ch << ch << " 4.   FORGOT PASSWORD ";
        cout << "\n\n " << ch << ch << " 5.   EXIT ";
        cout << "\n\n ";
        for (int i = 0; i < 25; i++)
            cout << ch;
        int choice;
        cout << " \n\n ENTER CHOICE -> ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerAccount();
                break;
            case 2:
                loginAccount();
                break;
            case 3:
                forgotEmail();
                break;
            case 4:
                forgotPassword();
                break;
            case 5:
                exit(0);
            default:
                cout << " \n\n\n " << ch << ch << " NOT VALID CHOICE " << ch << ch << "\n";
                system("pause");
        }
    goto p;
}