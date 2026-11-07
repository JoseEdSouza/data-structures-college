
def bubble_sort(array: list) -> list:
    for i in range(len(array)-1):
        for j in range(len(array)-1-i):
            if array[j] > array[j+1]:
                array[j+1], array[j] = array[j], array[j+1]
    return array


print(bubble_sort([700,5,499,3]))