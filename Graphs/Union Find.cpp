#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
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

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) {
            return;
        }
        else if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
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

int main()
{
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.areConnected(3, 7)) {
        cout<<"Same"<<endl;
    } else cout<<"Not Same"<<endl;
    
    ds.unionByRank(3, 7);
    if(ds.areConnected(3, 7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    
    DisjointSet ds1(7);

    ds1.unionBySize(1, 2);
    ds1.unionBySize(2, 3);
    ds1.unionBySize(4, 5);
    ds1.unionBySize(6, 7);
    ds1.unionBySize(5, 6);

    if(ds1.areConnected(3, 7)) {
        cout<<"Same"<<endl;
    } else cout<<"Not Same"<<endl;
    
    ds1.unionBySize(3, 7);
    if(ds1.areConnected(3, 7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    return 0;
}