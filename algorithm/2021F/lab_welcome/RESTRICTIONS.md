# Lab Welcome - Data Structure Restrictions

## Overview

Lab Welcome introduces the most basic data structures and programming concepts. Problems should be solvable using intuitive approaches without deep algorithmic knowledge.

## Allowed Data Structures

### Containers
- **Raw arrays**: `int arr[100]`, `int arr[N]` (fixed-size)
- **std::vector**: Dynamic arrays, `push_back()`, `size()`, index access
- **std::set**: Ordered set operations, `insert()`, `find()`, `erase()`
- **std::map**: Key-value pairs, `insert()`, `find()`, `[]` operator
- **std::unordered_set**: Hash set for O(1) average lookup
- **std::unordered_map**: Hash map for O(1) average key-value lookup

### Control Structures
- `if-else` conditional statements
- `for` loops (indexed and range-based)
- `while` loops
- Basic recursion (without memoization or complex DP)

### Functions
- Simple function definitions
- Pass by value/reference
- Return values

## Allowed Operations

- **Input/Output**: `cin`, `cout`, basic I/O operations
- **Math operations**: All arithmetic, `abs()`, `min()`, `max()`, `pow()`, etc.
- **String operations**: Basic string manipulation, concatenation, indexing
- **Comparisons**: All comparison operators

## Restrictions

### NOT Allowed
- Linked lists (neither custom `ListNode` nor `std::list`)
- Stack (`std::stack`)
- Queue (`std::queue`)
- Deque (`std::deque`)
- Priority queue/heap (`std::priority_queue`)
- Complex algorithmic patterns requiring formal analysis
- Advanced graph/tree data structures

### Approach
- **Intuition-based**: Solutions should be understandable without deep algorithm knowledge
- **No complexity analysis required**: Students don't yet need to analyze time/space complexity
- **Straightforward implementation**: Direct translation of problem logic to code

## Example Problems

### Problem Types Suitable for Lab Welcome

1. **Set membership checking** (lab_welcome_A)
   - Use: `unordered_set` for O(1) lookup
   - Pattern: Read set, answer queries

2. **Counting and frequency** (lab_welcome_B)
   - Use: `unordered_map` for counting occurrences
   - Pattern: Iterate and count, then answer queries

3. **Simple array operations** (lab_welcome_C, D, E)
   - Use: `vector` for dynamic arrays
   - Pattern: Read data, process with loops, output results

4. **Basic sorting/finding** (lab_welcome_F, G)
   - Use: Built-in comparison with `vector`
   - Can use: `std::min_element`, `std::max_element`
   - Cannot use: `std::sort` (reserved for lab_03)

## Solution Pattern

The typical solution structure at this level:

```cpp
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Read input
input_type read() {
    // Simple cin operations
    // Build vector/set/map
    return data;
}

// Calculate/process
output_type cal(const input_type &data) {
    // Intuitive logic using basic loops and conditionals
    // May use set/map for efficient lookups
    return result;
}

// Output results
void output(const output_type &data) {
    // Simple cout operations
}

int main() {
    auto input = read();
    auto result = cal(input);
    output(result);
    return 0;
}
```

## Learning Objectives

Students at this level should learn:
- Basic C++ syntax and STL container usage
- How to read problem statements and translate to code
- Using appropriate data structures (array vs set vs map)
- Basic problem-solving without algorithmic theory
- Input/output handling
- Simple iteration and conditionals

## Evaluation Criteria

When evaluating solutions:
1. ✅ Uses only allowed data structures
2. ✅ Solution is straightforward and intuitive
3. ✅ Code is readable and well-structured
4. ✅ Handles the input/output format correctly
5. ❌ No need for optimal time complexity (yet)
