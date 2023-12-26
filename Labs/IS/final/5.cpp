//PASSWORD VALIDATION




#include <bits/stdc++.h>
using namespace std;
set<string> errorString;
int isNumber(string s)
{
   int n = 0;
   for (int i = 0; i < s.length(); i++)
       if (isdigit(s[i]))
           n++;
   return n;
}
int isSpecial(string s)
{
   int n = 0;
   for (int i = 0; i < s.length(); i++)
   {
       if (!isalnum(s[i]))
       {
           n++;
       }
   }
   return n;
}
int isAllLower(string s)
{
   int n = 0;
   for (int i = 0; i < s.length(); i++)
   {
       if (islower(s[i]))
           n++;
   }
   return n;
}
int isAllUpper(string s)
{
   int n = 0;
   for (int i = 0; i < s.length(); i++)
   {
       if (isupper(s[i]))
           n++;
   }
   return n;
}
bool isConsectiveSame1(string s)
{
   set<char> smt(s.begin(), s.end());
   return (smt.size() == 1);
}
bool consec(int len, string line)
{
   bool valid = true;
   for (int i = 0; i < len; i++)
   {
       if (i + 3 < len + 1)
       {
           string sub = line.substr(i, 3);
           if (isNumber(sub) == 3)
           {
               errorString.insert("Consecutive Numbers Not Allowed");
               valid = false;
           }
           if (isSpecial(sub) == 3)
           {
               errorString.insert("Consecutive Special Not Allowed");
               valid = false;
           }
           if (isAllLower(sub) == 3)
           {
               cout << "All Lower" << endl;
               errorString.insert("Consecutive LowerCase Not Allowed");
               valid = false;
           }
           if (isAllUpper(sub) == 3)
           {
               errorString.insert("Consecutive UpperCase Not Allowed");
               valid = false;
           }
           if (isConsectiveSame1(sub))
           {
               errorString.insert("Consecutive Same Character Not Allowed");
               valid = false;
           }
       }
   }
   return valid;
}
bool checkLength(int length)
{
   bool validLength;
   if ((length >= 10) && (length <= 15))
   {
       validLength = true;
   }
   else
   {
       validLength = false;
       errorString.insert("The password must be between 10 and 15 characters");
   }
   return validLength;
}
bool lowerCase(int length, string line)
{


   if (isAllLower(line) < 1)
   {
       errorString.insert("Must have at least 1 lower Case letter");
       return false;
   }


   return true;
}
bool upperCase(int length, string line)
{


   if (isAllUpper(line) < 1)
   {
       errorString.insert("Must have at least 1 Upper Case letter");
       return false;
   }
   return true;
}
bool specialChar(int length, string line)
{
   if (isSpecial(line) < 1)
   {
       errorString.insert("Must have atleast 1 special characters");
       return false;
   }
   return true;
}
bool correctDigits(int length, string line)
{
   if (isNumber(line) < 1)
   {
       errorString.insert("Must have at least one digit");
       return false;
   }
   return true;
}
int main()
{
   string fileName;
   ifstream myFile;
   string line;
   int length;
   cout << "Enter password file: ";
   cin >> fileName;
   myFile.open(fileName.c_str());
   if (myFile.is_open())
   {
       while (!myFile.eof())
       {
           getline(myFile, line);
           length = line.length();
           errorString.clear();
           cout << "Proposed Password: " << line << endl;
           if (checkLength(length) == false || lowerCase(length, line) == false || upperCase(length, line) == false || correctDigits(length, line) == false || specialChar(length, line) == false || consec(length, line) == false)
           {
               vector<string> errorVec(errorString.begin(), errorString.end());
               for (int i = 0; i < errorVec.size(); i++)
               {
                   cout << i + 1 << " : " << errorVec.at(i) << endl;
               }
               cout << "Password is Invalid\n"
                    << endl;
           }
           else
           {
               cout << "Password is Valid\n"
                    << endl;
           }
       }
       myFile.close();
   }
   else
   {
       cerr << "Unable to open file " << fileName << " - does not exist in current directory";
       return 1;
   }
   return 0;
}
