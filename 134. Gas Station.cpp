class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = -1;   // -1 means no active candidate
        int tank = 0;     // running gas balance for the current candidate
        int location = 0; // current station being visited (unwrapped)
        while (location < n * 2) {
            if (start == -1) {
                start = location;
            }
            tank += gas[location % n] - cost[location % n];
            if (tank < 0) {
                start = -1;
                tank = 0;
            }
            location++;
            if (start != -1 && location - start == n) {
                return start % n;
            }
        }
        return -1;
    }
};
