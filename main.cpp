#include <iostream>
#include <sstream>

using namespace std;


class Triangle {
    double A;
    double B;
    double C;
public:
    Triangle() {
        A = 3;
        B = 4;
        C = 5;
    };



    Triangle(double a, double b, double c) {
        if (((a + b > c) && (a + c > b) && (b + c > a))) {
            A = a;
            B = b;
            C = c;
        } else {
            cout << "uncorrect sides";
            A = 3;
            B = 4;
            C = 5;
        }

    }

    Triangle(double a, double b)
    {

        if (2 * a > b)
        {
            A = C = a;
            B = b;
        }
        else if (2 * b > a)
        {
            B = C = b;
            A = a;
        }
        else {
            cout << "uncorrected sides, will be used default sides" << endl;
            Triangle();
            C = A;


        }

    }

    Triangle(const Triangle &other) : Triangle(A, B, C) {
        std::cout << "Copy Constr" << std::endl;

        A = other.A;
        B = other.B;
        C = other.C;
    }

    ~Triangle() {
        std::cout << "Class was deleted" << std::endl;

    }

    void setA(double a) {
        if (a > 0)
            A = a;
        else {
            cout << "error";
            A = 3;
        }

    }


    void setB(double b) {
        if (b > 0)
            B = b;
        else {
            cout << "error";
            B = 4;
        }
    }


    void setC(double c) {
        if (c > 0)
            C = c;
        else {
            cout << "error";
            C = 5;
        }
    }


    double getP() {
        return A + B + C;
    }

    double getMaxside() {
        return std::max(A, std::max(B, C));
    }

    std::string getInfo() {
        std::ostringstream oss;
        oss << "sides of Triangle: " << A << ", " << B << ", " << C << std::endl;
        oss << "perimeter: " << getP() << std::endl;
        return oss.str();
    }

    void printInfo() {
        std::string info = getInfo();
        std::cout << info;
    }

};


int main() {
    Triangle abc(1.0, 1.0);
    abc.printInfo();
    std::cout << "Max side: " << abc.getMaxside() << std::endl;
    cout<<endl;
    Triangle rt(3,1);
    rt.printInfo();
    return 0;
}
