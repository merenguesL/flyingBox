#ifndef FLYINGBOX_H
#define FLYINGBOX_H

#include <QtGui/QMainWindow>
#include "ui_flyingbox.h"
#include "QDesktopWidget"
#include <QPropertyAnimation>
#include <QTime>
#include <QLabel>
#include <iostream>
#include "Setup.h"
#include <thread>

class FlyingBox : public QMainWindow
{
	Q_OBJECT

public:
	FlyingBox(QWidget *parent = 0, Qt::WFlags flags = 0);
	~FlyingBox();
	
	/**
	  *  @brief  	 ���ڶ���
	  *  @param[in]  nRange:�����ķ�Χ����λΪ����
	  *				 nShakeCount:��������
	  */
	void shake(int nRange,int nShakeCount);

	/**
		* @brief       ֹͣ����
		* @param[in]   animation �����Ķ�������
		*/
	void stopShaking(QPropertyAnimation* animation);
	
	/**
	  *  @brief  	 ���ڷ�����ȥ
	  *				
	  */
	void fly();
	
	/**
	  *  @brief  	ʵʱ��ʾ��ǰλ��
	  */
	void paintEvent (QPaintEvent *);
	
	
private:
	
	/**
	  *  @brief  	 ����յ�λ��(�˺�����ʵ��һ��ײǽ������Ч�������㷨��ʱ������) 
	  *  @param[in]  
	  *				 curX:���ڵ�ǰ���Ͻǵ�X����
	  *				 curY:���ڵ�ǰ���Ͻǵ�Y����			 
	  */
	QPoint getFinalPoint(int &curX,int &curY);

	/**
	  *  @brief  	 ��ȡһ�����������
	  */
	QPoint getRandomPoint();

public:
	int widgetLength;	//��Ļ����
	int widgetWidth;	//��Ļ�߶�

	int curX;			//���ڵ�ǰ���Ͻǵ�X����
	int curY;			//���ڵ�ǰ���Ͻǵ�Y����

	int maxX;			//���Ͻ���󵽴��x����
	int maxY;			//���Ͻ���󵽴��Y����

	bool xless, yless;	//x��y�����յ�������Գ�ʼ�����Ƿ��С

	QPropertyAnimation *pAnimation;

public slots:

		void changeFlyDirection();
		void onFlyClicked();
		void onShakeClicked();
		void onSetupClicked();

private:
	Ui::FlyingBoxClass ui;

	bool isShaking;
	bool isFlying;

	OPTIONS option;
};

#endif