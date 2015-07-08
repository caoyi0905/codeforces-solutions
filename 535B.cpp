#include <iostream>
using namespace std;
int main() {
	int n,s,k=1;
	cin>>n;
	while(n>0){
		if(n%10==4) s+=k*1;
		else s+=k*2;
		k*=2; n/=10;
	}
	cout << s << endl;
	return 0;
}
