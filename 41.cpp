Problem Statement Break Down :

1. we have a string of characters pattern and a string of words s
2. we have to identify whether s follows the same pattern
3. return true if yes otherwise false

Solution :

// Optimised approach

class Solution {
public:
    bool wordPattern(string pattern, string s) {
    
        vector<string> v;

        for(int i=0;i<s.size();i++){

            string str = "";

            while(i < s.size() && s[i] != ' '){
                str = str + s[i];
                i++;
            }
            v.push_back(str);
        }
        
        if(v.size() != pattern.size()) return false;
        
        unordered_map<char,string> mp;
        unordered_map<string,char> mp1;

        for(int i=0;i<pattern.size();i++){

            char ch = pattern[i];
            string str = v[i];

            if(mp.count(ch) && mp[ch] != str ) return false;
            if(mp1.count(str) && mp1[str] != ch) return false;

            mp[ch] = str;
            mp1[str] = ch;
        }

        return true;
    }
};

Time complexity : O(n + m) where n is the size of the string s and m is the size of the string m
Space complexity : O(k) where k is the number of unique words in s and unique characters in pattern
