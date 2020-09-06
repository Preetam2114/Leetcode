class Solution {
public:
    void pushLeft(stack <TreeNode*>& st, TreeNode* root){
          TreeNode* curr = root;
          while(curr){
             st.push(curr);
             curr = curr->left;
        }
   }
   vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      vector <int> ans;
      stack <TreeNode*> st1, st2;
      TreeNode* curr1 = root1;
      TreeNode* curr2 = root2;
      pushLeft(st1, curr1);
      pushLeft(st2, curr2);
      while(!st1.empty() || !st2.empty()){
         TreeNode* temp;
         if(!st1.empty() && (st2.empty() || st1.top()->val <= st2.top()->val)){
            temp = st1.top();
            st1.pop();
            ans.push_back(temp->val);
            pushLeft(st1, temp->right);
         }
         else{
            temp = st2.top();
            st2.pop();
            ans.push_back(temp->val);
            pushLeft(st2, temp->right);
         }
      }
      return ans;
   }
};
