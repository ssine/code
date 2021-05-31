/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     next: Node | null
 *     random: Node | null
 *     constructor(val?: number, next?: Node, random?: Node) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *         this.random = (random===undefined ? null : random)
 *     }
 * }
 */

function copyRandomList(head: Node | null): Node | null {
  const mp = new WeakMap() // old node -> new node

  const gen = cur => {
    if (cur) {
      mp.set(cur, new Node(cur.val))
      gen(cur.next)
      return mp.get(cur)
    }
  }
  const newHead = gen(head) || null

  const attach = (cur, newCur) => {
    if (cur) {
      newCur.next = mp.get(cur.next) || null
      newCur.random = mp.get(cur.random) || null
      attach(cur.next, newCur.next)
    }
  }
  attach(head, newHead)

  return newHead
}
