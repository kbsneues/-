#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct TreeNode {
	char data[50];
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;

typedef struct {
	element stack[100];
	int top;
}StackType;

void initStack(StackType* s) {
	s->top = -1;
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

void push(StackType* s, element item) {
	if (is_full(s)) return;
	s->stack[++s->top] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) exit(1);
	return (s->stack[s->top--]);
}

preorder_iter(TreeNode* root) {
	
	StackType s;
	initStack(&s);

	while (1) {
		
		for (; root; root = root->left) {
			printf("%s\n", root->data);
			push(&s, root);
		}
		
		if (is_empty(&s)) {
			printf("\nEnd of Tree\n");
			break;
		}

		root = pop(&s);
		root = root->right;

	}
}

void main() {
	
	TreeNode n3 = {" 1.1. �˰���",NULL,NULL};
	TreeNode n4 = {" 1.2. UNIX ���α׷���",NULL,NULL};
	TreeNode n2 = {"1. �����ʼ�",&n3,&n4};

	TreeNode n6 = {" 2.1. Ȯ���� ���",NULL,NULL};
	TreeNode n7 = {" 2.2. ������ ���α׷���",NULL,NULL};
	TreeNode n5 = {"2. ��������",&n6,&n7};

	TreeNode n1 = {"�躸�� 2020�� ��������",&n2,&n5};

	TreeNode* root = &n1;

	preorder_iter(root);

}