/*

https://www.geeksforgeeks.org/closest-leaf-to-a-given-node-in-binary-tree/

*/

void findLeafDown(Node *root, int lev, int &minDist) {
	// base case
	if (root == NULL) return;
	// If this is a leaf node, then check if it is closer
	// than the closest so far
	if (root->left == NULL && root->right == NULL) {
		if (lev < minDist) {
			minDist = lev;
		}
		return;
	}
	// Recur for left and right subtrees
	findLeafDown(root->left, lev + 1, minDist);
	findLeafDown(root->right, lev + 1, minDist);
}

// This function finds if there is closer leaf to x through parent node.
int findThroughParent(Node *root, Node *x, int &minDist) {
	// Base cases
	if (root == NULL) return -1;
	if (root == x) return 0;

	// Search x in left subtree of root
	int l = findThroughParent(root->left, x,  minDist);

	// If left subtree has x
	if (l != -1) {
		// Find closest leaf in right subtree
		findLeafDown(root->right, l + 2, minDist);
		return l + 1;
	}

	// Search x in right subtree of root
	int r = findThroughParent(root->right, x, minDist);

	// If right subtree has x
	if (r != -1) {
		// Find closest leaf in left subtree
		findLeafDown(root->left, r + 2, minDist);
		return r + 1;
	}

	return -1;
}

// Returns minimum distance of a leaf from given node x
int minimumDistance(Node *root, Node *x) {
	// Initialize result (minimum distance from a leaf)
	int minDist = 100000;
	// Find closest leaf down to x
	findLeafDown(x, 0, minDist);

	// See if there is a closer leaf through parent
	findThroughParent(root, x, minDist);

	return minDist;
}