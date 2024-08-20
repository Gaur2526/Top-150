Problem statement Break Down :

1. we have an integer num which we have to convert to roman numerals
2. we have to return the string containing roman numerals of the corresponding num

Solution :

// Optimised approach

class Solution {
public:
    string intToRoman(int num) {
        
       map<int,string,greater<int> > mp;

        mp[1000] = "M";
        mp[900] = "CM";
        mp[500] = "D";
        mp[400] = "CD";
        mp[100] = "C";
        mp[90] = "XC";
        mp[50] = "L";
        mp[40] = "XL";
        mp[10] = "X";
        mp[9] = "IX";
        mp[5] = "V";
        mp[4] = "IV";
        mp[1] = "I";

        string ans = "";

        for(auto &itr : mp){

            while(num >= itr.first){
                ans = ans + itr.second;
                num = num - itr.first;
            }
        }

        return ans;
    }
};

Time complexity : O(n) where n is the value of the integer 
Space complexity : O(1)
