"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution: 
    visited: Dict['Node', 'Node'] = {}
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return node
        if self.visited.get(node):
            return self.visited[node]
        new_node = Node(node.val)
        self.visited[node] = new_node
        for neighbor in node.neighbors:
            new_node.neighbors.append(self.cloneGraph(neighbor))
        return new_node