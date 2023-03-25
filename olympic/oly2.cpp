#include"stdio.h"
#include"math.h"

int uoc(int n){
    int dem =0;
    for(int i=1; i<=n; i++){
        if(n % i == 0){
            dem++;
        }
    }
    return dem;
}
int main(){
    int n;
    FILE *fin = fopen("sqffree.inp", "r");
    fscanf(fin, "%d", &n);
    fclose(fin);

    FILE *fout = fopen("sqffree.out", "w");
    fprintf(fout,"%d", uoc(n));
    fclose(fout);
    return 0;
}