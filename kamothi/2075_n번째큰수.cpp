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

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t;
            cin >> t;
            q.push(-t);

            if(q.size() > n) q.pop();
        }
    }

    cout << -q.top();


}
