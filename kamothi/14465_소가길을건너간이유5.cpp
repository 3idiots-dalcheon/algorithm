#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k,b;
    cin >> n >> k >> b;

    for(int i=0;i<b;i++) {
        int tmp;
        cin >> tmp;
        arr[tmp] = 1;
    }

    int tmp=0;

    for (int i=1; i<=k; i++)
        if (arr[i]) tmp++;

    int result = tmp;
    for (int i=2; i<= n-k+1; i++) {
        if (arr[i-1]) tmp--;
        if (arr[i+k-1]) tmp++;
        result = min(result, tmp);
    }

    cout << result;

}
