#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>c && b+c>a && a+c>b)
	    cout<<"YES\n";
	else
	    cout<<"NO\n";
	    
	return 0;
}
