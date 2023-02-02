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
	  *  @brief  	 窗口抖动
	  *  @param[in]  nRange:抖动的范围，单位为像素
	  *				 nShakeCount:抖动次数
	  */
	void shake(int nRange,int nShakeCount);

	/**
		* @brief       停止抖动
		* @param[in]   animation 抖动的动画对象
		*/
	void stopShaking(QPropertyAnimation* animation);
	
	/**
	  *  @brief  	 窗口飞来飞去
	  *  @param[in]  directionion:窗口飞的方向
	  *				
	  */
	void fly(int directionion);
	
	/**
	  *  @brief  	实时显示当前位置
	  */
	void paintEvent (QPaintEvent *);
	
private:
	
	/**
	  *  @brief  	 算出终点位置(此函数想实现一个撞墙反弹的效果，但算法暂时有问题) 
	  *  @param[in]  
	  *				 directionion:飞出的方向
	  *				 curX:窗口当前左上角的X坐标
	  *				 curY:窗口当前左上角的Y坐标			 
	  */
	QPoint getFinalPoint(int directionion,int &curX,int &curY);

	/**
	  *  @brief  	 获取一个随机的坐标
	  */
	QPoint getRandomPoint();

public:
	int widgetLength;	//屏幕长度
	int widgetWidth;	//屏幕高度

	int curX;			//窗口当前左上角的X坐标
	int curY;			//窗口当前左上角的Y坐标

	QPropertyAnimation *pAnimation;
	
	enum directionion   //飞行的反向。如果是东北方向之类的，为45度角飞出
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

	int direction; //方向

public slots:
		void loopFinished();
		void OnFlyClicked();
		void OnShakeClicked();

private:
	Ui::FlyingBoxClass ui;

	bool isShaking;
};

#endif