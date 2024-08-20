Problem Statement Break Down : 

1. we have two strings haystack and needle 
2. we have to find the first occurence of needle in haystack
3. if needle is not the part of haystack then return -1

Solution : 

// Brute force 

class Solution {
public:
    int strStr(string haystack, string needle) {
        
         for(int i=0;i<haystack.size();i++){
        
             int index = i;
        
             bool flag = false;
             for(int j=0;j<needle.size();j++){
            
                 if(needle[j] == haystack[i+j]){
                     flag = true;
                 }
                else{
                    flag = false;
                    break;
                }
             }
           
            if(flag == true) return index;
         }  
       
        return -1;
    }
};

Time complexity : O(n*m) n is the size of haystack and m is the size of needle
Space complexity : O(1)

// Optimised approach

solution can be optimise but the solution become too difficult to understand so this approach is sufficient as it is an easy level question
optimisation uses Knuth-Morris-Pratt (KMP) Algorithm 

Time complexity : O(n + m)
Space complexity : O(1)
