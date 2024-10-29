class Solution {
  public:
    vector<int> countOccurrences(int n, int q, vector<int> &a,
                                 vector<vector<int>> &queries) {
        // code here
        map<int,map<int,int>> nmap; //nested map
        for(int i=0;i<n;i++){
            nmap[a[i]][i] = nmap[a[i]].size()+1;
        }
        
        vector<int> ans;
        for(auto q:queries){
            int l = q[0];
            int r = q[1];
            int val = q[2];
            
            map<int,int> &mpp = nmap[val];
            auto lb = mpp.lower_bound(l);
            auto ub = mpp.upper_bound(r);
            if(lb==ub) ans.push_back(0);
            else {
                ub--;
                ans.push_back(ub->second-lb->second+1);
            }
        }
        
        return ans;
    }

    
/* Test Case:
5
10
2 3 5 3 4
3 4 3
0 1 2
2 2 2
4 4 3
1 3 2
0 4 2
3 3 2
0 0 4
3 4 3
3 4 3
*/