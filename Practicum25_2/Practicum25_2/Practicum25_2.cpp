#include <iostream>
#include<cmath>
#include <concepts>
struct ComplexNumber {
    double real, img;
};

void print(const ComplexNumber & w) {
    std::cout << w.real << " + " << w.img << "i" << std::endl;
}
ComplexNumber read()
{
    ComplexNumber w;
    std::cin >> w.real >> w.img;
    return w;
}
void readInto(ComplexNumber &w) {
    std::cin >> w.real >> w.img;
}
ComplexNumber add(ComplexNumber &w1, ComplexNumber &w2)
{
    ComplexNumber sum;
    sum.real = w1.real + w2.real;
    sum.img = w1.img + w2.img;
    return sum;
}
ComplexNumber diff(ComplexNumber& w1, ComplexNumber& w2)
{
    ComplexNumber diff;
    diff.real = w1.real - w2.real;
    diff.img = w1.img - w2.img;
    return diff;
}
ComplexNumber prod(ComplexNumber& w1, ComplexNumber& w2)
{
    ComplexNumber res;
    res.real = w1.real*w2.real - w2.img*w1.img;
    res.img = w1.real*w2.img + w2.real*w1.img;
    return res;
}
ComplexNumber avg(ComplexNumber* arr, size_t n)
{
    ComplexNumber res = { 0,0 };
    for (int i = 0; i < n; i++)
    {
        res.real += arr[i].real;
        res.img += arr[i].img;
    }
    res.real /= n;
    res.img /= n;
    return res;
}
double mod(ComplexNumber w) {
    return sqrt(w.real * w.real + w.img * w.img);
}
void sort(ComplexNumber* arr, size_t n) {
    double* mods = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        mods[i] = mod(arr[i]);
    }
    for (size_t i=0;i<n;i++) {
        for (size_t y=i+1;y<n;y++) {
            if (mods[i] > mods[y])
            {
                ComplexNumber tmp = arr[i];
                arr[i] = arr[y];
                arr[y] = tmp;
                std::swap(mods[i], mods[y]);
            }
        }
    }
    delete[] mods;
}
int main()
{
    ComplexNumber arr[5];
    for (size_t i = 0; i < 5; i++)
    {
        readInto(arr[i]);
    }
    print(avg(arr,5));
    
}