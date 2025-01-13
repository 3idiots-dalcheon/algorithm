#include<iostream>
#include<algorithm>

using namespace std;

int n,result = 1e9;
int arrS[10];
int arrB[10];

void solve(int now, int s, int b){
    if(now == n){
        if(b!=0) result = min(result,abs(s-b));
        return;
    }
    solve(now + 1, s, b);
    solve(now + 1, s * arrS[now], b + arrB[now]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arrS[i] >> arrB[i];
    }

    solve(0,1,0);

    cout << result;
}
