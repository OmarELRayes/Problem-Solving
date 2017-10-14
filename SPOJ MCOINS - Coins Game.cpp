#include <bits/stdc++.h>
using namespace std;
bool winner[1000001];

int k , l , m, input[100];
void build_DP(){
    for(int i=1; i<1000001; i++)
    {
        if(i-1 >=0 && !winner[i-1])
            winner[i] = 1;
        else if(i-k >=0 && !winner[i-k])
            winner[i] = 1;
        else if(i-l >=0 && !winner[i-l])
            winner[i] = 1;
    }
}
int main()
{
    cin >> k >> l >> m;
    for(int i=0; i<m; i++)
        cin >> input[i];
    build_DP();
    for(int i=0; i<m; i++)
    {
        if(winner[input[i]])
            cout << "A";
        else
            cout << "B";
    }

}
