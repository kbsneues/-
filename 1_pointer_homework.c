#include <stdio.h>
#include <stdlib.h>

int ent_integer(); // ����ڿ��� �� ���� ������ ó���� ������ ����� �Լ� 
int* arr_alloc(int); // �迭�� �������� �Ҵ� �޾� �� �����ּҸ� ��ȯ�ϴ� �Լ� 
void ent_array(int*, int); // �迭�� �����ּҿ� ������ ���� n���� ������ Ű����κ��� �Է¹޾� �迭�� �����ϴ� �Լ� 
double retur_ave(int*, int); // �迭�� �����ּҿ� ������ ���� n�� �Ű������� �޾� �� ����� ��ȯ�ϴ� �Լ� 

int ent_integer() {

	int kbs;
	printf("�� ���� ������ �Է��ұ��? : ");
	scanf("%d", &kbs);

	return kbs;
}

int* arr_alloc(int n) {

	int* kbs;
	kbs = (int*)malloc(sizeof(int) * n);
	if (kbs == NULL) {
		printf("���� �߻�"); exit(1);
	}

	return kbs;
}

void ent_array(int* p, int n) {

	for (int i = 0; i < n; i++) {
		printf("%d��° ���� �Է� : ", i + 1);
		scanf("%d", p + i);
	}

}

double retur_ave(int* p, int n) {

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += *(p + i);

	return (double)sum / n;

}

int main() {

	int n, * kbs;

	n = ent_integer();

	kbs = arr_alloc(n);

	ent_array(kbs, n);

	printf("�迭�� ����� %.2f", retur_ave(kbs, n));

	free(kbs);

	return 0;
}