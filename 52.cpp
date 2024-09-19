Problem Statement Break Down :

1. we have a string s containing open & closed braces
2. we have to determine whether the paranthesis are balanced or not
3. paranthesis are balanced only if for every open braces their will be the same type closed braces in same order

Solution :

// Optimised approach :

class Solution {
public:
    bool isValid(string s) {
        
        stack<int> st;

        for(int i=0;i<s.size();i++){

            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }

            else{

                if(st.empty()) return false;

                else if(s[i] == ')' && st.top() == '(') st.pop();
                else if(s[i] == '}' && st.top() == '{') st.pop();
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else return false;

             }
        }

        if(st.empty()) return true;

        return false;
    }
};

Time complexity : O(n)
Space complexity : O(n)
