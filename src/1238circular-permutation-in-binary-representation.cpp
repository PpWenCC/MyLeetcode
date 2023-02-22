// 给你两个整数 n 和 start。你的任务是返回任意 (0,1,2,,...,2^n-1) 的排列 p，并且满足：

// p[0] = start
// p[i] 和 p[i+1] 的二进制表示形式只有一位不同
// p[0] 和 p[2^n -1] 的二进制表示形式也只有一位不同

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/circular-permutation-in-binary-representation
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// grayCode
// i ⊕ i/2
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res(1<<n,0);
        res[0]=start;
        for(int i = 1;i<res.size();i++){
            res[i]=(i>>1)^i^start; //异或
        }
        return res;
    }
};