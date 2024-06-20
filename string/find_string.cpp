#include <iomanip>
#include <iostream>
#include <string>
 
void print(int id, std::string::size_type n, std::string const& s)
{
    std::cout << id << ") ";
    if (std::string::npos == n)
        std::cout << "没有找到！n == npos\n";
    else
        std::cout << "在位置 n = " << n << " 找到，substr(" << n << ") = "
                  << std::quoted(s.substr(n)) << '\n';
}
 
int main()
{
    std::string::size_type n;
    std::string const s = "This is a string";  /*
                             ^  ^  ^
                             1  2  3           */
 
    // 从首个位置开始搜索
    n = s.find("is");
    print(1, n, s);
 
    // 从位置 5 开始搜索
    n = s.find("is", 5);
    print(2, n, s);
 
    // 寻找单个字符
    n = s.find('a');
    print(3, n, s);
 
    // 寻找单个字符
    n = s.find('q');
    print(4, n, s);
}