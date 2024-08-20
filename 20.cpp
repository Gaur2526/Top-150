Problem Statement Break Down : 

1. we have an vector of strings 
2. we have to find the longest common prefix among the strings
3. if no longest common prefix exist then we return an empty string ""

Solution :

// Optimised approach

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string res = "";
 
        if(strs.size() == 1) return strs[0];
    
        for(int i=0;i<strs[0].size();i++){

           char ch = strs[0][i];
           bool flag = false;

           for(int j = 1;j<strs.size();j++){
            
                if(ch == strs[j][i]){
                    flag = true;
                }
                else{
                    flag = false;
                    break;
                }
            }
        
           if(flag == true) res.push_back(ch);
           else break;
        }

       return res;
    }
};

Time complexity : O(n*m) where n is the size of strs and m is the size of the first string
Space complexity : O(1) because res is the part of the output so we don't count it
