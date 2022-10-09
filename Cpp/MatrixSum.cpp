#include <bits/stdc++.h>
#include <vector>

using namespace std;
int *minimum(int arr[][100], int n)
{
    int min = arr[0][0];
    static int ind[2];
    ind[0] = 0;
    ind[1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min > arr[i][j])
            {
                min = arr[i][j];
                ind[0] = i;
                ind[1] = j;
            }
        }
    }
    return ind;
}
vector<int> v;
void adj(int ind[2], int arr[][100], int n)
{
    if (ind[0] - 1 >= 0)
    {
        // cout << arr[ind[0] - 1][ind[1]] << endl;
        // v.push_back(arr[ind[0] - 1][ind[1]]);
        v.push_back(arr[ind[0]][ind[1]]);
        if (arr[ind[0]][ind[1]] == arr[ind[0] - 1][ind[1]] + 1)
        {
            int a[2];
            a[0] = ind[0] - 1;
            a[1] = ind[1];
            for (auto i : v)
            {
                cout << i;
            }
            adj(a, arr, n);
        }
    }
    if (ind[0] + 1 < n)
    {
        // cout << arr[ind[0] + 1][ind[1]] << endl;
        // v.push_back(arr[ind[0] + 1][ind[1]]);
    }
    if (ind[1] - 1 >= 0)
    {
        // cout << arr[ind[0]][ind[1] - 1] << endl;
        // v.push_back(arr[ind[0]][ind[1] - 1]);
    }
    if (ind[1] + 1 < n)
    {
        // cout << arr[ind[0]][ind[1] + 1] << endl;
        // v.push_back(arr[ind[0]][ind[1] + 1]);
    }
}
int main()
{
    int arr[100][100], n;
    cout << "Enter array size: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    // int num;
    // cout << "to be searched: ";
    // cin >> num;
    // int k = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[i][j] == num + k)
    //         {
    //         }
    //     }
    //     k++;
    // }
    int *ind;
    ind = minimum(arr, n);
    cout << ind[0] << " " << ind[1] << endl;
    adj(ind, arr, n);
    // vector<int> v;
    // if (ind[0] - 1 >= 0)
    // {
    //     // cout << arr[ind[0] - 1][ind[1]] << endl;
    //     // v.push_back(arr[ind[0] - 1][ind[1]]);
    //     if(arr[ind[0]][ind[1]] == arr[ind[0] - 1][ind[1]] + 1){

    //     }
    // }
    // if (ind[0] + 1 < n)
    // {
    //     // cout << arr[ind[0] + 1][ind[1]] << endl;
    //     // v.push_back(arr[ind[0] + 1][ind[1]]);
    // }
    // if (ind[1] - 1 >= 0)
    // {
    //     // cout << arr[ind[0]][ind[1] - 1] << endl;
    //     // v.push_back(arr[ind[0]][ind[1] - 1]);
    // }
    // if (ind[1] + 1 < n)
    // {
    //     // cout << arr[ind[0]][ind[1] + 1] << endl;
    //     //v.push_back(arr[ind[0]][ind[1] + 1]);
    // }
    // for (auto i : v){
    //     cout<<i;
    // }
}

// 0,0     0,2
//     0,1
// 1,0 1,1 1,2
//     2,1
// 2,0      2,2
