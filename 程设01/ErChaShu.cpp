//数据结构还是基本的东西，二叉树实现一下
#include "head_CS01.h"

//成员函数通过一个名为‘this’的额外隐式参数来访问调用它的那个对象
namespace ECS_CGYT //尝试使用面向对象构建，节点类
{
	enum NodeSel 
	{
		FATHER = 0,
		LEFT = 1,
		RIGHT=2
	};
	class JieDian  //二叉树的节点类
	{
	public:
		JieDian* Father;
		JieDian* LeftKid;
		JieDian* RightKid;

		double data;

		int Index; //在树中的索引，作为树中查找元素的关键字，互异

	public:
		void setData(double Data) //设定数据
		{
			this->data = Data;
		}

		void setNode(JieDian* F, JieDian* L, JieDian* R) //一起改
		{
			this->Father = F;
			this->LeftKid = L;
			this->RightKid = R;
		}

		void setNode(JieDian* Node,int NodeSelect) //只改一个，重载
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

		JieDian* getNode(JieDian* JD,int Position) //返回选择的子节点指针
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

	class Tree_bin  //二叉树类
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
		Tree_bin(ECS_CGYT::JieDian &Root)  //创建树以及一个根节点
		{	
			this->FristRoot = &Root;
			Root.setNode(nullptr, nullptr, nullptr);
			this->hight = 1;
			this->Num_JieDian = 1;
		}

		void addNode(JieDian &NewNode, JieDian &Father,int Position)  //在尾部增加一个节点
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
				printf("子节点已满，请使用INSERT方法");
			}
		} //此处也注意参数传递形式造成的影响
		
		JieDian* getRoot()
		{
			return this->FristRoot;
		}

		void Insert(JieDian NewNode,JieDian* Son,int PosOfSon,int PosOfNewnode) //指定新节点的子节点和新节点与原父节点的关系
		{
			JieDian* Father;
			Son->getNode(Father,FATHER);
			NewNode.setNode(Father, FATHER);
			NewNode.setNode(Son, PosOfSon);
			Father->setNode(&NewNode, PosOfNewnode);
			Son->setNode(&NewNode,FATHER);
		}
	};

//二叉搜索树相关的函数但是二叉搜索树地性质需要专有自行维护
	//中序遍历
	void InOrder_Tree_Walk(JieDian* root)
	{
		JieDian* x = root;
		if (x)
		{
			InOrder_Tree_Walk(x->LeftKid);
			printf("%d ", x->data);               //中序遍历必须得放在中间还
			InOrder_Tree_Walk(x->RightKid);
		}
	}

	//查询操作
	JieDian* Search(JieDian* root, double data)
	{
		JieDian* x = root;

		while (x != nullptr || x->data != data)
		{
			if (x->data > data)
			{
				x = x->LeftKid;
			}
			else
			{
				x = x->RightKid;
			}
		}
			return root;
	}

	//最大关键字
	JieDian* MaxKey(JieDian* root)
	{
		JieDian* x = root;
		while (x->RightKid)
		{
			x = x->RightKid;
		}
		return x;
	}

	//最小关键字
	JieDian* MinKey(JieDian* root)
	{
		JieDian* x = root;
		while (x->RightKid)
		{
			x = x->RightKid;
		}
		return x;
	}

	//查找后继
	JieDian* Successor(JieDian* x)
	{
		if (x->RightKid) //如果有右子树，那就从右子树里面找最小的
		{
			return MinKey(x->RightKid);
		}
		else
		{
			JieDian* y = x->Father;
			while (y!=nullptr || x==y->RightKid) //不断往上爬 爬到向左上方向移植爬到被右上方向的线挡死，再往右一拐
			{
				x = y;
				y = y->Father;
			}
			return y;
		}
	}

	//查找前驱
	JieDian* PreDecessor(JieDian* x)
	{
		if (x->LeftKid) //如果有左子树，那就从左子树里面找最大的，就是前驱
		{
			return MaxKey(x->LeftKid);
		}
		else
		{
			JieDian* y = x->Father;
			while (y !=nullptr || x==y->LeftKid) //不断往上爬 爬到向右上方向移植爬到被左上方向的线挡死，再往左一拐
			{
				x = y;
				y = y->Father;
			}
			return y;
		}
	}

	void Insert(JieDian* x)
	{
		
	}
}

//其实最好还是分俩文件分开实现
int main()
{

	ECS_CGYT::JieDian Root;  //根节点声明
	Root.setData(2903);
	ECS_CGYT::Tree_bin ErChaShu = ECS_CGYT::Tree_bin(Root);
	
	//增加一些节点
	ECS_CGYT::JieDian JD1, JD2, JD3, JD4, JD5;
	JD1.setData(10);
	JD2.setData(11);
	JD3.setData(100);
	JD4.setData(101);
	JD5.setData(110);

	ECS_CGYT::JieDian* Node1;
	ECS_CGYT::JieDian* Node2;

	ErChaShu.addNode(JD1, Root, ECS_CGYT::LEFT);
	ErChaShu.addNode(JD2, Root, ECS_CGYT::RIGHT);  //注意引用，要对函数大改了20200926

	Node1 = ErChaShu.getRoot();
	Node2 = Node1->getNode(Node1, ECS_CGYT::LEFT);

	ErChaShu.addNode(JD3, *Node2, ECS_CGYT::LEFT);
	ErChaShu.addNode(JD4, *Node2, ECS_CGYT::RIGHT);
	ErChaShu.addNode(JD5, JD4, ECS_CGYT::RIGHT);

	//操作符重载的一些试验

	box a = box(3, 2, 5);
	box b = box(4, 3, 2);

	a = b;      //若定义了重载的 =操作符 ，则此处使用重载的操作符
	box c = a;  //此处的=用的并非是重载的操作符
	b = 3.4;

	return 0;
}