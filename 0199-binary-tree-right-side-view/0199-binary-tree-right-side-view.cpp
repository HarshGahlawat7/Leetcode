class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }

        vector<int> result;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            TreeNode* node = NULL;

            while(n--){
                node = que.front();
                que.pop();

                if(node->left != NULL){
                    que.push(node ->left);
                }
                if(node ->right != NULL){
                    que.push(node -> right);
                }
            }
            result.push_back(node -> val);
        } 
        return result; 
    }
};