Problem Statement Break Down :

1. we have an n*n 2D matrix representing an image
2. we have to rotate it by 90 degree clockwise
3. we have to done this in in-place manner

Solution : 

// Brute force 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        vector<vector<int>> res;

        for(int i=0;i<matrix[0].size();i++){

            vector<int> ans;

            for(int j=matrix.size()-1;j>=0;j--){

                ans.push_back(matrix[j][i]);

            }

            res.push_back(ans);
        }

        for(int i=0;i<res.size();i++){

            for(int j=0;j<res[i].size();j++){

                matrix[i][j] = res[i][j];
            }
        }
    }
};

Time complexity : O(n^2)
Space complexity : O(n^2)

// Optimised approach(in-place)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i=0;i<matrix.size();i++){

            for(int j=i+1;j<matrix[0].size();j++){

                swap(matrix[i][j],matrix[j][i]);

            }
        }

        for(int i=0;i<matrix.size();i++){
            
            for(int j=0;j<matrix[0].size()/2;j++){

                swap(matrix[i][j],matrix[i][matrix[0].size()-1-j]);
            }
        }
    }
};

Time complexity : O(n^2)
Space complexity : O(1)

