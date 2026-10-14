class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum>num*9) return "";
        string n="";
        int d = sum / 9;
        int r = sum % 9;
        while (d--) n += '9';
        if (r > 0) n += char('0' + r);
        while ((int)n.size() < num) n += '0';
        return n;
    }
};