#include<iostream>
#include<cstdlib>
#include<ctime>

int main() {
    srand(time(0));

    int a = rand() % 9000 + 1000;
    int b = rand() % 9000 + 1000;
    int c = rand() % 9000 + 1000;

    std::cout << "a : " << a << "\n";
    std::cout << "b : " << b << "\n";
    std::cout << "c : " << c << "\n";

    long long sum = a + b + c;
    std::cout << "sum: " << sum << "\n";

    long long sum2 = static_cast<long long>(a) + static_cast<long long>(b) + static_cast<long long>(c);
    std::cout << "sum2: " << sum2 << "\n";

    return 0;
}