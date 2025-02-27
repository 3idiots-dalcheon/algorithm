#include<iostream>
#include<cstring>

using namespace std;

int k;
string s[5];
// -1 or 1(반시계, 시계)
int r[5];

void check(int num, int dir){
    r[num] = dir;

    // 해당 기어 기준 왼쪽
    for(int i=num-1;i>0;i--){
        int tmp = i + 1;
        // 기어가 안돌아감
        if(s[i][2] == s[tmp][6]){
            break;
        }
        else{
            r[i] = r[tmp] * -1;
        }
    }

    // 해당 기어 기준 오른쪽
    for(int i=num+1;i<5;i++){
        int tmp = i -1;
        // 기어가 안돌아감
        if(s[i][6] == s[tmp][2]){
            break;
        }
        else{
            r[i] = r[tmp] * -1;
        }
    }


}

void rotate(){
    for(int i=1;i<=4;i++){
        // 오른쪽으로 쉬프트
        if(r[i] == 1){
            char tmp = s[i].back();
            s[i].pop_back();
            s[i] = tmp + s[i];

        }
            // 왼쪽으로 쉬프트
        else if(r[i] == -1){
            char tmp = s[i].front();
            s[i].erase(s[i].begin());
            s[i] += tmp;
        }
    }
}

int result(){
    int sum=0;
    if(s[1][0] == '1') sum +=1;
    if(s[2][0] == '1') sum +=2;
    if(s[3][0] == '1') sum +=4;
    if(s[4][0] == '1') sum +=8;

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=1;i<=4;i++) cin >> s[i];
    cin >> k;

    while(k--){
        int a,b;
        cin >> a >> b;
        check(a,b);
        rotate();
        memset(r,0,sizeof(r));
    }

    cout << result();


}
