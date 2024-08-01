#include <bits/stdc++.h>
using namespace std;

class SGTree{
   
   vector<vector<int>> seg;
   public:
   SGTree(int n){
    seg.resize(4*n);
   }
   vector<int> calc(vector<int> l,vector<int> r){
         vector<int> ans(3);
         ans[2]=l[2]+r[2]+min(l[0],r[1]);
         ans[1]=l[1]+r[1]-min(l[0],r[1]);
         ans[0]=l[0]+r[0]-min(l[0],r[1]);
         return ans;
   }
   void build(int ind,int low,int high,string s){
    if(low==high){
        seg[ind]={s[low]=='(',s[high]==')',0};
        return;
    }
    int mid=(low+high)/2 ;
    build(2*ind+1,low,mid,s);
    build(2*ind+2,mid+1,high,s);
    seg[ind]=calc(seg[2*ind+1],seg[2*ind+2]);
   }
   vector<int> query(int ind,int low,int high,int l,int r){
    if(l>high || r<low)
    return {0,0,0};
    if(l<=low && r>=high)
    return seg[ind];
    int mid=(low+high)/2;
    vector<int> left=query(2*ind +1,low,mid,l,r);
    vector<int> right=query(2*ind+2,mid+1,high,l,r);
    return calc(left,right);

   }
   
};

int main(){
    string s;
    cin>>s;
    int n=s.size();
    SGTree sgt(n);
    sgt.build(0,0,n-1,s);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<sgt.query(0,0,n-1,l,r)[2]*2<<endl;
    }
}