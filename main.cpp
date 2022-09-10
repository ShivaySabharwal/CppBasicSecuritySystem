#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int a = 0;
    string line, old, pass1, pass2, pass = "null";

    do
    {
        cout << "************************************" << endl;
        cout << "* 1 -->  CHANGE THE PASSWORD  *" << endl;
        cout << "* 2 -->  LOGIN PANEL          *" << endl;
        cout << "* 3 -->  QUIT                 *" << endl;
        cout << "************************************" << endl;

        cout << " Enter your Choice: ";
        cin >> a;

        switch (a)
        {
        case 1:
        {
            ifstream outf;
            outf.open("file.txt");

            cout << "Enter the OLD PASSWORD: ";
            cin >> old;

            if (outf.is_open())
            {

                while (!outf.eof())
                {
                    outf >> line;

                    if (old == line)
                    {
                        outf.close();
                        ofstream outf1;
                        outf1.open("file.txt");

                        if (outf1.is_open())
                        {
                            cout << "Enter you NEW PASSWORD: ";
                            cin >> pass1;
                            cout << "Enter your NEW PASSWORD AGAIN: ";
                            cin >> pass2;

                            if (pass1 == pass2)
                            {
                                outf1 << pass1;
                                cout << "PASSWORD CHANGED SUCCESSFULLY";
                            }
                        }
                    }
                    else
                    {
                        cout << "*** PLEASE ENTER A VALID PASSWORD ***";
                    }
                }
            }
            break;
        }

        case 2:
        {
            ifstream outf2;
            outf2.open("file.txt");

            cout << "PLEASE ENTER A PASSWORD: ";
            cin >> pass;

            if (outf2.is_open())
            {

                while (!outf2.eof())
                {
                    outf2 >> line;

                    if (pass == line)
                    {
                        cout << "ACCESS GRANTED" << endl;
                    }
                    else
                    {
                        cout << "PASSWORD IS INVALID" << endl;
                    }
                }
            }
            break;
        }

        case 3:
        {
            break;
        }

        default:
            cout << "ENTER VALID CHOICE" << endl;
        }
    } while (a != 3);

    return 0;
}