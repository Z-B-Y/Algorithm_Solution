class Solution {
public:
    /**
     * ���ݹ˿����Լ�����˿��Ŷ�˳��
     * @param a int����vector �˿�a����
     * @param b int����vector �˿�b����
     * @return int����vector
     */
    vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
        // write code here
        vector<int> result;
        vector<int> data;
        for(int i = 0;i < a.size();i++){
            data.push_back(b[i] - a[i]);   //��ֵԽ��Խ��ǰ����ֵԽСԽ����
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
