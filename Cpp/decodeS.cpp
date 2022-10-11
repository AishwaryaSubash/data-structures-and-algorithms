#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    string decodedString(string s){
        int currNo=0;
       string currString="";
       int prevNo;
       string prevString;
       stack<string>stringstack;
       stack<int>numstack;
       for(int i=0;i<s.size();i++)
       {
           if(isdigit(s[i])) currNo = currNo*10 + (s[i]-'0');
           if(isalpha(s[i])) currString += s[i];
           if(s[i] == '[')
           {
               stringstack.push(currString);
               numstack.push(currNo);
               currNo=0;
               currString="";
           }
           if(s[i] == ']')
           {
               prevNo = numstack.top();
               numstack.pop();
               prevString = stringstack.top();
               stringstack.pop();
               
               while(prevNo--)
               {
                  prevString += currString;
               }
               currString = prevString;
           }
       }
       return currString;  // code here
    }
};





// bool numberCheck(char i)
// {
//     if (i == '1' || i == '2' || i == '3' || i == '4' || i == '3' || i == '6' || i == '7' || i == '8' || i == '9' || i == '0')
//     {
//         return true;
//     }
//     return false;
// }
// int main()
// {
//     string val;
//     string ans;
//     stack<char> v;
//     cin >> val;

//     string temp = "";
//     string num = "";

//     for (int i = 0; i < val.length(); i++)
//     {

//         if (numberCheck(val[i]))
//         {
//             num += val[i];
//         }

//         else if (val[i] == ']')
//         {
//             while (1)
//             {
//                 v.top();
//                 v.pop();
//                 if (val[i] == '[')
//                 {
//                 }
//             }
//             {
//                 v.push(val[i]);
//             }
//         }
//     }
//     cout << num << " ";

    // 3[n3[ffc]13[d13[caav]]]
    //  typeid(vsrname).name()
// }
