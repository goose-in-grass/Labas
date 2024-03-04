#include <iostream>
#include <sstream>
using namespace std;


class Triangle {
    double A;
    double B;
    double C;
public:
    Triangle(double a, double b, double c)
    {
        if (((a + b > c) && (a + c > b) && (b + c > a))) {
            A = a;
            B = b;
            C = c;
        } else {
            cout << "uncorrect sides";
            a = 0;
            b = 0;
            c = 0;
        }
    }

    Triangle(const Triangle& other) : Triangle(A, B, C)
    {
        std::cout << "Copy Constr" << std::endl;

        A = other.A;
        B = other.B;
        C = other.C;
    }

    ~Triangle()
    {
        std::cout << "Class was deleted" << std::endl;

    }


    double getA() {
        return A;
    }

    void setA(double a) {
        if (a > 0)
            A = a;
        else
            cout << "error";
    }

    double getB() {
        return B;
    }

    void setB(double b) {
        if (b > 0)
            B = b;
        else
            cout << "error";
    }

    double getC() {
        return C;
    }

    void setC(double c) {
        if (c > 0)
            C = c;
        else
            cout << "error";
    }

    double getP()
    {
        return A + B + C;
    }

    double getMaxside() {
        return std::max(A, std::max(B, C));
    }

    std::string getInfo()
    {
        std::ostringstream oss;
        oss << "Стороны треугольника: " << A << ", " << B << ", " << C << std::endl;
        //oss << "Периметр: " << getP() << std::endl;
        return oss.str();
    }
};


int main() {
    Triangle abc(3,5, 4);
    abc.getInfo();
    abc.getP();
    abc.getMaxside();
    return 0;
}
