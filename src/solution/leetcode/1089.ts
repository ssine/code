/**
 Do not return anything, modify arr in-place instead.
 */
function duplicateZeros(arr: number[]): void {
  let num_zeros = 0,
    bound,
    r
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === 0) num_zeros++
    bound = i
    r = i + num_zeros
    if (r >= arr.length) break
  }
  while (bound >= 0) {
    if (arr[bound] === 0) {
      r < arr.length && (arr[r] = 0)
      r - 1 < arr.length && (arr[r - 1] = 0)
      r -= 2
    } else {
      r < arr.length && (arr[r] = arr[bound])
      r--
    }
    bound--
  }
}
