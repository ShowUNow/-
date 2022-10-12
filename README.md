# -
学校留的作业
1、查询单链表长度
#include<stdio.h>
typedef int datatype;
typedef struct link_node
{
	datatype info;
	struct link_node* next;
}node;
node* init(node h[10])
{
	node* p = &h[0];
	for (int i = 0; i < 10; i++)
	{
		p->info = i + 1;
		if (i < 9)
		{
			p->next = &h[i + 1];
			p = &h[i + 1];
		}
		else
		{
			p->next = NULL;
		}
	}
	return h;
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

int main()
{
	node head[10];
	int a;
	a = size(init(head));
	printf("单链表的节点个数为：%d个", a);
	return 0;
} 
![image](https://user-images.githubusercontent.com/114962931/195360784-eedced70-176f-4176-818c-49bee8c05d5f.png)

2、在链表中插入数据
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct link_node
{
	datatype info;
	struct link_node* next;
}node;
//初始化一个节点个数为10的链表
node* init(node h[10])
{
	node* p = &h[0];//取数组的首地址
	for (int i = 0; i < 10; i++)
	{
		p->info = i + 1;
		if (i < 9)
		{
			//将p的地址传递到下一个元素上
			p->next = &h[i + 1];
			p = &h[i + 1];
		}
		else
		{
			//链表的最后一个节点
			p->next = NULL;
		}
	}
	return h;
}
//查找链表中y所在的节点
node* find(node* head, datatype y)
{
	//从第一个节点开始比较
	node* fast = head;
	node* slow = head;//作为p的上一个节点的地址
	while (1)
	{
		if (fast->info == y)//当找到相同的值时退出循环
		{
			break;
		}
		else
		{
			if (fast->next == NULL)
				return NULL;//链表循环完毕时还没有找到要找的值时
			slow = fast;
			fast = fast->next;
		}
	}
	//因为链表不能倒着找，所以需要输出上一个节点的地址
	return slow;
}
void display(node* h)//输出该链表的每个节点
{
	node* p;
	p = h;
	if (!p)
	{
		printf("\n该链表是空的！");
	}
	else
	{
		printf("\n该单链表的各值为：");
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
	//当找不到要插入的位置时
	if (!q)
	{
		printf("找不到要插入的节点！");
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
	node head[10];//确定链表的名称为head
	node* p = init(head);//创建出的链表的首地址
	display(head);
	printf("\n请输入你要插入的值：");
	datatype x;
	scanf("%d", &x);
	printf("\n请输入你要插入再哪一个值的前面：");
	datatype y;
	scanf("%d", &y);
	display(insert((head), x, y));
	return 0;
}
插在链表开头
 ![image](https://user-images.githubusercontent.com/114962931/195360588-249dcda8-c12b-4ef5-9459-2097694df4b9.png)

插在链表中间
 ![image](https://user-images.githubusercontent.com/114962931/195360688-b31b19f9-ea6a-4b50-a4ba-18f360b190aa.png)


