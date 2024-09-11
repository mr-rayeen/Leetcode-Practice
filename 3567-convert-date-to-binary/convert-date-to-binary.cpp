class Solution {
public:
    string decimalToBinary(int decimal){
        string binary = "";
        while(decimal > 0){
            binary = (decimal % 2 == 0 ? "0" : "1" ) + binary;
            decimal = decimal / 2;
        }
        return binary;
    };
    string convertDateToBinary(string date) {
         string binary = "";
    string temp = "";
    string month = "";
    string day = "";
    string year = "";

    for(int i=0; i<4; i++){
        temp = date[i];
        year += temp;
    }
    for(int i=5; i<7; i++){
        temp = date[i];
        month += temp;
    }
    for(int i=8; i<12; i++){
        temp = date[i];
        day += temp;
    }
    binary = decimalToBinary(stoi(year))+'-'+decimalToBinary(stoi(month))+'-'+decimalToBinary(stoi(day));

    return binary;
    }
};