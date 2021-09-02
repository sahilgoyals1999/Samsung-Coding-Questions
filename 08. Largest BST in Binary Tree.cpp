/*

https://practice.geeksforgeeks.org/problems/largest-bst/1

https://www.youtube.com/watch?v=UGsJz8fSYp0

*/

MinMax helper(Node *root, int &maxSz) {
    if(!root) {
        MinMax curr;
        curr.mini = 10000000;
        curr.maxi = 0;
        curr.size = 0;
        curr.isBST = true;
        
        return curr;
    }
    
    MinMax leftChild = helper(root->left, maxSz);
    MinMax rightChild = helper(root->right, maxSz);
    
    MinMax curr;
    if(leftChild.isBST && rightChild.isBST && root->data > leftChild.maxi && root->data < rightChild.mini) {
        curr.mini = root->data < leftChild.mini ? root->data : leftChild.mini;
        curr.maxi = root->data > rightChild.maxi ? root->data : rightChild.maxi;
        curr.size = 1 + leftChild.size + rightChild.size;
        curr.isBST = true;
        
        if(maxSz < curr.size) maxSz = curr.size;
    }
    else {
        curr.mini = 0;
        curr.maxi = 0;
        curr.size = 0;
        curr.isBST = false;
    }
    
    return curr;
}

int largestBst(Node *root) {
    int maxSz = 0;
    
    MinMax x = helper(root, maxSz);
    
    return maxSz;
}
