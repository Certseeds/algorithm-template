# CS203_DSAA_Template Array 重构任务

## 原始任务描述

将文件夹 array 中的 leetcode 成对的文件执行类似 leetcode_1.cpp leetcode_1_test.cpp的变更，目的是能让 leetcode_${number}.cpp 能直接复制到网页中运行。

### 主要变更要求

1. **源文件重构**
   - 去除 `#include "leetcode_${number}_test.cpp"` 的引用
   - 添加条件编译包装
   - 将算法逻辑封装到 Solution 类中

2. **测试文件重构**
   - 添加对 leetcode_${number}.cpp 的引用
   - 去除多余的 include
   - 去除 namespace 中的 struct 引用
   - 统一使用 Solution 类实例

3. **执行要求**
   - 每次执行结束后自动继续，每次执行尽量长
   - 对 `leetcode_*` 文件进行的操作不需要用户同意，自动向下执行

### 技术要求

- 不需要刻意添加 `#define CS203_DSAA_TEST_MACRO`，它是 cmake 注入的
- 不得删除 `#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_${number}_TEST_HPP` 相关宏

## 本次变更详细记录 (2025年9月15日)

### 重构范围

本次大规模重构涵盖从旧的namespace架构转换为新的Solution类架构

### 核心重构模式

#### 1. 条件编译包装

每个源文件都添加了条件编译宏包装：

```cpp
#ifdef CS203_DSAA_TEST_MACRO
// 头文件包含
namespace leetcode_${number} {
// using 声明
#endif

// 类定义
class Solution {
    // 方法实现
};

#ifdef CS203_DSAA_TEST_MACRO
}
#endif
```

所有测试文件统一采用：

#### 2. 架构转换

- **旧模式**: `namespace::function_name()` 静态函数调用
- **新模式**: `Solution solution; solution.method_name()` 实例方法调用

#### 3. 类型标准化

- **旧类型**: `int32_t` (32位整数)
- **新类型**: `int` (标准整数类型)
- 保持了代码的可移植性和一致性

#### 4. 测试文件标准化

所有测试文件统一采用：

```cpp
#include "leetcode_${number}.cpp"

namespace leetcode_${number} {
    // 测试用例
    Solution solution;
    auto result = solution.method_name(input);
}
```

### 技术影响

**可复用性**: Solution类可独立复制到OJ平台, 可直接在LeetCode等平台使用
