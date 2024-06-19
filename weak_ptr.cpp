#include <iostream>
#include <memory>
 
std::weak_ptr<int> gw;
 
void observe()
{
    std::cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()) { // 使用之前必须复制到 shared_ptr
	std::cout << *spt << "\n";
     std::cout << "after lock use_count == " << gw.use_count() << ": ";
    }
    else {
        std::cout << "gw is expired\n";
    }
}
 
int main()
{
    {
        auto sp = std::make_shared<int>(42);
	gw = sp;
 
	observe();
    }
 
    observe();
}