class Solution {
    struct Server{
        long long busyTill;
        int weight;
        int index;
    };
    // starred as this heap comparator is a new topic to learn, this works opposite to sorting 
    // comparator, true means the first one is of low priority
    struct Compare{
        bool operator()(const Server& a, const Server& b) const{
            return tie(a.busyTill, a.weight, a.index) > 
                   tie(b.busyTill, b.weight, b.index);
        }
    };
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<Server, vector<Server>, Compare> freeServers;
        priority_queue<Server, vector<Server>, Compare> busyServers;
        for(int i = 0; i < servers.size(); i++){
            freeServers.push({0, servers[i], i});
        }
        vector<int> res;
        for(int i = 0; i < tasks.size(); i++){
            while(!busyServers.empty() && busyServers.top().busyTill <= i){
                Server server = busyServers.top();
                busyServers.pop();
                server.busyTill = 0;
                freeServers.push(server);
            }
            if(freeServers.empty()){
                Server server = busyServers.top();
                busyServers.pop();
                res.push_back(server.index);
                server.busyTill += tasks[i];
                busyServers.push(server);
            }
            else{
                Server server = freeServers.top();
                freeServers.pop();
                res.push_back(server.index);
                server.busyTill = i + tasks[i];
                busyServers.push(server);
            }
        }
        return res;
    }
};