class BigInteger {
public:
    string number;

    BigInteger(string num = "0") : number(num) {
        while (number.size() > 1 && number[0] == '0') number.erase(0, 1);
    }

    BigInteger operator+(const BigInteger& other) const {
        string a = number, b = other.number;
        if (a.size() < b.size()) swap(a, b);
        int carry = 0, sum;
        string result = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < a.size(); ++i) {
            sum = (a[i] - '0') + (i < b.size() ? (b[i] - '0') : 0) + carry;
            carry = sum / 10;
            result += (sum % 10) + '0';
        }
        if (carry) result += '1';
        reverse(result.begin(), result.end());
        return BigInteger(result);
    }

    BigInteger operator*(const BigInteger& other) const {
        int n = number.size(), m = other.number.size();
        vector<int> result(n + m, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (number[i] - '0') * (other.number[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string res = "";
        for (int num : result) if (!(res.empty() && num == 0)) res += to_string(num);
        return BigInteger(res.empty() ? "0" : res);
    }

    bool operator<(const BigInteger& other) const {
        if (number.size() != other.number.size()) return number.size() < other.number.size();
        return number < other.number;
    }
    bool operator==(const BigInteger& other) const { return number == other.number; }
    bool operator>(const BigInteger& other) const { return other < *this; }
    bool operator<=(const BigInteger& other) const { return !(other < *this); }
    bool operator>=(const BigInteger& other) const { return !(*this < other); }
};
