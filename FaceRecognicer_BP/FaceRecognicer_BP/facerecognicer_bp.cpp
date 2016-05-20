#include "facerecognicer_bp.h"

FaceRecognicer_BP::FaceRecognicer_BP(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(loadRandPic_clicked()));
	connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(startToTrain_clicked()));
	srand((unsigned)time(NULL));
}

FaceRecognicer_BP::~FaceRecognicer_BP()
{

}

void FaceRecognicer_BP::createNet()
{
	net_d.init(INPUTNUM,HIDDENNUM_1,OUTPUTNUM_1,0.2,0.2);
	net_s.init(INPUTNUM,HIDDENNUM_2,OUTPUTNUM_2,0.05,0.05);
	readTrainData();
	net_d.train();
	ui.textEdit->setPlainText("Net for direction is trained.\n"); 
    net_s.train();
	ui.textEdit->append("Net for sunglasses is trained."); 
}

void FaceRecognicer_BP::readTrainData()
{
	double target1[16]=
	{
		0.1,0.1,0.1,0.9,	
		0.1,0.1,0.9,0.1,	
		0.1,0.9,0.1,0.1,	
		0.9,0.1,0.1,0.1
	};
	double target2[4]=
	{
		0.9,0.1,	
		0.1,0.9
	};
	double max=0.0,min=999.0;
	double temp=0.0;
	int image_id = 1;  
	char filename[256];  
	Mat image;
	sprintf_s(filename , "train\\face (%d).pgm" , image_id );  
	Mat src = imread(filename,0);  
	while(src.data)  
	{  
		for(int i=0;i<WIDTH;i++)
		{	
			for(int j=0;j<HEIGHT;j++)
			{
				temp=(double)src.at<uchar>(j,i)/256;
			    if(temp>max)max=temp;
				if(temp<min)min=temp;
			}	
		}
		for(int i=0;i<WIDTH;i++)
		{	
			for(int j=0;j<HEIGHT;j++)
			{
				temp=(double)src.at<uchar>(j,i)/256;
				temp=(temp-min)/(max-min);
				net_d.train_input[image_id-1].push_back(temp);
				net_s.train_input[image_id-1].push_back(temp);
			}	
		}
		max=0.0;
		min=999.0;
		src.release();
		image_id++;  
		sprintf_s(filename , "train\\face (%d).pgm" , image_id );  
		src = imread(filename,0); 
	} 

	for(int i=0;i<TRAINNUM;i++)
	{
		for(int j=0;j<OUTPUTNUM_1;j++)
		{
			int k=(i%32)/8*4+j;
			net_d.target_output[i].push_back(target1[k]);
		}
	}

	for(int j=0;j<TRAINNUM;j=j+2)
	{
		net_s.target_output[j].push_back(target2[0]);
		net_s.target_output[j].push_back(target2[1]);
		net_s.target_output[j+1].push_back(target2[2]);
		net_s.target_output[j+1].push_back(target2[3]);
	}
}

void FaceRecognicer_BP::loadRandPic_clicked()
{
	int image_id=rand()%60+1;
	char filename[256];
	sprintf_s(filename , "test\\test (%d).pgm" , image_id );  
	Mat src = imread(filename,0); 
	net_d.test_input.erase(net_d.test_input.begin(),net_d.test_input.end());
	net_s.test_input.erase(net_s.test_input.begin(),net_s.test_input.end());
	double max=0.0,min=999.0,temp=0.0;
	if(src.data)
	{
		for(int i=0;i<WIDTH;i++)
		{
			for(int j=0;j<HEIGHT;j++)
			{
				temp=(double)src.at<uchar>(j,i)/256;
				if(temp>max)max=temp;
				if(temp<min)min=temp;
			}
		}
		for(int i=0;i<WIDTH;i++)
		{
			for(int j=0;j<HEIGHT;j++)
			{
				temp=(double)src.at<uchar>(j,i)/256;
				temp=(temp-min)/(max-min);
				net_d.test_input.push_back(temp);
				net_s.test_input.push_back(temp);
			}
		}
		src.release();
		QPixmap pixmap(filename);
		ui.label->setPixmap(pixmap);
		net_d.foreCast();
		net_s.foreCast();
		Layer& result_d = net_d.getResult();
		Layer& result_s = net_s.getResult();
		QString str;
		QString str2;
		double max=0.0;
		int k=0;
		for(int j=0;j<4;j++)
		{
			double temp=result_d[j].output;
			if(temp>max)
			{
				max=temp;
				k=j;
			}
		}
		switch(k)
		{
		case 0:str="Up";break;
		case 1:str="Straight";break;
		case 2:str="Right";break;
		case 3:str="Left";break;
		default:break;
		}
		ui.label_4->setText(str);
		
		if(result_s[0].output>result_s[1].output)str2="No";
		else str2="YES";
		ui.label_5->setText(str2);
		update();	
	}
}
void FaceRecognicer_BP::startToTrain_clicked()
{
	createNet();
}