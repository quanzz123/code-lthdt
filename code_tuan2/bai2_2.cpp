#include"iostream"

using namespace std;

void tao_mang(int **&arr, int n, int m){
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
    }

}
void nhap_mang(int **arr, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << "\nnhap gia tri phan tu thu [" << i << "][" << j << "]";
            cin >> arr[i][j];
        }
    }
}

void in_mang(int **arr, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";

        }
        cout << endl;
    }

}
void tong_hieu(int **arr1, int n, int m, int **arr2, int p, int q){
    if(n == p && m == q){
        int **tong = new int*[n];
        int **hieu = new int *[n];
        for(int i=0; i<n; i++){
            tong[i] = new int[m];
            hieu[i]= new int[m];
            for(int j=0; j<m; j++){
                tong[i][j] = arr1[i][j] + arr2[i][j];
                hieu[i][j] = arr2[i][j] - arr2[i][j];
            }
        

        }
    }
    else(
        cout << "\nhai ma tran khong cug cap!";
    )

}    
void hieu(int **arr1, int n, int m, int **arr2, int p, int q){
    if(n == p && m == q){
        int **hieu = new int*[n];
        for(int i=0; i<n; i++){
            hieu = new int[m];
            for(int j=0; j<m; j++){
                hie
            }
        }
    }
}
int main(){
    int n,m,p,q;
    cout << "\nnhap so hang cua ma tran thu nhat: ";
    cin >> n;
    cout << "\nnhap so cot cua ma tran thu nhat: ";
    cin >> m;
    cout << "\nnhap so hang cua ma tran thu hai: ";
    cin >> p;
    cout << "\nnhap so cot cua ma trna thu hai: ";
    cin >> q;
    int  **arr1;
    arr1 = new float*[n];
    int **arr2;
    arr2 = new int[p];
    for(int i=0; i<n; i++)
    delete arr1[i];
    delete arr1;
    for(int i=0; i<p; i++)
    delete arr2[i];
    delete arr2;
    return 0;


}