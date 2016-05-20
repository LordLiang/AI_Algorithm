#include "Net.h"

Net::Net(void)
{

}
void Net::init(int input_num,int hidden_num,int output_num,double e,double a)/*接受一个vector来描述网络的形状*/
{
	in_num=input_num;
	hd_num=hidden_num;
	ou_num=output_num;
	error=e;
	accu=a;
	int shape[LAYER]={input_num,hidden_num,output_num};
	train_input=new vector<double>[TRAINNUM];
	target_output=new vector<double>[TRAINNUM];
	srand((unsigned)time(NULL));
	for(int i=0;i<LAYER;i++)
	{
		net.push_back(Layer());
		for(int j=0;j<shape[i];j++)
		{
			net.back().push_back(Node());
			if(i>0)
			{
				net[i][j].weights=vector<double>(shape[i-1]);
				net[i][j].old_weights=vector<double>(shape[i-1]);
				for(auto&val:net[i][j].weights)
				{
					val=rand()*(rand()%2?1:-1)*1.0/RAND_MAX;
				}
				for(int k=0;k<shape[i-1];k++)
				{
					net[i][j].old_weights[k]=0.0;
				}
				net[i][j].bias=rand()*(rand()%2?1:-1)*1.0/RAND_MAX;
			}
		}
	}
}
void Net::train()
{
	for(int iter=0;iter<ITERATIONNUM;iter++)
	{
		for(int cnt=0;cnt<TRAINNUM;cnt++)
			{
				int id=rand()%TRAINNUM;
				/*将输入层每个节点的输出设置为网络的输入*/
				for(int i=0;i<in_num;i++)
				{
					net[0][i].output=train_input[id][i];
				}
				while(1)
				{
					front();
					if(getError(id)<error)
						break;
					backprop(id);
				}
			}
			double accu=getAccu();
			
			if(accu<accu)break;
	}
}
/*
0  输入层         只需简单的把输入传递进来
1-n隐含层和输出层 根据前一层的输出和权重计算自己的输出
*/
void Net::front()/*前向操作*/
{
	//计算隐含层各个节点的输出值  
    for(int j = 0; j < hd_num; j++)  
    {  
        double t = 0.0;  
        for(int i = 0; i < in_num; i++)  
			t += net[1][j].weights[i] * net[0][i].output;  
		t += net[1][j].bias;  
        net[1][j].output = sig(t);  
    }  
  
    //计算输出层各节点的输出值  
      for(int j = 0; j < ou_num; j++)  
    {  
        double t = 0.0;  
        for(int i = 0; i < hd_num; i++)  
			t += net[2][j].weights[i] * net[1][i].output;  
		t += net[2][j].bias;  
        net[2][j].output = sig(t);  
    }   
}  


double Net::sig(const double& x)
{
	return A / (1.0 + exp(-x / B));
}

/*反向传播分为三个循环*/
void Net::backprop(int cnt)
{
	/*计算输出层的delta值*/
	for(int i=0;i<ou_num;i++)
	{
		Node& node=net.back()[i];
		node.delta=(node.output - target_output[cnt][i])* node.output * (A - node.output) / (A * B); 
	}

	/*计算隐含层的delta值*/
	for(int i=0;i<hd_num;i++)
	{
		double t=0.0;
		for(int j = 0; j < ou_num; j++) 
		{
			t+=net[2][j].weights[i]*net[2][j].delta;
		}
		net[1][i].delta=t*net[1][i].output*(A-net[1][i].output)/(A*B);
	}

	/*隐含层和输出层之间权值和阈值调整 */
	for(int i=0;i<hd_num;i++)
	{
		for(int j=0;j<ou_num;j++)
		{
			double temp=net[2][j].weights[i];
			net[2][j].weights[i]-=ETA_W*net[2][j].delta*net[1][i].output;
			net[2][j].weights[i]+=MOMENTUM*(temp-net[2][j].old_weights[i]);
			net[2][j].old_weights[i]=temp;
		}
	}
	for(int i=0;i<ou_num;i++)
	{
		net[2][i].bias-=ETA_B*net[2][i].delta;
	}

	for(int i=0;i<in_num;i++)
	{
		for(int j=0;j<hd_num;j++)
		{
			double temp=net[1][j].weights[i];
			net[1][j].weights[i]-=ETA_W*net[1][j].delta*net[0][i].output;
			net[1][j].weights[i]+=MOMENTUM*(temp-net[1][j].old_weights[i]);
			net[1][j].old_weights[i]=temp;
		}
	}
	for(int i=0;i<hd_num;i++)
	{
		net[1][i].bias-=ETA_B*net[1][i].delta;
	}
}


double Net::getError(int count)
{
	double error=0.0;
	for(int i=0;i<ou_num;i++)
	{
		double re=net.back()[i].output;
		double tar=target_output[count][i];
		error+=0.5*(re-tar)*(re-tar);
	}
	return error;
}
Layer Net::getResult() const
{
	return net.back();
}

double Net::getAccu()
{
	double ans=0.0;
	for(int i=0;i<TRAINNUM;i++)
	{
		for(int j=0;j<in_num;j++)
		{
			net[0][i].output=train_input[i][j];
		}
		front();
		for(int j=0;j<ou_num;j++)
		{
			double re=net.back()[j].output;
			double tar=target_output[i][j];
			ans+=0.5*(re-tar)*(re-tar);
		}
	}
	return ans/TRAINNUM;
}
Net::~Net(void)
{
	delete []train_input;
	delete []target_output;
}


void Net::foreCast()
{
		/*将输入层每个节点的输出设置为网络的输入*/
		for(size_t i=0;i<net[0].size();i++)
		{
			net[0][i].output=test_input[i];
		}
		front();
}