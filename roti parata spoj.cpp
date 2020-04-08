#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int ans;
bool parata(int *a,int minute,int tar,int l){
    int count = 0;
    for(int i = 0; i < l;i++){
        int val = 0;
        int k = 1;
        if(a[i] > minute && count < tar) return false;
        while(val < minute){
            val += a[i]*k;
            if(val > minute) break;
            count++;
            k++;
            if(count == tar) return true;
        }
    }
    return false;
}
int solve(int *a,int s,int e,int n,int l){
    if(s > e) return ans;
    int mid = (s+e)/2;
    if(parata(a,mid,n,l)) {
        ans = mid;
        return solve(a,s,mid-1,n,l);
    }
    else return solve(a,mid+1,e,n,l);
}
int main(void){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int l;
        cin>>l;
        int a[l];
        int e=-1;
        for(int i = 0; i < l; i++) {
                cin>>a[i];
                e=max(e,a[i]);
        }
        sort(a,a+l);
        int count = 0;
        int val = 0;
        int k = 1;
        while(count < n){
            val += a[l-1] * k;
            count++;
            k++;
        }
        e=INT_MAX;
        ans = 0;
        cout<<solve(a,a[0],e,n,l)<<endl;
    }
}
