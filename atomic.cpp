#include <atomic>
#include <iostream>

/*
Before C++17:
std::atomic<int> n = 6; cannot be compiled because the copy&move
constructor&assigment of std::atomic are deleted.

Since C++17:
Allows for compiling because of guaranteed copy elision.
Even though the syntax after expansion seems to suggest a copy construction, the
C++17 standard guarantees that no copy or move operation will occur in this
situation. Instead, the std::atomic<int> object n will be directly constructed
with the value 6, without creating any temporary. This is an application of
"guaranteed copy elision."
In other words, the generated code is equivalent to: std::atomic<int> n(6);
*/

int main() {
    // cppinsights: std::atomic<int> n = std::atomic<int>(6);
    std::atomic<int> n = 6;
}
