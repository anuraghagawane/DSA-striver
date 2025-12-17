class Solution {
public:
    void markAllAdjancentsRotten(vector<vector<int>>& grid, queue<pair<int, int>>& q, int i, int j, int rows, int cols) {
        vector<int> adjs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(auto adj: adjs) {
            int nextRow = i + adj[0];
            int nextCol = j + adj[1];
            if(nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols) {
                if(grid[nextRow][nextCol] == 1) {
                    grid[nextRow][nextCol] = 2;
                    q.push({nextRow, nextCol});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int totalOranges = 0;
        int rottenOranges = 0;

        for(int i = 0; i < rows; i++) {
            for (int j = 0; j<cols; j++) {
                if(grid[i][j]==0) {
                    continue;
                }

                if(grid[i][j] == 2) {
                    q.push({i, j});
                }

                totalOranges++;
            }
        }

        q.push({-1, -1});

        int depth = 0;
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            if(i == -1 && j == -1) {
                depth++;
                if(!q.empty()) q.push({-1, -1});
                continue;
            }
            rottenOranges++;

            markAllAdjancentsRotten(grid, q, i, j, rows, cols);
        }


        if(totalOranges != rottenOranges) return -1;

        return depth - 1;
    }
};