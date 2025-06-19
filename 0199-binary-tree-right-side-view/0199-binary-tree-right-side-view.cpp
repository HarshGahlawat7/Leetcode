class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL){
            return {};
        }

        queue<TreeNode*> que;
        que.push(root);
        vector<int> result;

        while(!que.empty()){
            int n = que.size();
            TreeNode* node = NULL;

            for(int i = 0 ; i< n ; i++){
                node = que.front();
                que.pop();

                if(node -> left){
                    que.push(node ->left);
                }
                if(node -> right){
                    que.push(node -> right);
                }
            }
        result.push_back(node -> val);
        }
        return result;
    }
};