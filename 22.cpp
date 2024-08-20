Problem Statement Break Down : 

1. we have an string s and an integer numrows 
2. we have to return the string in zig-zag manner in respect with numrows

Solution : 


// Optimised approach

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;
        
       vector<string> res(numRows);

        int current_row = 0;
        bool goingdown = false;

        for(int i=0;i<s.size();i++){
              
             res[current_row] = res[current_row] + s[i];

              if(current_row == 0 || current_row == numRows-1) goingdown = !goingdown;

              if(goingdown == true){
                  current_row = current_row + 1;
              }
              else{
                   current_row = current_row - 1;
              }
        }
        
        string ans = "";
        for(auto itr : res){
            ans = ans + itr;
        }

        return ans;
    }
};

Time complexity : O(n)
Space complexity : O(n)
