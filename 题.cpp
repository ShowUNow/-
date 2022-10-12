#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct link_node
{
	datatype info;
	struct link_node* next;
}node;
//��ʼ��һ���ڵ����Ϊ10������
node* init(node h[10])
{
	node* p = &h[0];//ȡ������׵�ַ
	for (int i = 0; i < 10; i++)
	{
		p->info = i + 1;
		if (i < 9)
		{
			//��p�ĵ�ַ���ݵ���һ��Ԫ����
			p->next = &h[i + 1];
			p = &h[i + 1];
		}
		else
		{
			//��������һ���ڵ�
			p->next = NULL;
		}
	}
	return h;
}
//����������y���ڵĽڵ�
node* find(node* head, datatype y)
{
	//�ӵ�һ���ڵ㿪ʼ�Ƚ�
	node* fast = head;
	node* slow = head;//��Ϊp����һ���ڵ�ĵ�ַ
	while (1)
	{
		if (fast->info == y)//���ҵ���ͬ��ֵʱ�˳�ѭ��
		{
			break;
		}
		else
		{
			if (fast->next == NULL)
				return NULL;//����ѭ�����ʱ��û���ҵ�Ҫ�ҵ�ֵʱ
			slow = fast;
			fast = fast->next;
		}
	}
	//��Ϊ�����ܵ����ң�������Ҫ�����һ���ڵ�ĵ�ַ
	return slow;
}
void display(node* h)//����������ÿ���ڵ�
{
	node* p;
	p = h;
	if (!p)
	{
		printf("\n�������ǿյģ�");
	}
	else
	{
		printf("\n�õ�����ĸ�ֵΪ��");
		while (p)
		{
			printf("%d ", p->info);
			p = p->next;
		}
	}
}
node* insert(node* h, datatype x, datatype y)
{
	node* p;
	node* q = find(h, y);
	//���Ҳ���Ҫ�����λ��ʱ
	if (!q)
	{
		printf("�Ҳ���Ҫ����Ľڵ㣡");
	}
	else
	{
		p = (node*)malloc(sizeof(node));
		p->info = x;
		if (y == 1)
		{
			h = p;
			p->next = q;
		}
		else
		{
			p->next = q->next;
			q->next = p;
		}
	}
	return h;
}
int main()
{
	node head[10];//ȷ�����������Ϊhead
	node* p = init(head);//��������������׵�ַ
	display(head);
	printf("\n��������Ҫ�����ֵ��");
	datatype x;
	scanf("%d", &x);
	printf("\n��������Ҫ��������һ��ֵ��ǰ�棺");
	datatype y;
	scanf("%d", &y);
	display(insert((head), x, y));
	return 0;
}
int size(node* head)
{
	int j = 0;
	node* p = head;
	while (p)
	{
		p = p->next;
		j++;
	}
	return j;
}
int main1()
{
	node head[10];
	int a;
	a = size(init(head));
	printf("������Ľڵ����Ϊ��%d��", a);
	return 0;
}
