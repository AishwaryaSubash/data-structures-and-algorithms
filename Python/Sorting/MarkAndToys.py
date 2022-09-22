"""
7 50
1 12 5 111 200 1000 10
"""
# Python program for implementation of Quicksort Sort

# This implementation utilizes pivot as the last element in the nums list
# It has a pointer to keep track of the elements smaller than the pivot
# At the very end of partition() function, the pointer is swapped with the pivot
# to come up with a "sorted" nums relative to the pivot


def partition(l, r, nums):
	# Last element will be the pivot and the first element the pointer
	pivot, ptr = nums[r], l
	for i in range(l, r):
		if nums[i] <= pivot:
			# Swapping values smaller than the pivot to the front
			nums[i], nums[ptr] = nums[ptr], nums[i]
			ptr += 1
	# Finally swapping the last element with the pointer indexed number
	nums[ptr], nums[r] = nums[r], nums[ptr]
	return ptr

# With quicksort() function, we will be utilizing the above code to obtain the pointer
# at which the left values are all smaller than the number at pointer index and vice versa
# for the right values.


def quicksort(l, r, nums):
	if len(nums) == 1: # Terminating Condition for recursion. VERY IMPORTANT!
		return nums
	if l < r:
		pi = partition(l, r, nums)
		quicksort(l, pi-1, nums) # Recursively sorting the left values
		quicksort(pi+1, r, nums) # Recursively sorting the right values
	return nums




def maximumToys(prices, k):
    prices = quicksort(0, len(prices)-1, prices)
    
    
    # Bubble sort
    # for i in range(len(prices)):            
    #     for j in range(i,len(prices)):
    #         if prices[i]>prices[j]:
    #             temp = prices[i]
    #             prices[i] = prices[j]
    #             prices[j] = temp
    cost = 0
    count = 0
    for i in prices:
        if cost + i <= k:
            cost += i
            count +=1
        else:
            break
    return count

first_multiple_input = input().rstrip().split()
n = int(first_multiple_input[0])
k = int(first_multiple_input[1])
prices = list(map(int, input().rstrip().split()))

result = maximumToys(prices, k)
print(result)