#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,k;
    int result=0;
    cin >> a >> k;

    while(a < k){
        if(k%2 == 0 && k/2 >= a) k/=2;
        else k -=1;
        result++;
    }

    cout << result;
}
