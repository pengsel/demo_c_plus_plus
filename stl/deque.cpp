#include <deque>
#include <string>
#include <iostream>
 
template<typename T>
std::ostream& operator<<(std::ostream& s, const std::deque<T>& v)
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v)
    {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}
 
void create_deque() 
{
    // C++11 初始化器列表语法：
    std::deque<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
    std::cout << "words1: " << words1 << '\n';
 
    // words2 == words1
    std::deque<std::string> words2(words1.begin(), words1.end());
    std::cout << "words2: " << words2 << '\n';
 
    // words3 == words1
    std::deque<std::string> words3(words1);
    std::cout << "words3: " << words3 << '\n';
 
    // words4 是 {"Mo", "Mo", "Mo", "Mo", "Mo"}
    std::deque<std::string> words4(5, "Mo");
    std::cout << "words4: " << words4 << '\n';
}

template<class Os, class Co>
Os& operator<<(Os& os, const Co& co)
{
    os << "{";
    for (auto const& i : co)
        os << ' ' << i;
    return os << " } ";
}
 
void swap()
{
    // 将内容与 other 的交换。不在单独的元素上调用任何移动、复制或交换操作。 
    // 与 std::vector 相反，deque 的元素不是相接存储的
    std::deque<int> a1{1, 2, 3}, a2{4, 5};
 
    auto it1 = std::next(a1.begin());
    auto it2 = std::next(a2.begin());
 
    int& ref1 = a1.front();
    int& ref2 = a2.front();
    ref1 = 110;
 
    std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
    a1.swap(a2);
    std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
 
    // 注意交换后迭代器与引用保持与原来的元素关联，
    // 例如尽管 'a1' 中值为 2 的元素被移动到 'a2' 中，
    // 原来指向它的 it1 仍指向同一元素。
}

int main() {
    create_deque();
    swap();
}