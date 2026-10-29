class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        int maxGroups = 0;

        for(auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            while(!minHeap.empty() && minHeap.top() < start) {
                minHeap.pop();
            }

            minHeap.push(end);

            maxGroups = max(maxGroups, (int)minHeap.size());
        }
        return maxGroups;
    }
};