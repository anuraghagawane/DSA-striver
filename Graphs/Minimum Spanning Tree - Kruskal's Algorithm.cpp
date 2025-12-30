// User function Template for C++
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int num) {
        if(parent[num] == num) return num;

        return parent[num] = findUPar(parent[num]);
    }

    void unite(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) {
            return;
        }
        else if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    bool areConnected(int u, int v) {
        return findUPar(u) == findUPar(v);
    }
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        int sum = 0;
        sort(edges.begin(), edges.end(), compareEdges);
        
        DisjointSet ds = DisjointSet(V);
        
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(!ds.areConnected(u, v)) {
                ds.unite(u, v);
                sum += w;
            }
        }
        
        return sum;
    }
    
    static bool compareEdges(vector<int> a, vector<int> b) {
        return a[2] < b[2];
    }
};