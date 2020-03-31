class Solution {
public:
    /**
     * 
     * @param a_vecData int����vector ���ݼ�
     * @return int����vector<vector<>>
     */
    vector <vector<int> > findAllType(vector<int>& a_vecData) {
        // write code here
        vector<vector<int> > result;
        vector<int> data;
        int start = 0,end = a_vecData.size();
        get(start,end,a_vecData,result);
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
    void get(int start,int end,vector<int>& a_vecData,vector<vector<int>>& result){
        if (start == end){ //�õ�ȫ���е�һ��
            result.push_back(a_vecData);
            return;
        }
        for(int i = start;i < end; i ++){
            swap(a_vecData[start],a_vecData[i]);
            get(start + 1,end,a_vecData,result);
            swap(a_vecData[i],a_vecData[start]);
        }
    }
};
