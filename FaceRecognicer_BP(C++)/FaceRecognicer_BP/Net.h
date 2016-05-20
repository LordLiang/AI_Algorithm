#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#define LAYER    3        //三层神经网络
#define ETA_W    0.1   //权值调整率  
#define ETA_B    0.1    //阈值调整率     
#define MOMENTUM 0.1
#define A        1.0  
#define B        1.0     //A和B是S型函数的参数 
#define TRAINNUM 224
#define TESTNUM 60
#define ITERATIONNUM 50
using namespace std;
/*定义神经元*/
struct Node
{
	vector<double>weights;/*表示前一层的每一个节点作为输入对该神经元的权重*/
	vector<double>old_weights;
	double 
		output,/*输出*/
		delta,/*记录delta学习规则中delta的值*/
		bias;/*偏置*/
	Node()
	{
		output=delta=bias=0.0;
	}
};

/*定义层*/
typedef vector<Node> Layer;

/*定义网络*/
class Net
{
public:  
	Net(void);
	void init(int,int,int,double,double);
	void front();
	static double sig(const double& x) ;
	void backprop(int cnt);
	Layer getResult() const;
	double getError(int count);
	double getAccu();
	void train();
	void foreCast();
	~Net(void);

public:
	vector<double>*train_input;;
	vector<double>*target_output;
	vector<double>test_input;
private:  
	int in_num;                 //输入层节点数  
    int ou_num;                 //输出层节点数  
    int hd_num;                 //隐含层节点数
	double error;//单个样本允许的误差
	double accu;//每次迭代允许的误差
	vector<Layer> net;

};


