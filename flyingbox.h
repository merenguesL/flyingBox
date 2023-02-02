#ifndef FLYINGBOX_H
#define FLYINGBOX_H

#include <QtGui/QMainWindow>
#include "ui_flyingbox.h"
#include "QDesktopWidget"
#include <QPropertyAnimation>
#include <QTime>
#include <QLabel>
#include <iostream>
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
	  *  @param[in]  directionion:���ڷɵķ���
	  *				
	  */
	void fly(int directionion);
	
	/**
	  *  @brief  	ʵʱ��ʾ��ǰλ��
	  */
	void paintEvent (QPaintEvent *);
	
private:
	
	/**
	  *  @brief  	 ����յ�λ��(�˺�����ʵ��һ��ײǽ������Ч�������㷨��ʱ������) 
	  *  @param[in]  
	  *				 directionion:�ɳ��ķ���
	  *				 curX:���ڵ�ǰ���Ͻǵ�X����
	  *				 curY:���ڵ�ǰ���Ͻǵ�Y����			 
	  */
	QPoint getFinalPoint(int directionion,int &curX,int &curY);

	/**
	  *  @brief  	 ��ȡһ�����������
	  */
	QPoint getRandomPoint();

public:
	int widgetLength;	//��Ļ����
	int widgetWidth;	//��Ļ�߶�

	int curX;			//���ڵ�ǰ���Ͻǵ�X����
	int curY;			//���ڵ�ǰ���Ͻǵ�Y����

	QPropertyAnimation *pAnimation;
	
	enum directionion   //���еķ�������Ƕ�������֮��ģ�Ϊ45�ȽǷɳ�
	{
		North,
		NorthWest,
		West,
		SouthWest,
		South,
		SouthEast,
		East,
		NorthEast
	};

	int direction; //����

public slots:
		void loopFinished();
		void OnFlyClicked();
		void OnShakeClicked();

private:
	Ui::FlyingBoxClass ui;

	bool isShaking;
};

#endif