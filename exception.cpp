#include <exception>
#include <iostream>

struct MyException : std::exception {
    std::string msg;
    MyException(const std::string &msg_) : msg(msg_) {
        std::cerr << "MyException ctor\n";
    }
    ~MyException() noexcept override { std::cerr << "~MyException dector\n"; }
    const char *what() const noexcept override { return msg.c_str(); }
};

void func() {
    throw MyException("Exception in func()");
}

int main() {
    try {
        func();
    } catch (const MyException &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}