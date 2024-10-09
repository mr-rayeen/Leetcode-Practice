class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        // int l = 0;
        // int r = num.length() -1;
        bool ans = false;

        // while(l<=r){
        //     if(num[0] == '-'){
        //         return ans = false;
        //     }
        //     if(num[l] == num[r]){
        //         ans = true;
        //     }else{
        //         ans = false;
        //     }
        //     l++;
        //     r--;
        // }
        // return ans;
        
        if(num[0] == '-'){
                return false;
            }
        int rev = 0;
        int temp = x;
        while(temp != 0){
            int lastDigit = temp%10;

            if((rev > INT_MAX /10) || (rev < INT_MIN/10)){
                return false;
            }
            temp = temp/10;
            rev = rev*10 + lastDigit;
        }
        if(rev == x){
            ans = true;
        }
        return ans;
    }
};