import time
import random
import matplotlib.pyplot as plt

def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def compare_time_complexity():
    sizes = [10, 100, 1000, 10000, 100000, 1000000]
    quicksort_times = []
    insertion_sort_times = []

    for size in sizes:
        arr = [random.randint(0, 100) for _ in range(size)]

        start_time = time.time()
        sorted_arr_quick = quicksort(arr)
        end_time = time.time()
        quicksort_times.append(end_time - start_time)

        start_time = time.time()
        sorted_arr_insertion = insertion_sort(arr.copy())
        end_time = time.time()
        insertion_sort_times.append(end_time - start_time)

    return sizes, quicksort_times, insertion_sort_times

def plot_time_complexity():
    sizes, quicksort_times, insertion_sort_times = compare_time_complexity()

    plt.figure(figsize=(10, 6))
    plt.plot(sizes, quicksort_times, label='Quicksort')
    plt.plot(sizes, insertion_sort_times, label='Insertion Sort')
    plt.title('Time Complexity Comparison')
    plt.xlabel('Array Size (n)')
    plt.ylabel('Time (seconds)')
    plt.xscale('log')
    plt.yscale('log')
    plt.xticks(sizes, [str(size) for size in sizes])
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    plot_time_complexity()
