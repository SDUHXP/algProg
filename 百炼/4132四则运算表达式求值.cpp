//factor , term and expression is catagoried by precedence
#include <iostream>
#include <iomanip>
using namespace std;
double calExp();	//terms connected by plus and minus operator(with lower precedence)
double calTerm();	//factors connected by multiply and divide operator (with higher precedence),comprise term
double calFac();	//elementary factors include numbers and expression in parenthesis
int main(){
	double ans = calExp();
	cout<<fixed<<setprecision(2)<<ans<<endl;
}
double calExp(){	//whether whitespace contains in expression ,it is important and change the processing method
	double ans = calTerm();
	while(true){
		char op = cin.peek();
		if(op=='+'||op=='-'){
			cin.get();	
			if(op=='+') ans += calTerm();
			else ans -= calTerm();		
		}
		else break;
	}
	return ans;
}
double calTerm(){
	double ans = calFac();
	while(true){
		char op = cin.peek();
		if(op=='*'||op=='/'){
			cin.get();
			if(op=='*') ans *= calFac();
			else ans /= calFac();
		}
		else break;
	}
	return ans;
}
double calFac(){
	char ch = cin.peek();
	double ans = 0;
	if(ch=='('){
		cin.get();
		ans = calExp();
		cin.get();
	}
	else{
		double base = 0.1;
		bool intFlag = true;   //flag to index whether integer part
		while(isdigit(ch)||ch=='.'){
			if(isdigit(ch)){
				if(intFlag) ans = ans*10 + ch -'0';
				else{
					ans += (ch-'0')*base;
					base /= 10;
				}
			}
			if(ch=='.') intFlag = false;
			cin.get();
			ch = cin.peek();
		}	
	}
	return ans;
}