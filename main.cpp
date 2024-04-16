#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
concept ComplexConcept = requires(T a) {
    { a.hash() } -> std::convertible_to<long>;
    { a.toString() } -> std::same_as<std::string>;
        requires !std::has_virtual_destructor_v<T>;
};

class MyClass {
public:
    long hash() const {
        return 42;
    }

    std::string toString() const {
        return "MyClass";
    }
};

template <ComplexConcept T>
void process(T& obj) {
    std::cout << obj.toString() << " has hash: " << obj.hash() << std::endl;
}

int main() {
    MyClass obj;
    process(obj);
    return 0;
}


