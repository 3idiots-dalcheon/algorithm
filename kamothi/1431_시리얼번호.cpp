#include<iostream>
#include<algorithm>

using namespace std;

int cmp(string a, string b) {
    int asize = a.size();
    int bsize = b.size();
    int asum = 0;
    int bsum = 0;

    if (asize != bsize) {
        return asize < bsize;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            asum += int(a[i]) - 48;
        }

        if (b[i] >= '0' && b[i] <= '9') {
            bsum += int(b[i]) - 48;
        }
    }

    if (asum != bsum) {
        return asum < bsum;
    }

    return a < b;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s[50];
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> s[i];
    }

    sort(s,s+n, cmp);

    for(int i=0;i<n;i++) cout << s[i] << "\n";

}
