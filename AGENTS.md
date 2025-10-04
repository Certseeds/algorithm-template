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

copilot-拉取: 按照cid, 拉取题目信息

copilot-获取题面: 使用cid, pid(按题目序号从0递增)按照题目信息(problem_id置为0), 写入子目录中, 各个题目的README中

copilot-优化README: 在README中, 根据句点`.`, 每一句话一个段落, 在不改变原始文字的情况下, 将长段落分为短段落

copilot-公式优化: 将题目格式化, 将 `\\`等符号替换为 标准Latex符号`$`, 实现符号渲染正常

## 题目实现流程

copilot-检查样例: 读取 README.md 中的样例输入输出, 检测与目录内 resource 目录下的 `01.data.in`, `01.data.out`是否相同, 不相同则覆盖写

copilot-生成: 读取目录中的 README.md 题面实现到 main.cpp 中(显然目标语言是C++), 严格遵守 `代码撰写原则`中的所有规则

copilot-上传: 使用problem_id(不传入cid, pid) 生成代码后, 不需要编译, 直接调用 hustoj-mcp, 将其上传到 hustoj 中.

copilot-解释算法: 按照 README.md 结合 main.cpp 的实现, 写出算法分析到 README.md 的最后(用zh-CN)

## 代码撰写原则

1. 使用 Modern C++ 11风格
2. 尽量使用 const 不可变变量
3. 尽量使用 auto 进行类型推导
4. 尽量使用 STL 标准库内的算法
5. 使用函数进行模块化
6. 使用注释进行代码说明
7. 使用统一的代码风格: main.cpp 的 输入-处理-输出三段式风格
8. 禁止使用 `#include <bits/stdc++.h>`
9. 尽量使用 `int32`, `int64`等定长类型
10. 智能指针只使用 `shared_ptr`

### README format

+ README.md内 `Description` 应该为 `## `, Input, Output, Sample Input, Sample Output, HINT 等均改写为 `### `
+ `Sample Input` `Sample Output`内里面的输入输出, 用 ``` log ``` 包裹
+ 注意去除/替换部分非中英文的字符
+ 只进行格式整理, 不对内容进行编辑

### 文件命名规则

1. 源文件: `lab_{number}/lab_{number}_{question-number}/main.cpp`
2. 测试文件 : `lab_{number}/lab_{number}_{question-number}/test.cpp`
3. 测试资源:: `lab_{number}/lab_{number}_{question-number}/resource` 目录下

输入: `{number}.data.in`
输出: `{number}.data.out`
