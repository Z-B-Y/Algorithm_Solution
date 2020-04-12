class Solution {
public:
    /**
     * 返回无重复幂因子的 N进制完美数之和的所有幂因子
     * @param R int整型 
     * @param N int整型 N进制
     * @return int整型vector
     */
    vector<int> GetPowerFactor(int R, int N) {
        // write code here
       vector<int> data;
       vector<int> result;
        for(int i = 0;i <= R;i ++){
            data.push_back(1);
        }
        int k = N;
       while(k <= R) {
        for(int i = k;i < R;i++)
           data[i] = data[i-k];
       
        k = k * N;
    }
        int j = 0;
        for(int i = 0;i < data.size();i++){
            if(data[i]!=1)
                result.push_back(data[i]);
        }
    return result;
    }
};
