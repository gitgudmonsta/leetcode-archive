class Solution {
public:
    char findKthBit(int n, int k) {
        int sz = std::pow(2, n);

        std::vector<char> s(sz);
        s[1] = '0';
        int idx = 2, pos = 2;

        while(idx <= n) {
            s[pos] = '1';
            for(int i = 1; pos - i > 0; i++)
                s[pos + i] = (s[pos - i] == '0')? '1': '0';
            idx += 1;
            pos *= 2;
        }

        return s[k];
    }
};
