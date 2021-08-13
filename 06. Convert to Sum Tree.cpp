/*

https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1

*/

int solve(Node *root) {
	if (!root) return 0;

	int val = root->data;
	int leftSum = solve(root->left);
	int rightSum = solve(root->right);
	root->data = leftSum + rightSum;

	return val + root->data;
}

void toSumTree(Node *root) {
	solve(root);
}