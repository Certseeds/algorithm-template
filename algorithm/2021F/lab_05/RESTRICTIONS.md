# Lab 05 - Data Structure Restrictions

## Overview

Lab 05 introduces **Stack**, **Queue**, and **Deque** data structures. These are fundamental linear data structures with specific access patterns (LIFO, FIFO, and both ends respectively).

## Allowed Data Structures

### Everything from Lab 04, plus:

### New Linear Structures
- **`std::stack`**: Last-In-First-Out (LIFO) structure
  - `push()`, `pop()`, `top()`, `empty()`, `size()`
- **`std::queue`**: First-In-First-Out (FIFO) structure
  - `push()`, `pop()`, `front()`, `back()`, `empty()`, `size()`
- **`std::deque`**: Double-ended queue
  - `push_front()`, `push_back()`, `pop_front()`, `pop_back()`
  - Random access like vector
- **Custom implementations**: Can implement stack/queue using arrays or linked lists

## Allowed Algorithms

### New in Lab 05

1. **Stack Applications**
   - Parentheses/bracket matching
   - Expression evaluation (infix, postfix, prefix)
   - Function call simulation (recursion simulation)
   - Undo/redo operations
   - Depth-First Search (DFS)
   - Monotonic stack problems

2. **Queue Applications**
   - Breadth-First Search (BFS)
   - Level-order traversal
   - Sliding window problems (with deque)
   - Task scheduling
   - Buffer management

3. **Deque Applications**
   - Sliding window maximum/minimum
   - Palindrome checking
   - Both stack and queue operations

## Restrictions

### Still NOT Allowed
- Priority queue / heap (`std::priority_queue`)
- Trees (binary trees, BST, etc.)
- Graphs (as explicit data structures)
- Advanced tree/graph algorithms

### New Capabilities
- **Stack, Queue, Deque**: Full access to these structures
- **BFS/DFS basics**: Simple traversal patterns
- **Monotonic stack/deque**: Advanced stack/deque techniques

## Example Problems

### Problem Types Suitable for Lab 05

### A. Stack Problems

#### 1. **Parentheses Matching** (lab_05_A)
```cpp
bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> pairs = {
        {')', '('}, {']', '['}, {'}', '{'}
    };
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else {
            if (stk.empty() || stk.top() != pairs[c]) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}
```

#### 2. **Postfix Expression Evaluation** (lab_05_B)
```cpp
int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            if (token == "+") stk.push(a + b);
            else if (token == "-") stk.push(a - b);
            else if (token == "*") stk.push(a * b);
            else stk.push(a / b);
        } else {
            stk.push(stoi(token));
        }
    }
    return stk.top();
}
```

#### 3. **Next Greater Element** (lab_05_C) - Monotonic Stack
```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> stk;  // Store indices
    
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && nums[stk.top()] < nums[i]) {
            result[stk.top()] = nums[i];
            stk.pop();
        }
        stk.push(i);
    }
    return result;
}
```

#### 4. **Largest Rectangle in Histogram** (lab_05_D)
```cpp
int largestRectangle(vector<int>& heights) {
    stack<int> stk;
    int maxArea = 0;
    heights.push_back(0);  // Sentinel
    
    for (int i = 0; i < heights.size(); i++) {
        while (!stk.empty() && heights[stk.top()] > heights[i]) {
            int h = heights[stk.top()];
            stk.pop();
            int w = stk.empty() ? i : i - stk.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        stk.push(i);
    }
    return maxArea;
}
```

### B. Queue Problems

#### 1. **BFS Traversal** (lab_05_E)
```cpp
void bfs(int start, vector<vector<int>>& graph) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        // Process node
        cout << node << " ";
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

#### 2. **Level Order Traversal** (lab_05_F)
```cpp
// For a tree structure (when trees are introduced)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}
```

#### 3. **Task Scheduling** (lab_05_G)
```cpp
// Process tasks in FIFO order
void processTasks(vector<Task>& tasks) {
    queue<Task> taskQueue;
    
    for (const Task& task : tasks) {
        taskQueue.push(task);
    }
    
    while (!taskQueue.empty()) {
        Task current = taskQueue.front();
        taskQueue.pop();
        
        // Process task
        cout << "Processing: " << current.name << endl;
    }
}
```

### C. Deque Problems

#### 1. **Sliding Window Maximum** (lab_05_H)
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Store indices
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
        // Remove elements outside window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Maintain decreasing order
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Add to result after first window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}
```

#### 2. **Palindrome Check** (simple use)
```cpp
bool isPalindrome(string s) {
    deque<char> dq;
    
    // Add only alphanumeric characters
    for (char c : s) {
        if (isalnum(c)) {
            dq.push_back(tolower(c));
        }
    }
    
    while (dq.size() > 1) {
        if (dq.front() != dq.back()) {
            return false;
        }
        dq.pop_front();
        dq.pop_back();
    }
    return true;
}
```

## Solution Pattern

```cpp
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// Stack example
void stackExample() {
    stack<int> stk;
    
    // Push elements
    stk.push(1);
    stk.push(2);
    stk.push(3);
    
    // Access and pop
    while (!stk.empty()) {
        cout << stk.top() << " ";  // 3 2 1 (LIFO)
        stk.pop();
    }
}

// Queue example
void queueExample() {
    queue<int> q;
    
    // Enqueue elements
    q.push(1);
    q.push(2);
    q.push(3);
    
    // Dequeue
    while (!q.empty()) {
        cout << q.front() << " ";  // 1 2 3 (FIFO)
        q.pop();
    }
}

// Deque example
void dequeExample() {
    deque<int> dq;
    
    // Add to both ends
    dq.push_back(1);
    dq.push_front(0);
    dq.push_back(2);
    
    // Access both ends
    cout << dq.front() << " " << dq.back() << endl;  // 0 2
    
    // Random access (like vector)
    cout << dq[1] << endl;  // 1
}

int main() {
    stackExample();
    queueExample();
    dequeExample();
    return 0;
}
```

## Learning Objectives

Students at this level should learn:
- **Stack**: LIFO structure, when to use it
- **Queue**: FIFO structure, BFS applications
- **Deque**: Double-ended queue, sliding window
- **Monotonic stack**: Advanced stack technique
- **BFS vs DFS**: Queue for BFS, stack (or recursion) for DFS
- **Expression evaluation**: Using stack
- **Pattern recognition**: When a problem needs stack/queue/deque

## Key Techniques

### Stack Techniques
1. **Matching/balancing**: Parentheses, brackets
2. **Expression evaluation**: Postfix, infix conversion
3. **Monotonic stack**: Next greater/smaller element
4. **DFS simulation**: Replace recursion with stack
5. **Undo operations**: State history

### Queue Techniques
1. **BFS traversal**: Level-by-level processing
2. **Task scheduling**: Process in order
3. **Buffer**: Temporary storage
4. **Level order**: Process by levels

### Deque Techniques
1. **Sliding window**: Maintain min/max in window
2. **Both ends access**: Need front and back operations
3. **Palindrome**: Check from both ends
4. **Dynamic array**: When need both vector and queue features

## Complexity Analysis

| Operation | Stack | Queue | Deque |
|-----------|-------|-------|-------|
| push/enqueue | O(1) | O(1) | O(1) both ends |
| pop/dequeue | O(1) | O(1) | O(1) both ends |
| top/front | O(1) | O(1) | O(1) both ends |
| Random access | ❌ | ❌ | ✅ O(1) |
| Size | O(1) | O(1) | O(1) |

## Common Patterns

### Pattern 1: Monotonic Stack
```cpp
// Find next greater element for each position
stack<int> stk;  // Decreasing stack
for (int i = 0; i < n; i++) {
    while (!stk.empty() && nums[stk.top()] < nums[i]) {
        result[stk.top()] = nums[i];
        stk.pop();
    }
    stk.push(i);
}
```

### Pattern 2: BFS Template
```cpp
queue<Node> q;
q.push(start);
visited[start] = true;

while (!q.empty()) {
    Node curr = q.front();
    q.pop();
    
    // Process current node
    
    // Add unvisited neighbors
    for (Node neighbor : curr.neighbors) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
}
```

### Pattern 3: Sliding Window with Deque
```cpp
deque<int> dq;
for (int i = 0; i < n; i++) {
    // Remove outside window
    if (!dq.empty() && dq.front() <= i - k) {
        dq.pop_front();
    }
    
    // Maintain monotonic property
    while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back();
    }
    
    dq.push_back(i);
}
```

## Implementation from Scratch

### Stack using Array
```cpp
class Stack {
    vector<int> data;
public:
    void push(int x) { data.push_back(x); }
    void pop() { data.pop_back(); }
    int top() { return data.back(); }
    bool empty() { return data.empty(); }
};
```

### Queue using Array
```cpp
class Queue {
    vector<int> data;
    int front_idx = 0;
public:
    void push(int x) { data.push_back(x); }
    void pop() { front_idx++; }
    int front() { return data[front_idx]; }
    bool empty() { return front_idx >= data.size(); }
};
```

## Evaluation Criteria

When evaluating solutions:
1. ✅ Uses appropriate structure (stack/queue/deque)
2. ✅ Recognizes when a problem needs LIFO/FIFO/both
3. ✅ Implements monotonic stack when applicable
4. ✅ Uses BFS correctly with queue
5. ✅ Handles edge cases (empty structures)
6. ✅ Understands time complexity of operations
7. ❌ Still should not use priority_queue/heap

## When to Use Each Structure

- **Stack**: 
  - Need LIFO (last in, first out)
  - Matching/balancing problems
  - Expression evaluation
  - DFS, backtracking
  - Undo/redo functionality

- **Queue**:
  - Need FIFO (first in, first out)
  - BFS traversal
  - Level-order processing
  - Task scheduling
  - Buffer management

- **Deque**:
  - Need access to both ends
  - Sliding window min/max
  - Palindrome checking
  - Need both vector and queue features

## Notes

- Stack and Queue are **adapters** in C++ STL (built on deque by default)
- Deque is a full container with random access
- Monotonic stack is a powerful technique for "next greater/smaller" problems
- BFS uses queue; DFS uses stack (or recursion)
- Sliding window problems often use deque for efficiency
