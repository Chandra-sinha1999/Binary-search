#include <bits/stdc++.h>
using namespace std;
int ans;
int traillin(int n){
    int count = 0;
    for(int i = 5; n/i >= 1; i *= 5){
        count += n/i;
    }
    return count;
}
int solve(int s,int e,int n){
    if(s > e) return ans;
    int mid = (s+e)/2;
    if(traillin(mid) < n) return solve(mid+1,e,n);
    if(traillin(mid) >= n) {
        ans = mid;
        return solve(s,mid-1,n);
    }
}
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    cout<<solve(5,n*5,n)<<endl;
	}
}
