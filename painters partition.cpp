long long int ans;
bool possible(vector<int> &a,int A,int val){
    //cout<<val<<endl;
    int painter = 1;
    long long int sum = 0, len = a.size();
    for(int i = 0; i < len; i++){
        if(a[i] > val) return false;
        sum += a[i];
        if(sum > val){
            sum = a[i];
            painter++;
            
        }
    }
    if(painter <= A) return true;
    return false;
}
long long int solve(vector<int> &C,long long int s,long long int e,int A){
    if(s > e) return ans;
    long long int mid = (s+e)/2;
    if(possible(C,A,mid)) {
        ans = mid;
        //cout<<s<<" "<<e<<" "<<ans<<endl;
        return solve(C,s,mid-1,A);
    }
    else return solve(C,mid+1,e,A);
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int len = C.size();
    /*if(A >= len) {
        long long int res = -1;
        for(int i = 0; i < len; i++) {
            if(res < C[i]) res = C[i];
        }
        return (B*res)%10000003;
    }*/
    long long int sum = 0;
    ans = 0;
    for(int i = 0; i < len; i++) {
        sum += C[i];
        sum = sum %10000003;
    }
    return (B * solve(C,C[0],sum,A))%10000003;
}
