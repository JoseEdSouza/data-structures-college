def insertion_sort(array: list, beg: int, end: int) -> list:

    def isSorted() -> bool:
        for i in range(beg, end):
            if array[i] > array[i+1]:
                return False
        return True

    def insert(beg:       int, end: int):
        key_element = array[end]
        index_to_compare = end-1
        while (index_to_compare >= beg and array[index_to_compare] > key_element):
            array[index_to_compare+1] = array[index_to_compare]
            index_to_compare -= 1
        array[index_to_compare+1] = key_element

    begin = beg
    ending = end
    while (not isSorted()):
        pass

    return array
