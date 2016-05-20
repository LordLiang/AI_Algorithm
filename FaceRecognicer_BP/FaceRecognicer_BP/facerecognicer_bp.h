#ifndef FACERECOGNICER_BP_H
#define FACERECOGNICER_BP_H

#include <QtWidgets/QMainWindow>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>  
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include "Net.h"
#include "ui_facerecognicer_bp.h"



using namespace std;
using namespace cv; 

#define WIDTH 64
#define HEIGHT 60
#define INPUTNUM 3840
#define HIDDENNUM_1 9
#define HIDDENNUM_2 3
#define OUTPUTNUM_1 4
#define OUTPUTNUM_2 2
class FaceRecognicer_BP : public QMainWindow
{
	Q_OBJECT

public:
	FaceRecognicer_BP(QWidget *parent = 0);
	void createNet();
	void readTrainData();
	~FaceRecognicer_BP();

signals:
	public slots:
	void loadRandPic_clicked();
	void startToTrain_clicked();
private:
	Ui::FaceRecognicer_BPClass ui;
	Net net_d;
	Net net_s;
};

#endif // FACERECOGNICER_BP_H
