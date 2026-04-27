class Solution {
public:
    /**
     * Insert a new interval into a list of non-overlapping intervals and merge if necessary
     * @param intervals: list of non-overlapping intervals sorted by start time
     * @param newInterval: the interval to be inserted
     * @return: list of non-overlapping intervals after insertion
     */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        return merge(intervals);
    }
private:
    /**
     * Merge overlapping intervals in a list
     * @param intervals: list of intervals (may contain overlapping intervals)
     * @return: list of non-overlapping intervals after merging
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by their start time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        mergedIntervals.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (mergedIntervals.back()[1] < intervals[i][0]) {
                mergedIntervals.emplace_back(intervals[i]);
            } else {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }
        return mergedIntervals;
    }
};