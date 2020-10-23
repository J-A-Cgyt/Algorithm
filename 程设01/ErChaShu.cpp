//���ݽṹ���ǻ����Ķ�����������ʵ��һ��
#include "head_CS01.h"

//��Ա����ͨ��һ����Ϊ��this���Ķ�����ʽ���������ʵ��������Ǹ�����
namespace ECS_CGYT //����ʹ��������󹹽����ڵ���
{
	enum NodeSel 
	{
		FATHER = 0,
		LEFT = 1,
		RIGHT=2
	};
	class JieDian  //�������Ľڵ���
	{
	private:
		JieDian* Father;
		JieDian* LeftKid;
		JieDian* RightKid;

		double data;

		int Index; //�����е���������Ϊ���в���Ԫ�صĹؼ��֣�����

	public:
		void setData(double Data) //�趨����
		{
			this->data = Data;
		}

		void setNode(JieDian* F, JieDian* L, JieDian* R) //һ���
		{
			this->Father = F;
			this->LeftKid = L;
			this->RightKid = R;
		}

		void setNode(JieDian* Node,int NodeSelect) //ֻ��һ��������
		{
			switch (NodeSelect)
			{
			case FATHER:
				this->Father = Node;
				break;
			case LEFT:
				this->LeftKid = Node;
				break;
			case RIGHT:
				this->RightKid = Node;
				break;
			}
		}

		JieDian* getNode(JieDian* JD,int Position) //����ѡ����ӽڵ�ָ��
		{
			if (Position == LEFT)
			{
				return JD->LeftKid;
			}
			if (Position == RIGHT)
			{
				return JD->RightKid;
			}
			if (Position == FATHER)
			{
				return JD->Father;
			}
		}

		bool isNotFull()
		{
			if ((this->LeftKid != nullptr) & (this->RightKid != nullptr))
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		void setIndex(int Idx)
		{
			this->Index = Idx;
		}
	};

	class Tree_bin  //��������
	{
	private:
		JieDian* FristRoot;

		int hight;
		int Num_JieDian;

		void setHight(int H)
		{
			this->hight = H;
		}

		void setNum(int N)
		{
			this->Num_JieDian = N;
		}

	public:
		Tree_bin(ECS_CGYT::JieDian &Root)  //�������Լ�һ�����ڵ�
		{	
			this->FristRoot = &Root;
			Root.setNode(nullptr, nullptr, nullptr);
			this->hight = 1;
			this->Num_JieDian = 1;
		}

		void addNode(JieDian &NewNode, JieDian &Father,int Position)  //��β������һ���ڵ�
		{
			if (Father.isNotFull())//
			{
				Father.setNode(&NewNode, Position);
				NewNode.setNode(&Father, FATHER);
				NewNode.setNode(nullptr, LEFT);
				NewNode.setNode(nullptr, RIGHT);
				NewNode.setIndex(this->Num_JieDian);
				this->Num_JieDian += 1;
			}
			else
			{
				printf("�ӽڵ���������ʹ��INSERT����");
			}
		} //�˴�Ҳע�����������ʽ��ɵ�Ӱ��
		
		JieDian* getRoot()
		{
			return this->FristRoot;
		}

		void Insert(JieDian NewNode,JieDian* Son,int PosOfSon,int PosOfNewnode) //ָ���½ڵ���ӽڵ���½ڵ���ԭ���ڵ�Ĺ�ϵ
		{
			JieDian* Father;
			Son->getNode(Father,FATHER);
			NewNode.setNode(Father, FATHER);
			NewNode.setNode(Son, PosOfSon);
			Father->setNode(&NewNode, PosOfNewnode);
			Son->setNode(&NewNode,FATHER);
		}
	};
}

//��ʵ��û��Ƿ����ļ��ֿ�ʵ��
int main()
{

	ECS_CGYT::JieDian Root;  //���ڵ�����
	Root.setData(2903);
	ECS_CGYT::Tree_bin ErChaShu = ECS_CGYT::Tree_bin(Root);
	
	//����һЩ�ڵ�
	ECS_CGYT::JieDian JD1, JD2, JD3, JD4, JD5;
	JD1.setData(10);
	JD2.setData(11);
	JD3.setData(100);
	JD4.setData(101);
	JD5.setData(110);

	ECS_CGYT::JieDian* Node1;
	ECS_CGYT::JieDian* Node2;

	ErChaShu.addNode(JD1, Root, ECS_CGYT::LEFT);
	ErChaShu.addNode(JD2, Root, ECS_CGYT::RIGHT);  //ע�����ã�Ҫ�Ժ��������20200926

	Node1 = ErChaShu.getRoot();
	Node2 = Node1->getNode(Node1, ECS_CGYT::LEFT);

	ErChaShu.addNode(JD3, *Node2, ECS_CGYT::LEFT);
	ErChaShu.addNode(JD4, *Node2, ECS_CGYT::RIGHT);
	ErChaShu.addNode(JD5, JD4, ECS_CGYT::RIGHT);

	//���������ص�һЩ����

	box a = box(3, 2, 5);
	box b = box(4, 3, 2);

	a = b;      //�����������ص� =������ ����˴�ʹ�����صĲ�����
	box c = a;  //�˴���=�õĲ��������صĲ�����
	b = 3.4;

	return 0;
}