# 2021fall CS203/CS217 llm implement workflow

## details

+ 以使用 `"` 为荣, 以使用 `“`, `”` 为耻
+ 以使用 `'` 为荣, 以使用 `‘`, `’` 为耻
+ 以使用 `,` 为荣, 以使用 `，` 为耻
+ 以使用 `.` 为荣, 以使用 `。` 为耻
+ 以使用 `:` 为荣, 以使用 `：` 为耻
+ 以使用 `;` 为荣, 以使用 `；` 为耻
+ 以使用 `!` 为荣, 以使用 `！` 为耻
+ 以使用 `?` 为荣, 以使用 `？` 为耻

即不使用任何全角符号, 将其替换为对应的英文标点

## 本地拉取流程

人工干预: contest目录中实现README, 获取cid, 题目信息

copilot 实现: 按照cid, 拉取题目信息

copilot 实现: 按照题目信息, 写入子目录中, 各个题目的README中

copilot 实现: 在README中, 根据句点`.`以及语义, 在不改变原始文字的情况下, 将长段落分为短段落, 方便观察

copilot 实现: 将题目格式化, 将 `\\`等符号替换为 标准Latex符号`$`, 实现符号渲染正常

## 题目实现流程

copilot 实现: 读取目录中的 README.md 题面实现

copilot 实现: 读取 README.md 中的样例输入输出, 检测与目录内 resource 目录下的 `01.data.in`, `01.data.out`是否相同, 不相同则覆盖写

copilot 实现: 生成代码后, 不需要编译, 直接调用 hustoj-mcp, 将其上传到 hustoj 中.

copilot 实现: 按照 README.md 结合 main.cpp 的实现, 写出分析到 README.md 的最后

## 代码撰写原则

1. 使用 Modern C++ 11风格
2. 尽量使用 const 不可变变量
3. 尽量使用 auto 进行类型推导
4. 使用 STL 标准库
5. 使用函数进行模块化
6. 使用注释进行代码说明
7. 使用统一的代码风格
8. 使用输入-处理-输出三段式风格
9. 禁止使用 `#include <bits/stdc++.h>`
10. 保留原有main.cpp结构
11. 尽量使用 `int32`, `int64`等定长类型, 不使用`long` `long long`等类型

### 文件命名规则

1. 源文件: `lab_{number}/lab_{number}_{question-number}/main.cpp`
2. 测试文件 : `lab_{number}/lab_{number}_{question-number}/test.cpp`
3. 测试资源:: `lab_{number}/lab_{number}_{question-number}/resource` 目录下

输入: `{number}.data.in`
输出: `{number}.data.out`
