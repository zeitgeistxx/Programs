#include<iostream>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    int a[m][n];

    for(int i = 0; i <m; i++){
        for(int j = 0; j <n; j++){
            cin >> a[i][j];
        }
    }

    int target;
    cin >> target;

    //Linear search approach
    // int key = 0;
    // for(int i = 0; i <m; i++){
    //     for(int j = 0; j <n; j++){
    //         if(a[i][j] == item){
    //             key = 1;
    //             break;
    //         }
    //     }
    // }

    // if(key==1){
    //     cout<<"Element present"<<endl;
    // }
    // else{
    //     cout<<"Element not present"<<endl;
    // }


    //**Rows and columns are sorted
    int r = 0, c = n - 1;
    bool found = false;
    while(r<m && c>=0){
        if(a[r][c]==target){
            found = true;
        }
        if(a[r][c]>target){
            c--;
        }
        else{
            r++;
        }
    }

    if(found){
        cout << "Element found" << endl;
    }
    else{
        cout << "Element does not exist" << endl;
    }
}