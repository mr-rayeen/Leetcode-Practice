class ParkingSystem {
public:
    int abig, amedium, asmall;
    ParkingSystem(int big, int medium, int small) {
        abig = big;
        amedium = medium;
        asmall = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(abig == 0) {
                return false;
            }else{
                abig--;
                return true;
            }
        }
        if(carType == 2){
            if(amedium == 0) {
                return false;
            }else{
                amedium--;
                return true;
            }
        }
        if(carType == 3){
            if(asmall == 0) {
                return false;
            }else{
                asmall--;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */