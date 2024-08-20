Problem Statement Break Down :

1. we have an string s we have to reverse the order of words in the string
2. we have to return the reversed string
3. we have to reverse in a way that their will we be no starting or trailling space in the new string and each word is seperated by a single space

Solution : 

// Brute Force 

class Solution {
public:
    string reverseWords(string s) {
        
        string res = "";
        stack<string> st;
    
        int i = 0;
        int j = 0;
    
       while(i < s.size()){
        
            string word ="";
            j = i;
            while(j < s.size() && s[j] != ' '){
                word.push_back(s[j]);
                j++;
            }
            if(word.size() > 0) st.push(word);
            i = j+1;
        }
    
        while(!st.empty()){
        
          res = res + st.top();
          st.pop();

          if(!st.empty()){
            res.push_back(' ');
          }
       
        }
        return res;
    }
};

Time complexity : O(n) as both loops runs in the sequence
Space complexity : O(n) 

// Optimised approach

class Solution {
public:
    string reverseWords(string s) {

        int i = s.size()-1;
        string res = "";

        while(i>=0){

             while(i>=0 && s[i] == ' ') i--;

             if(i<0) break;

             int j = i;

             while(i>=0 && s[i] != ' ') i--;

             if(!res.empty()) res.push_back(' ');

            res = res + s.substr(i+1,j-i);

        }

        return res;
        
    }
};

Time complexity : O(n)
Space complexity : O(!)
