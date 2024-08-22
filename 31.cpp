Problem Statement Break Down :

1. we have an string s
2. we have to return the longest substring having no repeated characters

Solution : 

// Brute force

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
          int len = INT_MIN;
    
          if(s.size() == 0) return 0;

        for(int i=0;i<s.size();i++){
        
            string str = "";
        
            for(int j=i;j<s.size();j++){
            
                char ch = s[j];
            
                auto itr = str.find(ch);

                if(itr == string::npos){
                    str.push_back(ch);
                    len = max(len,(int)str.size());
                }
                  
                else{

                    break;
                }
           
            }
        }
    
         return len;
    }
};

Time complexity : O(n^3)
Space complexity : O(n)

// Optimised approach

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = INT_MIN;

        if(s.size() == 0) return 0;

        for(int i = 0;i<s.size();i++){

            unordered_set<char> unique;

            for(int j=i;j<s.size();j++){
                  
                  char ch = s[j];

                  if(unique.find(ch) != unique.end()){
                      break;
                  }

                  unique.insert(ch);

                  len = max(len,(int)unique.size());
            }
        }

        return len;
    }
};

Time complexity : O(n^2)
Space complexity : O(n)

// Best approach

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); ++right) {
            while (seen.find(s[right]) != seen.end()) {
                seen.erase(s[left]);
                ++left;
            }
            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

Time complexity : O(n)
Space complexity : O(n)
