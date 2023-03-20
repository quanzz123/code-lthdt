#include"iostream"

using namespace std;

class dgtr{
    private :
        float bankinh;
        float chuvi;
        float dientich;
    public :
        void getinformation( float r){
            bankinh = r;
        }
        float cv(){
            return  2 * 3.14 * bankinh;
        }
        float dt(){
            return bankinh * bankinh * 3.14;
        }
        void display(){
            cout << "\nchu vi = " << cv() << "\n dien tich = " << dt();
        }

};
int main(){
    dgtr a;
    float n;
    cout << "\nnhap n= ";
    cin >> n;
    a.getinformation(n);
    a.cv();
    a.dt();
    a.display();
    cout << endl;

}