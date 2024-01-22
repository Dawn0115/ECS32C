//A function to check the types of different letters and return different values
int between(char lowerBound, char upperBound, char target){
     //situation 1
    if (!(lowerBound >= 65 && lowerBound <= 90) ||
        !(upperBound >= 65 && upperBound <= 90) ||
        !(target >= 65 && target <= 90)) {
        return -1;
    }
//situation2
    if(lowerBound>upperBound){
        return-2;
    }
    //situation 3
     if (target >= lowerBound && target <= upperBound) {
        return 1;}
// TODO: Implement.
// The below return statement is here in order to prevent
// a compiler error. You probably won't need it once you
// implement this function.


return 0;
}
