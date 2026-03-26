class TreeTwo:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right
        self.parent = None
    def setParent(self):
        if self.left:
            self.left.parent = self
            self.left.setParent()
        if self.right:
            self.right.parent = self
            self.right.setParent()
    def getRoot(self):
        node = self
        while node.parent:
            node = node.parent
        return node
    def getUp(self):
        depth = 0
        node = self
        while node.parent:
            depth += 1
            node = node.parent
        return depth
    def getUnder(self):
        if not self.left and not self.right:
            return 0
        left_depth = self.left.getUnder() if self.left else 0
        right_depth = self.right.getUnder() if self.right else 0
        return max(left_depth, right_depth) + 1

class BTW(TreeTwo):
    def __init__(self, x, left=None, right=None):
        super().__init__(x, left, right)
    
    def find(self, x):
        if self.val == x:
            return self
        elif x < self.val:
            if self.left:
                return self.left.find(x)
        else:
            if self.right:
                return self.right.find(x)
        return None
    
    def contain(self, x):
        return self.find(x) is not None
    
    def add(self, x):#left < root < right
        if(self.contain(x)):
            return False
        if self.left is None and self.right is None:
            if x < self.val:
                self.left = BTW(x)
                self.left.parent = self
            else:
                self.right = BTW(x)
                self.right.parent = self
        else:
            if x < self.val:
                if self.left:
                    self.left.add(x)
                else:
                    self.left = BTW(x)
                    self.left.parent = self
            else:
                if self.right:
                    self.right.add(x)
                else:
                    self.right = BTW(x)
                    self.right.parent = self
        self.balance()
        return True

    def delete(self, x):
        node = self.find(x)
        if node.left is None and node.right is None:
            if node.parent.left == node:
                node.parent.left = None
            else:
                node.parent.right = None
        elif node.left is None:
            if node.parent.left == node:
                node.parent.left = node.left
            else:
                node.parent.right = node.left
        elif node.right is None:
            if node.parent.left == node:
                node.parent.left = node.right
            else:
                node.parent.right = node.right
        else:
            if node.parent.left == node:
                pass
            else:
                pass
        return True
    
    def isBalanced(self):
        left_depth = self.left.getUnder() if self.left else 0
        right_depth = self.right.getUnder() if self.right else 0
        if abs(left_depth - right_depth) > 1:
            return False
        left_balanced = self.left.isBalanced() if self.left else True
        right_balanced = self.right.isBalanced() if self.right else True
        return left_balanced and right_balanced
    
    def balance(self):
        if self.isBalanced():
            return self
        
        