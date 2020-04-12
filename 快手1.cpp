class Solution {
public:
    /**
     * 根据顾客属性计算出顾客排队顺序
     * @param a int整型vector 顾客a属性
     * @param b int整型vector 顾客b属性
     * @return int整型vector
     */
    vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
        // write code here
        vector<int> result;
        vector<int> data;
        for(int i = 0;i < a.size();i++){
            data.push_back(b[i] - a[i]);   //差值越大越靠前，差值越小越靠后
        }
        sort(data.begin(),data.end());
        for(int i = 0;i < a.size();i++){
            for(int j = 0;j < a.size();j++){
                if(data[i] == b[j] - a[j]){
                    result.push_back(j+1);
                    break;
                }
            }
        }
        return result;
    }
};
