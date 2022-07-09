#include<iostream>
using namespace std;

void TowersOfHanoi(int n, char fromTower, char toTower, char auxTower){
    if(n==1){
        cout<<"Move disk 1 from tower "<<fromTower<<" to tower "<<toTower<<endl;
        return;
    }
    TowersOfHanoi(n-1, fromTower, auxTower, toTower);

    cout << "Move disk " << n << " from tower " << fromTower << " to tower " << toTower << endl;
    
    TowersOfHanoi(n-1, auxTower,toTower,fromTower);

}

int main(){
    int n;
    char fromTower, auxTower, toTower;
    cin >> n >> fromTower >> auxTower >> toTower;
    TowersOfHanoi(n,fromTower,toTower,auxTower);
}
