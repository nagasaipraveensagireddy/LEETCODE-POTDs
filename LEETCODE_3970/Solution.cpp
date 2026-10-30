class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> graph(n);

        for (const auto& edge : edges) {
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];

            graph[source].push_back({destination, weight});
        }

        vector<int> bestRun(n, k + 1);

        using State = tuple<long long, int, int>;

        priority_queue<State, vector<State>, greater<State>> minHeap;

        minHeap.push({0, 1, 0});

        while (!minHeap.empty()) {

            auto [currentDistance, currentRun, currentNode] = minHeap.top();
            minHeap.pop();

            if (currentRun >= bestRun[currentNode]) {
                continue;
            }

            if (currentNode == n - 1) {
                return currentDistance;
            }

            bestRun[currentNode] = currentRun;

            for (const auto& [nextNode, edgeWeight] : graph[currentNode]) {

                int nextRun;

                if (labels[currentNode] == labels[nextNode]) {
                    nextRun = currentRun + 1;
                }
                else {
                    nextRun = 1;
                }

                if (nextRun < bestRun[nextNode]) {

                    long long newDistance = currentDistance + edgeWeight;

                    minHeap.push({
                        newDistance,
                        nextRun,
                        nextNode
                    });
                }
            }
        }

        return -1;
    }
};