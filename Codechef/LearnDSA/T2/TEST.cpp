#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int a = 0;
    while (1)
    {
        cin >> a;
        if (a == 42)
            break;
        cout << a << '\n';
    }
    return 0;
}
//  We have populated the solutions for the 10 easiest problems for your support.
// Click on the SUBMIT button to make a submission to this problem.

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    // for(int i=1;i<=t;i++){
    //     int n,reverse=0,r;
    //     cin>>n;
    //     for(;n>0;n=n/10){
    //         r=n%10;
    //         reverse=reverse*10+r;
    //     }
    //     cout<<reverse<<endl;
    // }
    while(t--)
    {
        int n=0;
        cin>>n;
        int reverse=0;
        while(n)
        {
            reverse*=10;
            reverse+=(n%10);
            n/=10;
        }
        cout<<reverse<<'\n';
    }
	return 0;
}

