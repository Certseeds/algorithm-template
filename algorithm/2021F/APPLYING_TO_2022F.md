# Applying Data Structure Restrictions to 2022 Fall Problems

## Overview

This document provides guidance on how to apply the Data Structure Restrictions Framework to 2022 Fall (2022F) problems, or any new problem set.

## Framework Summary

The Data Structure Restrictions Framework defines progressive levels of allowed data structures and algorithms:

1. **Lab Welcome**: Basic containers (vector, set, map, unordered_set/map)
2. **Lab 02**: + Binary search, complexity analysis
3. **Lab 03**: + std::sort, custom comparators
4. **Lab 04**: + Linked lists, two-pointer techniques
5. **Lab 05**: + Stack, Queue, Deque
6. **Lab 06+**: + Trees, heaps, graphs, advanced algorithms

## Purpose

The framework helps:
- **Evaluate problem difficulty** relative to available tools
- **Assess solution intelligence** when using limited resources
- **Provide progressive learning** from basic to advanced concepts
- **Test LLM/AI capabilities** with constrained problem-solving

## How to Apply to New Problems

### Step 1: Categorize by Lab Level

For each problem, determine its intended lab level based on:
- **Concepts required**: What knowledge is needed to solve it?
- **Structures needed**: What's the minimal set of structures required?
- **Difficulty**: How complex is the logic/algorithm?

Example categorization:
- Simple array manipulation → lab_welcome
- Binary search problem → lab_02
- Greedy with sorting → lab_03
- Linked list reversal → lab_04
- Parentheses matching → lab_05
- Tree traversal → lab_06
- Shortest path → lab_09

### Step 2: Verify Solvability

Confirm the problem can be solved using only structures allowed at that level:

```
For a lab_03 problem:
✓ Can use: vector, set, map, std::sort, binary search
✗ Cannot use: stack, queue, linked list, tree, heap

Design solution using only allowed structures.
If impossible, the problem is mis-categorized.
```

### Step 3: Create Problem Directory

Follow the existing structure:

```
algorithm/2022F/lab_XX/lab_XX_Y/
├── CMakeLists.txt
├── README.md
├── main.cpp
├── test.cpp
└── resource/
    ├── 01.data.in
    └── 01.data.out
```

### Step 4: Document in README

Each problem's README should include:

```markdown
# Problem Title

## Description
[Problem statement]

## Input/Output
[Format specification]

## Sample
[Examples]

## Data Structure Restrictions

**Lab Level**: Lab XX

**Allowed Structures Used**:
- ✅ Structure 1: Why/how it's used
- ✅ Structure 2: Why/how it's used

**Complexity Analysis**:
- Time: O(...)
- Space: O(...)

**Compliance**: 
This solution demonstrates Lab XX level capabilities by:
- Key technique 1
- Key technique 2

**Alternative Approaches**:
(Optional) Discuss solutions at other lab levels.

See [Lab XX Restrictions](../RESTRICTIONS.md) for details.
```

### Step 5: Implement Solution

Write `main.cpp` using only allowed structures:

```cpp
// Include only allowed headers for this lab level
#include <vector>
#include <algorithm>  // Only if lab_03+
// Do NOT include <stack>, <queue> for lab_welcome through lab_03

// Solution using allowed structures
output_type cal(const input_type &data) {
    // Implementation constrained to lab level
}
```

### Step 6: Create Tests

Write `test.cpp` following repository patterns:

```cpp
#include <catch_main.hpp>
#include "main.cpp"

TEST_CASE("test case 1") {
    // Test with example data
    const auto output = cal(input);
    CHECK(output == expected);
}
```

## Example: Categorizing a New Problem

### Problem: "Find Missing Number"
*Given an array of n distinct numbers in range [0, n], find the missing number.*

**Analysis**:
- **Concept**: Simple array traversal, math (sum formula)
- **Minimal structures**: vector or raw array
- **Complexity**: O(n) time, O(1) space
- **Category**: **lab_welcome**

**lab_welcome Solution**:
```cpp
int findMissing(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int x : nums) actualSum += x;
    return expectedSum - actualSum;
}
```
Uses only: vector, basic math → ✓ lab_welcome compliant

### Problem: "Merge Intervals"
*Given intervals, merge overlapping ones.*

**Analysis**:
- **Concept**: Sorting by start time, greedy merging
- **Minimal structures**: vector + std::sort
- **Complexity**: O(n log n) time
- **Category**: **lab_03**

**lab_03 Solution**:
```cpp
vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), 
         [](const Interval& a, const Interval& b) {
             return a.start < b.start;
         });
    
    vector<Interval> result;
    for (const auto& interval : intervals) {
        if (result.empty() || result.back().end < interval.start) {
            result.push_back(interval);
        } else {
            result.back().end = max(result.back().end, interval.end);
        }
    }
    return result;
}
```
Uses: vector, std::sort, lambda → ✓ lab_03 compliant

### Problem: "Valid Parentheses"
*Check if string has valid balanced parentheses.*

**Analysis**:
- **Concept**: Stack for matching
- **Minimal structures**: stack
- **Complexity**: O(n) time, O(n) space
- **Category**: **lab_05**

**lab_05 Solution**:
```cpp
bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> pairs = {
        {')', '('}, {']', '['}, {'}', '{'}
    };
    
    for (char c : s) {
        if (pairs.count(c)) {
            if (stk.empty() || stk.top() != pairs[c]) {
                return false;
            }
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.empty();
}
```
Uses: stack, unordered_map → ✓ lab_05 compliant

## Creating 2022F Directory Structure

If creating a new 2022F directory:

```bash
cd algorithm/
mkdir -p 2022F
cd 2022F

# Copy restriction documents
cp ../2021F/DATA_STRUCTURE_RESTRICTIONS.md .
cp ../2021F/ADVANCED_LABS_RESTRICTIONS.md .
cp ../2021F/README.md . # Edit for 2022F

# Create lab directories
for lab in lab_welcome lab_02 lab_03 lab_04 lab_05 lab_06 lab_07 lab_08 lab_09 lab_10; do
    mkdir -p $lab
    # Copy RESTRICTIONS.md from 2021F
    if [ -f "../2021F/$lab/RESTRICTIONS.md" ]; then
        cp "../2021F/$lab/RESTRICTIONS.md" "$lab/"
    fi
done

# Create CMakeLists.txt
cat > CMakeLists.txt << 'EOF'
add_subdirectory(lab_welcome)
add_subdirectory(lab_02)
add_subdirectory(lab_03)
add_subdirectory(lab_04)
add_subdirectory(lab_05)
add_subdirectory(lab_06)
add_subdirectory(lab_07)
add_subdirectory(lab_08)
add_subdirectory(lab_09)
add_subdirectory(lab_10)
EOF
```

Then add to main `algorithm/CMakeLists.txt`:
```cmake
add_subdirectory(2022F)
```

## Validation Checklist

For each problem in 2022F:

- [ ] Problem is categorized to appropriate lab level
- [ ] Solution uses only allowed structures for that level
- [ ] README includes "Data Structure Restrictions" section
- [ ] Complexity is analyzed and documented
- [ ] Test cases are provided
- [ ] Code compiles and passes tests
- [ ] Solution demonstrates key concepts of that lab level

## Multi-Level Problems

Some problems can be solved at multiple levels:

**Example: Two Sum**

- **lab_welcome**: Nested loops O(n²)
- **lab_02**: Hash map O(n) - demonstrates complexity awareness
- **lab_03**: Sort + two pointers O(n log n) - demonstrates sorting

Document all approaches in README:

```markdown
## Data Structure Restrictions

**Minimal Lab Level**: Lab Welcome (but inefficient)

**Approaches by Lab**:

### Lab Welcome Approach - O(n²)
Brute force nested loops.

### Lab 02 Approach - O(n) ⭐ Optimal
Hash map for O(1) lookup.

### Lab 03 Approach - O(n log n)
Sort then two pointers.

**Recommended**: Lab 02 approach demonstrates proper complexity analysis.
```

## FAQ

**Q: What if a problem needs structures from lab_06 but the topic is from lab_03?**

A: Categorize by the most advanced structure needed. If it truly needs a tree, it's a lab_06+ problem regardless of topic.

**Q: Can students use more advanced structures on earlier lab problems?**

A: Yes, but they should also understand the "restricted" solution. Advanced structures on simple problems might indicate:
- Over-engineering
- Lack of understanding of simpler approaches
- Or, creative problem-solving

**Q: How do I handle problems that are "between" lab levels?**

A: Assign to the higher level. Better for a lab_03 problem to be easy than for a lab_02 problem to be impossible.

**Q: Should I create problems specifically for this framework?**

A: You can, but existing problems naturally fit into these categories. The framework is descriptive (categorizing problems) as well as prescriptive (designing new ones).

## Tools and Automation

Future enhancements could include:

1. **Structure checker**: Script to analyze code and verify allowed structures
2. **Complexity analyzer**: Tool to estimate time/space complexity
3. **Auto-categorizer**: Suggest lab level based on code analysis
4. **Test generator**: Create test cases for different complexity scenarios

## Conclusion

The Data Structure Restrictions Framework provides a systematic way to:
- Organize problems by difficulty
- Document learning progression
- Evaluate solutions fairly
- Test problem-solving with constraints

Apply it to 2022F problems by categorizing, documenting, and verifying each problem follows the level's restrictions.

## References

- [Main Framework Document](./DATA_STRUCTURE_RESTRICTIONS.md)
- [2021F README](./README.md)
- Individual lab RESTRICTIONS.md files
- Example problems in 2021F labs
