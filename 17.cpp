Problem Statement Break Down :

1. we have an string s contains roman numerals
2. we have to return the corresponding number 

Solution :

// Optimised approach

class Solution {
public:
    int romanToInt(string s) {

        map<char,int> mp;
    
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
    
        int num = 0;
        for(int i=0;i<s.size();i++){
        
           if(mp[s[i]] >= mp[s[i+1]]){
               num = num + mp[s[i]];
           }
           else{
               num = num + mp[s[i+1]] - mp[s[i]];
               i++;
           }
        }
        
      return num;
        
    }
};

Time complexity : O(n)
Space complexity : O(1)
