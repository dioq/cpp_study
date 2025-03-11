# C++ `std::map` 容器介绍

## 概述

`std::map` 是 C++ 标准库提供的一种关联容器，用于存储键值对（key-value pairs）。每个元素都有一个唯一的键，通过键可以快速查找到对应的值。`std::map` 使用红黑树（Red-Black Tree）实现，因此所有的操作（插入、删除、查找）都具有对数时间复杂度。

## 头文件

使用 `std::map` 需要包含头文件：

```cpp
#include <map>
```

## 主要特点

- **有序性**：`std::map` 内的元素按照键的顺序自动排序。
- **唯一性**：每个键在 `std::map` 中是唯一的，不能有重复的键。
- **键值对**：每个元素都是一个键值对，键用于查找，值是与键关联的数据。
- **自动平衡**：`std::map` 使用平衡二叉树（红黑树）实现，因此插入、删除和查找操作的时间复杂度都是 O(log n)。

## 常用操作

## 声明和初始化

```cpp
std::map<int, std::string> myMap;
```

## 插入元素

使用 `insert` 函数或重载的 `operator[]` 插入元素：

```cpp
myMap.insert(std::make_pair(1, "One"));
myMap[2] = "Two";
```

## 访问元素

使用键来访问对应的值：

```cpp
std::string value = myMap[1]; // 返回 "One"
```

## 查找元素

使用 `find` 函数查找元素，返回一个迭代器：

```cpp
auto it = myMap.find(1);
if (it != myMap.end()) {
    std::cout << "Key 1 found with value: " << it->second << std::endl;
} else {
    std::cout << "Key 1 not found" << std::endl;
}
```

## 删除元素

使用 `erase` 函数删除元素：

```cpp
myMap.erase(1); // 删除键为 1 的元素
```

## 检查是否为空

使用 `empty` 函数检查 `std::map` 是否为空：

```cpp
if (myMap.empty()) {
    std::cout << "The map is empty." << std::endl;
} else {
    std::cout << "The map is not empty." << std::endl;
}
```

## 获取大小

使用 `size` 函数获取 `std::map` 中元素的数量：

```cpp
std::cout << "Size of the map: " << myMap.size() << std::endl;
```
