#include<iostream>
#include<deque>

using namespace std;

int n;
deque<pair<int,int>> d;

// 원형
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        d.push_back({x,i});
    }

    cout << d.front().second << ' ';
    while (d.size() > 1) {
        int tmp = d.front().first;
        d.pop_front();

        if (tmp > 0) {
            while (tmp > 1) {
                d.push_back(d.front());
                d.pop_front();
                tmp--;
            }
        }
        else {
            while (tmp < 0) {
                d.push_front(d.back());
                d.pop_back();
                tmp++;
            }
        }
        cout << d.front().second << ' ';
    }
}
