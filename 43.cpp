Problem Statement Break Down :

1. we have an array of strings 
2. we have to group anagrams together
3. an anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once

Solution : 

// Optimised approach
 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;

        for(string str : strs){

            string key = str;

            sort(key.begin(),key.end());

            mp[key].push_back(str);
        }

        for(auto itr : mp){

            res.push_back(itr.second);
        }
        
        return res;
    }
};

Time complexity : O(n * mlogm)
Space complexity : O(n * m)
