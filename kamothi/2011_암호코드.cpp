#include<iostream>

using namespace std;


long long dp[5001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    if(input[0] == '0'){
        cout << 0;
        return 0;
    }

    dp[0]=1, dp[1]=1;

    for(int i=2;i<=input.size();i++){
        if(input[i-1] != '0') dp[i] = dp[i-1]%1000000;

        int temp = (input[i-2]-'0')*10 + input[i-1]-'0';

        if(10 <= temp && temp <= 26) dp[i]=(dp[i]+dp[i-2])%1000000;
    }

    cout << dp[input.size()];

}
