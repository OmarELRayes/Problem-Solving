#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp(int i , int j){
    if(a.size() == i || b.size() == j)
        return 0;
    if(a[i] == b[j])
        return 1 + dp(i+1,j+1);
    return max(dp(i+1,j),dp(i,j+1));
}
int main()
{
    cin >> a >>b;
    cout << dp(0,0);
}
