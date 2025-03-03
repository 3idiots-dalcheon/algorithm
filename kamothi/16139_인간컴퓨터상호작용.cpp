#include<iostream>

using namespace std;

// S 문자열에서 특정 a와 구간 l,r 사이에서 몇번 나오는가
// 질문은 q번
string s;
char a;
int l,r,q;
int dp[200001][27];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    cin >> q;
    dp[0][s[0] - 'a'] = 1;
    for(int i=1;i<=s.size();i++){
        for (int j = 0; j < 27; j++)
        {
            dp[i][j] = dp[i-1][j];
        }
        
        dp[i][s[i] - 'a']++;
    }

    for(int i=0;i<q;i++){
        cin >> a >> l >> r;
        if(l == 0) cout <<  dp[r][a - 'a'] << "\n";
        else cout << dp[r][a - 'a'] - dp[l-1][a - 'a'] << "\n";
    }
}
