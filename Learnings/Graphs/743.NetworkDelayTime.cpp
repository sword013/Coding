//https://leetcode.com/problems/network-delay-time/
//This is a simple implementation of Dij 

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //it is 1-based indexing!
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;   //minheap
        //distance, nodeid
        vector<int> d(n+1,1e9);
        pq.push({0,k});
        d[k]=0;

        vector<pair<int,int>> adj[n+1];
        for(auto it:times) adj[it[0]].push_back({it[1],it[2]});
        

        while(!pq.empty()){
            int du = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto it:adj[u]){
                int v = it.first;
                int wt = it.second;

                if(du+wt < d[v]){
                    d[v] = du+wt;
                    pq.push({d[v],v});
                }
            }
        }

        int max_time = INT_MIN; //this is the minimum time required for all nodes to get signal
        for(int i=1;i<=n;i++){
            if(d[i]==1e9) return -1;
            max_time = max(max_time,d[i]);
        }

        return max_time;


    }
};