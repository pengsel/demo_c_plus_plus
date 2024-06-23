#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v)
{
    s.put('{');
    for (int i = 0; i < v.size(); ++i) {
        s << v[i];
        if (i != v.size() - 1) {
            s << ", ";
        }
    }
    return s << "}\n";
}
 
void create_vector()
{
    // C++11 初始化式列表语法：
    std::vector<std::string> words1{"the", "frogurt", "is", "also", "cursed"};
    std::cout << "1: " << words1;
 
    // words2 == words1
    std::vector<std::string> words2(words1.begin(), words1.end());
    std::cout << "2: " << words2;
 
    // words3 == words1
    std::vector<std::string> words3(words1);
    std::cout << "3: " << words3;
 
    // words4 是 {"Mo", "Mo", "Mo", "Mo", "Mo"}
    std::vector<std::string> words4(5, "Mo");
    std::cout << "4: " << words4;
 
    auto const rg = {"cat", "cow", "crow"};
#ifdef __cpp_lib_containers_ranges
    std::vector<std::string> words5(std::from_range, rg); // 重载 (11)
#else
    std::vector<std::string> words5(rg.begin(), rg.end()); // 重载 (5)
#endif
    std::cout << "5: " << words5;
}

void iterator() {
    std::vector<int> nums{1, 2, 4, 8, 16};
    std::vector<std::string> fruits{"orange", "apple", "raspberry"};
    std::vector<char> empty;
 
    // 打印 vector。
    std::for_each(nums.begin(), nums.end(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';
 
    // 求和 vector nums 中的所有整数（若存在），仅打印结果。
    std::cout << "求和 nums: "
              << std::accumulate(nums.begin(), nums.end(), 0) << '\n';
 
    // 打印 vector fruits 中的第一个水果，不检查是否有一个。
    if (!fruits.empty())
        std::cout << "第一个水果: " << *fruits.begin() << '\n';
 
    if (empty.begin() == empty.end())
        std::cout << "vector 'empty' 确实是空的。\n";
}

void print(auto rem, const std::vector<int>& c)
{
    for (std::cout << rem; const int el : c)
        std::cout << el << ' ';
    std::cout << '\n';    
}
 
void resize() {
    std::vector<int> c = {1, 2, 3};
    print("vector 持有：", c);
 
    c.resize(5);
    print("在增加大小到 5 之后：", c);
 
    c.resize(2);
    print("在减少大小到 2 之后：", c);
 
    c.resize(6, 4);
    print("在增加大小到 6 之后（初始化式 = 4）：", c);
}

int f(int a) {
    
}

typedef int(*Func)(int a);
int main() {
    create_vector();
    iterator();
    resize();
    Func fff = f;
}