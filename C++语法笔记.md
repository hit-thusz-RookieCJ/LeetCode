# C++语法笔记

## 函数篇

- sort函数也可以对字符串进行排序（字典序）,一般用法：sort(a.begin(), a.end())
- copy函数可以用来快速复制：*copy(names.begin(), names.end(), table[0].begin() + 1);*
- to_string()可以：int -> string
- stoi()可以：string -> int
- max_element()：int maxVal = *max_element(deliciousness.begin(), deliciousness.end());
- upper_bound()：返回第一个大于x的数的地址，auto i = upper_bound(pairs.begin(), pairs.end(), x);（具体可见q981）





## std库篇

- 全引用：

  *\#include <bits/stdc++.h>*

  *using namespace std;*

- **unordered_set**：insert()插入集合中、

- **vector<v_type>** ：push_back()放到表后、emplace_back()直接构造某对象放到表后（如pair，具体可见q981）

- unordered_map<v_type, int>中没有的会一律初始化为0。

- **for(auto a:b)**用法：

  for(auto a:b)中b为一个容器，效果是利用a遍历并获得b容器中的每一个值，但是a无法影响到b容器中的元素。

  for(auto &a:b)中加了引用符号，可以对容器中的内容进行赋值，即可通过对a赋值来做到容器b的内容填充。

- 



