#include <bits/stdc++.h>
using namespace std;


// string lstrip(string line)
// {
//     string l = "";
//     for (int i = 0; i < line.length(); i++)
//     {
//         if (line[i] != ' ')
//         {
//             l = line.substr(i, line.length());
//             break;
//         }
//     }
//     return l;
// }


vector<string> allWords(string line)
{
   string l = "";
   vector<string> v;
   for (int i = 0; i < line.length(); i++)
   {
       if (line[i] != ' ')
       {
           l += line[i];
       }
       else
       {
           if (l != "" && l != " ")
           {
               v.push_back(l);
           }
           l = "";
       }
   }
   if (l != "" && l != " ")
   {
       v.push_back(l);
   }
   return v;
}
int main()
{
   ifstream myFile;
   string line;
   int length;
   myFile.open("sample.c");
   if (myFile.is_open())
   {
       map<string, string> mp;
       while (!myFile.eof())
       {
           getline(myFile, line);
           length = line.length();
           vector<string> first = allWords(line);
           if (first.front() == "int" || first.front() == "float" || first.front() == "char" || first.front() == "double")
           {
               for (int i = 1; i < first.size(); i++)
               {
                   string fir = "";
                   for (int j = 0; j < first.at(i).length(); j++)
                   {
                       if (isalnum(first.at(i).at(j)) || first.at(i).at(j) == '_')
                       {
                           fir += first.at(i).at(j);
                       }
                   }
                   mp[fir] = first.front();
               }
           }
       }
       cout << "Variable -> Type" << endl;
       map<string, string>::iterator it = mp.begin();
       while (it != mp.end())
       {
           cout << it->first << "\t->\t" << it->second << endl;
           ++it;
       }
       myFile.close();
       cout << endl
            << "Enter an input string : ";
       string input = "";
       getline(cin, input);
       vector<string> splitIn = allWords(input);
       vector<string> precedence = {"double", "float", "int"};
       string result = "";
       if (mp[splitIn.front()] == "int" && mp[splitIn.back()] == "int" && splitIn.at(1) == "%")
       {
           cout << mp[splitIn.front()] << " " << splitIn.at(1) << " " << mp[splitIn.back()] << " = " << mp[splitIn.back()];
       }
       else if ((mp[splitIn.front()] == "int" || mp[splitIn.front()] == "float" || mp[splitIn.front()] == "double") && (mp[splitIn.back()] == "int" || mp[splitIn.back()] == "float" || mp[splitIn.back()] == "double") && (splitIn.at(1) == "+" || splitIn.at(1) == "-" || splitIn.at(1) == "*" || splitIn.at(1) == "/"))
       {
           if (mp[splitIn.front()] == mp[splitIn.back()])
           {
               result = mp[splitIn.back()];
           }
           else
           {
               int i1, i2;
               for (int i = 0; i < precedence.size(); i++)
               {
                   if (precedence[i] == mp[splitIn.front()])
                   {
                       i1 = i;
                   }
                   if (precedence[i] == mp[splitIn.back()])
                   {
                       i2 = i;
                   }
               }
               if (i1 > i2)
               {
                   result = mp[splitIn.back()];
               }
               else
               {
                   result = mp[splitIn.front()];
               }
           }
           cout << mp[splitIn.front()] << " " << splitIn.at(1) << " " << mp[splitIn.back()] << " = " << result;
       }
       else if ((mp[splitIn.front()] == "char" || mp[splitIn.front()] == "int") && (mp[splitIn.back()] == "char" || mp[splitIn.back()] == "int") && (splitIn.at(1) == "+" || splitIn.at(1) == "-"))
       {
           if (mp[splitIn.front()] == mp[splitIn.back()])
           {
               result = "char";
           }
           else
           {
               result = "int";
           }
           cout << mp[splitIn.front()] << " " << splitIn.at(1) << " " << mp[splitIn.back()] << " = " << result;
       }
       else
       {
           cout << "Invalid expression";
       }
       cout << endl;
   }
   else
   {
       cerr << "Unable to open file - does not exist in current directory";
       return 1;
   }
   return 0;
}
