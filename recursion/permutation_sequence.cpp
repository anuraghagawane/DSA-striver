class Solution {
public:
    int perm_count;
    string solve(int n, int k, int taken, vector<int>& taken_val, string curr) {
        if(taken == n){
            perm_count++;
            return curr;
        }

        for(int i = 0; i < n; i++) {
            if(taken_val[i]) continue;
            taken_val[i] = 1;
            string ans = solve(n, k, taken+1, taken_val, curr + to_string(i+1));
            if(perm_count == k) return ans;
            taken_val[i] = 0;
        }

        return curr;
    }
    string getPermutation(int n, int k) {
        // vector<int> taken_val(n, 0);
        // return solve(n, k, 0, taken_val, "");
        
        vector<int> numbers;
        int fact = 1;

        for(int i = 1; i<n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k--;
        string ans = "";
        while(n) {
            ans += to_string(numbers[ceil(k/fact)]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0) break;

            k = k % fact;
            fact = fact / numbers.size();
        }

        return ans;
    }
};