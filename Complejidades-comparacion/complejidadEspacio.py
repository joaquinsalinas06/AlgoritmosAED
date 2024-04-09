import matplotlib.pyplot as plt

def quicksort_space_complexity(n):
    return 1 if n <= 1 else 1 + quicksort_space_complexity(n // 2)

def insertion_sort_space_complexity(n):
    return 1

def plot_space_complexity():
    sizes = [10, 100, 1000, 10000, 100000, 1000000]
    quicksort_space = [quicksort_space_complexity(n) for n in sizes]
    insertion_sort_space = [insertion_sort_space_complexity(n) for n in sizes]

    plt.figure(figsize=(10, 6))
    plt.plot(sizes, quicksort_space, label='Quicksort')
    plt.plot(sizes, insertion_sort_space, label='Insertion Sort')
    plt.title('Space Complexity Comparison')
    plt.xlabel('Array Size (n)')
    plt.ylabel('Space Used')
    plt.xscale('log')
    plt.yscale('log')
    plt.xticks(sizes, [str(size) for size in sizes])
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    plot_space_complexity()
