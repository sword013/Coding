/*
Logic:
Keep a stack
1) Traverse the string
    2) if u get any operand, just append it in answer
    3) if u get operator, push in stack if its priority is greater than stack top(bracket prio=least)
    else pop all operators having greater priority and append to answer
    4) if u get opening bracket, blindly push in stack
    5) if u get closing bracket, pop all until you get opening and append to answer
*/

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int getPriority(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' or ch=='/') return 2;
        else if(ch=='+' or ch=='-') return 1;
        return -1;
    }
    bool isOperand(char ch){
        if((ch>='a' and ch<='z')
        or (ch>='A' and ch<='Z')
        or (ch>='0' and ch<='9')) return true;
        return false;
    }
    string infixToPostfix(string s) {
        // Your code here
        stack<int> st;
        int n =s.size();
        string ans;
        for(char ch:s){
            if(isOperand(ch)) ans+=ch;
            else if(ch=='(') st.push('(');
            else if(ch==')'){
                //pop all until you get '('
                while(!st.empty() and st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();   //removing '('
            }else{
                //its an operator
                while(!st.empty() and getPriority(ch)<=getPriority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()) {
            ans+= st.top();
            st.pop();
        }
        return ans;
        //O(n)+O(n) , O(n)+O(n)
    }
};