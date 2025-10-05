# Lab 02 - Data Structure Restrictions

## Overview

Lab 02 introduces **complexity analysis** and **binary search**. Students should now understand the trade-offs between different algorithmic approaches and select algorithms based on input constraints.

## Allowed Data Structures

### Everything from Lab Welcome, plus:

### Algorithmic Concepts
- **Time complexity analysis**: O(1), O(log n), O(n), O(n log n), O(n²)
- **Space complexity awareness**
- **Algorithm selection based on input size**

## Allowed Algorithms

### New in Lab 02

1. **Binary Search**
   - Search in sorted arrays
   - `std::lower_bound()`, `std::upper_bound()`
   - Custom binary search implementation
   - Binary search on answer

2. **Complexity-Driven Decisions**
   - Choose O(n²) for small inputs
   - Choose O(n log n) for larger inputs
   - Recognize when brute force is acceptable

## Restrictions

### Still NOT Allowed
- Linked lists (custom or `std::list`)
- Stack, Queue, Deque
- Priority queue
- Custom sorting (still cannot use `std::sort` - that's lab_03)

### New Requirements
- **Must consider time complexity**: Solutions should demonstrate awareness of efficiency
- **Input size matters**: Different approaches for different constraints
- **Binary search usage**: Problems may require binary search for optimal solutions

## Example Problems

### Problem Types Suitable for Lab 02

1. **Set membership with constraints** (lab_02_A)
   - Use: `unordered_set` with O(1) lookup
   - Analysis: O(n + m) vs O(n log n + m log n)

2. **Finding in sorted data** (lab_02_B, lab_02_C)
   - Use: Binary search on sorted arrays
   - Pattern: Sort first (if needed), then binary search
   - Note: Can use `std::lower_bound` but not `std::sort` (must sort manually if needed)

3. **Two-sum style problems** (lab_02_D)
   - Use: Hash map for O(n) solution
   - Alternative: Sort + two pointers (manual sort using insertion/selection)
   - Analysis: Compare O(n) hash vs O(n²) nested loops

4. **Range queries on static data** (lab_02_E)
   - Use: Binary search for range boundaries
   - Pattern: Preprocess then answer queries efficiently

5. **Counting with constraints** (lab_02_F, G)
   - Use: Map/unordered_map
   - Analysis: Choose structure based on whether ordering matters

## Solution Pattern

```cpp
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>  // for lower_bound, upper_bound

using namespace std;

// Read input
input_type read() {
    // Standard input reading
    return data;
}

// Calculate with complexity awareness
output_type cal(const input_type &data) {
    // Consider input size and complexity
    
    // Example 1: Binary search usage
    auto it = lower_bound(data.begin(), data.end(), target);
    
    // Example 2: Hash-based O(n) approach
    unordered_map<int, int> freq;
    for (auto x : data) {
        freq[x]++;
    }
    
    // Choose algorithm based on constraints:
    // - Small n (< 1000): O(n²) acceptable
    // - Large n (> 10^5): Need O(n log n) or better
    
    return result;
}

void output(const output_type &data) {
    // Standard output
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
- **Complexity analysis**: Calculate and compare time/space complexity
- **Binary search**: Implement and use in various contexts
- **Algorithm selection**: Choose approach based on input constraints
- **Trade-offs**: Understand space-time trade-offs (e.g., hash map vs sorting)
- **Optimization**: Move from brute force to efficient solutions

## Key Techniques

### Binary Search Applications
1. **Find exact value** in sorted array
2. **Find insertion position** (`lower_bound`, `upper_bound`)
3. **Binary search on answer** (find minimum/maximum satisfying a condition)
4. **Count occurrences** in sorted array

### Complexity Guidelines
- **O(1)**: Direct access, hash lookups
- **O(log n)**: Binary search
- **O(n)**: Single pass, hash map building
- **O(n log n)**: Binary search for each of n elements
- **O(n²)**: Nested loops (acceptable only for small n)

## Common Patterns

### Pattern 1: Search in Sorted Data
```cpp
// Given sorted array, find if target exists
vector<int> arr = {1, 3, 5, 7, 9};
auto it = lower_bound(arr.begin(), arr.end(), 5);
if (it != arr.end() && *it == 5) {
    // Found
}
```

### Pattern 2: Hash Map for O(1) Lookup
```cpp
// Two-sum problem: find if two numbers sum to target
unordered_set<int> seen;
for (int x : arr) {
    if (seen.count(target - x)) {
        return true;
    }
    seen.insert(x);
}
```

### Pattern 3: Binary Search on Answer
```cpp
// Find minimum value that satisfies condition
int left = 0, right = MAX_VALUE;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (check(mid)) {
        right = mid;  // Try smaller
    } else {
        left = mid + 1;  // Need larger
    }
}
```

## Evaluation Criteria

When evaluating solutions:
1. ✅ Uses only allowed data structures (Lab Welcome + binary search concepts)
2. ✅ Demonstrates complexity awareness
3. ✅ Chooses appropriate algorithm for input size
4. ✅ Implements binary search correctly when needed
5. ✅ Solution passes time limits (not TLE due to poor complexity)
6. ❌ Should not use `std::sort` (that's lab_03)
7. ❌ Should not use stack/queue/linked list

## Complexity Decision Tree

```
Input size n:
  n ≤ 100: O(n²) or O(n³) acceptable
  100 < n ≤ 10³: O(n²) acceptable, O(n log n) preferred
  10³ < n ≤ 10⁵: O(n log n) required
  n > 10⁵: O(n) or O(n log n) required

Data is sorted?
  Yes: Consider binary search O(log n) per query
  No: Consider hashing O(1) per query or sorting cost
```

## Notes

- Students can manually implement simple sorting (like bubble sort or insertion sort) if needed, but should recognize it's O(n²)
- The focus is on **understanding complexity**, not on using built-in sorting (that comes in lab_03)
- Binary search is the key new tool at this level
