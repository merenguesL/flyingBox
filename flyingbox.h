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
	  *  @brief  	 窗口飞来飞去
	  *  @param[in]  direction:窗口飞的方向
	  *				
	  */
	void fly(int direction);
	
	/**
	  *  @brief  	实时显示当前位置
	  */
	void paintEvent (QPaintEvent *);
	
private:
	
	/**
	  *  @brief  	 算出终点位置 
	  *  @param[in]  
	  *				 direction:飞出的方向
	  *				 curX:窗口当前左上角的X坐标
	  *				 curY:窗口当前左上角的Y坐标
	  *				 
	  */
	QPoint getFinalPoint(int direction,int &curX,int &curY);


public:
	int widgetLength;	//屏幕长度
	int widgetWidth;	//屏幕高度

	int curX;			//窗口当前左上角的X坐标
	int curY;			//窗口当前左上角的Y坐标

	QPropertyAnimation *pAnimation;
	
	enum Direction   //飞行的反向。如果是东北方向之类的，为45度角飞出
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

	int direct; //方向

public slots:
		void loopFinished();
		void OnFlyClicked();
		void OnShakeClicked();

private:
	Ui::FlyingBoxClass ui;
};

#endif