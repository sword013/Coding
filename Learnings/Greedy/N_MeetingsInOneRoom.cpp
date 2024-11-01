/*
    https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
    Logic:
    End the meetings as fast as possible. Fast ending means you have to sort acc to ending time.
*/
class Solution {
  public:
    class Meet{
      public:
      int start,end;
    };
    static bool comp(Meet m1,Meet m2){
        return m1.end < m2.end; 
    }
    
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> start, vector<int> end) {
        // Your code here
        int n = start.size();
        vector<Meet> m(n);
        for(int i =0;i<n;i++){
            m[i].start = start[i];
            m[i].end= end[i];
        }
        
        sort(m.begin(),m.end(),comp);
        
        int endd=INT_MIN;
        int cnt = 0;
        for(int i =0;i<n;i++){
            if(m[i].start <= endd){
                //overlapped. dont consider this meeting
            }
            else{
                //consider this meeting;
                cnt ++;
                endd = m[i].end;
            }
        }
        return cnt;
    }
};