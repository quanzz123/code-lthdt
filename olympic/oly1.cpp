#include"stdio.h"
#include"math.h"
int sont(int n){
    if(n<2){
        return 0;

    }
    for(int i=2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    printf("\nhap so n tu ban phim: ");
    scanf("%d", &n);
    if(sont(n)){
        printf("la so nguyen to!");
    }
    else
    printf("khong la so nguyen to!");
    return 0;
}