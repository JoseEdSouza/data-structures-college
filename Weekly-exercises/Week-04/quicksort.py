# def partition(l:list[int],beg:int,end:int) -> int:
#     i = beg - 1
#     pivot = l[end]
#     for j in range(beg,end):
#         if l[j] <= pivot:
#             i+=1
#             temp = l[i]
#             l[i] = l[j]
#             l[j] = temp
#     temp = l[i+1]
#     l[i+1] = l[end]
#     l[end] = temp
#     return i+1

# def quicksort(l:list[int],beg:int,end:int):
#     if(beg >= end): return l
#     pivot_index = partition(l,beg,end)
#     quicksort(l,beg,pivot_index -1)
#     quicksort(l,pivot_index+1,end)

# teste = [8,9,7,5,6,4,3,2,1]
# quicksort(teste,0,len(teste)-1)
# print(teste)

# def partition(l:list[int],beg:int,end:int) -> int:
#     i = end
#     pivot = l[beg]
#     for j in range(end,beg,-1):
#         if l[i] > pivot:
#             temp = l[i]
#             l[i] = l[j]
#             l[j] = temp
#             i-=1
#     temp = l[i]
#     l[i] = l[beg]
#     l[beg] = temp
#     return i

# def quicksort(l:list[int],beg:int,end:int):
#     if(beg >= end): return l
#     pivot_index = partition(l,beg,end)
#     quicksort(l,beg,pivot_index -1)
#     quicksort(l,pivot_index+1,end)

# teste = [8,9,7,5,6,4,3,2,1]
# quicksort(teste,0,len(teste)-1)
# print(teste)


def partition(l: list[int], beg: int, end: int) -> int:
    i = beg+1
    j = end
    pivot = l[beg]
    while i <= j:
        if l[i] <= pivot:
            i += 1
        elif l[j] > pivot:
            j -= 1
        else:
            l[i], l[j] = l[j], l[i]
            i+=1
            j-=1
    l[j], l[beg] = l[beg], l[j]
    return j


def quicksort(l: list[int], beg: int, end: int):
    if (beg >= end):
        return l
    pivot_index = partition(l, beg, end)
    quicksort(l, beg, pivot_index - 1)
    quicksort(l, pivot_index+1, end)


teste = [8, 9, 7, 5, 6, 4, 3, 2, 1]
quicksort(teste, 0, len(teste)-1)
print(teste)
