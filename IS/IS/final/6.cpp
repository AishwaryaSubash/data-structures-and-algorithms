// USER AUTH

#include <bits/stdc++.h>
#include "validpasswordcheck.cpp"
using namespace std;
void addUser()
{
   ifstream inputFile;
   ofstream outputFile;
   inputFile.open("user.txt");
   if (inputFile.is_open())
   {
       string name, password;
       cout << "Enter Name : ";
       cin >> name;
       bool valid = false;
       while (!valid)
       {
           cout << "Enter Password : ";
           cin >> password;
           valid = checkPassword(password);
       }
       if (valid)
       {
           string data = '\n' + name + '|' + password;
           outputFile.open("user.txt", ios::app);
           outputFile << data;
       }
   }
   outputFile.close();
   inputFile.close();
}
void updatePassword()
{
   ifstream inputFile;
   ofstream outputFile;
   inputFile.open("user.txt");
   vector<string> v;
   if (inputFile.is_open())
   {
       bool change = false;
       while (!inputFile.eof())
       {
           string line;
           getline(inputFile, line);
           v.push_back(line);
       }
       string name;
       cout << "Enter Name : ";
       cin >> name;
       for (int j = 0; j < v.size(); j++)
       {
           string line = v.at(j);
           string temp = "";


           for (int i = 0; i < line.length(); i++)
           {
               if (line[i] != '|')
               {
                   temp += line[i];
               }
               else
               {
                   if (name.compare(temp) == 0)
                   {
                       string oldpwd;
                       bool valid = false;
                       while (!valid)
                       {
                           cout << "Enter old password : ";
                           cin >> oldpwd;
                           string expwd = line.substr(i + 1, line.length());
                           if (oldpwd.compare(expwd) == 0)
                           {
                               valid = true;
                           }
                       }
                       if (valid)
                       {
                           v.at(j).erase(v.at(j).begin() + i + 1, v.at(j).begin() + v.at(j).length());
                           change = true;
                           string newpwd;
                           bool check = false;
                           while (!check)
                           {
                               cout << "Enter new password : ";
                               cin >> newpwd;
                               check = checkPassword(newpwd);
                           }
                           v.at(j) += newpwd;
                           break;
                       }
                   }
                   else
                   {
                       break;
                   }
               }
               if (change)
                   break;
           }
       }
       if (change)
       {
           outputFile.open("user.txt");
           string all = "";
           for (int i = 0; i < v.size(); i++)
           {
               all += v.at(i) + ((i != v.size() - 1) ? "\n" : "");
           }
           outputFile << all;
       }
       else
       {
           cout << "User not found\n";
       }
   }
   inputFile.close();
   outputFile.close();
}
void removeUser()
{
   ifstream inputFile;
   ofstream outputFile;
   inputFile.open("user.txt");
   vector<string> v;
   if (inputFile.is_open())
   {
       bool change = false;
       while (!inputFile.eof())
       {
           string line;
           getline(inputFile, line);
           v.push_back(line);
       }
       string name;
       cout << "Enter Name : ";
       cin >> name;
       for (int j = 0; j < v.size(); j++)
       {
           string line = v.at(j);
           string temp = "";


           for (int i = 0; i < line.length(); i++)
           {
               if (line[i] != '|')
               {
                   temp += line[i];
               }
               else
               {
                   if (name.compare(temp) == 0)
                   {
                       string oldpwd;
                       bool valid = false;
                       while (!valid)
                       {
                           cout << "Enter password : ";
                           cin >> oldpwd;
                           string expwd = line.substr(i + 1, line.length());
                           if (oldpwd.compare(expwd) == 0)
                           {
                               valid = true;
                           }
                       }
                       if (valid)
                       {
                           v.erase(v.begin() + j);
                           change = true;
                           break;
                       }
                   }
                   else
                   {
                       break;
                   }
               }
               if (change)
                   break;
           }
       }
       if (change)
       {
           outputFile.open("user.txt");
           string all = "";
           for (int i = 0; i < v.size(); i++)
           {
               all += v.at(i) + ((i != v.size() - 1) ? "\n" : "");
           }
           outputFile << all;
       }
       else
       {
           cout << "User not found\n";
       }
   }
   inputFile.close();
   outputFile.close();
}
void authUser()
{
   ifstream inputFile;
   inputFile.open("user.txt");
   if (inputFile.is_open())
   {
       string name;
       cout << "Enter Name : ";
       cin >> name;
       while (!inputFile.eof())
       {
           string line;
           getline(inputFile, line);
           string temp = "";
           for (int i = 0; i < line.length(); i++)
           {
               if (line[i] != '|')
               {
                   temp += line[i];
               }
               else
               {
                   if (name.compare(temp) == 0)
                   {
                       string oldpwd;
                       bool valid = false;
                       while (!valid)
                       {
                           cout << "Enter password : ";
                           cin >> oldpwd;
                           string expwd = line.substr(i + 1, line.length());
                           if (oldpwd.compare(expwd) == 0)
                           {
                               valid = true;
                               cout << "Valid";
                               inputFile.close();
                               return;
                           }
                           else
                           {
                               cout << "Invalid! Try Again" << endl;
                           }
                       }
                   }
                   else
                   {
                       break;
                   }
               }
           }
       }
   }
   inputFile.close();
}
int main()
{
   int choice;
   do
   {
       cout << "1.Add user\n2.Update user\n3.Remove user\n4.Authenticate user\n5.Exit";
       cout << "Enter choice: ";
       cin >> choice;
       switch (choice)
       {
       case 1:
           addUser();
           break;
       case 2:
           updatePassword();
           break;
       case 3:
           removeUser();
           break;
       case 4:
           authUser();
           break;
       }
   } while (choice != 5);
}
