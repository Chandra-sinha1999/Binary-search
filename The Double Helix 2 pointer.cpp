#include<bits/stdc++.h>
using namespace std;
int solve(int *a,int *b,int n,int m){
    int pre[n+1],pos[m+1];
    pre[0] = 0;
    pos[0] = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            pre[i+1] = pre[i] + a[i];
            i++;
        }
        else if(a[i] > b[j]){
            pos[j+1] = pos[j] + b[j];
            j++;
        }
        else{
            if(pre[i] > pos[j]){
                pre[i+1] = pre[i] + a[i];
                pos[j+1] = pre[i+1];
                i++;
                j++;
            }
            else if(pre[i] < pos[j]){
                pos[j+1] = pos[j] + b[j];
                pre[i+1] = pos[j+1];
                j++;
                i++;
            }
            else{
                pre[i+1] = pre[i] + a[i];
                pos[j+1] = pre[i+1];
                i++;
                j++;
            }
        }
    }
    if(i == n && j < m){
        while(j != m){
            pos[j+1] = pos[j] + b[j];
            j++;
        }
    }
    if(i < n && j == m){
        while(i != n){
            pre[i+1] = pre[i] + a[i];
            i++;
        }
    }
    return max(pre[n],pos[m]);
}
int main(void){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int m;
        cin>>m;
        int b[m];
        for(int j = 0;j < m; j++) cin >> b[j];
        cout<<solve(a,b,n,m)<<endl;
    }
}
