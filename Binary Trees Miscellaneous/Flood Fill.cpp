class Solution {
    vector<vector<int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
public:
    void solve(vector<vector<int>>& image, int i, int j, int ogc, int m, int n, int color) {
        if(i >= m || i < 0 || j < 0 || j >= n || image[i][j] == color || image[i][j] != ogc) return;

        image[i][j] = color;

        for(auto move: moves) {
            solve(image, i + move[0], j + move[1], ogc, m, n, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        solve(image, sr, sc, image[sr][sc], image.size(), image[0].size(), color);
        return image;
    }
};