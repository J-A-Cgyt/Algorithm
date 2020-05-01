#include <cstdlib>
#include <iostream>
using namespace std;
//����ʹ�õ�����������
typedef int DataType;
//�������Ľڵ㶨��
typedef struct NODE Node;
typedef struct NODE
{
	DataType  data;    //������
	Node* next;    //ָ����
}Node;
//ͷָ��
typedef Node* Head;
//�����ķ�������
int GetLinkListLength(Head head);        //������
void DestroyLinkList(Head head);     //��������
int GetElement(Head head, int n, DataType* data);   //��ȡ���Ա��е�n��Ԫ��
int FindElement(Head head, DataType data);      //����data ��һ�γ��ֵ�λ��
int GetPriorElement(Head head, int n, DataType* data);   //��ȡ��i��Ԫ�ص�ǰ��
int GetNextElement(Head head, int n, DataType* data);     //��ȡ��i��Ԫ�صĺ���
int InsertToList(Head* head, int pos, DataType data);  //�� data���뵽 pos ��
int DeleteFromList(Head head, int pos);             //ɾ�����Ա���λ��Ϊpos ��Ԫ��
void PrintList(Head head);          //�������Ա�
int InsertRear(Head* head, DataType data);          //�ӱ�β����Ԫ��
int InsertHead(Head* head, DataType data);          //�ӱ�ͷ����Ԫ��

													//������
int main()
{
	//����һ���յ����Ա�
	Head head = NULL;
	//�����Ƕ����α��Ĳ���
	//����5��Ԫ�ز���ʾ
	for (int i = 0; i < 5; ++i)
		InsertToList(&head, i, i + 1);
	//�������Ա�
	PrintList(head);
	//��λ��2����99����ʾ
	cout<<"����99���ı�����"<<endl<<InsertToList(&head, 2, 99);
	cout<<"����99�������Ա�"<<endl;
	PrintList(head);
	//ɾ����4��Ԫ��
	cout<<"ɾ����4��Ԫ�غ��ı�����"<<endl<< DeleteFromList(head, 4);
	cout<<"ɾ����4��Ԫ�غ������Ա�"<<endl;
	PrintList(head);
	//��ʾ��3��Ԫ�ص�ǰ��
	DataType data;
	if (GetPriorElement(head, 3, &data) > -1);
	cout<<"��3��Ԫ�ص�ǰ����%d"<<endl<<data;
	DestroyLinkList(head);
	return 0;
}

//�����ķ���ʵ��
/**
*@brief   ������
*@param head ������ͷָ��
*@return �����ĳ���
*/
int GetLinkListLength(Head head)
{
	if (head == NULL)
		return 0;
	int i = 1;
	Node* pNode = head;
	while (pNode->next)    //!=NULL
	{
		i++;
		pNode = pNode->next;   //��һ�ڵ�
	}
	return i;
}
/**
*@brief   ��������
*@param head ������ͷָ��
*/
void DestroyLinkList(Head head)
{
	//��ͷ��ʼ�������ͷ�ÿһ���ڵ�
	Node* pNode;
	while (head)
	{
		pNode = head;
		head = head->next;   //ָ����һ���ڵ�
		delete(pNode);  //�ͷŵ�ǰ�ڵ�
	}
}
/**
*@brief   ��ȡ���Ա��е�n��Ԫ�أ���һ��Ԫ�ص�λ��Ϊ0
*@param head ������ͷָ��
*@param n Ҫ��ȡ��Ԫ��λ��
*@param data ��ȡ�����ݴ�������
*@return  ��ȡ�ɹ�����1, ʧ���򷵻�0
*/
int GetElement(Head head, int n, DataType* data)
{
	if (n<0 || n>GetLinkListLength(head) - 1)
		return 0;
	for (int i = 0; i < n; ++i)
		head = head->next;       //�ƶ���λ��n
	*data = head->data;
	return 1;
}
/**
*@brie ����data��һ�γ��ֵ�λ��
*@param head ָ�����Ա���ͷָ��
*@param data Ҫ���ҵ�Ԫ��
*@return �ҵ��򷵻ظ�λ��, δ�ҵ�������-1
*/
int FindElement(Head head, DataType data)
{
	int i = 0;
	while (head)
	{
		if (head->data == data)   //�ҵ�
			return i;
		head = head->next;  //��һ���ڵ�
		i++;
	}
	return -1;
}
/**
*@brief ��ȡ��n��Ԫ�ص�ǰ��
*@param head ָ�����Ա���ͷָ��
*@param n n��ǰ��
*@param data ��ȡ�ɹ���ȡ��Ԫ�ش�����data��
*@return �ҵ��򷵻�ǰ����λ�ã�n-1��, δ�ҵ�������-1
*/
int GetPriorElement(Head head, int n, DataType* data)
{
	if (n<1 || n>GetLinkListLength(head) - 1)
		return -1;
	for (int i = 0; i < n - 1; ++i)
		head = head->next;      //�ƶ���n-1
	*data = head->data;
	return n - 1;
}
/**
*@brief ��ȡ��n��Ԫ�صĺ���
*@param head ָ�����Ա���ͷָ��
*@param n n�ĺ���
*@param data ��ȡ�ɹ���ȡ��Ԫ�ش�����data��
*@return �ҵ��򷵻�ǰ����λ�ã�n+1��, δ�ҵ�������-1
*/
int GetNextElement(Head head, int n, DataType* data)
{
	if (n<0 || n>GetLinkListLength(head) - 2)
		return -1;
	for (int i = 0; i < n + 1; ++i)
		head = head->next;      //�ƶ���n
	*data = head->data;
	return n + 1;
}
/**
*@brief  �� data���뵽 pos ��
*@param head ָ�����Ա���ͷָ��
*@param pos ������λ��
*@param data Ҫ����������
*@return �����ɹ������µı��������򷵻�-1
*/
int InsertToList(Head* head, int pos, DataType data)
{
	Node* pNode = *head;
	int length = GetLinkListLength(pNode);  //�õ�����
	if (pos<0 || pos> length)
		return -1;      //������λ�ò���
	if (pos == 0)    //�ڱ�ͷ����
		return InsertHead(head, data);
	if (pos == length - 1)   //�ڱ�β����
		return InsertRear(head, data);
	//��λ��posǰ1λ��
	for (int i = 0; i < pos - 1; ++i)
		pNode = pNode->next;
	//����һ���µĽڵ�
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL)
		return -1;    //�����ڴ�ʧ��
	pNewNode->data = data;     //����Ҫ����������
							   //��������
	pNewNode->next = pNode->next;
	pNode->next = pNewNode;
	//�����µ���������
	return ++length;
}
/**
*@brief  ɾ�����Ա���λ��Ϊpos ��Ԫ��
*@param head ָ�����Ա���ͷָ��
*@param pos ɾ����λ��
*@return �����ɹ������µı��������򷵻�-1
*/
int DeleteFromList(Head head, int pos)
{
	Node* pNode = head;
	int length = GetLinkListLength(head);  //�õ�����
	if (pos<0 || pos> length - 1)
		return -1;      //ɾ����λ�ò���
						//��λ��posλ��
	for (int i = 0; i < pos - 1; ++i)
		pNode = pNode->next;
	Node* pDeleteNode = pNode->next;
	pNode->next = pNode->next->next;
	delete(pDeleteNode);
	return --length;
}
/**
*@brief  �������Ա�
*@param head ָ�����Ա���ͷָ��
*/
void PrintList(Head head)
{
	int n = 0;
	while (head)
	{
		cout<<"��%d"<<n<<"��Ԫ��Ϊ"<<head->data<<endl;
		head = head->next;
		++n;
	}
}
/**
*@brief  �ӱ�β����Ԫ��
*@param head ָ�����Ա���ͷָ��
*@param data ����������
*@return �����ɹ������µı��������򷵻�-1
*/
int InsertRear(Head* head, DataType data)
{
	//׼��������
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL)  //�ڴ�����ʧ��
		return -1;
	pNewNode->data = data;
	if (*head == NULL)   //�����ǿձ�
	{
		*head = pNewNode;
		pNewNode->next = NULL;
		return 1;  //����Ϊ1
	}
	//�ҵ���β
	Node* pNode = *head;
	while (pNode->next)
		pNode = pNode->next;
	//���뵽��β
	pNode->next = pNewNode;
	pNewNode->next = NULL;
	//�����µı���
	return GetLinkListLength(*head);
}
/**
*@brief  �ӱ�ͷ����Ԫ��
*@param head ָ�����Ա���ͷָ��
*@param data ����������
*@return �����ɹ������µı��������򷵻�-1
*/
int InsertHead(Head* head, DataType data)
{
	//׼��������
	Node* pNewNode = new Node;
	if (pNewNode == NULL)  //�ڴ�����ʧ��
		return -1;
	pNewNode->data = data;
	//����
	if (*head == NULL)    //�����ǿձ�
		pNewNode->next = NULL;
	else
		pNewNode->next = (*head)->next;
	*head = pNewNode;
	//�����µı���
	return GetLinkListLength(*head);
}