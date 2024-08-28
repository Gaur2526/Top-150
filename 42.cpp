Problem Statement Break Down :

1. we have two string s and t 
2. we have to determine whether t is the anagram of s or not
3. an anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once

Solution :

// Brute force

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        for(int i=0;i<s.size();i++){

            if(s[i] != t[i]) return false;
        }
        
        return true;
    }
};

Time complexity : O(nlogn)
Space complexity : O(1)

// Optimised approach

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(int i=0;i<s.size();i++){

            mp1[s[i]]++;
        }

        for(int i=0;i<t.size();i++){

            mp2[t[i]]++;
        }

        for(int i=0;i<s.size();i++){
            
            char ch = s[i];

            if(mp1[ch] != mp2[ch]) return false;
        }

        return true;
    }
};

Time complexity : O(n) 
Space complexity : O(1)

// Best approach

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;

        unordered_map<char,int> char_count;

        for(char ch : s){

            char_count[ch]++;
        }

        for(char ch : t){

            char_count[ch]--;

            if(char_count[ch] < 0) return false;
        }

        return true;
    }
};

Time complexity : O(n)
Space complexity : O(1)
