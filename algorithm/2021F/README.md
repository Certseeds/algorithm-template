# CS203 2021 Fall - Algorithm Problems

This directory contains algorithm problems from CS203 2021 Fall semester, organized by lab.

## Lab Structure

Each lab introduces new concepts and data structures in a progressive manner:

- **lab_welcome**: Basic programming and data structures
- **lab_02**: Complexity analysis and binary search  
- **lab_03**: Sorting algorithms
- **lab_04**: Linked lists and pointer manipulation
- **lab_05**: Stack, Queue, and Deque
- **lab_06+**: Advanced topics (trees, graphs, etc.)

## Data Structure Restrictions Framework

This repository implements a **Data Structure Restrictions Framework** to help evaluate problem difficulty and solution intelligence. Each lab level restricts which data structures and algorithms can be used, creating a progressive learning path.

### Why Restrictions?

1. **Evaluate Problem Difficulty**: Problems designed for lab_02 should be solvable with only lab_02 concepts
2. **Assess Understanding**: Solutions using only allowed structures demonstrate deeper understanding
3. **Progressive Learning**: Students build up their toolkit gradually
4. **LLM Evaluation**: Test AI systems' ability to solve problems with limited resources

### Quick Reference

| Lab | New Additions | Key Concepts |
|-----|---------------|--------------|
| Welcome | vector, set, map, unordered_set/map | Basic containers, intuition |
| Lab 02 | Binary search, complexity analysis | O(n²) vs O(n log n) decisions |
| Lab 03 | std::sort, custom comparators | Sorting as preprocessing |
| Lab 04 | Linked lists, two-pointer techniques | ListNode, fast-slow pointers |
| Lab 05 | Stack, Queue, Deque | LIFO/FIFO, BFS/DFS |

### Documentation

- **[DATA_STRUCTURE_RESTRICTIONS.md](./DATA_STRUCTURE_RESTRICTIONS.md)**: Complete framework overview
- **[lab_welcome/RESTRICTIONS.md](./lab_welcome/RESTRICTIONS.md)**: Lab Welcome restrictions
- **[lab_02/RESTRICTIONS.md](./lab_02/RESTRICTIONS.md)**: Lab 02 restrictions  
- **[lab_03/RESTRICTIONS.md](./lab_03/RESTRICTIONS.md)**: Lab 03 restrictions
- **[lab_04/RESTRICTIONS.md](./lab_04/RESTRICTIONS.md)**: Lab 04 restrictions
- **[lab_05/RESTRICTIONS.md](./lab_05/RESTRICTIONS.md)**: Lab 05 restrictions

### Using the Framework

#### For Problem Setters

When creating a problem for lab_XX:
1. Review `lab_XX/RESTRICTIONS.md` for allowed structures
2. Design the problem to require only those structures
3. Add a "Data Structure Restrictions" section to the problem's README

#### For Problem Solvers

When solving a problem in lab_XX:
1. Check `lab_XX/RESTRICTIONS.md` first
2. Attempt to solve using only allowed structures
3. Consider: "What would I do if more advanced structures weren't available?"

#### For Educators & Evaluators

When reviewing solutions:
1. Verify which structures were used
2. Check if they match the lab level
3. Assess if the solution demonstrates the lab's learning objectives

### Example: Problem Evolution

Consider a "find duplicates" problem across different labs:

**Lab Welcome Solution**:
```cpp
// Use unordered_map to count frequencies
unordered_map<int, int> freq;
for (int x : arr) freq[x]++;
```

**Lab 02 Solution**:
```cpp
// Manual sort + linear scan (understand O(n²) sort)
// Or hash map with complexity analysis
```

**Lab 03 Solution**:
```cpp
// Use std::sort then find adjacent duplicates
sort(arr.begin(), arr.end());
for (int i = 1; i < arr.size(); i++) {
    if (arr[i] == arr[i-1]) { /* found duplicate */ }
}
```

Each solution is valid for its level, demonstrating different concepts.

## Problem Index

### lab_welcome
- lab_welcome_A: Set membership checking
- lab_welcome_B: Frequency counting
- lab_welcome_C, D, E: Array operations
- lab_welcome_F, G: Finding min/max

### lab_02
- lab_02_A: Set membership with complexity analysis
- lab_02_B, C: Binary search applications
- lab_02_D: Two-sum with hash map
- lab_02_E, F, G: Range queries and counting

### lab_03
- lab_03_A, B: Kth element problems
- lab_03_C: Sorting algorithm comparison
- lab_03_D: Custom sorting
- lab_03_E, F, G: Greedy with sorting, two-pointer

### lab_04
- lab_04_A: Basic linked list operations
- lab_04_B: Reverse linked list
- lab_04_C: Chain connection problem
- lab_04_D: Merge sorted lists
- lab_04_E: Find middle/kth from end

### lab_05
- lab_05_A: Parentheses matching (stack)
- lab_05_B: Expression evaluation (stack)
- lab_05_C, D: Monotonic stack problems
- lab_05_E, F: BFS and level-order (queue)
- lab_05_G, H: Deque applications

## Target: 2022 Fall Problems

The restrictions framework is designed to be applied to 2022 Fall problems as well. When 2022F problems are added to the repository, they should:

1. Be categorized by lab level
2. Include "Data Structure Restrictions" sections in READMEs
3. Follow the progressive difficulty model
4. Demonstrate concepts from their respective lab levels

## Contributing

When adding new problems or solutions:
- Follow the restrictions for the target lab level
- Document which structures are used
- Include complexity analysis
- Add a "Data Structure Restrictions" section to README
- Provide example solutions at the appropriate level

## Related Documents

- Repository root [README.md](../../README.md): Overall project documentation
- [Algorithm directory](..): Other algorithm collections
- Individual problem READMEs: Problem-specific details

## Notes

- These restrictions are **guidelines** for problem design and learning progression
- They help maintain consistent difficulty levels across semesters
- Advanced students can still solve with optimal algorithms, but should also consider "restricted" approaches
- The framework is useful for both human learning and AI/LLM capability evaluation
