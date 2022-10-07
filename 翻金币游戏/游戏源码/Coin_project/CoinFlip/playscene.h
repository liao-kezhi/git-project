#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include"mycoin.h"
#include <QMainWindow>
#include<QDebug>
#include<QTimer>
class playscene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit playscene(QWidget *parent = nullptr);
    playscene(int levelNum);

    int levelIndex;  //内部成员属性，记录所选的关卡

    //重写painterEvent事件
    void paintEvent(QPaintEvent *);

// vector<vector<int>>;
    int gameArray[4][4];  //二维数组  维护每个关卡的具体数据

    MyCoin * coinBtn[4][4];

    //是否胜利的标志
    bool isWin = false;

signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
