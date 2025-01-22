#include<iostream>
#include<regex>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    // 정규식
    regex reg("(^[A-F]?A+F+C+[A-F]?$)");
    while(t--){
        string a;
        cin >> a;
        if(regex_match(a,reg)){
            cout << "Infected!" << '\n';
        }
        else cout << "Good" << "\n";
    }
}
