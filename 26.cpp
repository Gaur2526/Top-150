Problem Statement Break Down : 

1. we have two strings s and t if s is a subsequence of t then return true otherwise false 
2. A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.

Solution : 

// Brute force 

class Solution {
public:
    bool isSubsequence(string s, string t) {
         
      if(s.size() == 0) return true;
      if(t.size() == 0) return false;
      
      int index = 0;
      bool flag = false;
      int cnt = 0;
      
      for(int i=0;i<s.size();i++){
          
          for(int j=index;j<t.size();j++){
              
              if(s[i] == t[j]){
                  flag = true;
                  index = j+1;
                  cnt++;
                  break;
              }
              else{
                  flag = false;
              }
          }
          
          if(flag == false) return false;
      }
      
      if(cnt == s.size()) return true;
      else return false;


    }
};

Time complexity : O(n * m) where n is the size of s and m is the size of t
Space complexity : O(1)

// Optimised approach

class Solution {
public:
    bool isSubsequence(string s, string t) {
         
       int i = 0;
       int j = 0;

       while(i<s.size() && j<t.size()){

           if(s[i] == t[j]){
              i++;
           }
           j++;
       }

       if(i == s.size()) return true;

       return false;

    }
};

Time complexity : O(n + m)
Space complexity : O(1)
