#include <iostream>
using namespace std;

int main() {
	int t;cin>> t;
while(t--){
    long long n,x,tmp=1; cin>>n;
 for(int i =1;i<=32;i++){
     if(tmp*2<=n) tmp*=2;
     else break;
 }   
     
 
cout<<tmp-1<<endl;}

	return 0;
}
