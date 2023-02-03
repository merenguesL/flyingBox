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
	  *				
	  */
	void fly();
	
	/**
	  *  @brief  	实时显示当前位置
	  */
	void paintEvent (QPaintEvent *);
	
	
private:
	
	/**
	  *  @brief  	 算出终点位置(此函数想实现一个撞墙反弹的效果，但算法暂时有问题) 
	  *  @param[in]  
	  *				 curX:窗口当前左上角的X坐标
	  *				 curY:窗口当前左上角的Y坐标			 
	  */
	QPoint getFinalPoint(int &curX,int &curY);

	/**
	  *  @brief  	 获取一个随机的坐标
	  */
	QPoint getRandomPoint();

public:
	int widgetLength;	//屏幕长度
	int widgetWidth;	//屏幕高度

	int curX;			//窗口当前左上角的X坐标
	int curY;			//窗口当前左上角的Y坐标

	int maxX;			//左上角最大到达的x坐标
	int maxY;			//左上角最大到达的Y坐标

	bool xless, yless;	//x和y坐标终点坐标相对初始坐标是否减小

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