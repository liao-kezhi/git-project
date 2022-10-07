#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QPixmap>
#include<QDir>
#include<QDebug>
#include"mypushbutton.h"
#include<QTimer>
#include<QSound>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);


    //配置主场景

    //设置固定大小
    setFixedSize(400,700);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币主场景");

    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
       this->close();
    });

    //准备开始按钮的音效
    QSound * startSound = new QSound(":/res/TapButtonSound.wav",this);
//    startSound->setLoops(10);  //设置循环  如果是-1，代表无限循环
//    startSound->play();


    //开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5,this->height() * 0.7);

    //示例化选择关卡场景
    chooseScence = new ChooseLevelScence;

    //监听选择关卡的返回按钮的信号  只需要一次链接即可
    connect(chooseScence,&ChooseLevelScence::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScence->geometry());
        chooseScence->hide();    //将选择关卡场景 隐藏掉
        this->show();    //重新显示主场景

    });
    connect(startBtn,&MyPushButton::clicked,[=](){
       qDebug()<<"点击了开始";
       //播放开始音效资源
       startSound->play();
       startBtn->zoom1();
       startBtn->zoom2();


       //延时0.5s进入到选择关卡场景中
       QTimer::singleShot(500,this,[=](){
           //设置chooseScene场景的位置
           chooseScence->setGeometry(this->geometry());

           //自身隐藏
           this->hide();
           //显示选择关卡场景
           chooseScence->show();

       });

    });
}

//重新paintEvent事件  画背景图
void MainScene::paintEvent(QPaintEvent *)
{
//    QString pixmap_url = ":/res/PlayLevelSceneBg.png";
//    QImage image(pixmap_url);  //定义QImage对象，读取图片
//    if(image.isNull()){
//        qDebug()<<"读取图片错误";
//    }
//    else{
//        image.save(pixmap_url,"PNG");
//    }

    QPainter painter(this);
    //加载图片
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    //绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上图标
    pix.load(":/res/Title.png");

    //收缩图标
    pix = pix.scaled(pix.width() * 0.5,pix.height() * 0.5);
    painter.drawPixmap(100,30,pix);
}

MainScene::~MainScene()
{
    delete ui;
}

