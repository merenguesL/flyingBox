#include "flyingbox.h"
#include "Setup.h"
#include <random>
using namespace std;

FlyingBox::FlyingBox(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags), option(OPTIONS{0,5,12})
{
	ui.setupUi(this);
	this ->setWindowFlags ( Qt ::FramelessWindowHint );		//无标题栏

	widgetLength=QApplication::desktop ()->availableGeometry ().width ();
	widgetWidth=QApplication::desktop ()->availableGeometry ().height ();
	curX=this->geometry ().x ();
	curY=this->geometry ().y ();

	maxX = widgetLength - geometry().width();
	maxY = widgetWidth - geometry().height();

	connect(ui.pushButton_fly,SIGNAL(clicked()),this,SLOT(onFlyClicked ()));
	connect(ui.pushButton_shake,SIGNAL(clicked()),this,SLOT(onShakeClicked ()));
	connect(ui.pushButton_setup, SIGNAL(clicked()), this, SLOT(onSetupClicked()));
	
	isShaking = false;
	isFlying = false;

	xless = false;
	yless = false;

	setFixedSize(500, 500);
}

FlyingBox::~FlyingBox()
{

}

void FlyingBox::onShakeClicked()
{
	if (isShaking)
		stopShaking(pAnimation);
	else
		shake(option.shakeRange, option.shakeCounts);
}

void FlyingBox::shake (int nRange,int nShakeCount)
{	
	int nX =QApplication::desktop ()->availableGeometry ().width ()/2-this->width ()/2; 
	int nY =QApplication::desktop ()->availableGeometry ().height ()/2-this->height ()/2;
	pAnimation = new QPropertyAnimation(this,"geometry",this);
	pAnimation->setEasingCurve(QEasingCurve::InOutSine);			//动画效果
	pAnimation->setDuration(1000);								//动画持续的时长，100为1秒
	pAnimation->setLoopCount (100);
	pAnimation->setStartValue(QRect(QPoint(nX,nY),this->size()));	//动画起始位置

	double nStep = 1.0/nShakeCount;

	//让窗口上下左右轮流移动、归位，形成窗口晃动的效果
	for(int i = 1; i < nShakeCount; i++)
	{	
		nRange = i&1 ? -nRange : nRange;
		if(i%2==0)
		{	
			pAnimation->setKeyValueAt(nStep*i,QRect(QPoint(nX +nRange,nY),this->size()*1.01)); //向右移动
			
		}
		else
		{	
			pAnimation->setKeyValueAt(nStep*i,QRect(QPoint(nX,nY+nRange),this->size()/1.01)); //向上移动
			
		}

	}
	pAnimation->setEndValue(QRect(QPoint(nX,nY),this->size()));
	pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
	isShaking = true;
}

void FlyingBox::stopShaking(QPropertyAnimation* animation)
{
	animation->stop();
	isShaking = false;
}

void FlyingBox::onFlyClicked()
{
	fly();
}

void FlyingBox::fly ()
{	
	isFlying = true;

	//随机飞行模式
	if (option.flyingMode == FLYING_RANDOM)
	{
		pAnimation = new QPropertyAnimation(this, "geometry", this);
		pAnimation->setEasingCurve(QEasingCurve::InOutSine);			//动画效果

		static default_random_engine e;
		static uniform_int_distribution<int> u(0, 3000);
		pAnimation->setDuration(u(e)); //随机指定动画持续的时长

		pAnimation->setStartValue(QRect(QPoint(curX, curY), this->size()));	//动画起始位置
		pAnimation->setEndValue(QRect(getRandomPoint(), this->size()));			//动画终点位置
		pAnimation->start(QAbstractAnimation::DeleteWhenStopped);			//开始动画
		connect(pAnimation, SIGNAL(finished()), this, SLOT(changeFlyDirection()));
	}
	else
	{
		pAnimation = new QPropertyAnimation(this, "geometry", this);
		pAnimation->setEasingCurve(QEasingCurve::InOutSine);			//动画效果
		pAnimation->setDuration(1500);									//动画持续的时长(6秒)
		pAnimation->setStartValue(QRect(QPoint(curX, curY), this->size()));	//动画起始位置

		QPoint tmpPoint = getFinalPoint(curX, curY);
		//QPoint tmpPoint(widgetLength-geometry().width(), widgetWidth * 0.8);
		pAnimation->setEndValue(QRect(tmpPoint, this->size()));				//动画终点位置
		pAnimation->start(QAbstractAnimation::DeleteWhenStopped);			//开始动画
		connect(pAnimation, SIGNAL(finished()), this, SLOT(changeFlyDirection()));
	}
	
}
void FlyingBox::changeFlyDirection()
{
	pAnimation = new QPropertyAnimation(this, "geometry", this);
	pAnimation->setEasingCurve(QEasingCurve::InOutSine);			//动画效果
	pAnimation->setDuration(1500);									//动画持续的时长(6秒)
	pAnimation->setStartValue(QRect(QPoint(curX, curY), this->size()));	//动画起始位置
	QPoint tmpPoint = getFinalPoint(curX, curY);
	pAnimation->setEndValue(QRect(tmpPoint, this->size()));				//动画终点位置
	pAnimation->start(QAbstractAnimation::DeleteWhenStopped);			//开始动画
	connect(pAnimation, SIGNAL(finished()), this, SLOT(changeFlyDirection()));
}

QPoint FlyingBox::getFinalPoint (int &curX,int &curY)
{	
	int x,y;		 //窗口横向和纵向距离屏幕边缘的距离
	int rectX{curX},rectY{curY}; //窗口抵达屏幕边缘时的横坐标和纵坐标

	int offsetX, offsetY;
	if (xless)
	{
		offsetX = 1;
		offsetY = yless ? -1 : 1;	
	}
	else
	{
		offsetX = -1;
		offsetY = yless ? 1 : -1;
	}

	rectX += offsetX;
	rectY += offsetY;

	while (rectX > 0  && rectX < maxX  && rectY > 0 && rectY < maxY)
	{
		rectX += offsetX;
		rectY += offsetY;
	}

	xless = rectX < curX ? true : false;
	yless = rectY < curY ? true : false;

	return {rectX, rectY};
}

QPoint FlyingBox::getRandomPoint()
{
	static default_random_engine e;
	static uniform_int_distribution<int> uLength(0,widgetLength);
	static uniform_int_distribution<int> uHeight(0, widgetWidth);
	return {uLength(e),uHeight(e)};
}

void FlyingBox::paintEvent (QPaintEvent *)
{	
	update ();
	ui.textEdit->clear ();
	
	ui.textEdit->append(tr("屏幕长度：")+QString::number (widgetLength));
	ui.textEdit->append(tr("屏幕宽度：")+QString::number (widgetWidth));

	curX=this->geometry ().x ();
	curY=this->geometry ().y ();
	ui.textEdit->append(tr("X：")+QString::number (curX));
	ui.textEdit->append(tr("Y：")+QString::number (curY));

	ui.textEdit->append(tr("当前飞行模式:") + 
		(option.flyingMode == FLYING_RANDOM ? QString(tr("乱飞模式")) : QString(tr("反弹模式"))));
	ui.textEdit->append(tr("摇晃范围(像素):")+QString::number(option.shakeRange));
	ui.textEdit->append(tr("摇晃次数:") + QString::number(option.shakeCounts));

/*
	if (!isFlying)
		return ;
	if (curX <= 0 || curX >= maxX || curY <= 0 || curY >= maxY)
	{
		pAnimation->stop();
		changeFlyDirection();
	}
*/

}


void FlyingBox::onSetupClicked()
{
	Setup st(option);
	if (st.exec() == QDialog::Accepted)
	{
		option = st.getOption();
	}
}