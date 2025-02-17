# Push Swap

Push Swap is a sorting algorithm project from School 42. The goal is to sort a stack of integers with the least number of operations using a limited set of stack manipulation commands.

## Table of Contents
- [Overview](#overview)
- [Allowed Operations](#allowed-operations)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Evaluation](#evaluation)
- [Author](#author)

## Overview
The project consists of writing a program that receives a list of integers and sorts them using two stacks (`a` and `b`) and a set of predefined operations. The program must be efficient in terms of the number of operations performed.

## Allowed Operations
The following operations are allowed:

- `sa` (swap a): Swap the first two elements of stack a.
- `sb` (swap b): Swap the first two elements of stack b.
- `ss` (swap a & b): Perform `sa` and `sb` simultaneously.
- `pa` (push a): Move the first element of stack b to stack a.
- `pb` (push b): Move the first element of stack a to stack b.
- `ra` (rotate a): Shift all elements of stack a up by one.
- `rb` (rotate b): Shift all elements of stack b up by one.
- `rr` (rotate a & b): Perform `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Shift all elements of stack a down by one.
- `rrb` (reverse rotate b): Shift all elements of stack b down by one.
- `rrr` (reverse rotate a & b): Perform `rra` and `rrb` simultaneously.

## Installation
Clone the repository and compile the project:

```sh
 git clone https://github.com/yourusername/push_swap.git
 cd push_swap
 make
```

## Usage
To run the program and sort numbers:

```sh
./push_swap 4 67 3 87 23
```

To check if the output is correct, you can use:

```sh
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

To count the number of operations used:

```sh
./push_swap 4 67 3 87 23 | wc -l
```

## Algorithm
The implementation should use an efficient algorithm based on the number of elements:

- **Small inputs (≤ 5 numbers):** Hardcoded sorting logic.
- **Larger inputs:** Optimized sorting using a variation of quicksort and radix sort.

The goal is to minimize the number of operations and stay within the project limits.

## Evaluation
The project is graded based on:
- Correctness (producing a sorted output for any valid input).
- Efficiency (minimizing the number of operations).
- Code quality and error handling.
- Compliance with 42's project requirements.

## Author
- **Your Name** - [GitHub Profile](https://github.com/abdelkabirelmajdoub)

