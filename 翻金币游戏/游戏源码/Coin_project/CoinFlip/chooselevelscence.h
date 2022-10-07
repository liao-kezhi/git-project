#ifndef CHOOSELEVELSCENCE_H
#define CHOOSELEVELSCENCE_H

#include <QMainWindow>
#include"playscene.h"

class ChooseLevelScence : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScence(QWidget *parent = nullptr);

    //重写绘图事件
    void paintEvent(QPaintEvent *);

    //游戏场景对象指针
    playscene * play = NULL;

signals:
    //写一个自定义信号，告诉主场景  点击了返回
    void chooseSceneBack();  //自定义信号只需要声明不需要实现
};

#endif // CHOOSELEVELSCENCE_H
