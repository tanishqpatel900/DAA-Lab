# DAA-Lab

Design and Analysis of Algorithms lab programs in C.

Tanishq Patel — PRN 26070521506

## Compile and run

```sh
gcc program.c -o program
./program
```

Every program reads its input from stdin and prints prompts telling you what to enter.

## Programs

| Topic | Program | Complexity |
|---|---|---|
| **Searching** | [Linear Search](01-Searching/linear_search.c) | O(n) |
| | [Binary Search (iterative + recursive)](01-Searching/binary_search.c) | O(log n) |
| **Sorting** | [Bubble Sort](02-Sorting/bubble_sort.c) | O(n²) |
| | [Selection Sort](02-Sorting/selection_sort.c) | O(n²) |
| | [Insertion Sort](02-Sorting/insertion_sort.c) | O(n²) |
| | [Shell Sort](02-Sorting/shell_sort.c) | ~O(n^1.5) |
| | [Merge Sort](02-Sorting/merge_sort.c) | O(n log n) |
| | [Quick Sort](02-Sorting/quick_sort.c) | O(n log n) avg |
| | [Heap Sort](02-Sorting/heap_sort.c) | O(n log n) |
| | [Counting Sort](02-Sorting/counting_sort.c) | O(n + k) |
| | [Radix Sort](02-Sorting/radix_sort.c) | O(d(n + 10)) |
| **Divide and Conquer** | [Max-Min](03-Divide-and-Conquer/max_min.c) | O(n) |
| | [Strassen's Matrix Multiplication](03-Divide-and-Conquer/strassen_matrix.c) | O(n^2.81) |
| | [Fast Power](03-Divide-and-Conquer/power.c) | O(log n) |
| | [Maximum Subarray Sum](03-Divide-and-Conquer/max_subarray.c) | O(n log n) |
| **Greedy** | [Fractional Knapsack](04-Greedy/fractional_knapsack.c) | O(n log n) |
| | [Activity Selection](04-Greedy/activity_selection.c) | O(n log n) |
| | [Job Sequencing with Deadlines](04-Greedy/job_sequencing.c) | O(n²) |
| | [Huffman Coding](04-Greedy/huffman_coding.c) | O(n log n) |
| | [Prim's MST](04-Greedy/prims_mst.c) | O(V²) |
| | [Kruskal's MST](04-Greedy/kruskals_mst.c) | O(E log E) |
| | [Dijkstra's Shortest Path](04-Greedy/dijkstra.c) | O(V²) |
| **Dynamic Programming** | [0/1 Knapsack](05-Dynamic-Programming/knapsack_01.c) | O(nW) |
| | [Longest Common Subsequence](05-Dynamic-Programming/lcs.c) | O(mn) |
| | [Longest Increasing Subsequence](05-Dynamic-Programming/lis.c) | O(n²) |
| | [Matrix Chain Multiplication](05-Dynamic-Programming/matrix_chain_multiplication.c) | O(n³) |
| | [Optimal Binary Search Tree](05-Dynamic-Programming/optimal_bst.c) | O(n³) |
| | [Coin Change](05-Dynamic-Programming/coin_change.c) | O(n · amount) |
| | [Floyd-Warshall (All Pairs Shortest Path)](05-Dynamic-Programming/floyd_warshall.c) | O(V³) |
| | [Bellman-Ford](05-Dynamic-Programming/bellman_ford.c) | O(VE) |
| | [Travelling Salesman (bitmask DP)](05-Dynamic-Programming/travelling_salesman.c) | O(n² 2ⁿ) |
| **Backtracking** | [N-Queens](06-Backtracking/n_queens.c) | O(n!) |
| | [Sum of Subsets](06-Backtracking/sum_of_subsets.c) | O(2ⁿ) |
| | [Graph Colouring](06-Backtracking/graph_coloring.c) | O(mⁿ) |
| | [Hamiltonian Cycle](06-Backtracking/hamiltonian_cycle.c) | O(n!) |
| | [Subset Generation](06-Backtracking/subset_generation.c) | O(2ⁿ) |
| **Branch and Bound** | [0/1 Knapsack](07-Branch-and-Bound/knapsack_bnb.c) | O(2ⁿ) worst |
| | [Job Assignment](07-Branch-and-Bound/job_assignment_bnb.c) | O(n!) worst |
| **Graph Algorithms** | [Breadth First Search](08-Graph-Algorithms/bfs.c) | O(V²) |
| | [Depth First Search](08-Graph-Algorithms/dfs.c) | O(V²) |
| | [Topological Sort](08-Graph-Algorithms/topological_sort.c) | O(V²) |
| | [Warshall's Transitive Closure](08-Graph-Algorithms/warshall_transitive_closure.c) | O(V³) |
| **String Matching** | [Naive String Matching](09-String-Matching/naive_string_match.c) | O(nm) |
| | [Knuth-Morris-Pratt](09-String-Matching/kmp.c) | O(n + m) |
| | [Rabin-Karp](09-String-Matching/rabin_karp.c) | O(n + m) avg |
