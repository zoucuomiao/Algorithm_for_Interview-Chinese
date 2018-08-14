/*
最长递增子序列_牛客网 https://www.nowcoder.com/questionTerminal/585d46a1447b4064b749f08c2ab9ce66
*/
#pragma once

#include "../all.h"

class AscentSequence {
public:
    int findLongest(vector<int> nums, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;

        int ret = dp[0];
        for (int i = 1; i < n; i++)
            ret = max(ret, dp[i]);

        return ret;
    }
};

void
solve() {
    AscentSequence().findLongest({ 203,39,186,207,83,80,89,237,247 }, 9);
}