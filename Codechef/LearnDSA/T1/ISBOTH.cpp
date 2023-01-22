#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n=0;
	cin>>n;
	cout<<((n%5)?(n%11?"NONE":"ONE"):(n%11?"ONE":"BOTH"));
	return 0;
}
