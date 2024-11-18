/*
https://leetcode.com/problems/longest-repeating-character-replacement/submissions/1455908547/
Strivers last approach is much better but as of now I dont understand it. Check later !
Our logic:
    Either you generate all the substrings and do else optimal :
    Sliding window logic :
        Think! What is a valid window ? A window where we have (length of window - maxfrequency) no of characters and
        these characters must be <=k; WHY you ask ?
        Take a window : aaabbc; a->3,b->2,c->1
        Which character out of these 3 makes sense that you must replace with ? Ofc a. you will replace b and c with "a"
        to minimise the number of conversions you do. In below code you can get others_freq also as length(j-i+1) - max_freq;
        There could be cases like : aabb; where both a and b can be max_freq. so i am keeping a count of no_of_max here. 
        If you dont wish to use that; at window; loop through all 26 places in freq and get your max_freq and then you can have
        your others_freq = length - max_freq;
        Valid window is a window where others_freq<=k; these are other characters that you will replace with the character having
        the max_freq.
    Thats it! 
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
       vector<int> freq(26,0);
       int maxlen=1;
       int i = 0,j=0;
       freq[s[0]-'A']++;
       int others_freq = 0;
       int max_freq = 1;
        int no_of_max=1;
       while(true){
            while(j<n and others_freq<=k){
                //you can increase your windows size
                maxlen = max(maxlen,j-i+1);
                j++;
                if(j==n) break;
                freq[s[j]-'A']++;
                if(freq[s[j]-'A']>max_freq) max_freq=freq[s[j]-'A'];
                else {
                    if(freq[s[j]-'A']==max_freq) no_of_max++;
                    others_freq++;
                    }
            }
            if(j==n) break;

            //now the window is not satisfying your conditions
            while(others_freq>k){
                //decrease your window size
                if(freq[s[i]-'A']==max_freq){
                    if(no_of_max==1){
                        no_of_max=0;
                        max_freq--;
                    }
                    else{
                        no_of_max--;
                        others_freq--;
                    }
                }else others_freq--;

                freq[s[i]-'A']--;
                i++;
            }

       }

       return maxlen;
    }
};