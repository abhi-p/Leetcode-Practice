/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 void recursiveFlatten(TreeNode* parent) {
      if (!parent)
        return;
      
      
      //If parent has a left child
      if(parent->left) {
        TreeNode * leftChild=parent->left;
        TreeNode * rightMostChild = leftChild;
        while(rightMostChild->right) {
          rightMostChild = rightMostChild->right;
        }
       
       TreeNode* oldRightChild = parent->right;
    //   cout<<parent->right<<" "<<parent->left<<" "<<leftChild<<endl;
      // cout<<parent->right->val<<" "<<parent->left->val<<endl; 
        parent->right = leftChild;
     //   cout<<"done"<<endl;
        if(oldRightChild) {      
          rightMostChild->right=oldRightChild;
        } 
        parent->left=nullptr;
     //   cout<<"finish"<<endl;      
      }
      
    //  cout<<"end recusive"<<endl;
      
      //If parent doesnt have a left child
      //parent has no children
      //Call recursiveFlatten on new right child of parent
      recursiveFlatten(parent->right); 
    }
  
       void flatten(TreeNode* root) {
      
        recursiveFlatten(root);
      //  cout<<"done flatten"<<endl;
      //  TreeNode * verification = root;

 /*       while(verification->right) {
     //     cout<<verification->left<<" "<<verification->right<<endl;
                    verification = verification->right;

        }*/
    }

};