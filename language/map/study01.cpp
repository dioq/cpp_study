#include <iostream>
#include <map>

int main()
{
    std::map<std::string, std::string> myMap;

    // 插入元素
    myMap["key_01"] = "value_01";
    myMap["key_02"] = "value_02";
    myMap["key_03"] = "value_03";

    // 访问元素
    std::cout << "Key key_01 has value: " << myMap["key_01"] << std::endl;

    // 查找元素
    auto it = myMap.find("key_02");
    if (it != myMap.end())
    {
        std::cout << "Key key_02 found with value: " << it->second << std::endl;
    }
    else
    {
        std::cout << "Key key_02 not found" << std::endl;
    }

    // 删除元素
    myMap.erase("key_03");

    // 检查是否为空
    if (myMap.empty())
    {
        std::cout << "The map is empty." << std::endl;
    }
    else
    {
        std::cout << "The map is not empty." << std::endl;
    }

    // 获取大小
    std::cout << "Size of the map: " << myMap.size() << std::endl;

    return 0;
}