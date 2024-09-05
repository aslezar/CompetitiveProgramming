arr = list(map(int, input().split()))
load = int(input())

arr = sorted(filter(lambda x: x != 0, arr), reverse=True)
    
left, right = 0, len(arr) - 1
ans = 0
    
while left <= right:
    if arr[left] + arr[right] <= load:
        right -= 1
    left += 1
    ans += 1

print(ans, end="")
