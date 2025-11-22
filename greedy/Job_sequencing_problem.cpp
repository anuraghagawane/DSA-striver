#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
    static bool comp(Job a, Job b) {
      return a.profit > b.profit;
    }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {
      sort(arr, arr+n, comp);

      int max_slot = 0;
      for(int i = 0; i < n; i++) {
        max_slot = max(max_slot, arr[i].dead);
      }

      int slots[max_slot];
      for(int i = 0; i<max_slot; i++) {
        slots[i] = -1;
      }

      int jobCount = 0, totalProfit = 0;

      for(int i = 0; i<n; i++) {
        for(int j = arr[i].dead; j>0; j--) {
          if(slots[j] == -1) {
            slots[j] = arr[i].id;
            jobCount++;
            totalProfit += arr[i].profit;
            break;
          }
        }
      }

      return {jobCount, totalProfit};
   }
};
int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 
