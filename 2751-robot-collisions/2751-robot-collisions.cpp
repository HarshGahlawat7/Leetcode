struct Robot {
    int pos;
    int health;
    char dir;
    int id;
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);

        for (int i = 0; i < n; ++i) {
            robots[i] = {positions[i], healths[i], directions[i], i};
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });

        stack<Robot> st;
        for (auto& curr : robots) {
            if (curr.dir == 'R') {
                st.push(curr);
                continue;
            }

            while (!st.empty() && st.top().dir == 'R' && curr.health > 0) {
                if (st.top().health < curr.health) {
                    st.pop();
                    curr.health -= 1;
                } else if (st.top().health > curr.health) {
                    st.top().health -= 1;
                    curr.health = 0;
                } else {
                    st.pop();
                    curr.health = 0;
                }
            }

            if (curr.health > 0) {
                st.push(curr);
            }
        }

        vector<Robot> survivors;
        while (!st.empty()) {
            survivors.push_back(st.top());
            st.pop();
        }

        sort(survivors.begin(), survivors.end(), [](const Robot& a, const Robot& b) {
            return a.id < b.id;
        });

        vector<int> result;
        for (const auto& r : survivors) {
            result.push_back(r.health);
        }

        return result;
    }
};