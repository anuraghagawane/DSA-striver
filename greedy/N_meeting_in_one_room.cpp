#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> maxMeetings(vector<int> &start, vector<int> &end) {
      vector<tuple<int, int, int>> meetings;
      for(int i = 0; i < start.size(); i++) {
        meetings.push_back({end[i], start[i], i+1});
      }
      sort(meetings.begin(), meetings.end());
      int lastEnd = -1;

      vector<int> ans;
      for(auto m: meetings) {
        int e = get<0>(m);
        int s = get<1>(m);
        int i = get<2>(m);

        if (s > lastEnd) {
          ans.push_back(i);
          lastEnd = e;
        }
      }

      return ans;
    }
};

int main() {
  vector<int> start = {1,3,0,5,8,5};
  vector<int> end = {2,4,5,7,9,9};

  Solution sol;
  vector<int> res = sol.maxMeetings(start, end);

  for (int idx: res) cout << idx << "";
  cout<<endl;
  return 0;
}
