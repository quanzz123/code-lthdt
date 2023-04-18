#include<iostream>
using namespace std;

class Vector {
  private:
    int n;
    double *v;
  public:
    Vector() { // Hàm thiết lập 0 tham số
      n = 0;
      v = NULL;    
    }
    
    Vector(int num) { // Hàm thiết lập 1 tham số
      n = num;
      v = new double[n];
      for(int i=0;i<n;i++)
        v[i] = 0.0;
    }
    
    Vector(int num, double val) { // Hàm thiết lập 2 tham số
      n = num;
      v = new double[n];
      for(int i=0;i<n;i++)
        v[i] = val;
    }
    
    void add() { // Hàm nhập dữ liệu cho véc tơ
      cout<<"Enter "<<n<<" values: ";
      for(int i=0;i<n;i++)
        cin>>v[i];
    }
    
    Vector(const Vector &obj) { // Hàm thiết lập sao chép
      n = obj.n;
      v = new double[n];
      for(int i=0;i<n;i++)
        v[i] = obj.v[i];
    }
    
    ~Vector() { // Hàm huỷ bỏ
      delete [] v;
    }
    
    Vector& operator=(const Vector &obj) { // Phép gán đối tượng
      if(this == &obj)
        return *this;
      delete [] v;
      n = obj.n;
      v = new double[n];
      for(int i=0;i<n;i++)
        v[i] = obj.v[i];
      return *this;
    }
    
    void print() { // Hàm in 1 véc tơ
      cout<<"[ ";
      for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
      cout<<"]"<<endl;
    }
};


