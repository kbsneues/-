#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// �ݺ����� Ž�� �Լ�
TreeNode* search(TreeNode* node, int key) {
	while (node != NULL) {
		if (key == node->key)
			return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL; // Ž���� ������ ��� NULL ��ȯ 
}

// ������� Ž�� �Լ� 
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* new_node(element item) {
	TreeNode* p;
	p = (TreeNode*)malloc(sizeof(TreeNode));
	p->key = item;
	p->left = p->right = NULL;
	return p;
}

// ����Ž��Ʈ�������� ���Կ��� - �ݺ��� �̿� 
TreeNode* insert_node(TreeNode* root, element key) {
	TreeNode* p, * t; // p�� �θ� ���, t�� ������
	TreeNode* node; // node�� ���ο� ���

	t = root; p = NULL;

	while (t != NULL) { 
		if (key == t->key) return root;
		p = t; // t�� �θ���� �ٲ۴�
		if (key < t->key) t = t->left;
		else t = t->right;
	}

	// node�� �ϳ� ����� key�� �߰�
	node = new_node(key);

	if (p == NULL)
		root = node;
	else {
		if (key < p->key) p->left = node;
		else p->right = node;
	}

	return root;

}

// ���� Ž��Ʈ�������� ���� ���� - ��� ���
TreeNode* insert_node(TreeNode* node, int key) {
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 

	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�.
	return node;
}