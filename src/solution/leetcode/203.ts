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

function removeElements(head: ListNode | null, val: number): ListNode | null {
  const rm = (cur: ListNode | null) => {
    if (!cur) return null
    if (cur.val === val) return rm(cur.next)
    cur.next = rm(cur.next)
    return cur
  }
  return rm(head)
}
