class Solution:

  def longestPalindrome(self, s: str) -> str:
    padded = f"#{'#'.join(s)}#"
    l = []
    left_most = 0
    left_most_idx = 0
    max_len = -1
    max_str = ''
    for idx, c in enumerate(padded):
      x = 0
      if idx < left_most:
        x = min(l[2 * left_most_idx - idx], left_most - idx - 1)
      while idx - x >= 0 and idx + x < len(padded) and padded[idx - x] == padded[idx + x]:
        x += 1
      x -= 1
      if idx + x > left_most:
        left_most = idx + x
        left_most_idx = idx
      if x > max_len:
        max_len = x
        max_str = padded[idx - x:idx + x + 1]
      l.append(x)
    return max_str.replace('#', '')
