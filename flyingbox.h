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
	  *  @brief  	 ���ڷ�����ȥ
	  *  @param[in]  direction:���ڷɵķ���
	  *				
	  */
	void fly(int direction);
	
	/**
	  *  @brief  	ʵʱ��ʾ��ǰλ��
	  */
	void paintEvent (QPaintEvent *);
	
private:
	
	/**
	  *  @brief  	 ����յ�λ�� 
	  *  @param[in]  
	  *				 direction:�ɳ��ķ���
	  *				 curX:���ڵ�ǰ���Ͻǵ�X����
	  *				 curY:���ڵ�ǰ���Ͻǵ�Y����
	  *				 
	  */
	QPoint getFinalPoint(int direction,int &curX,int &curY);


public:
	int widgetLength;	//��Ļ����
	int widgetWidth;	//��Ļ�߶�

	int curX;			//���ڵ�ǰ���Ͻǵ�X����
	int curY;			//���ڵ�ǰ���Ͻǵ�Y����

	QPropertyAnimation *pAnimation;
	
	enum Direction   //���еķ�������Ƕ�������֮��ģ�Ϊ45�ȽǷɳ�
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

	int direct; //����

public slots:
		void loopFinished();
		void OnFlyClicked();
		void OnShakeClicked();

private:
	Ui::FlyingBoxClass ui;
};

#endif