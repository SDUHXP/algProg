//watch out tpyos
#include <cstdio>
#include <cmath>
using namespace std;
//#define isZero(x)   (abs(x)<=1e-6?true:false)
bool isZero(double x){
	return abs(x)<1e-6;
}
const int maxN = 11;
double arr[maxN];   //reserve for more than four numbers
//every step in recursion only enumerate all possible operation between two numbers,
//which means each step reduce a number in array
bool cal24(double arr[],int n){	//calculate twenty four using arr[] ,with n numbers
	if(n==1&&isZero(arr[0]-24)) return true;
	double newArr[n];
	for(int i=0;i<n-1;i++)		//enumerate all possible pair 
		for(int j=i+1;j<n;j++){
			int cnt = 0;
			//watch out typos, writen for(int k=0;i<n;k++) will cause program collapse
			for(int k=0;k<n;k++)	//construct the new array
				if(k!=i&&k!=j) newArr[cnt++] = arr[k];
			//enumerate all possible operation
			newArr[cnt] = arr[i] + arr[j];
			if(cal24(newArr,cnt+1)) return true;
			newArr[cnt] = arr[i] - arr[j];
			if(cal24(newArr,cnt+1)) return true;
			newArr[cnt] = arr[j] - arr[i];
			if(cal24(newArr,cnt+1)) return true;
			newArr[cnt] = arr[i]*arr[j];
			if(cal24(newArr,cnt+1)) return true;
			if(!isZero(arr[j])){
				newArr[cnt] = arr[i]/arr[j];
				if(cal24(newArr,cnt+1)) return true;	
			}
			if(!isZero(arr[i])){
				newArr[cnt] = arr[j]/arr[i];	
				if(cal24(newArr,cnt+1)) return true;	
			}
	}
	return false;	
}
int main(){
	while(1){
		for(int i=0;i<4;i++) scanf("%lf",&arr[i]);	
		if(isZero(arr[0])) break;  //this problem assume four positive integer is given, so check arr[0] is enough
		if(cal24(arr,4)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}