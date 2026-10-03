#include<iostream>
#include<vector>
#include<algorithm>

int my_max(std::vector<int> &arr)
{
    int i = 0;
    int pre1 = 0; // dp[i-1] 到上一个位置的最优值
    int pre2 = 0; // dp[i-2] 隔一个位置的最优值
    for_each(arr.begin(),arr.end(),[&i,&pre1,&pre2](int j)->void{
        int choose = pre2 + j; // 选当前j
        int cur = std::max(pre1, choose); // 二选一：不选(pre1) / 选(choose)

        pre2 = pre1;
        pre1 = cur;
        i++;
    });
    return pre1;
}

int main()
{
    std::vector<int> arr={5,1,2,10,6,2,9,3,8,4};
    int res=my_max(arr);
    std::cout<<res;
    return 0;
}
