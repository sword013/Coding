//https://leetcode.com/problems/valid-parenthesis-string/
/*
Logic: 
left is a variable that holds the count of opening brackets
at * we have to either do l--, l++ or make it stay l
so we will have to keep 3 variables. on other * again 3*3 = 9 variables
rather we thus keep a range going ahead that min left count can be this this and 
max left count can be so n so. thus only 2 variabels lmin and lmax;

*/
class Solution {
public:
    bool checkValidString(string s) {
        int lmin=0,lmax=0;  //l denotes #opening brackets

        for(char ch:s){
            if(ch=='('){
                lmin++;
                lmax++;
            }else if(ch==')'){
                lmin--;
                lmax--;
            }else{
                //*
                lmin--;
                lmax++;
            }
            if(lmin<0) lmin=0;
            if(lmax<0) return false;
        }
        
        return lmin==0;
    }
    
};