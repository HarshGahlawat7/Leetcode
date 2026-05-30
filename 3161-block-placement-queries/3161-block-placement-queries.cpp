class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l || l > r) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        // Define a safe tracking size for the segment tree
        int N = max_x + 2;
        SegmentTree st(N);
        
        set<int> obstacles;
        obstacles.insert(0); // Origin is our natural base
        
        vector<bool> results;
        
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                auto it = obstacles.upper_bound(x);
                
                int l = *prev(it);
                st.update(1, 0, N - 1, x, x - l);
                
                // If there is an obstacle to the right, update its gap value
                if (it != obstacles.end()) {
                    int r = *it;
                    st.update(1, 0, N - 1, r, r - x);
                }
                
                obstacles.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
                
                // Find the closest obstacle to the left of or exactly at x
                auto it = obstacles.upper_bound(x);
                int l = *prev(it);
                
                // 1. Max gap completely contained within [0, l]
                int max_prev_gap = st.query(1, 0, N - 1, 0, l);
                
                // 2. The remaining suffix gap stretching to x
                int last_gap = x - l;
                
                if (max(max_prev_gap, last_gap) >= sz) {
                    results.push_back(true);
                } else {
                    results.push_back(false);
                }
            }
        }
        
        return results;
    }
};