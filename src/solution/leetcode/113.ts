/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function pathSum(root: TreeNode | null, targetSum: number): number[][] {
  const dfs = (root: TreeNode, currentSum: number): number[][] => {
    if (!root) return []
    if (!root.left && !root.right && root.val + currentSum === targetSum) {
      return [[root.val]]
    }
    const paths = [].concat(dfs(root.left, root.val + currentSum), dfs(root.right, root.val + currentSum))
    for (const path of paths) {
      path.unshift(root.val)
    }
    return paths
  }
  return dfs(root, 0)
}
