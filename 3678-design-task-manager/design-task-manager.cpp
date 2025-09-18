class TaskManager {
public:
    unordered_map<int,int> task_to_user;
    unordered_map<int,pair<unordered_map<int,int>,unordered_map<int,set<int>>>> Manager;

    struct Node {
        int priority, taskId, userId;
        bool operator<(const Node& other) const {
            if(priority != other.priority) return priority < other.priority;
            return taskId < other.taskId;
        }
    };

    priority_queue<Node> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        task_to_user[taskId] = userId;
        Manager[userId].first[taskId] = priority;
        Manager[userId].second[priority].insert(taskId);
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        int userId = task_to_user[taskId];
        int oldPriority = Manager[userId].first[taskId];
        Manager[userId].second[oldPriority].erase(taskId);
        if(Manager[userId].second[oldPriority].empty())
            Manager[userId].second.erase(oldPriority);

        Manager[userId].first[taskId] = newPriority;
        Manager[userId].second[newPriority].insert(taskId);
        pq.push({newPriority, taskId, userId});
    }

    void rmv(int taskId) {
        int userId = task_to_user[taskId];
        int priority = Manager[userId].first[taskId];
        Manager[userId].first.erase(taskId);
        Manager[userId].second[priority].erase(taskId);
        if(Manager[userId].second[priority].empty())
            Manager[userId].second.erase(priority);
        task_to_user.erase(taskId);
    }

    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int taskId = top.taskId;
            int userId = top.userId;
            int priority = top.priority;
            if (task_to_user.count(taskId) &&
                Manager[userId].first[taskId] == priority) {
                rmv(taskId);
                return userId;
            }
        }
        return -1;
    }
};
