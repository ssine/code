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

function generateTrees(n: number): Array<TreeNode | null> {
  const gen = (start: number, len: number): Array<TreeNode | null> => {
    if (len === 0) return [null]
    if (len === 1) return [new TreeNode(start)]
    return [...Array(len).keys()]
      .map(p => {
        const res = [],
          l = gen(start, p),
          r = gen(start + p + 1, len - p - 1)
        l.forEach(lnode => {
          r.forEach(rnode => {
            res.push(new TreeNode(start + p, lnode, rnode))
          })
        })
        return res
      })
      .flat(1)
  }
  return gen(1, n)
}
