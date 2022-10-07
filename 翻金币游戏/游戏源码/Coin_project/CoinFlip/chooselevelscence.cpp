#include "chooselevelscence.h"
#include<QMenu>
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QLabel>
#include<QSound>

ChooseLevelScence::ChooseLevelScence(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(400,700);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("选择关卡场景");

    //创建菜单栏addMenu("开始");
    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");

    //创建退出  菜单项
    QAction * quitAction = startMenu->addAction("退出");

    //点击退出，实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //选择关卡按钮音效
    QSound * chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    //返回按钮音效
    QSound * backSound = new QSound(":/res/BackButtonSound.wav",this);

    //返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png",":res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //点击返回按钮
    connect(backBtn,&MyPushButton::clicked,[=](){
//        qDebug()<<"点击了BACK按钮";
        //告诉主场景 我返回了，主场景监听chooseLevelScene的返回按钮
        //延时返回
        //播放返回按钮音效
        backSound->play();

        QTimer::singleShot(200,this,[=](){
            emit this->chooseSceneBack();
        });
//        emit this->chooseSceneBack();
    });
    //创建选择关卡的按钮
    for(int i = 0;i < 20;i++)
    {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(70+i%4 * 70,140+i/4 *80);

//        menuBtn->setText(QString::number(i+1));
        //监听每个按钮的点击事件
        connect(menuBtn,&MyPushButton::clicked,[=](){
            //播放选择关卡音效
            chooseSound->play();

            QString str = QString("你选择的是第 %1 个").arg(i+1);
            qDebug()<<str;

            //进入到游戏场景
            this->hide();  //将选关场景隐藏
            play = new playscene(i+1);  //创建游戏场景
            //设置游戏场景的初始位置
            play->setGeometry(this->geometry());
            play->show();   //显示游戏场景

            connect(play,&playscene::chooseSceneBack,[=](){
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = NULL;
            });
        });

        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(70+i%4 * 70,140+i/4 *80);

        //设置label上的文字对齐方式 水平居中和垂直居中
        label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        //设置让鼠标进行穿透  51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

//重写绘图事件
void ChooseLevelScence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //制作背景
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上图标
    pix.load(":/res/Title.png");

    //收缩图标
//    pix = pix.scaled(pix.width() * 0.5,pix.height() * 0.5);
    painter.drawPixmap((this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
