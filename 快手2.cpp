class Solution {
public:
    /**
     * �������ظ������ӵ� N����������֮�͵�����������
     * @param R int���� 
     * @param N int���� N����
     * @return int����vector
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
