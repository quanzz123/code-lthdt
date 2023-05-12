#include <iostream>
#include <vector>
using namespace std;

// Vector class to represent vectors
class Vector {
    int n; // number of elements
    int *v; // pointer to data elements
public:
    // Default constructor
    Vector() {
        n = 0;
        v = nullptr;
    }

    // Constructor with one parameter (size)
    Vector(int size) {
        n = size;
        v = new int[n]; // allocate memory for data elements
    }

    // Constructor with two parameters (size and value)
    Vector(int size, int value) {
        n = size;
        v = new int[n]; // allocate memory for data elements
        for (int i = 0; i < n; i++) {
            v[i] = value; // initialize data elements with value
        }
    }

    // Copy constructor
    Vector(const Vector& other) {
        n = other.n;
        v = new int[n]; // allocate memory for data elements
        for (int i = 0; i < n; i++) {
            v[i] = other.v[i]; // copy data elements from other vector
        }
    }

    // Destructor
    ~Vector() {
        delete[] v; // deallocate memory for data elements
    }

    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) { // avoid self-assignment
            delete[] v; // deallocate memory for data elements
            n = other.n;
            v = new int[n]; // allocate memory for data elements
            for (int i = 0; i < n; i++) {
                v[i] = other.v[i]; // copy data elements from other vector
            }
        }
        return *this;
    }

    // Input operator (friend function)
    friend istream& operator>>(istream& in, Vector& vec) {
        cout << "Enter " << vec.n << " elements: ";
        for (int i = 0; i < vec.n; i++) {
            in >> vec.v[i]; // input data elements
        }
        return in;
    }

    // Output operator (friend function)
    friend ostream& operator<<(ostream& out, const Vector& vec) {
        out << "[";
        for (int i = 0; i < vec.n; i++) {
            out << vec.v[i]; // output data elements
            if (i < vec.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    // Addition operator (friend function)
    friend Vector operator+(const Vector& vec1, const Vector& vec2) {
        if (vec1.n == vec2.n) { // check if vectors have same size
            Vector result(vec1.n); // create a result vector with same size
            for (int i = 0; i < result.n; i++) {
                result.v[i] = vec1.v[i] + vec2.v[i]; // add corresponding data elements
            }
            return result;
        }
        else { // vectors have different sizes
            throw invalid_argument("Vectors must have same size to add"); // throw an exception
        }
    }
};

// Main function to test the vector class
int main() {
    try { 
        Vector a(3); // create a vector of size 3
        cin >> a; // input data elements for a

        Vector b(3); // create another vector of size 3
        cin >> b; // input data elements for b

        Vector c = a + b; // add two vectors and assign to c

        cout << "a = " << a << endl; // print vector a
        cout << "b = " << b << endl; // print vector b
        cout << "c = " << c << endl; // print vector c

    } catch (const exception& e) { 
       cout << e.what() << endl; // print exception message if any 
   } 
   return 0;
}
