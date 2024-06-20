#include <iostream>
#include <iomanip>
#include <cassert>
#include <iterator>
#include <string>
#include <cctype>
 
int main()
{
    std::cout << "1) string(); ";
    std::string s1;
    assert(s1.empty() && (s1.length() == 0) && (s1.size() == 0));
    std::cout << "s1.capacity(): " << s1.capacity() << '\n'; // 未指定
 
    std::cout << "2) string(size_type count, charT ch): ";
    std::string s2(4, '=');
    std::cout << std::quoted(s2) << '\n'; // "===="
 
    std::cout << "3) string(const string& other, size_type pos, size_type count): ";
    std::string const other3("Exemplary");
    std::string s3(other3, 0, other3.length() - 1);
    std::cout << quoted(s3) << '\n'; // "Exemplar"
 
    std::cout << "4) string(const string& other, size_type pos): ";
    std::string const other4("Mutatis Mutandis");
    std::string s4(other4, 8);
    std::cout << quoted(s4) << '\n'; // "Mutandis"，即 [8, 16)
 
    std::cout << "5) string(charT const* s, size_type count): ";
    std::string s5("C-style string", 7);
    std::cout << quoted(s5) << '\n'; // "C-style"，即 [0, 7)
 
    std::cout << "6) string(charT const* s): ";
    std::string s6("C-style\0string");
    std::cout << quoted(s6) << '\n'; // "C-style"
 
    std::cout << "7) string(InputIt first, InputIt last): ";
    char mutable_c_str[] = "another C-style string";
    std::string s7(std::begin(mutable_c_str) + 8, std::end(mutable_c_str) - 1);
    std::cout << quoted(s7) << '\n'; // "C-style string"
 
    std::cout << "8) string(string&): ";
    std::string const other8("Exemplar");
    std::string s8(other8);
    std::cout << quoted(s8) << '\n'; // "Exemplar"
 
    std::cout << "9) string(string&&): ";
    std::string s9(std::string("C++ by ") + std::string("example"));
    std::cout << quoted(s9) << '\n'; // "C++ by example"
 
    std::cout << "a) string(std::initializer_list<charT>): ";
    std::string sa({'C', '-', 's', 't', 'y', 'l', 'e'});
    std::cout << quoted(sa) << '\n'; // "C-style"
 
    // 在 C++11 前，重载决议会选择 string(InputIt first, InputIt last)
    // [其中 InputIt = int]，它会表现*如同* string(size_type count, charT ch)
    // 在 C++11 后，对整数类型参数的构造函数调用会禁用使用 InputIt 的构造函数：
    std::cout << "b) string(size_type count, charT ch) is called: ";
    std::string sb(3, std::toupper('a'));
    std::cout << quoted(sb) << '\n'; // "AAA"
 
    [[maybe_unused]]
    auto zero = [] { /* ... */ return nullptr; };
    //  std::string sc{zero()}; // C++23 前：抛出 std::logic_error
                            // C++23 后：不会编译，见重载 (12)
}