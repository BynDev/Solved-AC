import sys

T = int(sys.stdin.readline().strip())

nums = [1, 1, 1]

for i in range(3, 100):
    nums.append(nums[i-2] + nums[i-3])

for _ in range(T):
    N = int(sys.stdin.readline().strip())

    print(nums[N-1])