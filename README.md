# Moglix Coding Assignment

## Problem Statement

Given a string consisting of only `'('` and `')'`, determine the **length of the longest valid (well-formed) parentheses substring**.

---

## Solution Approaches

### 1. Stack-Based Approach

#### Algorithm
- Initialize a stack and push `-1` as the base index.
- Traverse the string from left to right.
- If the current character is `'('`, push its index onto the stack.
- If the current character is `')'`:
  - Pop the top element.
  - If the stack becomes empty, push the current index as the new base.
  - Otherwise, calculate the length of the current valid substring as:
    ```
    current_length = current_index - stack.top()
    ```
  - Update the maximum length if needed.

#### Time Complexity
- **O(n)**

#### Space Complexity
- **O(n)** (stack stores indices)

---

### 2. Optimized Two-Pass Approach (Implemented)

This solution avoids using any extra data structure and uses **constant extra space**.

#### Algorithm

### First Pass (Left → Right)

- Maintain two counters:
  - `left` for `'('`
  - `right` for `')'`
- Traverse the string from left to right.
- Increment the corresponding counter.
- If `left == right`, update:
  ```
  maxLength = max(maxLength, 2 × right)
  ```
- If `right > left`, reset both counters to `0`.

### Second Pass (Right → Left)

- Reset both counters.
- Traverse the string from right to left.
- Increment counters similarly.
- If `left == right`, update the maximum length.
- If `left > right`, reset both counters.

The second pass is necessary to correctly handle cases where extra opening parentheses remain unmatched.

#### Time Complexity
- **O(n)**

#### Space Complexity
- **O(1)**

---

## Example

### Input
```
)()())
```

### Output
```
4
```

Explanation:

The longest valid parentheses substring is:

```
()()
```

whose length is **4**.

---

## Language Used

- C++

---

## Author
**Animesh Singh**
**animesh0518@gmail.com**
