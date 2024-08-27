Problem Statement Break Down :

1. we have two strings ransomNote and magazine
2. we have to determine whether ransomNote can be formed by using letters of magazine once or not
3. if yes return true otherwise false

Solution :

// Optimised approach

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(int i=0;i<ransomNote.size();i++){
            mp1[ransomNote[i]]++;
        }

        for(int i=0;i<magazine.size();i++){
            mp2[magazine[i]]++;
        }

        for(int i=0;i<ransomNote.size();i++){

            if(mp1[ransomNote[i]] > mp2[ransomNote[i]]) return false;
        }

        return true;
    }
};

Time complexity : O(m + n) where m is the length of ransomNote and n is the size of magazine
Space complexity : O(1), since the space used for the hash maps is constant relative to the number of unique characters (in this case, at most 26 letters)
