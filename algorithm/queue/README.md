# queue

DOING: using ring buffer to simulate a queue

ring buffer应该有的接口

1. `bool isFull()`, push前先检查, 如果满了就不能push, 什么也不干.
2. `bool isEmpty()`, pop前先检查, 如果空了就不能pop, 什么也不干.
3. `void push(T value)` push对象, 满了什么也不干.
4. `void pop()`, 弹出第一个对象(对POD对象来说不清理), 如果空的话什么也不干.
5. `T front()`, 获取第一个对象, 空的话直接解引用head地址.