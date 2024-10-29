//https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
	public:
	void dfs_s(int i,vector<int> adj[],stack<int> &s,vector<int> &vis){
	    vis[i]=1;
	    for(auto neigh:adj[i]) 
	        if(!vis[neigh]) dfs_s(neigh,adj,s,vis);
	        
	    s.push(i);
	}
	
	
	void dfs(int i,vector<int> adj[],vector<int> &vis){
	    vis[i]=1;
	    for(auto neigh:adj[i]) 
	        if(!vis[neigh]) dfs(neigh,adj,vis);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adjj)
    {
        vector<int> adj[V],adjr[V];
        
        for(int i=0;i<V;i++){
            for(auto it:adjj[i]){
                adj[i].push_back(it);
                adjr[it].push_back(i);
            }
                
        }
        
        stack<int> s;
        vector<int> vis(V,0);
        //step 1.
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs_s(i,adj,s,vis);
            }
        }
        
        //step 2
        for(int i=0;i<V;i++)vis[i]=0;
        int scc=0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!vis[node]){
                dfs(node,adjr,vis);
                scc++;
            }
        }
        return scc;
        
    }
};