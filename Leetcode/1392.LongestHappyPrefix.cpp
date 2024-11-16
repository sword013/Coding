/*
https://leetcode.com/problems/longest-happy-prefix/
[HARD]

This is already a well known algorithm used in KMP to find the largest prefix which is also suffix on ith position.
here lps[n-1] says that for the entire string, what is the largest prefix which is also suffix
*/

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n);

        lps[0]=0;
        int prevLPS = 0,i=1;

        while(i<n){
            if(s[i] == s[prevLPS]){
                lps[i] = prevLPS + 1;
                prevLPS++;
                i++;
            }else{
                if(prevLPS==0){
                    lps[i]=0;
                    i++;
                }else{
                    prevLPS = lps[prevLPS-1];
                }
            }
        }

        int common = lps[n-1];
        string ans="";
        for(int i=0;i<common;i++) ans+=s[i];
        return ans;
    }
};