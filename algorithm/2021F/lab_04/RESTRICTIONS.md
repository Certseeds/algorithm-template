# Lab 04 - Data Structure Restrictions

## Overview

Lab 04 introduces **linked lists** and related algorithms. This includes both custom linked list implementation and the standard library's `std::list`. Key techniques include two-pointer methods, fast-slow pointers, and linked list manipulation.

## Allowed Data Structures

### Everything from Lab 03, plus:

### New Linked List Capabilities
- **Custom ListNode**: Define and use custom linked list nodes
  ```cpp
  struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
  ```
- **`std::list`**: Doubly-linked list from STL
- **Doubly-linked lists**: Custom implementation with prev/next pointers

## Allowed Algorithms

### New in Lab 04

1. **Linked List Basics**
   - Create, traverse, insert, delete nodes
   - Reverse linked list (iterative and recursive)
   - Merge two sorted linked lists
   - Find middle of linked list
   - Detect cycles in linked list

2. **Two-Pointer Techniques**
   - Fast and slow pointers (Floyd's algorithm)
   - Find cycle start point
   - Find kth node from end
   - Remove nth node from end
   - Check if linked list is palindrome

3. **Linked List Manipulation**
   - Split linked list into parts
   - Rotate linked list
   - Partition linked list
   - Clone linked list with random pointers
   - Flatten multi-level linked list

## Restrictions

### Still NOT Allowed
- Stack (`std::stack`)
- Queue (`std::queue`)
- Deque (`std::deque`)
- Priority queue (`std::priority_queue`)
- Trees and graphs (coming in later labs)

### New Capabilities
- **Linked lists**: Full access to list operations
- **Pointer manipulation**: Deep understanding of pointers required
- **In-place algorithms**: Many linked list algorithms should be in-place

## Example Problems

### Problem Types Suitable for Lab 04

1. **Basic linked list operations** (lab_04_A)
   - Create linked list from array
   - Traverse and print
   - Insert at position
   - Delete node
   ```cpp
   ListNode* head = new ListNode(1);
   head->next = new ListNode(2);
   head->next->next = new ListNode(3);
   ```

2. **Reverse linked list** (lab_04_B)
   - Iterative reversal
   - Recursive reversal
   - Reverse between positions
   ```cpp
   ListNode* reverse(ListNode* head) {
       ListNode* prev = nullptr;
       ListNode* curr = head;
       while (curr) {
           ListNode* next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
       }
       return prev;
   }
   ```

3. **Cycle detection** (lab_04_C)
   - Floyd's cycle detection (fast-slow pointers)
   - Find cycle start
   ```cpp
   bool hasCycle(ListNode* head) {
       ListNode *slow = head, *fast = head;
       while (fast && fast->next) {
           slow = slow->next;
           fast = fast->next->next;
           if (slow == fast) return true;
       }
       return false;
   }
   ```

4. **Merge sorted lists** (lab_04_D)
   - Merge two sorted linked lists
   - Merge k sorted linked lists
   ```cpp
   ListNode* merge(ListNode* l1, ListNode* l2) {
       ListNode dummy(0);
       ListNode* tail = &dummy;
       while (l1 && l2) {
           if (l1->val < l2->val) {
               tail->next = l1;
               l1 = l1->next;
           } else {
               tail->next = l2;
               l2 = l2->next;
           }
           tail = tail->next;
       }
       tail->next = l1 ? l1 : l2;
       return dummy.next;
   }
   ```

5. **Find middle/kth from end** (lab_04_E)
   - Use fast-slow pointers
   - Find kth node from end with one pass
   ```cpp
   ListNode* findMiddle(ListNode* head) {
       ListNode *slow = head, *fast = head;
       while (fast && fast->next) {
           slow = slow->next;
           fast = fast->next->next;
       }
       return slow;
   }
   ```

6. **Using std::list** (lab_04_F, G)
   - Use STL's doubly-linked list
   - Bidirectional traversal
   - Efficient insert/delete in middle
   ```cpp
   std::list<int> mylist = {1, 2, 3, 4, 5};
   auto it = mylist.begin();
   std::advance(it, 2);  // Move to 3rd element
   mylist.insert(it, 10);  // Insert before 3rd element
   ```

## Solution Pattern

```cpp
#include <iostream>

// Custom ListNode definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper: Create linked list from vector
ListNode* createList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: Delete entire linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main algorithm
ListNode* solve(ListNode* head) {
    // Two-pointer example
    if (!head || !head->next) return head;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;  // Middle node
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    ListNode* head = createList(input);
    
    ListNode* result = solve(head);
    
    // Output result
    
    // Clean up
    deleteList(head);
    return 0;
}
```

## Learning Objectives

Students at this level should learn:
- **Pointer manipulation**: Deep understanding of pointer operations
- **Linked list vs array**: When to use each structure
- **Two-pointer technique**: Fast-slow pointers for cycle detection, finding middle
- **In-place algorithms**: Manipulate linked list without extra space
- **Memory management**: Proper allocation and deallocation
- **Edge cases**: Empty list, single node, cycles

## Key Techniques

### Technique 1: Fast-Slow Pointers (Floyd's Algorithm)
```cpp
// Detect cycle
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Find cycle start
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
```

### Technique 2: Reverse Linked List
```cpp
// Iterative
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Recursive
ListNode* reverseRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

### Technique 3: Remove Nth from End
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* first = &dummy;
    ListNode* second = &dummy;
    
    // Move first n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    // Move both until first reaches end
    while (first) {
        first = first->next;
        second = second->next;
    }
    
    // Remove nth from end
    ListNode* temp = second->next;
    second->next = second->next->next;
    delete temp;
    
    return dummy.next;
}
```

### Technique 4: Merge Two Sorted Lists
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
```

### Technique 5: Using std::list
```cpp
#include <list>

void useStdList() {
    std::list<int> mylist = {1, 2, 3, 4, 5};
    
    // Insert at front/back: O(1)
    mylist.push_front(0);
    mylist.push_back(6);
    
    // Insert at position: O(1) if iterator available
    auto it = mylist.begin();
    std::advance(it, 3);
    mylist.insert(it, 99);
    
    // Remove: O(1)
    mylist.remove(99);  // Remove all 99s
    
    // Traverse
    for (auto x : mylist) {
        std::cout << x << " ";
    }
}
```

## Common Patterns

1. **Dummy head**: Simplify edge cases when manipulating list
2. **Fast-slow pointers**: Find middle, detect cycles
3. **Two pointers with gap**: Find kth from end
4. **Recursive approach**: Often elegant for linked list problems
5. **In-place reversal**: Reverse without extra space

## Memory Management

**Important**: Always properly manage memory with custom linked lists!

```cpp
// Create
ListNode* node = new ListNode(1);

// Delete single node
delete node;

// Delete entire list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}
```

## std::list vs Custom ListNode

| Feature | std::list | Custom ListNode |
|---------|-----------|-----------------|
| Implementation | Doubly-linked | Usually singly-linked |
| Memory management | Automatic | Manual |
| Flexibility | Limited | Full control |
| Safety | Safer | More error-prone |
| Use case | General purpose | Algorithm practice, OJ |

## Evaluation Criteria

When evaluating solutions:
1. ✅ Uses linked lists appropriately
2. ✅ Implements two-pointer techniques correctly
3. ✅ Handles edge cases (empty list, single node)
4. ✅ Manages memory properly (no leaks)
5. ✅ Chooses in-place algorithms when appropriate
6. ✅ Understands time complexity: O(n) for most operations
7. ❌ Still should not use stack/queue/deque/priority_queue

## Common Edge Cases

- Empty list (`head == nullptr`)
- Single node (`head->next == nullptr`)
- Two nodes
- Cycle in list
- Operation on last node
- Removing head
- List with duplicate values

## Notes

- Linked lists have O(n) access time vs O(1) for arrays
- But O(1) insert/delete at known position vs O(n) for arrays
- Most linked list algorithms should be O(n) time, O(1) space
- Two-pointer technique is powerful and appears in many problems
