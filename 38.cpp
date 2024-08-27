Problem Statement Break Down :

1. we have an board of m*n size
2. where each cell have initial state of either 1(live) or 0(dead)
3. each cell have 8 neighbours(horizontal,vertical,diagonal)
4. we have to find the next state of the cell using four rules : 
    a) Any live cell with fewer than two live neighbors dies as if caused by under-population.
    b) Any live cell with two or three live neighbors lives on to the next generation.
    c) Any live cell with more than three live neighbors dies, as if by over-population.
    d) Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
5. we have to return updated state board

Solution : 

// Optimised approach

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        if(board.size() == 0) return;

        vector<pair<int,int>> directions = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},       {0,1},
            {1,-1},{1,0},{1,1}
        };

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){

                int live_neighbours = 0;

                for(auto dir : directions){

                    int r = i + dir.first;
                    int c = j + dir.second;

                    if(r>=0 && r<board.size() && c>=0 && c<board[0].size()){

                        if(board[r][c] == 1 || board[r][c] == 2){

                            live_neighbours++;

                        }
                    }
                }

                if(board[i][j] == 1){

                    if(live_neighbours < 2 || live_neighbours > 3){
                        board[i][j] = 2;
                    }
                }
                else{

                    if(live_neighbours == 3){
                        board[i][j] = -1;
                    }
                }
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){

                if(board[i][j] == -1) board[i][j] = 1;
                else if(board[i][j] == 2) board[i][j] = 0;
            }
        }
        
    }
};

Time complexity : O(m * n) where m are the rows and n are the cols
Space complexity : O(1)
