#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }}
        int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
        void unionBysize(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(size[ulp_u]>size[ulp_v]){
                size[ulp_u]=size[ulp_u]+size[ulp_v];
                parent[ulp_v]=ulp_u;
            } else   {
                size[ulp_v]=size[ulp_v]+size[ulp_u];
                parent[ulp_u]=ulp_v;
            } 
            
        }
    
};

int main(){
    DisjointSet ds(7);
    ds.unionBysize(1, 2);
    ds.unionBysize(2, 3);
    ds.unionBysize(4, 5);
    ds.unionBysize(6, 7);
    ds.unionBysize(5, 6);
    // if 3 & 7 from same component?
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    ds.unionBysize(3, 7);
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
    return 0;
}