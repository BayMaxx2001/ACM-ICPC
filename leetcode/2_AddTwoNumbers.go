package main

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	ans := new(ListNode)
	curAns = ans
	sum := 0
	for l1 != nil || l2 != nil {
		if l1 != nil {
			sum = sum + l1.val
			l1 = l1.Next
		}
		if l2 != nil {
			sum = sum + l2.Val
			l2 = l2.Next
		}
		curAns.Next = &ListNode{
			sum % 10,
			nil,
		}
		curAns = curAns.Next
		sum = sum / 10
	}
	if sum > 0 {
		curAns.Next = &ListNode{sum, nil}
	}

	return ans.Next
}
