#include <bits/stdc++.h>

using namespace std;
int* minimum(int arr[][100],int n){
    int min = arr[0][0];
    int ind[2] = {0,0};
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n ; j++){
            if (min>arr[i][j]) {
                min = arr[i][j];
                ind[0] = i;
                ind[1] = j;
            }
        }
    } 
    return ind;
}
int main(){
    int arr[100][100], n;
    cout << "Enter array size: ";
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> arr[i][j];
        }
    }
    int ind[2] = minimum(arr,n);
    cout<<ind[0]<<ind[1];
}

//     1,2
// 2,1 2,2 2,3
//     3,2