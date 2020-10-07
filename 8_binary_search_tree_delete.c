#include <stdio.h>
#include <stdlib.h>

// ����Ž��Ʈ�������� �������� - �ݺ��� �̿�

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* delete_node(TreeNode* root, element key) {
	TreeNode* p, * t, * child, * succ, * succ_p;
	// key�� ���� ��� t�� Ž��, p�� t�� �θ��� 
	p = NULL; t = root;
	// key�� ���� ��� t�� Ž���Ѵ�.
	while (t != NULL && t->key != key) { // ��� t�� ���� �̰ų� ���ϴ� ���� ã�� �� ���� Ż��
		p = t;
		t = (key < t->key) ? t->left : t->right;
	}

	if(t == NULL) { // Ž���� ����� ������ t�� NULL�̸� Ʈ�� �ȿ� key�� ����
		printf("key is not in the tree");
		return root;
	}

	// 2. ������ ��� ���� ��ũ�� �����Ѵ�.
	// case 1 : �ܸ������ ��� : �θ��尡 �ִ��� �������� ���� �ٸ��� 
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) { // �θ����� �ڽ��ʵ带 NULL�� �����
			if (p->left == t)
				p->left = NULL;
			else p->right = NULL;
		}
		else // ���� �θ��尡 NULL�̸�?
			root = NULL; // �����Ǵ� ��尡 ��Ʈ
	}
	// case 2 : �ϳ��� �ڽĸ� ������ ��� 
	else if ((t->left == NULL) || (t->right == NULL)) {
		// t�� �ڽ� ����� �ּҸ� ��´� 
		child = (t->left != NULL) ? t->left : t->right;

		// �θ� �ڽİ� ���� 
		if (p != NULL) {
			if (p->left == t) p->left = child;
			else p->right = child;
		}
		else // ���� �θ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ 
			root = child;
	}

	// case 3 : �ΰ��� �ڽ��� ������ ��� 

	else { // ������ ����Ʈ������ �ļ��ڸ� ã�´� 
		succ_p = t; succ = t->right;
		// �ļ��ڸ� ã�Ƽ� ��� �������� �̵� 
		while (succ->left != NULL) {
			succ_p = succ; succ = succ->left;
		}
		// �ļ����� �θ�� �ڽ��� ���� 
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;

		// �ļ��ڰ� ���� Ű���� ���� ��忡 ������ ���� 
		t->key = succ->key;
		// ������ �ļ��� ������ ���� ������ ���� 
		t = succ;
	}
	free(t);
	return root; // 3. ������ ��带 free ��Ű��, root�� ��ȯ�Ѵ�
}


