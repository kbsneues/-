#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char sub[100]; // ����� 
	char pro[100]; // ��米���� 
	char score[20]; // ���� 
}sub_info;

sub_info* allocMem(int n) {

	sub_info* p;

	p = (sub_info*)malloc(sizeof(sub_info) * n);

	if (p == NULL) {
		printf("���� �߻�\n"); exit(1);
	}

	return p;
}

void get_info(sub_info* p, int n) {

	for (int i = 0; i < n; i++) {
		printf("����� : "); getchar(); gets(p[i].sub);
		printf("��� ������ : "); scanf("%s", p[i].pro);
		printf("���� : "); scanf("%s", p[i].score);
	}
}

int main() {

	int sub_num; // ������ ���� 
	sub_info* p; // ����ü sub_info�� ����Ű�� ����ü ������ p 

	printf("������û�� ������ ������ �Է��ϼ��� : ");
	scanf("%d", &sub_num);

	p = allocMem(sub_num); // p�� �����ּҸ� ������. p�� �迭ó�� ��� �����ϴ�

	get_info(p, sub_num); // ������û ���� �ۼ� 

	printf("------------- ������û ���� ---------------\n");

	for (int i = 0; i < sub_num; i++) {
		printf("����� : %s\n", p[i].sub);
		printf("��� ������ : %s\n", p[i].pro);
		printf("���� : %s\n\n", p[i].score);
	}

	free(p);

	return 0;

}