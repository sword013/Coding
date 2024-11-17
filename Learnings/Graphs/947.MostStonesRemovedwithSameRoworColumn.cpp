//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
/*
    Logic: For every stone on ith row and jth column, it makes ith row and jth column depend on each other
    they should be observed as one itself. 
    If a component has say 5 people(5 Rows/Cols depending on each other). means you can delete max of 4 stones from it. 
    Last one you cant delete, it will stand independently
    Ans = max stones u can delete
    Say there are components like C1 , C2 ,....Ck having n1,n2,...nk stones.
    Ans = n1-1 +n2-1 +... nk-1 
        = n1+n2+..nk - (1+1+1..k times)
        = total number of stones *you observed* - number of components
*/

class DisjointSet{
    public:
     vector<int> size;
    vector<int> parent;
    DisjointSet(int n){
        size.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++) {
            parent[i]=i;
            size[i]=1; 
        }
    }

    int getUPar(int u){
        if(u==parent[u]) return u;
        return parent[u] = getUPar(parent[u]);
    }

    void unionBySize(int u,int v){
        int ulp_u = getUPar(u);
        int ulp_v = getUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }

};

class Solution {
private: 
    
public:
    int removeStones(vector<vector<int>>& stones) {
      int n=0 ;        //max rows
      int m=0 ;        //max cols
      for(auto it:stones){
        n=max(n,it[0]);
        m=max(m,it[1]);
      }
      n++; m++;

      unordered_set<int> st;
      DisjointSet ds(n+m);
      
      for(auto it:stones){
        ds.unionBySize(it[0],it[1]+n);
        st.insert(it[0]); st.insert(it[1]+n); //marking that this row and this col has came
      }

      int components = 0;
      for(auto it:st){
        if(ds.getUPar(it)==it) components++;
      }

      return stones.size()-components;
      
    }
};