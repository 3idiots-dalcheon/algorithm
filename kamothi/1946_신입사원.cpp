#include<iostream>
#include<algorithm>

using namespace std;

int t,n;
pair<int,int> arr[100000];

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first< b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> t;

    while(t--){
        cin >> n;

        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            arr[i] = {a,b};
        }

        sort(arr,arr+n);
        
        int tmp = arr[0].second, count = 0;
        
        for (int j = 1; j < n; j++) {
            if (tmp <= arr[j].second) count++;
            else tmp = arr[j].second;
        }

        cout << n-count << "\n";
    }
}
