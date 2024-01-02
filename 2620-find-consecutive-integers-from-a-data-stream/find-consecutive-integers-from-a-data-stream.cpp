class DataStream {
public:
    int count;
    int val;
    int K;
    DataStream(int value, int k) {
        count = 0;
        val = value;
        K = k;
    }
    
    bool consec(int num) {
        if(val == num)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        if(count >= K)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */