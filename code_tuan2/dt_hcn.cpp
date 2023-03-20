#include"iostream"

using namespace std;

class hcn{
    private :
        float width;
        float length;
    public :
        void getinformation(float a, float b){
            width = a;
            length = b;
        }
        float cv(){
            return (width + length) / 2;
        }
        float dt(){
            return width * length;
        }
        void display(){
            cout << "\nchu vi hinh chu nhat la: " << cv() << "\ndien tich hinh chu nhat la: " << dt();
        }

};
int main(){
    hcn q;
    float n,m;
    cout << "\nnhap m= ";
    cin >> m;
    cout << "\nnhap n= ";
    cin >> n;
    q.getinformation(m,n);
    q.cv();
    q.dt();
    q.display();
    cout << endl;
}

