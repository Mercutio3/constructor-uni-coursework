#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkPassword(char *str){
    int strL = strlen(str);
    int digitCount = 0;
    if(strL < 8){
        return false;
    } else {
        for(int i = 0; i < strL; i++){
            char curr = str[i];
            if(curr=='0' || curr=='1' || curr=='2' || curr=='3' || curr=='4' || curr=='5' || curr=='6' || curr=='7'|| curr=='8' || curr=='9'){
                digitCount++;
            }
        }
        if(digitCount >= 3){
            return true;
        } else {
            return false;
        }
    }
}

int main(){
    char passOne[1000] = "p455w";
    printf("%d", checkPassword(passOne));

    return 0;
}