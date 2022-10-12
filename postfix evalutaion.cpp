#include<bits/stdc++.h>
using namespace std;
int postfixevaluation(string s){
	int op1,op2,result=0;
	stack<int>st;
	for(int i=0;i<s.length();i++ ){
		if(s[i]>='0' &&s[i]<='9'){
			st.push(s[i]-'0');
		}else{
			op2=st.top();
			st.pop();
			op1=st.top();
			st.pop();
			switch(s[i]){
				case  '+':
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op1);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					st.push(op1/op2);
					break;
				case '^':
					st.push(pow(op1,op2));
					break;
				default:
					break;
			}
				
			}
		}
		return st.top();
	}
	

int main(){
	string s="46+2/5*7+";
	cout<<postfixevaluation(s)<<endl;
	return 0;
}