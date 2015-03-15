TODO:
    1. check if a binary tree is balanced
    2. Given a sorted array in increasing order, write algorithm to create binary tree with minimal height
    3. Given a binary tree, create linked list of all nodes at each depth
    (if have a tree with depth D, will have D linked list!)
    4. Write algorithm to find the next node of a given node in a BST where each node has a link to the parent
    5. Design algorithm to find first common ancestor in a binary tree (not necessarily BST!)
    Avoid storing additional nodes in data structure.
    6. Given 2 binary tree, where  BT1 > BT2 , decide if BT2 is a subtree of BT1.
    7. Given a binary tree where each node contains a value. Design an algorithm to print all paths which sum up
    to that value. Note: It can be any path in the tree and does not have to start at root (refer to coding interview)
    8.

    10. Print all nodes in a binary tree at level k
print(tree root , int level)
Method1: BFS.
Method2:
    We can also do a simple post-order traversal.

    void printNodesAtGivenLevel(Node node, final int requiredLevel, int currLevel){
        if(node != null){
            if(currLevel < requiredLevel){
                printNodesAtGivenLevel(node.left, requiredLevel, currLevel + 1);
                printNodesAtGivenLevel(node.right, requiredLevel, currLevel + 1);
            }
            else if(currLevel == requiredLevel){
                System.out.println(node.data);
            }
        }
    }

//call the function as printNodesAtGivenLevel(root, n, 1);
