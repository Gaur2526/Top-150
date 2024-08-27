Problem Statement Break Down :

1. we have two strings s and t
2. we have to determine whether they are isomorphic or not
3. Two strings s and t are isomorphic if the characters in s can be replaced to get t

Solution : 

// Optimised approach

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size()) return false;

        unordered_map<char,char> s_t;
        unordered_map<char,char> t_s;

        for(int i=0;i<s.size();i++){

            char ch1 = s[i];
            char ch2 = t[i];

            if(s_t.count(ch1) && s_t[ch1] != ch2){
                return false;
            }

            if(t_s.count(ch2) && t_s[ch2] != ch1){
                return false;
            }

            s_t[ch1] = ch2;
            t_s[ch2] = ch1;
        }

        return true;
    }
};

Time complexity : O(n) where n is the length of strings
Space complexity : O(1)
