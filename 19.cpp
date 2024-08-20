Problem Statement Break Down : 

1. we have an string which consist both spaces and words
2. we have to return the length of the last word

Solution :

// Optimised approach 

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len = 0;
        int i = s.size()-1;
        for(i ; i>=0 ;i--){

            if(s[i] == ' ') continue;
            else break;
        }

        while(i>=0 && s[i] != ' ' ){
            len++;
            i--;
        }

        return len;
    }
};

Time complexity : O(n)
Space complexty : O(1)
