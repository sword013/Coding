/*
https://leetcode.com/problems/single-threaded-cpu/description/
WAS TOUGH TO IMPLEMENT.
Logic:
This is non-preemptive!
1. Sort by AT
2. Start timer with AT[0]. Do not increment timer with 1 each time, rather jump ahead directly if CPU is idle
3. 
while(pq is not empty or still some tasks left to do){
    3.1 Add all the tasks to the PQ that has came till currTime
    3.2 if PQ is empty{
            No tasks will now come till currTime. Thus CPU has to sit idle until the next process arrives
            Rather than doing timer = +1 ,+2,+3..., do
            currTime = next process's AT
        }else{
            PQ is not empty; so take the smallest job and run it. update timer accordingly
            Pi = pop
            currTime += BT of Pi
            since we complete this, push it in answer
            After we complete any process, we have to again check how many processes arrived till the latest time
            thus you have to execute 3.1 onwards again.
        }
}
*/

class Solution {
public:
    class Process{
        public:
            int id;
            int bt;
            int at;
    };
    static bool comp(Process p1,Process p2){ return p1.at < p2.at; }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<Process> p(n);
        for(int i =0;i<n;i++){
            p[i].id = i;
            p[i].at = tasks[i][0];
            p[i].bt = tasks[i][1];
        }
        sort(p.begin(),p.end(),comp);
    
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        int i=0;
        long long currTime = p[0].at; //AT of task 1
        vector<int> ans;
        while(i<n or !pq.empty()){
            while(i<n and p[i].at<=currTime){
                pq.push({p[i].bt,p[i].id});
                i++;
            }
            if(pq.empty()){
                //no tasks till now. Cpu is sitting idle
                currTime = p[i].at;
            }else{
                int bt = pq.top().first;
                int pid = pq.top().second;
                pq.pop();
                currTime+= bt;
                ans.push_back(pid);
            }
        }
        return ans;
    }
};