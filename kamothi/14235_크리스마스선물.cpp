#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    priority_queue<int> q;
    cin >> n;

    while(n--){
        int a;
        cin >> a;
        if(a == 0){
            if(q.empty()) cout << -1 << "\n";
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else{
            while(a--){
                int b;
                cin >> b;
                q.push(b);
            }
        }
    }
}
