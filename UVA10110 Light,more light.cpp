#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    unsigned int s;
    while(cin>>n && n != 0){
        s = sqrt(n);
        n == s * s ? cout<<"yes\n" : cout<<"no\n";
    }
}
