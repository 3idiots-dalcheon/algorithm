#include<iostream>
#include<algorithm>

using namespace std;

// 편집 거리 알고리즘
int d[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    for(int i=0;i<=s1.size();i++) d[i][0] = i;
    for(int j=0;j<=s2.size();j++) d[0][j] = j;

    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            int tmp = 1;
            if(s1[i-1] == s2[j-1]) tmp = 0;
            d[i][j] =  min({d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1] + tmp});
        }
    }

    cout << d[s1.size()][s2.size()];

}
