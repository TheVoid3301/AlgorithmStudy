/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */
var visited = make(map[*Node]*Node)

func cloneGraph(node *Node) *Node {
	if node == nil {
		return node
	}
	if visited[node] != nil {
		return visited[node]
	}
	clone := &Node{Val: node.Val, Neighbors: make([]*Node, 0)}
	visited[node] = clone
	for _, neighbor := range node.Neighbors {
		clone.Neighbors = append(clone.Neighbors, cloneGraph(neighbor))
	}
	return clone
}