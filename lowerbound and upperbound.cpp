#include <bits/stdc++.h>
using namespace std;
int ans;
int lowerbound(int *a,int s, int e,int key){
    if(s > e) return ans;
    if(a[e] < key) return e+1;
    if(a[s] > key) return s;
    int mid = (s+e)/2;
    if(a[mid] == key) {
        ans = mid;
        if(a[mid-1] == key) return lowerbound(a,s,mid-1,key);
        else return ans;
    }
    if(a[mid] > key){
        ans = mid;
        return lowerbound(a,s,mid-1,key);
    }
    if(a[mid] < key) return lowerbound(a,mid+1,e,key);
}
int ans1;
int upperbound(int *a,int s,int e,int key){
    //cout<<s<<" "<<e<<" "<<ans1<<endl;
    if(s > e) return ans1;
    if(a[e] < key) return e+1;
    if(a[s] > key) return s;
    int mid = (s+e) / 2;
    if(a[mid] == key){
        ans1 = mid+1;
        if(a[mid+1] == key) return upperbound(a,mid+1,e,key);
        else return ans1;
    }
    if(a[mid] > key){
        ans1 = mid;
        return upperbound(a,s,mid-1,key);
    }
    if(a[mid] < key) return upperbound(a,mid+1,e,key);
}
int main() {
	int n;
	cin >> n;
	int a[n],key = 2;
	for(int i = 0; i < n; i++) cin>>a[i];
	int res = lowerbound(a,0,n-1,key);
	int res1 = lower_bound(a,a+n,key) - a;
	cout <<"actual lb " << res1 << endl;
	cout <<"My lb " << res << endl;
	int res2 = upperbound(a,0,n - 1,key);
	int res3 = upper_bound(a,a+n,key) - a;
	cout <<"actual ub " << res3 << endl;
	cout <<"My ub " << res2 << endl;
	return 0;
}
