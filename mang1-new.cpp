#include"iostream"

using namespace std;

void nhap(float arr[], int n)
{
   for(int i=0; i<n; i++)
   {
        cout << "\nnhap phan tu thu " << i << ":  ";
        cin >> arr[i];
   }
}
void xuat(float arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
float sum(float arr[], int n)
{
    float sum =0;
    for(int i=0; i<n; i++)
    {
         sum += arr[i];
    }
    return sum;

}

int main()
{
    int n;
    cout << "\nnhap so phan tu cua mang: ";
    cin >> n;
    float *arr = new float[n];

    nhap(arr,n);

    xuat(arr,n);

    float avg = (float)sum(arr,n) / n;
    cout << "\nAvg= " << avg;
    cout << endl;

    delete[] arr;

    return 0;

}