Problem Statement Break Down :

1. we have an integer array height where the height[i] is the elevation of the (i)th bar 
2. the width of each bar is 1
3. we have to compute the volume of water it can hold 

Solution :

// Optimised approach

class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = height.size()-1;
        int left_max = 0;
        int right_max = 0;
        int total_water = 0;

        while(left <= right){

            if(height[left] <= height[right]){

                if(height[left] >= left_max){
                    left_max = height[left];
                }
                else{
                    total_water = total_water + left_max - height[left];
                }

                left++;
            }

            else{

                if(height[right] >= right_max){
                    right_max = height[right];
                }
                else{
                    total_water = total_water + right_max - height[right];
                }
                right--;
            }
        }

        return total_water;

    }
};

Time complexity : O(n)
Space complexity : O(1)
