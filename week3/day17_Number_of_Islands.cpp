class Solution {
public:
    void findLand(vector<vector<char>>& grid, int i, int j){
        //check if point is valid...then if it's island
        //then if it is->visit and mark whole island
        if(i<0 || i==grid.size()) return;
        if(j<0 || j==grid[0].size()) return;
        if(grid[i][j] == '1') grid[i][j] = '2';
        else return;
        findLand(grid, i+1, j);
        findLand(grid, i, j+1);
        findLand(grid, i-1, j);
        findLand(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1'){//found island point
                    islands++;//add it in islands then
                    findLand( grid, i, j);//mark all of it's points
                }
            }
        }
        return islands;
    }
};
