#include<iostream>
#include<algorithm>

using namespace std;

// 연산자의 우선 순위는 무시된다.
// 나눗셈은 몫만 취한다.

int n;
long long arr[11];
int opr[4];
int tmp[11];
long long result_max = -100e9,result_min=100e9;
// 연산자는 0,1,2,3

void solve(int now){
    if(now == (n-1)){
        // 여기는 마지막 연산, 결과 체크
        long long result  = arr[0];
        for(int i=1;i<n;i++){
            if(tmp[i-1] == 0){
                result += arr[i];
            }
            else if(tmp[i-1] == 1){
                result -= arr[i];
            }
            else if(tmp[i-1] == 2){
                result *= arr[i];
            }
            else{
                result /= arr[i];
            }
        }

        result_max = max(result,result_max);
        result_min = min(result,result_min);

        return;
    }

    for (int i = 0; i < 4; i++) {
		if (opr[i] != 0) {
			tmp[now] = i;
			--opr[i];
			solve(now + 1);
			++opr[i];
		}
	}

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<4;i++) cin >> opr[i];

    solve(0);
    cout << result_max << "\n" << result_min;
    
}
