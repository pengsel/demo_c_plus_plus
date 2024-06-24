#include <cmath>
#include <iostream>
#include <set>
#include <string>
 
struct Point { double x, y; };
 
struct PointCmp
{
    bool operator()(const Point& lhs, const Point& rhs) const
    {
        return std::hypot(lhs.x, lhs.y) < std::hypot(rhs.x, rhs.y);
    }
};
 
int main()
{
    // (1) 默认构造函数
    std::set<std::string> a;
    a.insert("cat");
    a.insert("dog");
    a.insert("horse");
    for (auto& str : a)
        std::cout << str << ' ';
    std::cout << '\n';
 
    // (4) 范围构造函数
    std::set<std::string> b(a.find("dog"), a.end());
    for (auto& str : b)
        std::cout << str << ' ';
    std::cout << '\n';
 
    // (6) 复制构造函数
    std::set<std::string> c(a);
    c.insert("another horse");
    for (auto& str : c)
        std::cout << str << ' ';
    std::cout << '\n';
 
    // (8) 移动构造函数
    std::set<std::string> d(std::move(a));
    for (auto& str : d)
        std::cout << str << ' ';
    std::cout << '\n';
    std::cout << "moved-from set is ";
    for (auto& str : a)
        std::cout << str << ' ';
    std::cout << '\n';
 
    // (10) 初始化器列表构造函数
    std::set<std::string> e{"one", "two", "three", "five", "eight"};
    for (auto& str : e)
        std::cout << str << ' ';
    std::cout << '\n';
 
    // 自定义比较器
    std::set<Point, PointCmp> z = {{2, 5}, {3, 4}, {1, 1}};
    z.insert({1, -1}); // 插入会因为 (1,-1) 和 (1,1) 的大小相同而失败
    for (auto& p : z)
        std::cout << '(' << p.x << ',' << p.y << ") ";
    std::cout << '\n';
}