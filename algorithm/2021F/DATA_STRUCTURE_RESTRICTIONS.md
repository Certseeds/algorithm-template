# Data Structure Restrictions Framework

## Purpose

This document defines a progressive framework for restricting available data structures and algorithms based on lab level. This helps:

1. Evaluate problem difficulty relative to available tools
2. Assess solution intelligence when using limited resources
3. Provide clear learning progression from basic to advanced concepts

## Restriction Levels

### Lab Welcome (lab_welcome)

**Allowed Data Structures:**
- Raw arrays (`int arr[]`, `int arr[N]`)
- `std::vector` / `ArrayList`
- `std::set` / `TreeSet`
- `std::map` / `TreeMap`
- `std::unordered_set` / `HashSet`
- `std::unordered_map` / `HashMap`

**Allowed Control Flow:**
- `if-else` statements
- Basic loops (`for`, `while`)
- Recursion

**Allowed Techniques:**
- Simple function definitions
- All mathematical operations and skills
- Input → Calculate → Output pattern
- Intuition-based solutions

**Restrictions:**
- No formal complexity analysis required
- No advanced data structures (linked lists, stacks, queues)
- Solutions should be intuitive rather than algorithmically optimal

### Lab 2 (lab_02)

**Everything from Lab Welcome, plus:**

**New Allowed:**
- Complexity analysis concepts (O(n), O(n²), O(n log n))
- Binary search algorithms
- Selection of appropriate algorithm based on input size

**New Skills:**
- Understand when to use O(n²) vs O(n log n) algorithms
- Implement binary search
- Time complexity awareness

### Lab 3 (lab_03)

**Everything from Lab 2, plus:**

**New Allowed:**
- `std::sort` / `Arrays.sort()` / `Collections.sort()`
- Sorting algorithms understanding
- Comparator/comparison functions

**New Skills:**
- Custom sorting with comparators
- Sorting as a preprocessing step
- Stability of sorting algorithms

### Lab 4 (lab_04)

**Everything from Lab 3, plus:**

**New Allowed:**
- Custom linked list implementation (`ListNode` structures)
- `std::list` / `LinkedList`
- Linked list algorithms
- Two-pointer technique
- Fast-slow pointer technique

**New Skills:**
- Linked list traversal and manipulation
- Detecting cycles in linked lists
- Reversing linked lists
- Merging sorted linked lists
- Two-pointer algorithms

### Lab 5 (lab_05)

**Everything from Lab 4, plus:**

**New Allowed:**
- `std::queue` / `Queue` / `Deque`
- `std::stack` / `Stack`
- `std::deque` / `ArrayDeque`
- Stack-based algorithms
- Queue-based algorithms (BFS)

**New Skills:**
- Stack applications (expression evaluation, parentheses matching)
- Queue applications (BFS, level-order traversal)
- Monotonic stack/queue
- Deque for sliding window problems

### Lab 6+ (lab_06 onwards)

**Progressive additions continue:**
- Trees (binary trees, BST, balanced trees)
- Graphs (adjacency lists, matrices)
- Heaps / Priority queues
- Advanced DP
- Advanced graph algorithms (DFS, Dijkstra, etc.)

## Usage

### For Problem Setters

When creating a problem for a specific lab:
1. Check the allowed data structures for that lab level
2. Design the problem to be solvable using only those structures
3. Document any special considerations in the problem's README

### For Problem Solvers

When solving a problem in a specific lab:
1. Review the allowed data structures for that lab
2. Attempt to solve using only those structures
3. If stuck, review if you're missing a fundamental technique from that lab's level

### For AI/LLM Evaluation

When evaluating AI solutions:
1. Check which data structures were used
2. Verify they match the lab level restrictions
3. Assess if the solution demonstrates understanding of that lab's concepts
4. Compare solutions using only allowed structures vs. using advanced structures

## Implementation Notes

- These restrictions are **guidelines** for problem design and evaluation
- They help maintain a consistent difficulty progression
- They can be used to create "challenge modes" where only certain structures are allowed
- Useful for educational purposes and algorithmic thinking development

## Related Files

- Each lab directory may contain a `RESTRICTIONS.md` file with lab-specific details
- Individual problem READMEs may note which structures are expected/recommended
