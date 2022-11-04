#include<iostream>
#include<climits>
using namespace std;

int getMax(int a[], int n){
	int max = INT_MIN; 
	for(int i=0; i<n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
}

void countSort(int a[], int n){
	int max = getMax(a, n);
	int count[max+1] = {0};
	int output[n];
	
	for(int i=0; i<n; i++) count[a[i]]++;
	
	// Relative frequency
	for(int  i=1; i<=max; i++) count[i]+=count[i-1];
	
	for(int i=n-1; i>=0; i--){
		int index = count[a[i]] - 1;
		count[a[i]]--;
		output[index] = a[i];
	}
	
	for(int i=0; i<n; i++) a[i] = output[i];
	
}






int main(){
	int n;
	cout << "Enter size of array -> ";
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i]; 
	}
	//cout << getMax(a,n);
	
	countSort(a,n);
	for(int i=0; i<n; i++) cout << a[i] << " "; 
}



