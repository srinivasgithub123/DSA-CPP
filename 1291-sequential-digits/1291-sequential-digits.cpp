class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> seq;

        int lowwindlen = to_string(low).size();
        int highwindlen = min((int)to_string(high).size(), 9);

        string res = "123456789";

        for (int len = lowwindlen; len <= highwindlen; len++) {
            for (int start = 0; start <= (int)res.size() - len; start++) {
                string str = res.substr(start, len);
                int num = stoi(str);

                if (num >= low && num <= high) {
                    seq.push_back(num);
                }
            }
        }

        return seq;
    }
};