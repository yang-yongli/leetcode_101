class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        const int mod = 1e9 + 7;
        int ans = 0;
        // 从小到大排序
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int j = drinks.size() - 1;
        /*
        思想：让主食的最小去依次去加饮料从大到小的价格，
        如果加到一个当前最大的饮料价格就不用再计算比这个价格小的那些价格了（必然满足），
        此时数量就是当前主食对应的购买方案个数
        。。。。。
        以此类推计算下一个主食的搭配
        */ 
        for (int i = 0; i < staple.size(); i++) {
            while (j >= 0 && staple[i] + drinks[j] > x) 
                j--;
            if (j == -1)
                break;
            ans += j + 1;
            ans %= mod;
        }
        return ans;
    }
};

