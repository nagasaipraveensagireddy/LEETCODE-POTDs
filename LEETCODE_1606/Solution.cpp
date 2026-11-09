class Solution {
    struct Job{
        int finishTime;
        int server;
        bool operator>(const Job& other) const{
            if(finishTime != other.finishTime){
                return finishTime > other.finishTime;
            }
            return server > other.server;
        }
    };
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> handled(k, 0);
        vector<int> initialAvailableTimes(k);
        for(int i = 0; i < k; i++) initialAvailableTimes[i] = i;
        priority_queue<int, vector<int>, greater<int>> freeServers(
            initialAvailableTimes.begin(), initialAvailableTimes.end());
        priority_queue<Job, vector<Job>, greater<Job>> busyServers;
        for(int i = 0; i < arrival.size(); i++){
            while(!busyServers.empty() && 
                  busyServers.top().finishTime <= arrival[i]){
                    int server = busyServers.top().server;
                    busyServers.pop();
                    int nextAvailTime = i + (server - i % k + k) % k;
                    freeServers.push(nextAvailTime);
            }
            if(freeServers.empty()) continue;
            int server = freeServers.top() % k;
            freeServers.pop();
            int busyTill = arrival[i] + load[i];
            handled[server]++; 
            busyServers.push({busyTill, server});
        }
        int maxi = INT_MIN;
        for(auto& it : handled) maxi = max(maxi, it);
        vector<int> res;
        for(int i = 0; i < k; i++){
            if(handled[i] == maxi) res.push_back(i);
        }
        return res;
    }
};