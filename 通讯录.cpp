#include<stdio.h>
#include<string.h>
void swi(struct entry *p, struct entry *q);
int lookup (struct entry student[], char search[], int entries);
void sort(struct entry *p);
struct entry
{
	char name[15];
	char bphone[20];
	char sphone[10];
};
void sort(struct entry *p) 
{
	int i, j;
	for (j = 0; j < 49; j++)
		for (i = 0; i < 49 - j; i++)
		{
			if (strcmp((p + i) -> name, (p + 1 + i) -> name) == 1)
				swi(p + i, p + 1 + i);
		}
} 
void swi(struct entry *p, struct entry *q)
{
	struct entry temp;
	temp = *q;
	*q = *p;
	*p = temp;
}
int lookup(struct entry student[], char search[], int entries)
{
	int low = 0;
	int high = entries - 1;
	int mid, result;
	
	while (low <= high)
	{
		mid = (low + high) / 2;
		result = strcmp(student[mid].name, search);
		
		if (result == -1)
			low = mid + 1;
		else if (result == 1)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int entries = 50;
	char name[15];
	int entry;
	struct entry student[50] = {
		{"����", "����", "�̺�"}
	};//����ԭ������ʮ���������ţ��̺ŵĽṹ�� �����漰������˽��ȫ��ɾ���� 
	sort(student);
	printf("������������");
	scanf ("%14s", name);
	
	entry = lookup (student, name, entries);
	
	if (entry != -1)
		printf("���ţ�%s �̺ţ�%s", student[entry].bphone, student[entry].sphone);
	else
		printf("���޴��ˣ�~������~��\n");
	return 0;
}

