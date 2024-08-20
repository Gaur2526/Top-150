Problem Statement Break Down :

1. we have an integer array ratings where the rattings[i[ is the rating of the (i)th student
2. we have to return the min number of candies we can assign to the students
3. we have to assign candies in a way such that :
     a) every student have atleast 1 candy
     b) if one student have higher rating than it's neighbour that he gets more candies than their neighbours

Solution : 

// Optimised approach

class Solution {
public:
    int candy(vector<int>& ratings) {

        vector<int> candies(ratings.size(),1);

        for(int i=1;i<ratings.size();i++){

            if(ratings[i] > ratings[i-1]){
                 candies[i] = candies[i-1] + 1;
            }
        }

        for(int i=ratings.size()-2;i>=0;i--){

            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        
        int total_min_candies = accumulate(candies.begin(),candies.end(),0);
        return total_min_candies;
    }
};

Time complexity : O(n)
Space complexity : O(n)
  
