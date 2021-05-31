/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseBetween(head: ListNode | null, left: number, right: number): ListNode | null {
  if (!head || left === right) return head

  let endNode = null,
    afterEnd = null

  // return the node in [pos] after reversion
  const rev = (pos: number, curNode: ListNode, parent: ListNode): ListNode | null => {
    const next = curNode.next
    if (pos < left) {
      curNode.next = rev(pos + 1, curNode.next, curNode)
      return curNode
    } else if (pos === left) {
      rev(pos + 1, curNode.next, curNode)
      curNode.next = afterEnd
      return endNode
    } else if (left < pos && pos < right) {
      rev(pos + 1, curNode.next, curNode)
      curNode.next = parent
    } else if (pos === right) {
      endNode = curNode
      afterEnd = curNode.next
      curNode.next = parent
    }
  }

  return rev(1, head, null)
}
