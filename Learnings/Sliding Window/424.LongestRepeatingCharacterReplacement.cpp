/*
https://leetcode.com/problems/longest-repeating-character-replacement/submissions/1455908547/

Code 1:
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

Code 2 : 
Strivers Logic. The explanation of why not to update max_freq is VERY VERY CRUTIAL ! 

Both codes are O(2n),O(1)
*/

/*---------------------------------------------------------------Code 1----------------------------------------------------------- */
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

/*---------------------------------------------------------------Code 2----------------------------------------------------------- */
class Solution {
public:
    int characterReplacement(string s, int k) {
       int n = s.size();
       vector<int> freq(26,0);
       int maxlen=1,l=0,max_freq = 0;

       for(int r=0;r<n;r++){
            freq[s[r]-'A']++;
            max_freq=max(max_freq,freq[s[r]-'A']);
            
            //int length = r-l+1; //length is variable so dont assign length variable before and use it later
            while(r-l+1-max_freq>k){   
                freq[s[l]-'A']--;
                // for(int i=0;i<26;i++)max_freq =max(max_freq,freq[s[i]-'A']);
                //no need to do above; check reason in explanation below (1)
                l++;
            }

            //window satisfies
            maxlen=max(maxlen,r-l+1);
       }

       return maxlen;
    }

    /*
    Explanation:
        aaabc; here max_freq = 3; and length = 5;
        you have fixed your max_freq here; means you have k=2;
        theres no sense to decrease your max_freq further as you wont get any better answer;
        say: max_freq = 2 now; then because k=2; length can be 4 only max, but you already have length 5;
        (1) can decrease your max_freq as you're moving r ahead. so dont bother to replace max_freq with lesser value now
        its not wrong to do so, but we are going towards more optimal approach : O(2n*26)->O(2n)

    */
};