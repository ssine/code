class Solution:

  def jump(self, nums: List[int]) -> int:
    jp = [9999] * len(nums)
    jp[len(nums) - 1] = 0
    for i in reversed(range(0, len(nums))):
      if i + 1 >= len(nums):
        continue
      for j in range(i + 1, min(len(nums), i + nums[i] + 1)):
        jp[i] = min(jp[i], jp[j] + 1)
    return jp[0]
