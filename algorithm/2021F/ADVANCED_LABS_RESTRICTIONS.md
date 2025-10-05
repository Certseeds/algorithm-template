# Lab 06+ - Data Structure Restrictions

## Overview

Labs 06 and beyond introduce progressively more advanced data structures and algorithms. The restrictions become less about "what you cannot use" and more about "understanding the right tool for the job".

## Lab 06 - Trees

### New Additions
- **Binary Trees**: Tree node structures, traversal algorithms
- **Binary Search Trees (BST)**: Insert, search, delete operations
- **Tree Traversals**: Preorder, inorder, postorder (recursive and iterative)
- **Level-order traversal**: Using queue (from lab_05)

### Key Concepts
- Tree node structures (`TreeNode* left, right`)
- Recursive tree algorithms
- BST properties
- Tree traversal patterns

### Example Structures
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

## Lab 07 - Priority Queue / Heap

### New Additions
- **std::priority_queue**: Max heap by default
- **Heap operations**: push, pop, top in O(log n)
- **Custom comparators**: Min heap, custom priority
- **Heap algorithms**: heapify, heap sort

### Key Concepts
- Priority queue for "best element" access
- Heap as complete binary tree
- Applications: top-k problems, merge k sorted arrays
- Greedy algorithms with heap

## Lab 08 - Hash Tables & Advanced Containers

### New Additions
- **std::unordered_multiset**: Multiple identical elements
- **std::unordered_multimap**: Multiple values per key
- **Custom hash functions**: For user-defined types
- **Hash collision handling**: Understanding performance

### Key Concepts
- Hash table internals
- When to use multiset/multimap
- Hash function design
- Load factor and rehashing

## Lab 09 - Graph Algorithms

### New Additions
- **Graph representations**: Adjacency list, adjacency matrix
- **DFS/BFS on graphs**: Full implementation
- **Shortest path**: Dijkstra's algorithm, Bellman-Ford
- **Minimum spanning tree**: Kruskal's, Prim's
- **Topological sort**: DAG applications

### Key Concepts
- Graph traversal patterns
- Weighted vs unweighted graphs
- Directed vs undirected graphs
- Path finding algorithms
- Union-Find (Disjoint Set)

### Example Structures
```cpp
// Adjacency list
vector<vector<int>> graph(n);
graph[u].push_back(v);

// With weights
vector<vector<pair<int, int>>> graph(n);
graph[u].push_back({v, weight});
```

## Lab 10 - Advanced Topics

### New Additions
- **Dynamic Programming**: Advanced DP patterns
- **Segment Trees**: Range queries
- **Trie**: Prefix trees for strings
- **Suffix Arrays**: Advanced string processing
- **Advanced graph**: Floyd-Warshall, network flow

### Key Concepts
- Complex DP state design
- Range query data structures
- String algorithms
- All-pairs shortest path
- Maximum flow problems

## Progressive Philosophy

At these advanced levels:

1. **All previous structures are available**: The focus shifts to choosing the right structure
2. **Complexity is crucial**: Must analyze and optimize
3. **Multiple approaches**: Often several valid solutions with different trade-offs
4. **Problem-specific structures**: May need to design custom data structures

## Evaluation at Advanced Levels

For labs 06+, evaluation focuses on:

1. **Correct structure choice**: Using the most appropriate data structure
2. **Optimal complexity**: Achieving the best known complexity
3. **Implementation quality**: Clean, efficient code
4. **Edge case handling**: Robust solutions
5. **Space-time trade-offs**: Understanding when to optimize for space vs time

## Common Patterns by Lab

### Lab 06 (Trees)
- Tree traversal (recursive and iterative)
- Path finding in trees
- Tree construction from traversals
- Lowest Common Ancestor (LCA)

### Lab 07 (Heaps)
- Top-K elements
- Merge K sorted lists/arrays
- Median maintenance
- Greedy scheduling with priorities

### Lab 08 (Advanced Hash)
- Substring problems with hash
- Anagram grouping
- Custom hash for complex keys
- Frequency-based problems

### Lab 09 (Graphs)
- Connected components
- Shortest paths (single-source, all-pairs)
- Cycle detection
- Topological ordering
- Minimum spanning tree

### Lab 10 (Advanced)
- Multi-dimensional DP
- Range query optimization
- String matching algorithms
- Network flow applications

## Notes

- At advanced levels, the restrictions framework becomes more about **best practices** than hard limitations
- Students should understand **why** certain structures are better for certain problems
- The goal is to develop **algorithmic intuition** and **problem-solving patterns**
- Real-world problems often require combining multiple data structures effectively

## See Also

- [Main Restrictions Document](../DATA_STRUCTURE_RESTRICTIONS.md)
- [Lab Welcome Restrictions](../lab_welcome/RESTRICTIONS.md)
- [Lab 02 Restrictions](../lab_02/RESTRICTIONS.md)
- [Lab 03 Restrictions](../lab_03/RESTRICTIONS.md)
- [Lab 04 Restrictions](../lab_04/RESTRICTIONS.md)
- [Lab 05 Restrictions](../lab_05/RESTRICTIONS.md)

## Future Extensions

As new advanced topics are added (e.g., computational geometry, advanced string algorithms, etc.), this document can be extended to include:

- Specialized data structures (KD-trees, R-trees, etc.)
- Advanced string structures (suffix trees, suffix automaton)
- Probabilistic data structures (Bloom filters, Count-Min Sketch)
- Parallel/concurrent data structures
