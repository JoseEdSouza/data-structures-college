import time
import random

def insertion_sort(array: list) -> list:
    def insert(_beg: int, _end: int):
        if _beg >= _end:
            return
        insert(_beg, _end - 1)
        key_element = array[_end]
        index_to_compare = _end - 1

        while index_to_compare >= _beg and array[index_to_compare] > key_element:
            array[index_to_compare + 1] = array[index_to_compare]
            index_to_compare -= 1

        array[index_to_compare + 1] = key_element

    insert(0, len(array)-1)

    return array

random_array = []
for i in range(random.randrange(start = 1,stop=100)):
    random_array.append(random.randint(1,1000))
print(*random_array,sep=' ')
start = time.time()
print(*insertion_sort(random_array), sep=' ')
delta_time = time.time() - start
print('delta time = ',delta_time)