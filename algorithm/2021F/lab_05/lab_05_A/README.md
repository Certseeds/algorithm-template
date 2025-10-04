# lab_05_A — Canteen Queue

## Description

It's lunch time now!

Students are queuing in a queue and each student has one specific kind of favourite food

The canteen offers different kinds of food in a stack

If the food on the top of the stack matches one's favourite food in his turn, he will take it and leave the queue.

Otherwise, he will go back to the end of the line to queue up again.

The canteen will open for $T$ time slots.

LowbieH now gives you the event of each time slot.

There are 3 types of events in total:

+ Event 1 : NewFood NameOfNewFood (Push new food into the stack.)
+ Event 2 : NewComer NameOfFavouriteFood (A new student will join the queue with his favourite food.)
+ Event 3 : TakeFood (The first student in the queue will make his choice. If the food stack is empty, he will do nothing. )

After $T$ time slots, the canteen will stop providing new food. The remaining students in the queue will take the food or queue again successively until the food stack is empty or nobody could get his favourite food . After that the canteen will close. Can you tell LowbieH that how many students will be left to starve when the canteen closes?

## Input

The first line contains an integer $T(0 \leq T \leq 10000)$. The following $T$ lines are the events that mentioned in the description above. The input is guaranteed to be valid.

## Output

If everyone had taken his favorite food, you should print "Qi Fei!"(without quotation marks). Otherwise, please tell LowbieH the number of the remaining hungry students.

## Sample Input

```log
6
NewComer SpicyHotPot
NewComer BarbecuedPorkCombo
NewFood BarbecuedPorkCombo
TakeFood
NewFood SpicyHotPot
NewFood BarbecuedPorkCombo
```

## Sample Output

```log
Qi Fei!
```

## 解题思路

### 问题分析

本题模拟了一个食堂打饭的场景, 涉及两种数据结构:
1. **学生队列 (Queue)**: 学生排队, 符合先进先出 (FIFO) 的特性.
2. **食物栈 (Stack)**: 食堂提供的食物, 符合后进先出 (LIFO) 的特性.

核心逻辑是:
+ 队首的学生查看栈顶的食物.
+ 如果食物是该学生喜欢的, 学生取走食物并离开队列.
+ 如果不是, 学生回到队尾重新排队.
+ 这个过程会持续进行, 直到食物栈为空, 或者队列中的所有学生都无法在当前栈顶找到自己喜欢的食物.

### 数据结构选择

根据题目描述, `main.cpp` 的实现直接使用了 C++ STL 中对应的标准容器:
+ `std::queue<size_t> comer`: 用于模拟学生队列.
+ `std::stack<size_t> way`: 用于模拟食物栈.

为了处理食物名称这种字符串类型, 代码采用 `std::hash<string>` 将字符串转换为 `size_t` 类型的哈希值进行存储和比较. 这样做可以提高比较效率, 避免了在循环中进行大量的字符串比较.

### 算法流程

1. **初始化**:
    + 读取事件数量 `T`.
    + 创建 `stack<size_t> way` 和 `queue<size_t> comer`.
    + 使用 `std::hash<string>` 预计算 "NewFood", "NewComer", "TakeFood" 等命令的哈希值, 以便快速匹配命令.

2. **处理 T 个时间槽的事件**:
    + 循环 `T` 次, 每次读取一个事件.
    + **NewFood**: 将新食物的名称哈希后压入 `way` 栈.
    + **NewComer**: 将新学生的喜爱食物名称哈希后加入 `comer` 队列.
    + **TakeFood**:
        + 检查食物栈 `way` 是否为空. 如果为空, 则什么都不做.
        + 如果食物栈不为空, 取出队首学生 `comer.front()` 和栈顶食物 `way.top()`.
        + 比较两者. 如果匹配, 则学生出队, 食物出栈.
        + 如果不匹配, 学生出队后, 再重新入队, 回到队尾.

3. **处理剩余学生**:
    + 在 `T` 个时间槽结束后, 进入一个 `while` 循环, 处理仍在队列中的学生.
    + 这个循环的终止条件是: 食物栈 `way` 为空, 或者学生队列 `comer` 为空.
    + 还有一个重要的终止条件: **死锁检测**. 如果队列中的所有学生都轮了一遍, 却没有一个人能取走食物, 那么就不会再有变化了, 循环必须终止.
    + 代码通过一个计数器 `continue_time` 来实现死锁检测. `continue_time` 记录了连续多少个学生无法取走食物. 如果 `continue_time` 等于当前队列的长度 `comer_size`, 就意味着发生了死锁, 循环中断.
    + 如果一个学生成功取走食物, `continue_time` 会被重置为 0.

4. **输出结果**:
    + 统计总学生数和成功取走食物的学生数.
    + 如果两者相等, 说明所有学生都吃到了饭, 输出 "Qi Fei!".
    + 否则, 输出两者之差, 即挨饿的学生数量.

### 结论

该实现清晰地模拟了题目所描述的整个过程. 通过使用标准库中的 `queue` 和 `stack`, 代码结构简单明了. 关键点在于第二阶段处理剩余学生时的 **死锁判断**, 这是确保程序在无解情况下能够正常终止的核心.
