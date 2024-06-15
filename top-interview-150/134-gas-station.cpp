class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total = 0;
        int remain = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            remain += gas[i] - cost[i];
            if (remain < 0) {
                remain = 0;
                j = i + 1;
            }
        }

        return total < 0 ? -1 : j;
    }
};
