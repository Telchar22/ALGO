from typing import List
import time
import math
import random

def LinearSearch(arr: List[float],x:float)->int:
    '''
    :param arr: input array
    :param x: element to search
    :return: index of searched elements in array
    '''
    tic = time.perf_counter()
    for i in range(len(arr)):
        if x == arr[i]:
            break
        if i == (len(arr) - 1) and x != arr[len(arr) - 1]:
            print(f'Element {x} isn\'t present in array!')
            i = None
            break
    toc = time.perf_counter()
    print(f"Function run time: {(toc - tic)*1000:0.4f} milliseconds")
    return i

def BinarySearch(arr: List[float],x:float)->int:
    '''
    :param arr: input array
    :param x: element to search
    :return: index of searched elements in array
    '''
    tic = time.perf_counter ()
    first = 0
    last = len(arr)-1
    mid = 0
    while first <= last:
        mid = (first+last)//2
        if arr[mid] > x:
            last = mid - 1
        elif arr[mid] < x:
            first = mid +1
        else:
            break
    toc = time.perf_counter()
    print(f"Function run time: {(toc - tic) * 1000:0.4f} milliseconds")
    if arr[mid] == x:
        return mid
    print(f'Element {x} isn\'t present in array!')
    return -1

if __name__ == '__main__':

    a = random.sample(range(-300000, 300000), 5000)
    a = sorted(a)
    print(LinearSearch(a,a[1304]))
    print(BinarySearch(a,a[1304]))
