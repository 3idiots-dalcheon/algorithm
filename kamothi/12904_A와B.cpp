#include<iostream>
#include<algorithm>

using namespace std;

// s를 t로 변경
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s,t;
    cin >> s >> t;

    while(s.length() < t.length()){

        if(t[t.length()-1] == 'A'){
            t.erase(t.length()-1,1);
        }else{
            t.erase(t.length()-1,1);
            reverse(t.begin(),t.end());
        }

        if(t==s){
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}
