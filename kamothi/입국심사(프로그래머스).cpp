#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {    
    long long answer = 1e18;
    long long left = times[0];
    long long right = (long long)times.back() * (long long)n;
    
    while(left <= right){
        long long mid = (left+right)/2;
        long long cnt = 0;
        for(int i=0;i<times.size();i++){
            cnt += mid / times[i];
        }
        if(cnt >= n) {
            answer = min(answer, mid);
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return answer;
}
