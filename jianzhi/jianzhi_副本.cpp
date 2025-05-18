#include<iostream>
#include<vector>
using namespace std;
int cuttingRope(int n){
     if(n==1) return 1;
     if(n==2) return 1;
     if(n==3) return 2;
     vector<int> vec(n + 1, 0);
     int index = 1;
     vec[index++]=1;
     vec[index++]=2;
     vec[index++]=3;
     while(index<=n){
         int res = 0;
         for(int i = 1;i<=index/2;++i){
             int tmp = vec[i]*vec[index - i];
             if(tmp>res)res = tmp;
         }
         vec[index++] = res;
     }
     return vec[n];
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool jianyan(TreeNode* root, int val, bool flag){ //flag = true 左孩子
        if(root == nullptr) return true;
        if(flag){
            if(root->val>=val) return false;
            return jianyan(root->left, val, true) && jianyan(root->right, val, true);
        }else{
            if(root->val<=val) return false;
            return jianyan(root->left, val, false) && jianyan(root->right, val, false);
        }
}

bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        if(!jianyan(root->left, root->val, true)) return false;
        if(!jianyan(root->right, root->val, false)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
}
int nthUglyNumber(int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    int index = 1;
    int a = 0, b = 0, c = 0;
    while(index<=n-1){
        int tmp = min(min(dp[a]*2, dp[b]*3),dp[c]*5);
        if(tmp == dp[a]*2) ++a;
        if(tmp == dp[b]*3) ++b;
        if(tmp == dp[c]*5) ++c;
        dp[index++] = tmp;
    }
    return dp[n-1];
}
//2025-5-18 everyday 爬楼梯
int climbStairs(int n) {
    //dp[i] = dp[i-1] + dp[i-2] 状态方程
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 2;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
//打家劫舍
int rob(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); ++i){
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[nums.size() - 1];
}

//等差数列划分
int numberOfArithmeticSlices(vector<int>& nums) {
    if(nums.size() < 3) return 0;
    int res = 0;
    int count = 0;
    for(int i = 2; i < nums.size(); ++i){
        if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]){
            ++count;
            res += count;
        }else{
            count = 0;
        }
    }
    return res;
    
}

int main(){
	
}

