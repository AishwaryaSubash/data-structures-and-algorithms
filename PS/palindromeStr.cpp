#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    // scanf("%[^\n]", s);
    // scanf("%s",s);
    getline(cin, s);
    cout<<s<<endl;
    string t;
    int i=0;
    while (s[i]!='\0') {
        if (isalnum(s[i])) {
            t+=tolower(s[i]);
        }
        i++;
    }
    cout<<t<<" "<<t.size()<<endl;
    string u;
    for (int j=t.length()-1 ; j>=0 ; j--) {
        u+=t[j];
    }
    cout<<u<<endl;
    if (t==u) {
        cout<<"yes";
    } else cout<<"no";
    return 0;
}