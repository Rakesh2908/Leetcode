class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);  // 1-indexed graph
        vector<int> indegree(n + 1, 0);
        vector<int> dp(n + 1, 0);

        // Build the graph and calculate indegrees
        for (const auto& rel : relations) {
            int prevCourse = rel[0];
            int nextCourse = rel[1];
            graph[prevCourse].push_back(nextCourse);
            indegree[nextCourse]++;
        }

        // Perform topological sorting
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = time[i - 1];  // Course i can be started immediately
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            for (int nextCourse : graph[course]) {
                dp[nextCourse] = max(dp[nextCourse], dp[course] + time[nextCourse - 1]);
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0)
                    q.push(nextCourse);
            }
        }

        // Find the maximum time needed among all courses
        int maxTime = 0;
        for (int i = 1; i <= n; ++i)
            maxTime = max(maxTime, dp[i]);

        return maxTime;
    }
};
