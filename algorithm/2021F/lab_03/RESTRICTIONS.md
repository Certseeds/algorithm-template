# Lab 03 - Data Structure Restrictions

## Overview

Lab 03 introduces **sorting algorithms** and the ability to use built-in sort functions. This is a major milestone as sorting is one of the most fundamental algorithmic tools.

## Allowed Data Structures

### Everything from Lab 02, plus:

### New Sorting Capabilities
- **`std::sort()`**: General-purpose sorting
- **`std::stable_sort()`**: Stable sorting (preserves relative order of equal elements)
- **Custom comparators**: Sorting with custom comparison functions
- **Partial sorting**: `std::partial_sort()`, `std::nth_element()`

## Allowed Algorithms

### New in Lab 03

1. **Sorting Algorithms**
   - Use `std::sort()` for O(n log n) sorting
   - Understand different sorting algorithms (insertion, selection, merge, quick)
   - Compare sorting algorithm performance
   - Implement basic sorting algorithms manually (for learning)

2. **Sorting-Based Solutions**
   - Sort as preprocessing step
   - Two-pointer technique on sorted arrays
   - Greedy algorithms with sorting
   - Finding duplicates/unique elements via sorting

3. **Custom Comparators**
   - Sort by custom criteria
   - Lambda functions for comparison
   - Struct/class with comparison operators

## Restrictions

### Still NOT Allowed
- Linked lists (custom or `std::list`)
- Stack (`std::stack`)
- Queue (`std::queue`)
- Deque (`std::deque`)
- Priority queue (`std::priority_queue`)

### New Capabilities
- **Can now use `std::sort()`**: The most important addition
- **Sorting-based algorithms**: Many problems become easier
- **Comparator functions**: Sort by multiple criteria

## Example Problems

### Problem Types Suitable for Lab 03

1. **Compare sorting algorithms** (lab_03_C)
   - Implement: Insertion sort, selection sort, merge sort, quick sort
   - Compare: Number of operations, time complexity
   - Pattern: Educational comparison of algorithms

2. **Sorting with custom criteria** (lab_03_D)
   - Use: `std::sort()` with lambda comparator
   - Pattern: Sort by multiple fields or custom rules
   ```cpp
   sort(arr.begin(), arr.end(), [](const T& a, const T& b) {
       return a.value < b.value;  // Custom comparison
   });
   ```

3. **Greedy with sorting** (lab_03_E, F)
   - Pattern: Sort first, then greedily select elements
   - Example: Interval scheduling, activity selection

4. **Two-pointer on sorted data** (lab_03_G)
   - Use: Sort array, then two-pointer technique
   - Pattern: Find pairs/triplets with certain properties
   ```cpp
   sort(arr.begin(), arr.end());
   int left = 0, right = arr.size() - 1;
   while (left < right) {
       // Two-pointer logic
   }
   ```

5. **Finding kth element** (lab_03_A, B)
   - Use: `std::sort()` then direct access
   - Or: `std::nth_element()` for O(n) average
   - Pattern: Kth largest/smallest element

## Solution Pattern

```cpp
#include <vector>
#include <iostream>
#include <algorithm>  // for sort, stable_sort

using namespace std;

// Read input
input_type read() {
    // Standard input reading
    return data;
}

// Calculate with sorting
output_type cal(const input_type &data) {
    vector<int> arr = data;
    
    // Example 1: Basic sort
    sort(arr.begin(), arr.end());
    
    // Example 2: Custom comparator
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b;  // Descending order
    });
    
    // Example 3: Sort by multiple criteria
    struct Item {
        int value;
        int priority;
    };
    vector<Item> items;
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        if (a.priority != b.priority) {
            return a.priority > b.priority;  // Higher priority first
        }
        return a.value < b.value;  // Then by value
    });
    
    // Example 4: After sorting, use two pointers
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            // Found
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
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
- **Sorting algorithms**: Understand different algorithms and their properties
- **Using `std::sort()`**: Apply sorting to solve problems
- **Custom comparators**: Sort by complex criteria
- **Sorting-based patterns**: Recognize when sorting simplifies a problem
- **Stability**: Understand when stable sorting matters
- **Complexity**: Sorting is O(n log n), factor this into total complexity

## Key Techniques

### Technique 1: Sort Then Process
```cpp
// Find duplicates
sort(arr.begin(), arr.end());
for (int i = 1; i < arr.size(); i++) {
    if (arr[i] == arr[i-1]) {
        // Duplicate found
    }
}
```

### Technique 2: Custom Comparator
```cpp
// Sort intervals by start time, then by end time
struct Interval {
    int start, end;
};
vector<Interval> intervals;
sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
    return a.start < b.start || (a.start == b.start && a.end < b.end);
});
```

### Technique 3: Greedy After Sorting
```cpp
// Activity selection: choose maximum non-overlapping intervals
sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
    return a.end < b.end;  // Sort by end time
});
int count = 0, lastEnd = INT_MIN;
for (const auto& interval : intervals) {
    if (interval.start >= lastEnd) {
        count++;
        lastEnd = interval.end;
    }
}
```

### Technique 4: Two Pointers
```cpp
// Two sum: find pair that sums to target
sort(arr.begin(), arr.end());
int left = 0, right = arr.size() - 1;
while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) return true;
    if (sum < target) left++;
    else right--;
}
return false;
```

## Sorting Algorithm Implementations

For educational purposes, students might implement:

### Insertion Sort - O(n²)
```cpp
void insertion_sort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

### Selection Sort - O(n²)
```cpp
void selection_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}
```

### Merge Sort - O(n log n)
```cpp
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

## Common Patterns

1. **Sort + Greedy**: Sort by one criterion, greedily select
2. **Sort + Two Pointers**: Sort then use left/right pointers
3. **Sort + Binary Search**: Sort once, binary search many times
4. **Stable Sort**: When relative order of equal elements matters
5. **Partial Sort**: When only k smallest/largest elements needed

## Evaluation Criteria

When evaluating solutions:
1. ✅ Uses `std::sort()` appropriately
2. ✅ Chooses correct sorting strategy (stable vs unstable)
3. ✅ Implements custom comparators correctly
4. ✅ Recognizes when sorting helps solve the problem
5. ✅ Understands time complexity with sorting (O(n log n))
6. ✅ Can implement basic sorting algorithms manually
7. ❌ Still should not use stack/queue/linked list/deque

## Notes

- `std::sort()` is typically quicksort or introsort: O(n log n) average, O(n²) worst
- `std::stable_sort()` preserves order of equal elements: typically mergesort
- After sorting, many problems become easier (duplicates, pairs, ranges)
- Sorting changes the complexity budget: now have O(n log n) available
