#ifndef MAINSCENE_H
#define MAINSCENE_H
#include<QPaintEvent>
#include <QMainWindow>
#include"chooselevelscence.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //重新paintEvent事件  画背景图
//    void painEvent(QPaintEvent *);
    void paintEvent(QPaintEvent *);

    ChooseLevelScence * chooseScence = NULL;

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
