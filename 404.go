/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumOfLeftLeaves(root *TreeNode) int {
    return InOrderWithSide(root, 1)
}

func InOrderWithSide(node *TreeNode, side int) int {
    if node == nil {
        return 0
    }

    if node.Right == nil && node.Left == nil {
        if side == 0 {
            return node.Val
        } else {
            return 0
        }
    }

    var leftVal, rightVal int

    if node.Left != nil {
        leftVal = InOrderWithSide(node.Left, 0)
    }

    if node.Right != nil {
        rightVal = InOrderWithSide(node.Right, 1)
    }

    return leftVal + rightVal
}
