#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode():val(0), left(nullptr), right(nullptr){}
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
        TreeNode(int x, TreeNode* left, TreeNode *right): val(x), left(left),right(right){}
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root){    
    vector<vector<int>> res;
    if(!root) return res;
    vector<int> vec;
    stack<TreeNode*> stk;
    skt.push(root);
    int count_current = 1, count = 0;
    bool left_to_right = false;
    while(!stk.empty()){
        if(count_current){
            --count_current;
            TreeNode* tmp = stk.top();
            stk.pop();
            vec.push_back(tmp->val);
            if(left_to_right){
               if(tmp->left){
                    ++count;
                    stk.push(tmp->left);
               }
               if(tmp->right){
                    ++count;
                    stk.push(tmp->right);
               } 
            }else{
                if(tmp->right){
                        ++count;
                        stk.push(tmp->right);
                }
                if(tmp->left){
                        ++count;
                        stk.push(tmp->left);
                }
            }         
        }else{
            if(left_to_right) left_to_right = false;
            else left_to_right  true;
            res.push_back(vec);
            vec.clear();
            count_current = count;
            count = 0;
        }
    }
    return res;
}
int main(){
 }
