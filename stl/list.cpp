#include <list>
#include <iostream>

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
    for (const int i : list)
        ostr << ' ' << i;
    return ostr;
}
 
void sort()
{
    std::list<int> list{8, 7, 5, 9, 0, 1, 3, 2, 6, 4};
    std::cout << "初始：" << list << '\n';
 
    list.sort();
    std::cout << "升序：" << list << '\n';
 
    list.sort(std::greater<int>());
    std::cout << "降序：" << list << '\n';

    list.sort([](int a, int b) { return a < b; });
    std::cout << "升序：" << list << '\n';

}

 
int main()
{
    std::list<int> l = {1, 100, 2, 3, 10, 1, 11, -1, 12};
    size_t tmp = l.size();
    l.remove(1);
    std::cout << " 移除了 " << (tmp - l.size()) << " 个等于 1 的元素\n";
 
    tmp = l.size();
    l.remove_if([](int n){ return n > 10; });

    std::cout << " 移除了 " << tmp - l.size() << " 个大于 10 的元素\n";
 
    std::cout << "最后，链表包含：";
    for (int n : l)
        std::cout << n << ' ';
    std::cout << '\n';

    sort();
}