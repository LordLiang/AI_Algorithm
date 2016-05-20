#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#define LAYER    3        //����������
#define ETA_W    0.1   //Ȩֵ������  
#define ETA_B    0.1    //��ֵ������     
#define MOMENTUM 0.1
#define A        1.0  
#define B        1.0     //A��B��S�ͺ����Ĳ��� 
#define TRAINNUM 224
#define TESTNUM 60
#define ITERATIONNUM 50
using namespace std;
/*������Ԫ*/
struct Node
{
	vector<double>weights;/*��ʾǰһ���ÿһ���ڵ���Ϊ����Ը���Ԫ��Ȩ��*/
	vector<double>old_weights;
	double 
		output,/*���*/
		delta,/*��¼deltaѧϰ������delta��ֵ*/
		bias;/*ƫ��*/
	Node()
	{
		output=delta=bias=0.0;
	}
};

/*�����*/
typedef vector<Node> Layer;

/*��������*/
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
	int in_num;                 //�����ڵ���  
    int ou_num;                 //�����ڵ���  
    int hd_num;                 //������ڵ���
	double error;//����������������
	double accu;//ÿ�ε�����������
	vector<Layer> net;

};


