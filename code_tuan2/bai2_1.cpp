#include"iostream"

using namespace std;

void taoVecto( float arr[], int n){
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}
void inVecto(float arr[], int n){
    cout << "(";
    for(int i=0; i<n; i++){
        cout <<arr[i] << " ";
    }
    cout << ")";
    cout << endl;
}
void tinh(float arr[], int n, int m){
    if(n == m){
        
    } else{
        cout << "\nhai vecto khong cung chieu";

    }
}
void vector_add_subtract(float* a, int n, float* b, int m)
{
    if(n!=m)
    {
        cout<<"Hai vector khong cung chieu!"<<endl;
        return;
    }
    float* sum = new float[n];
    float* diff = new float[n];
    for(int i=0;i<n;i++)
    {
        sum[i] = a[i]+b[i];
        diff[i] = a[i]-b[i];
    }
    cout<<"Tong cua hai vector la: ";
    cout << "(";
    for(int i=0;i<n;i++){
        cout<<sum[i]<<" ";
    }
    cout << ")";
    cout<<endl<<"Hieu cua hai vector la: ";
    cout << "(";
    for(int i=0;i<n;i++){
        cout<<diff[i]<<" ";
    }
    cout << ")";
    cout<<endl;
    delete[] sum;
    delete[] diff;
}

int main(){
    int m,n;
    
    cout << "\nnhap so phan tua cua vecto thu nhat: ";
    cin >> n;
    cout << "\nnhap so phan tu cua vecto thu hai: ";
    cin >> m;
    float *arr = new float[n];
    float *arr2 = new float[m];
    taoVecto(arr, n);
    taoVecto(arr2 , m);
    inVecto(arr,n);
    inVecto(arr2,m);

    vector_add_subtract(arr,n,arr2,m);

    delete[] arr;
    delete[] arr2;
    
}

