#include "mycoin.h"

//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{

//}
MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug()<<str;
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器对象
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    //监听正面翻反面的信号，并且翻转金币
    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:Opx;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断 如果翻完了，将min重置为1
        if(this->min > this->max)
        {
            this->min = 1;
            this->isAnmation = false;
            timer1->stop();
        }
    });

    //监听反面翻正的信号，并且翻转金币
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:Opx;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断 如果翻完了，将min重置为1
        if(this->max < this->min)
        {
            this->max = 8;
            this->isAnmation = false;
            timer2->stop();
        }
    });
}

//重新  按下
void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnmation || this->isWin)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}

//改变标志的方法
void  MyCoin::changeFlag()
{
    //如果是正面，翻成反面
    if(this->flag)
    {
        //开始正面翻反面的定时器
        timer1->start(30);
        this->isAnmation = true;  //开始做动画
        this->flag = false;

    }
    else  //反面翻正面
    {
        timer2->start(30);
        this->isAnmation = true;  //开始做动画
        this->flag = true;
    }
}
