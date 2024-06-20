#include <string>
#include <iostream>
#include <regex>
 
void replace_one() {
    std::string str  = "C++ primer 4ths";
    std::string subStr = "primer";
    std::string newStr = "book";
    std::cout << "Old str:" << str << '\n';
    // 下面方法如果前后字符不同，会出现只替换一部分的情况
    // std::string replacedStr = str.replace(str.find(subStr), newStr.length(), newStr);
    size_t pos = str.find(subStr);
    std::string replacedStr = str.erase(pos, subStr.length()).insert(pos, newStr);
    std::cout << "New str:" << replacedStr << '\n';
}

void replace_all() {
    std::string str  = "C++ primer primer 4ths";
    std::string subStr = "primer";
    std::string newStr = "book";
    std::cout << "Old str:" << str << '\n';
    // 下面方法如果前后字符不同，会出现只替换一部分的情况
    // std::string replacedStr = str.replace(str.find(subStr), newStr.length(), newStr);
    size_t pos = 0;
    while ((pos = str.find(subStr)) != std::string::npos) {
        str.erase(pos, subStr.length()).insert(pos, newStr);
    }
    std::cout << "New str:" << str << '\n';
}

void replace_all_by_regex() {
    std::string str  = "C++ primer primer 4ths";
    std::string subStr = "primer";
    std::string newStr = "book";
    std::cout << "Old str:" << str << '\n';
    std::string replacedStr = std::regex_replace(str, std::regex(subStr), newStr);
    std::cout << "New str:" << str << '\n';
    std::cout << "New replacedStr:" << replacedStr << '\n';
}

int main()
{
    const std::string str = "C++ primer 4ths";
    const std::string replace = "is a books";
 
    // 从位置 11 开始删除 4 个字符并添加 "5th"
    std::string replace_str1 = str;
    replace_str1.replace(11, 4, "5th");
    std::cout << replace_str1 << '\n';
 
    // 同上
    std::string replace_str2 = str;
    replace_str2.replace(replace_str2.end() - 4,replace_str2.end(),"6th");
    std::cout << replace_str2 << '\n';
 
    // 从位置 11 开始删除 4 个字符并添加 "is a book"
    std::string replace_str3 = str;
    replace_str3.replace(11, 4, replace, 0, replace.size() - 1);
    std::cout << replace_str3 << '\n';

    // 替换单个字符串
    replace_one();

    // 替换所有字符串
    replace_all();

    // 正则替换所有字符串
    replace_all_by_regex();
}