class Solution{
    public:
        void preorder(TreeNode* root , vector<int>& result){
            if(root == nullptr){
                return;
            }
            result.push_back(root->val);
            preorder(root -> left, result);
            preorder(root ->right , result);
        }


        vector<int> preorderTraversal(TreeNode* root){

            vector<int> result;
            preorder(root , result);

            return result;

        }
};
