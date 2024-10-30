//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
/*
    Learnings : Via normal Disjoint set this will not work. You will have to change union function
    a little bit so that it works. Take and example and see that slot-1 is to be made parent of slot
    no matter what size or rank. so this union doesnt depend on size or rank. its purely 
    parent[slot] = (slot-1) or (slot-1)'s ult parent;
*/
class Solution {
  public:
    static bool comp(Job j1,Job j2){
        return j1.profit>j2.profit;
    }

    vector<int> JobScheduling(Job jobs[], int n) {
        sort(jobs,jobs+n,comp);
        int md=0;
        for(int i=0;i<n;i++) md=max(md,jobs[i].deadline);
        vector<int> temp(md+1,-1);
        int profit=0,n_jobs=0;
        for(int i=0;i<n;i++){
            int j = jobs[i].deadline;
            while(temp[j]!=-1) j--;
            if(j!=0) {
                temp[j] = 1;    //marking this slot as used
                profit+=jobs[i].profit;
                n_jobs++;
            }
        }
        
        return {n_jobs,profit};
    }
    
    //O(nlogn) + n*max_deadline, O(md)
    //inner loop can be optimsed using disjoint set -CP
};

/*VIA Disjoint Set:-----------------------------------------------------------------------------------------*/

class DisjointSet{
  
  public:
  vector<int> parent;
    DisjointSet(int n){
        parent.resize(n+1);
        //size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUPar(parent[u]);
    }
    
    void unionCustom(int u,int v){
        parent[v]=u;
    }
    
};

class Solution {
  public:
    static bool comp(Job j1,Job j2){
        return j1.profit>j2.profit;
    }

    vector<int> JobScheduling(Job jobs[], int n) {
        sort(jobs,jobs+n,comp);
        int md=0;
        for(int i=0;i<n;i++) md=max(md,jobs[i].deadline);
        
        DisjointSet ds(md);
        //3,5 -> 0(taken) ; 1,2,4,6-> not taken
        int profit=0,n_jobs=0;
        for(int i=0;i<n;i++){
            int d = jobs[i].deadline;
            int slot = ds.findUPar(d);
            //cout<<"getting slot as : " <<slot <<endl;
            if(slot>0) {
                //cout<<"doing union on " << slot<< " and " <<slot-1<<endl;
                ds.unionCustom(ds.findUPar(slot-1),slot);
                n_jobs++;
                profit+=jobs[i].profit;
            }
            
        }
        
        return {n_jobs,profit};
    }
    
    
};