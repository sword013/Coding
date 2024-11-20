//https://leetcode.com/problems/is-graph-bipartite/description/
//below code is for gfg : 
//https://www.geeksforgeeks.org/problems/bipartite-graph/1

class Solution {
public:
    bool dfs(int node, int color, vector<int> &colored,vector<int>adj[]){
        colored[node]=color;
        for(neighbor:adj[node]){
            if(colored[neighbor]==-1){
                //the neighbor is not yet colored
                bool ans = dfs(neighbor,(color+1)%2,colored,adj);
                if(ans==false) return false;
            }else {
                //neighbor is colored, just check that it is different from your color
                if(colored[neighbor]==color) return false;
            }
        }
        return true;
    }
    
    bool bfs(int src, vector<int> &color,vector<int>adj[]){
        
        queue<int> q; //node
        q.push(src);
        color[src]=0;
        
        while(!q.empty()){
            int node = q.front(); 
            q.pop();
    
            for(neighbor:adj[node]){
                if(color[neighbor]==-1){
                    //neighbor is not colored, color it with opposite color of yours
                    color[neighbor]=(color[node]+1)%2;
                    q.push(neighbor);
                }else{
                    //neighbor is already colored, just ensure that your color is not same as neighbor color
                    if(color[node]==color[neighbor]) return false;
                }
            }
        }
        return true;
        
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    /* DFS implementation
	    vector<int> colored(V,-1); //-1 = not colored, 0:color red, 1:color blue
	   
	   //graph could be disconnected; so we doing this:
	    for(int i=0;i<V;i++){
	        if(colored[i]==-1) {
	            if(dfs(i,0,colored,adj)==false) return false;
	        }
	    }
	   
	    return true;
	    */
	    
	    //BFS implementation
	    vector<int> color(V,-1);
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            //node is not colored yet
	            if(bfs(i,color,adj)==false) return false;
	        }
	    }
	    return true;
	}

};