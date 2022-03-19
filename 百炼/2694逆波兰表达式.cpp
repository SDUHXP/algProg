#include <cstdio>
#include <cstdlib>
using namespace std;
/*
definition of RPN(reverse polish notation): number is elementary RPN,  an operator fllowed by two PRN consist new PRN
function of cal(): read a RPN from stdin and return it's value recrusively;
*/
double cal(){
	char num[10];
	scanf("%s",num);
	switch(num[0]){
		case '+': return cal() + cal();
		case '-': return cal() - cal();
		case '*': return cal()*cal();
		case '/' : return cal()/cal();
		default: return atof(num); 
	}		
		
}
int main(){
	double ans = cal();
	printf("%f",ans);
}