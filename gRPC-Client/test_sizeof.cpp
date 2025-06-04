#include <functional>
#include <iostream>

int main() {
    // Test różnych typów std::function
    std::function<void()> func1;
    std::function<int()> func2;
    std::function<void(int)> func3;
    std::function<int(int, double)> func4;
    std::function<void(const std::string&)> func5;
    
    std::cout << "sizeof(std::function<void()>): " << sizeof(func1) << " bytes\n";
    std::cout << "sizeof(std::function<int()>): " << sizeof(func2) << " bytes\n";
    std::cout << "sizeof(std::function<void(int)>): " << sizeof(func3) << " bytes\n";
    std::cout << "sizeof(std::function<int(int, double)>): " << sizeof(func4) << " bytes\n";
    std::cout << "sizeof(std::function<void(const std::string&)>): " << sizeof(func5) << " bytes\n";
    
    // Porównanie z innymi typami
    std::cout << "\nPorównanie z innymi typami:\n";
    std::cout << "sizeof(void*): " << sizeof(void*) << " bytes\n";
    std::cout << "sizeof(int): " << sizeof(int) << " bytes\n";
    std::cout << "sizeof(double): " << sizeof(double) << " bytes\n";
    std::cout << "sizeof(std::string): " << sizeof(std::string) << " bytes\n";
    
    // Test z lambda
    auto lambda = []() { return 42; };
    std::function<int()> func_lambda = lambda;
    std::cout << "\nsizeof(lambda): " << sizeof(lambda) << " bytes\n";
    std::cout << "sizeof(std::function<int()> with lambda): " << sizeof(func_lambda) << " bytes\n";
    
    return 0;
}
