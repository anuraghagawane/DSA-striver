class DisjointSet {
    vector<int> parent, size;
    int count;

public:
    DisjointSet(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        parent.resize((m*n) + 2);
        size.resize((m*n) + 2, 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    size[i * n + j] = 1;
                    parent[i * n + j] = i * n + j;
                    count++;
                }
            }
        }
    }

    int findUPar(int num) {
        if(parent[num] == num) return num;

        return parent[num] = findUPar(parent[num]);
    }

    // void unionByRank(int u, int v) {
    //     int ulp_u = findUPar(u);
    //     int ulp_v = findUPar(v);

    //     if(ulp_u == ulp_v) {
    //         return;
    //     }
    //     else if(rank[ulp_u] < rank[ulp_v]) {
    //         parent[ulp_u] = ulp_v;
    //     }
    //     else if(rank[ulp_v] < rank[ulp_u]) {
    //         parent[ulp_v] = ulp_u;
    //     }
    //     else {
    //         parent[ulp_v] = ulp_u;
    //         rank[ulp_u]++;
    //     }
    // }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) {
            return;
        }
        else if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
            count--;
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            count--;
        }
    }

    bool areConnected(int u, int v) {
        return findUPar(u) == findUPar(v);
    }

    int getCount() {
        return count;
    }
};

class Solution {
    vector<vector<int>> moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
public:

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        DisjointSet ds(grid);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != '1') continue;
                for(auto move: moves) {
                    int nextRow = i + move[0];
                    int nextCol = j + move[1];
                    if(nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >=n) continue;
                    if(grid[nextRow][nextCol] == '1') {
                        int id1 = i * n + j;
                        int id2 = nextRow * n + nextCol;
                        ds.unionBySize(id1, id2);
                    }
                }
            }
        }

        return ds.getCount();
    }
};