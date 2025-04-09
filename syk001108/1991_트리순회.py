import sys

N = int(sys.stdin.readline().strip())
tree = {} # 파이썬에서 트리 구현하는 방법-> 딕셔너리 사용 {"root" : ("left","right")}

for _ in range(N):
    root, left, right = sys.stdin.readline().strip().split()
    tree[root] = (left, right) # 딕셔너리 key->root, value->자식들

# 전위 순회: 루트-> 왼쪽-> 오른쪽
def preorder(node):
    if node == '.':
        return ''
    left, right = tree[node]
    return node + preorder(left) + preorder(right)

# 중위 순회: 왼쪽-> 루트-> 오른쪽
def inorder(node):
    if node == '.':
        return ''
    left, right = tree[node]
    return inorder(left) + node + inorder(right)

# 후위 순회: 왼쪽-> 오른쪽-> 루트
def postorder(node):
    if node == '.':
        return ''
    left, right = tree[node]
    return postorder(left) + postorder(right) + node

# A가 루트 노드
print(preorder('A'))
print(inorder('A'))
print(postorder('A'))
