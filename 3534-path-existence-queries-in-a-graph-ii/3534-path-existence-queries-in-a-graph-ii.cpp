class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
      vector<pair<int, int>> valIdx(n);
        for (int i = 0; i < n; ++i) {
            valIdx[i] = {nums[i], i};
        }
        sort(valIdx.begin(), valIdx.end());

        vector<int> uniqueVals;
        for (int i = 0; i < n; ++i) {
            if (uniqueVals.empty() || uniqueVals.back() != valIdx[i].first) {
                uniqueVals.push_back(valIdx[i].first);
            }
        }

        int m = uniqueVals.size();
        vector<int> componentId(n, -1);
        int currId = 0;
        
        vector<int> valToComp(m);
        valToComp[0] = currId;
        for (int i = 1; i < m; ++i) {
            if (uniqueVals[i] - uniqueVals[i - 1] > maxDiff) {
                currId++;
            }
            valToComp[i] = currId;
        }

        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(uniqueVals.begin(), uniqueVals.end(), nums[i]) - uniqueVals.begin();
            componentId[i] = valToComp[pos];
        }

        int logM = 18;
        vector<vector<int>> upRight(m, vector<int>(logM));
        vector<vector<int>> upLeft(m, vector<int>(logM));

        for (int i = 0; i < m; ++i) {
            int targetRight = uniqueVals[i] + maxDiff;
            int idxRight = upper_bound(uniqueVals.begin(), uniqueVals.end(), targetRight) - uniqueVals.begin() - 1;
            upRight[i][0] = idxRight;

            int targetLeft = uniqueVals[i] - maxDiff;
            int idxLeft = lower_bound(uniqueVals.begin(), uniqueVals.end(), targetLeft) - uniqueVals.begin();
            upLeft[i][0] = idxLeft;
        }

        for (int j = 1; j < logM; ++j) {
            for (int i = 0; i < m; ++i) {
                upRight[i][j] = upRight[upRight[i][j - 1]][j - 1];
                upLeft[i][j] = upLeft[upLeft[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (componentId[u] != componentId[v]) {
                ans.push_back(-1);
                continue;
            }
            if (nums[u] == nums[v]) {
                ans.push_back(1);
                continue;
            }

            int startVal = nums[u];
            int endVal = nums[v];
            int startIdx = lower_bound(uniqueVals.begin(), uniqueVals.end(), startVal) - uniqueVals.begin();
            int endIdx = lower_bound(uniqueVals.begin(), uniqueVals.end(), endVal) - uniqueVals.begin();

            int steps = 0;
            if (startIdx < endIdx) {
                int curr = startIdx;
                for (int j = logM - 1; j >= 0; --j) {
                    if (upRight[curr][j] < endIdx) {
                        steps += (1 << j);
                        curr = upRight[curr][j];
                    }
                }
                steps++; 
                ans.push_back(steps);
            } else {
                int curr = startIdx;
                for (int j = logM - 1; j >= 0; --j) {
                    if (upLeft[curr][j] > endIdx) {
                        steps += (1 << j);
                        curr = upLeft[curr][j];
                    }
                }
                steps++; 
                ans.push_back(steps);
            }
        }

        return ans;
    }
};