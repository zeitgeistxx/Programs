#include<bits/stdc++.h>
using namespace std;
int main(){
	int num;
	int decimal=0,weight=1;
	cout<<"enter the number in binary";
	cin>>num;
	while(num>0){
		int rem=num%10;
		decimal+=rem*weight;
		num=num/10;
		weight=weight*2;
	}
	
// 	<-----Alternate method------>
// 	after taking input(from line 7) num We can also write this code
// 	string inum = to_string(num);
//  	cout << stoi(inum, 0, 2);
// 	<--Closed Alternate method-->
	
	cout<<decimal;
}
