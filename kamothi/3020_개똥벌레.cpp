#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,h;
    int cnt=0;
    vector<int> s,j;
    cin >> n >> h;

    for(int i=0;i<n/2;i++) {
        int a,b;
        cin >> a >> b;
        s.push_back(a), j.push_back(b);
    }

    sort(s.begin(),s.end());
    sort(j.begin(),j.end());
    int min = 1e9;

    for(int i=1;i<=h;i++) {
        int down = lower_bound(s.begin(), s.end(), i) - s.begin();
        int up = lower_bound(j.begin(), j.end(), h - i + 1) - j.begin();

        int tmp = n-(down+up);

        if(tmp < min) {
            min = tmp;
            cnt = 1;
        }
        else if(tmp == min) cnt++;
    }
    cout << min << " " << cnt;
}
