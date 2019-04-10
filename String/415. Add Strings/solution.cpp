class Solution1 {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()>num2.size())swap(num1,num2);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        bool add = false;
        string res = "";
        for(int i = 0; i < num1.size(); ++i){
            int tmp = (num1[i] - '0') + (num2[i] - '0');
            if(add){
                tmp += 1;
                add = false;
                if(tmp>=10){
                    tmp = tmp % 10;
                    add = true;
                }
                res += (tmp + '0');
            }
            else{
                if(tmp>=10){
                    tmp = tmp % 10;
                    add = true;
                }
                res += (tmp + '0');
            }
        }
        if(!add)res += num2.substr(num1.size(), num2.size()-num1.size() + 1);
        else{
            int k = num1.size();
            int tmp;
            while(k<num2.size() && add){
                tmp = (num2[k] - '0') + 1;
                if(tmp >= 10){
                    tmp = tmp % 10;
                    add = true;
                }
                else add = false;
                res += (tmp + '0');
                k++;
            }
           
            if(k<num2.size())res += num2.substr(k, num2.size()-num1.size() + 1);
            else{
                if(add)res += '1';
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

class Solution2 {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0,sum;
        for(int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0;){
            sum = carry;
            if(i >= 0) sum += num1[i--] - '0';
            if(j >= 0) sum += num2[j--] - '0';
            res += (sum % 10 + '0');
            carry = sum /10;
        }
        if(carry) res += '1';
        reverse(res.begin(),res.end());
        return res;
    }
};
