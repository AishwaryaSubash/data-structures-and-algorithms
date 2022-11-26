def largestRectangle(heights):
    maxera = 0
    stack = []  # (i,h)
    for i, h in enumerate(heights):
        start = i
        while stack and stack[-1][1] > h:
            index, height = stack.pop()
            maxera = max(maxera, (i - index) * height)
            start = index
        stack.append((start, h))
    for i, h in stack:
        maxera = max(maxera, h * (len(heights) - i))
    return maxera


print(largestRectangle([5, 3, 2, 4, 1]))
