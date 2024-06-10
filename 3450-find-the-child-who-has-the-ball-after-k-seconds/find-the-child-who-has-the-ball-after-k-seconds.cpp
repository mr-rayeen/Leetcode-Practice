class Solution {
public:
    int numberOfChild(int n, int k) {

        // n childs me total n-1 passes hoge
        //  n=5, k = 6
        //   -1->  -2->  -3->   -4->
        //  0     1     2     3     4 
        //   <-8-   <-7-  <-6-  <-5-
        //  8 sec ke bad hum intial state par agaye
        //  8 = 2(5-1)
        //  8 = 2(n-1)

        int d = k / (n-1);
        int rem = k % (n-1);

        if(d%2 == 0){
            return rem;
        }else{
            return (n-1) -rem;
        }

    }
};