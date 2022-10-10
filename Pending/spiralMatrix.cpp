//https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1?page=2&curated[]=1&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v;

    for (int i = 0; i < r; i++)
    {
        vector<int> temp;
        int a;
        for (int j = 0; j < c; j++)
        {
            cin >> a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }

    int i = 0, j = 0;
    int cnt = 0;
    // for (int k = 0; k < r * c; k++)
    // {
    //     cnt = 0;
    //     if (j < c)
    //     {
    //         cout << v[i][j++] << " ";
    //     }
    //     else
    //     {   
    //     //     if (k % r ==0)
    //     //         i = 0;
    //     //     cout << v[i++][j] << " ";
    //     // }
    //     // if (k % (r + c) == 0)
    //     //     cnt++;
        
    //     if(i < r){
    //         cout << v[i++][j] << " "
    //     }
    //     }
    // }

    //(0,0)0 (0,1)1 (0,2)2
    //(1,0)1 (1,1)2 (1,2)3
    //(2,0)2 (2,1)3 (2,2)4
    //(3,0)3 (3,1)4 (3,2)5

    /*
    1 2 3
    4 5 6
    7 8 9
    10 11 12
    */
    return 0;
}