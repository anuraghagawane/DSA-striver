#include <bits/stdc++.h>

using namespace std;

struct Item {
   int value;
   int weight;
};
class Solution {
   public:
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   // function to return fractionalweights
   double fractionalKnapsack(int W, Item arr[], int n) {
      sort(arr, arr+n, comp);

      double finalValue = 0;
      double finalWeight = 0;
      for (int i = 0; i < n; i++) {
        Item curr = arr[i];
        if(curr.weight + finalWeight <= W) {
          finalValue += curr.value;
          finalWeight += curr.weight;
        } 
        else {
          int remain = W - finalWeight;
          finalWeight += remain;
          finalValue += (curr.value /curr.weight) * remain;
        }
      }

      return finalValue;
   }
};
int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}
