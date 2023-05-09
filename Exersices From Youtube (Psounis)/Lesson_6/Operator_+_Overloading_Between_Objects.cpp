#include <iostream>
using namespace std;

class complex
{
    public:
        complex();
        complex(double in_real,double in_imag);
        void set_real(double in_real);
        void set_imag(double in_imag);
        double get_real() const;
        double get_imag() const;
        complex operator+ (const complex &b);  //!
    private:
        double real;
        double imag;
};

int main(void)
{
    complex a(1.0,2.0);
    complex b(2.0,3.0);
    complex x(8.9,2.1);

    complex c;

    c = x+b;

    cout << c.get_real() <<" "<<c.get_imag() << endl;


    return 0;
}

complex::complex()
{
    real = 0.0;
    imag = 0.0;
}

complex::complex(double in_real,double in_imag)
{
    real = in_real;
    imag = in_imag;
}

void complex::set_real(double in_real)
{
    real = in_real;
}

void complex::set_imag(double in_imag)
{
    imag = in_imag;
}

double complex::get_real() const
{
    return real;
}

double complex::get_imag() const
{
    return imag;
}

complex complex::operator+(const complex &b)
{
    return complex(real+b.real, imag+b.imag);
}