## 1	Qt概述

### 1.1	什么是Qt

Qt是一个**跨平台**的C++图像用户应用程序框架。它是完全**面向对象的**，很容易扩展，并且允许真正的组件编程。

### 1.2	Qt的发展历史

1991年 Qt最早由奇趣科技开发

1991年 Qt最早由奇趣科技开发

1996年 进入商业领域，它也是目前流行的Linux桌面环境KDE的基础

2008年 奇趣科技被诺基亚公司收购，Qt称为诺基亚旗下的编程语言

2012年 Qt又被Digia公司收购

2014年4月 跨平台的集成开发环境Qt Creator3.1.0发布，同年5月20日配发了Qt5.3正式版，至此Qt实现了对iOS、Android、WP等各平台的全面支持。

当前Qt最新版本为 6.3.2



### 1.3	支持平台

- Windows – XP、Vista、Win7、Win8、Win2008、Win10

- Uinux/X11 – Linux、Sun Solaris、HP-UX、Compaq Tru64 UNIX、IBM AIX、SGI IRIX、FreeBSD、BSD/OS、和其他很多X11平台

- Macintosh – Mac OS X

- Embedded – 有帧缓冲支持的嵌入式Linux平台，Windows CE

### 1.4	Qt版本

Qt按照不同的版本发行，分为商业版和开源版

- 商业版

​		为商业软件提供开发，他们提供传统商业软件发行版，并且提供在商业有效期内的免费升级和技术支持服务。

- 开源的LGPL版本：

​         为了开发自有而设计的开放源码软件，它提供了和商业版本同样的功能，在GNU通用公共许可下，它是免费的。

### 1.5	Qt的下载与安装

**1、下载地址：**

> https://download.qt.io/archive/qt/

![04](picture\04.png)



**2、安装**

默认安装（建议组件全部选中）

· Qt对不同的平台提供了不同版本的安装包，可根据实际情况自行下载安装，本文档使用**qt-opensource-windows-x86-mingw482_opengl-5.14.1** 版本进行讲解

### 1.6	Qt优点

1. 跨平台，几乎支持所有的平台
2. 接口简单，容易上手，信息QT框架对线性其他框架有参考意义
3. 一定程度上简化了内存回收机制
4. 开发效率高，能够快速的构建应用程序
5. 有很好的社区氛围，市场份额持续上升
6. 可以进行嵌入式开发

### 1.7	成功案例

1. Linux桌面环境KDE

2. WPS Office 办公软件

3. Skype 网络电话

4. Google Earth 谷歌地图

5. VLC多媒体播放器

6. VirtualBox虚拟机软件
7. ..........

**总结:**

```c
1Qt简介
1.1跨平台图形界面引擎
1.2历史
1.2.11991  奇趣科技
1.3优点
    1.3.1跨平台
    1.3.2接口简单，容易上手
    1.3.3一定程度上简化了内存回收
1.4版本
    1.4.1商业版
    1.4.2开源版
1.5成功案例
    1.5.1Linux桌面环境 KDE
    1.5.2谷歌地图
    1.5.3VLC多媒体播放器
    1.5.4…
```



## 2	创建QT项目

### 2.1	使用向导创建

打开Qt Creator 界面选择 New Project或者选择菜单栏 【文件】-【新建文件或项目】菜单项

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml14864\wps1.jpg)

弹出New Project对话框，选择Qt Widgets Application， 

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml14864\wps2.jpg) 

选择【Choose】按钮，弹出如下对话框

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml14864\wps3.jpg) 

设置项目名称和路径，按照向导进行下一步，

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml14864\wps4.jpg) 

选择编译套件

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml14864\wps5.jpg) 

向导会默认添加一个继承自CMainWindow的类，可以在此修改类的名字和基类。默认的基类有QMainWindow、QWidget以及QDialog三个，我们可以选择QWidget（类似于空窗口），这里我们可以先创建一个不带UI的界面，继续下一步

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml14864\wps6.jpg) 

系统会默认给我们添加main.cpp、mywidget.cpp、 mywidget.h和一个.pro项目文件，点击完成，即可创建出一个Qt桌面程序。

 

### 2.2 	手动创建

添加一个空项目

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml14864\wps7.jpg)

选择【choose】进行下一步。设置项目名称和路径 —> 选择编译套件 --> 修改类信息 --> 完成（步骤同上），生成一个空项目。在空项目中添加文件：在项目名称上单击鼠标右键弹出右键菜单，选择【添加新文件】

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml14864\wps8.jpg) 

弹出新建文件对话框

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml14864\wps9.jpg) 

在此对话框中选择要添加的类或者文件，根据向导完成文件的添加。

### 2.3	.pro文件

在使用Qt向导生成的应用程序.pro文件格式如下：

 ```c
 QT       += core gui
 
 greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
 
 CONFIG += c++11
 
 # The following define makes your compiler emit warnings if you use
 # any Qt feature that has been marked deprecated (the exact warnings
 # depend on your compiler). Please consult the documentation of the
 # deprecated API in order to know how to port your code away from it.
 DEFINES += QT_DEPRECATED_WARNINGS
 
 # You can also make your code fail to compile if it uses deprecated APIs.
 # In order to do so, uncomment the following line.
 # You can also select to disable deprecated APIs only up to a certain version of Qt.
 #DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
 
 SOURCES += \
     main.cpp \
     student.cpp \
     teacher.cpp \
     widget.cpp
 
 HEADERS += \
     student.h \
     teacher.h \
     widget.h
 
 FORMS += \
     widget.ui
 
 # Default rules for deployment.
 qnx: target.path = /tmp/$${TARGET}/bin
 else: unix:!android: target.path = /opt/$${TARGET}/bin
 !isEmpty(target.path): INSTALLS += target
 
 ```

**.pro就是工程文件(project)，它是qmake自动生成的用于生产makefile的配置文件**。.pro文件的写法如下：

- 注释

从“#”开始，到这一行结束。

- 模板变量告诉qmake为这个应用程序生成哪种makefile。下面是可供使用的选择：**TEMPLATE** = app

- app -建立一个应用程序的makefile。这是默认值，所以如果模板没有被指定，这个将被使用。

- lib - 建立一个库的makefile。

- vcapp - 建立一个应用程序的VisualStudio项目文件。

- vclib - 建立一个库的VisualStudio项目文件。

- subdirs -这是一个特殊的模板，它可以创建一个能够进入特定目录并且为一个项目文件生成makefile并且为它调用make的makefile。

- #指定生成的应用程序名： 

**TARGET** = QtDemo

- #工程中包含的头文件

**HEADERS** += include/painter.h

- #工程中包含的.ui设计文件

**FORMS** += forms/painter.ui

- #工程中包含的源文件

**SOURCES** += sources/main.cpp sources

- #工程中包含的资源文件

**RESOURCES** += qrc/painter.qrc

- **greaterThan(QT_MAJOR_VERSION, 4): QT += widgets**

**这条****语句的含义是，如果QT_MAJOR_VERSION****大于4（也就是****当前使用的Qt5****及****更高版本）****需要****增加widgets模块。如果****项目****仅需****支持****Qt5****，****也可以直接添加“QT += widgets”一句。不过为了保持代码****兼容****，最好还是按照QtCreator生成的语句编写。**

- #配置信息

CONFIG用来告诉qmake关于应用程序的配置信息。

CONFIG += c++11	//使用c++11的特性

在这里使用“+=”，是因为我们添加我们的配置选项到任何一个已经存在中。这样做比使用“=”那样替换已经指定的所有选项更安全。

### 2.4 一个最简单的Qt应用程序

main.cpp

```c
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
```

解释：

- Qt系统提供的标准类名声明头文件没有.h后缀

- Qt一个类对应一个头文件，类名就是头文件名

- QApplication应用程序类

- 管理图形用户界面应用程序的控制流和主要设置。

- 是Qt的整个后台管理的命脉它**包含主事件循环**，在其中来自窗口系统和其它资源的**所有事件处理和调度**。它也处理**应用程序的初始化和结束**，并且**提供对话管理**。

- 对于任何一个使用Qt的图形用户界面应用程序，都正好存在一个QApplication 对象，而不论这个应用程序在同一时间内是不是有0、1、2或更多个窗口。

- a.exec()

**程序进入消息循环**，等待对用户输入进行响应。这里main()把控制权转交给Qt，Qt完成事件处理工作，当应用程序退出的时候exec()的值就会返回。**在exec()中，Qt接受并处理用户和系统的事件并且把它们传递给适当的窗口部件。**

 



## 3	第一个QT小程序

### 3.1	按键的创建

在Qt程序中，最常用的控件之一就是按钮了，首先我们来看下如何创建一个按钮

```c
QPushButton * btn = new QPushButton; 头文件 #include <QPushButton>

    //设置父亲
    btn->setParent(this);
    //设置文字
    btn->setText("德玛西亚");
    //移动位置
    btn->move(100,100);

    //第二种创建
    QPushButton * btn2 = new QPushButton("孙悟空",this);
    //重新指定窗口大小
    this->resize(600,400);

    //设置窗口标题
    this->setWindowTitle("第一个项目");

    //限制窗口大小
    this->setFixedSize(600,400);
```

上面代码中，一个按钮其实就是一个QPushButton类下的对象，如果只是创建出对象，是无法显示到窗口中的，所以我们需要依赖一个父窗口，也就是指定一个父亲利用setParent函数即可，如果想设置按钮上显示的文字利用setText，移动按钮位置用move

​	对于窗口而言，我们可以修改左上角窗口的标题setWindowTitle，重新指定窗口大小：resize，或者设置固定的窗口大小setFixedSize；

### 3.2	对象模型（对象树）

在Qt中创建对象的时候会提供一个Parent对象指针，下面来解释这个parent到底是干什么的。

-  QObject是以对象树的形式组织起来的。

  -  当你创建一个QObject对象时，会看到QObject的构造函数接收一个QObject指针作为参数，这个参数就是 parent，也就是父对象指针。这相当于，**在创建QObject对象时，可以提供一个其父对象，我们创建的这个QObject对象会自动添加到其父对象的children()列表。**

  -  **当父对象析构的时候，这个列表中的所有对象也会被析构。（注意，这里的父对象并不是继承意义上的父类！）**这种机制在 GUI 程序设计中相当有用。例如，一个按钮有一个QShortcut（快捷键）对象作为其子对象。当我们删除按钮的时候，这个快捷键理应被删除。这是合理的。

- QWidget是能够在屏幕上显示的一切组件的父类。

  -  **QWidget继承自QObject，因此也继承了这种对象树关系。一个孩子自动地成为父组件的一个子组件**。因此，它会显示在父组件的坐标系统中，被父组件的边界剪裁。例如，当用户关闭一个对话框的时候，应用程序将其删除，那么，我们希望属于这个对话框的按钮、图标等应该一起被删除。事实就是如此，因为这些都是对话框的子组件。

  -  当然，**我们也可以自己删除子对象，它们会自动从其父对象列表中删除。**比如，当我们删除了一个工具栏时，其所在的主窗口会自动将该工具栏从其子对象列表中删除，并且自动调整屏幕显示。

Qt 引入对象树的概念，在一定程度上解决了内存问题。

-  当一个QObject对象在堆上创建的时候，Qt 会同时为其创建一个对象树。不过，对象树中对象的顺序是没有定义的。这意味着，销毁这些对象的顺序也是未定义的。

-  任何对象树中的 QObject对象 delete 的时候，如果这个对象有 parent，则自动将其从 parent 的children()列表中删除；如果有孩子，则自动 delete 每一个孩子。Qt 保证没有QObject会被 delete 两次，这是由析构顺序决定的。

如果QObject在栈上创建，Qt 保持同样的行为。正常情况下，这也不会发生什么问题。来看下下面的代码片段：

```c
{
    QWidget window;
    QPushButton quit("Quit", &window);
}
```

作为父组件的 window 和作为子组件的 quit 都是QObject的子类（事实上，它们都是QWidget的子类，而QWidget是QObject的子类）。这段代码是正确的，quit 的析构函数不会被调用两次，因为标准 C++要求，**局部对象的析构顺序应该按照其创建顺序的相反过程**。因此，这段代码在超出作用域时，会先调用 quit 的析构函数，将其从父对象 window 的子对象列表中删除，然后才会再调用 window 的析构函数。

但是，如果我们使用下面的代码：

```c
{
    QPushButton quit("Quit");
    QWidget window;
    quit.setParent(&window);
}
```

情况又有所不同，析构顺序就有了问题。我们看到，在上面的代码中，作为父对象的 window 会首先被析构，因为它是最后一个创建的对象。在析构过程中，它会调用子对象列表中每一个对象的析构函数，也就是说， quit 此时就被析构了。然后，代码继续执行，在 window 析构之后，quit 也会被析构，因为 quit 也是一个局部变量，在超出作用域的时候当然也需要析构。但是，这时候已经是第二次调用 quit 的析构函数了，C++ 不允许调用两次析构函数，因此，程序崩溃了。

由此我们看到，Qt 的对象树机制虽然帮助我们在一定程度上解决了内存问题，但是也引入了一些值得注意的事情。这些细节在今后的开发过程中很可能时不时跳出来烦扰一下，所以，我们最好从开始就养成良好习惯，在 Qt 中，尽量在构造的时候就指定 parent 对象，并且大胆在堆上创建。

### 3.3	Qt窗口坐标体系

坐标体系：

以左上角为原点（0,0），X向右增加，Y向下增加。

![](qt_picture/09.png)

对于嵌套窗口，其坐标是**相对于父窗口**来说的。

**01_FirstProject**

![](qt_picture/12.png)

main.cpp

```c
#include "mywidget.h"

#include <QApplication> //包含一个应用程序的类

//main程序入口  argc命令行变量的数量   argc命令行变量的数组
int main(int argc, char *argv[])
{
    //a应用程序对象，在Qt中，应用程序对象，有且仅有一个
    QApplication a(argc, argv);
    //窗口对象，mywidget  父类是   ->  Qwidget
    myWidget w;
    //窗口对象，默认不会显示，必须要调用show方法显示窗口
    w.show();

    //让应用程序对象进入消息循环
    return a.exec();

//    while(true)
//    {
//        if(点击叉子)
//        {
//            break;
//        }
//    }
}

```

mypusbutton.h

```c
#ifndef MYPUSBUTTON_H
#define MYPUSBUTTON_H

#include <QPushButton>

class myPusButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPusButton(QWidget *parent = nullptr);
//    myPusButton();
    ~myPusButton();

signals:

};

#endif // MYPUSBUTTON_H

```

mypusbutton.cpp

```c
#include "mypusbutton.h"
#include<QDebug>

myPusButton::myPusButton(QWidget *parent) : QPushButton(parent)
{
    qDebug()<<"我的按钮构造";
}

myPusButton::~myPusButton()
{
    qDebug()<<"我的按钮类析构";
}

```

mywidget.h

```c
#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>  //包含头文件 QWidget  窗口类

class myWidget : public QWidget
{
    Q_OBJECT        //允许使用循环和槽的机制

public:
    myWidget(QWidget *parent = nullptr);       //构造函数
    ~myWidget();    //析构函数
};
#endif // MYWIDGET_H

```

mywidget.cpp

```c
#include "mywidget.h"
#include<QPushButton>   //按钮控件的头文件
#include"mypusbutton.h"
#include<QDebug>

//命名规范
//类名    首字母大写，单词和单词之间首字母大写
//函数名   变量名称    首字母小写，单词和单词之间首字母大写

//快捷键
//注释    ctrl + /
//运行    ctrl + r
//编译    ctrl + b
//字体缩放 ctrl + 鼠标滑轮
//查找     ctrl + f
//整行移动  ctrl + shift + 上、下键
//帮助文档  F1
//自动对齐  ctrl + i
//同名之间的.h 和 .cpp 切换 F4
//打开帮助文档 第一种： F1  第二种：左侧按钮  第三种：D:\studyyuanjian\Qt5_14_1\5.14.1\mingw73_64\bin



myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn = new QPushButton;
    btn->show();    //show以顶层方式弹出窗口控件
    //让btn对象 依赖在mywidget窗口中
    btn->setParent(this);

    btn->move(10,10);

    //显示 文本
    btn->setText("第一个按钮");

    //创建第二个按钮,按照控件的大小创建窗口
    QPushButton *btn2 = new QPushButton("第二个按钮",this);

    //移动btn2按钮
    btn2->move(100,100);

    //按钮也可以设置大小
    btn2->resize(80,50);

    //重置窗口大小
    resize(600,400);

    setFixedSize(600,400);

    //设置窗口标题
    setWindowTitle("第一个窗口");

    //创建一个自己的按钮对象
    myPusButton *myBtn = new myPusButton;
    myBtn->setText("我自己的按钮");

    myBtn->move(50,50);
    myBtn->setParent(this); //设置到对象树中，结束时自动释放

    //需求  点击我的按钮关闭窗口
    //参数1：信号的发送者    参数2：发送的信号（函数的地址）    参数3：信号的接收者  参数4：处理的槽函数
//    connect(myBtn,&myPusButton::clicked,this,&myWidget::close);
    connect(myBtn,&QPushButton::clicked,this,&QWidget::close);

}

myWidget::~myWidget()
{
    qDebug()<<"myWidget析构调用";
}


```

**运行结果：**

![](qt_picture/11.png)



## 4	信号和槽机制

信号槽是 Qt 框架引以为豪的机制之一。所谓信号槽，实际就是观察者模式。**当某个事件发生之后**，比如，按钮检测到自己被点击了一下，**它就会发出一个信号（signal）**。这种发出是没有目的的，类似广播。**如果有对象对这个信号感兴趣，它就会使用连接（connect）函数**，意思是，**将想要处理的信号和自己的一个函数（称为槽（slot））绑定来处理这个信号**。也就是说，**当信号发出时，被连接的槽函数会自动被回调**。这就类似观察者模式：当发生了感兴趣的事件，某一个操作就会被自动触发。

### 4.1	系统自带的信号和槽

下面我们完成一个小功能，上面我们已经学习了按钮的创建，但是还没有体现出按钮的功能，按钮最大的功能也就是点击后触发一些事情，比如我们点击按钮，就把当前的窗口给关闭掉，那么在Qt中，这样的功能如何实现呢？

​	其实无法两行代码就可以搞定了，我们看下面的代码

```c
QPushButton * quitBtn = new QPushButton("关闭窗口",this);
connect(quitBtn,&QPushButton::clicked,this,&MyWidget::close);
```

第一行是创建一个关闭按钮，这个之前已经学过，第二行就是核心了，也就是信号槽的使用方式

connect()函数最常用的一般形式：

> connect(sender, signal, receiver, slot);

参数解释：

- sender：发出信号的对象

- signal：发送对象发出的信号

- receiver：接收信号的对象

- slot：接收对象在接收到信号之后所需要调用的函数（槽函数）

那么系统自带的信号和槽通常如何查找呢，这个就需要利用帮助文档了，在帮助文档中比如我们上面的按钮的点击信号，在帮助文档中输入QPushButton，首先我们可以在Contents中寻找关键字 signals，信号的意思，但是我们发现并没有找到，这时候我们应该想到也许这个信号的被父类继承下来的，因此我们去他的父类QAbstractButton中就可以找到该关键字，点击signals索引到系统自带的信号有如下几个

![](qt_picture/10.png)

这里的clicked就是我们要找到，槽函数的寻找方式和信号一样，只不过他的关键字是slot。

### 4.2	自定义信号和槽

使用connect()可以让我们连接系统提供的信号和槽。但是，Qt 的信号槽机制并不仅仅是使用系统提供的那部分，还会允许我们自己设计自己的信号和槽。

下面我们看看使用 Qt 的信号槽：

```c
首先定义一个学生类和老师类：
	老师类中声明信号 饿了 hungry
signals:
       void hungury();
	学生类中声明槽   请客 treat
	public slots:
       void treat();
	在窗口中声明一个公共方法下课，这个方法的调用会触发老师饿了这个信号，而响应槽函数学生请客
	void MyWidget::ClassIsOver()
{
    //发送信号
    emit teacher->hungury();
}
	学生响应了槽函数，并且打印信息
//自定义槽函数 实现
void Student::eat()
{
       qDebug() << "该吃饭了！";
}
在窗口中连接信号槽
    teacher = new Teacher(this);
    student = new Student(this);

    connect(teacher,&Teacher::hungury,student,&Student::treat);
并且调用下课函数，测试打印出 “该吃饭了”
```

```c
自定义的信号 hungry带参数，需要提供重载的自定义信号和 自定义槽
void hungury(QString name);  自定义信号
void treat(QString name );    自定义槽
但是由于有两个重名的自定义信号和自定义的槽，直接连接会报错，所以需要利用函数指针来指向函数地址， 然后在做连接
void (Teacher:: * teacherSingal)(QString) = &Teacher::hungury;
void (Student:: * studentSlot)(QString) = &Student::treat;
connect(teacher,teacherSingal,student,studentSlot);
```

**自定义信号槽需要注意的事项****：**

- **发送者和接收者都需要是QObject的子类（当然，槽函数是全局函数、Lambda 表达式等无需接收者的时候除外）；**

- **信号和槽函数返回值是 void**

- **信号只需要声明，不需要实现**

- **槽函数需要声明也需要实现**

- **槽函数是普通的成员函数，作为成员函数，会受到 public、private、protected 的影响；**

- **使用 emit 在恰当的位置发送信号；**

- **使用connect()函数连接信号和槽。**

- **任何成员函数、static 函数、全局函数和 Lambda 表达式都可以作为槽函数**

- **信号槽要求信号和槽的参数一致，所谓一致，是参数类型一致。**

- **如果信号和槽的参数不一致，允许的情况是，槽函数的参数可以比信号的少，即便如此，槽函数存在的那些参数的顺序也必须和信号的前面几个一致起来。这是因为，你可以在槽函数中选择忽略信号传来的数据（也就是槽函数的参数比信号的少）。**



### 4.3	信号槽的拓展



- 一个信号可以和多个槽相连

**如果是这种情况，这些槽会一个接一个的被调用，但是它们的****调用顺序是不确定的。**

- 多个信号可以连接到一个槽

**只要任意一个信号发出，这个槽就会被调用**。

- 一个信号可以连接到另外的一个信号

**当第一个信号发出时，第二个信号被发出。除此之外，这种信号-信号的形式和信号-槽的形式没有什么区别。**

- 槽可以被取消链接

这种情况并不经常出现，因为**当一个对象delete之后，Qt自动取消所有连接到这个对象上面的槽**。

- 信号槽可以断开

利用**disconnect**关键字是可以断开信号槽的

- 使用Lambda 表达式

在使用 Qt 5 的时候，能够支持 Qt 5 的编译器都是支持 Lambda 表达式的。

​	在连接信号和槽的时候，槽函数可以使用Lambda表达式的方式进行处理。后面我们会详细介绍什么是Lambda表达式



### 4.4	QT4版本的信号槽写法

> connect(zt,**SIGNAL**(hungry(QString)),st,**SLOT**(treat(QString)));

这里使用了**SIGNAL和SLOT这两个宏，将两个函数名转换成了字符串**。注意到connect()函数的 signal 和 slot 都是接受字符串，一旦出现连接不成功的情况，Qt4是没有编译错误的（因为一切都是字符串，编译期是不检查字符串是否匹配），而是在运行时给出错误。这无疑会增加程序的不稳定性。

Qt5在语法上完全兼容Qt4，而反之是不可以的。

### 4.5	Lambda表达式

```c
capture](parameters) mutable ->return-type
{
statement
}
```

[函数对象参数](操作符重载函数参数)mutable ->返回值{函数体}

 

① 函数对象参数；

[]，标识一个**Lambda的开始**，这部分必须存在，**不能省略**。函数对象参数是传递给编译器自动生成的函数对象类的构造函数的。函数对象参数只能使用那些到定义Lambda为止时Lambda所在作用范围内可见的局部变量（包括Lambda所在类的this）。函数对象参数有以下形式：

- 空。没有使用任何函数对象参数。

- =。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是**值传递方式**（相当于编译器自动为我们按值传递了所有局部变量）。

- &。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是**引用传递方式**（相当于编译器自动为我们按引用传递了所有局部变量）。

- this。函数体内可以使用Lambda所在类中的成员变量。

- a。将a按值进行传递。按值进行传递时，函数体内不能修改传递进来的a的拷贝，因为默认情况下函数是const的。**要修改传递进来的a的拷贝**，可以添加mutable修饰符。

- &a。将a按引用进行传递。

- a, &b。将a按值进行传递，b按引用进行传递。

- =，&a, &b。除a和b按引用进行传递外，其他参数都按值进行传递。

- &, a, b。除a和b按值进行传递外，其他参数都按引用进行传递。

② 操作符重载函数参数；

标识重载的()操作符的参数，没有参数时，这部分可以省略。参数可以通过按值（如：(a,b)）和按引用（如：(&a,&b)）两种方式进行传递。

③ 可修改标示符；

mutable声明，这部分可以省略。按值传递函数对象参数时，加上mutable修饰符后，可以修改按值传递进来的拷贝（注意是能修改拷贝，而不是值本身）。

```c
 QPushButton * myBtn = new QPushButton (this);
    QPushButton * myBtn2 = new QPushButton (this);
    myBtn2->move(100,100);
    int m = 10;

    connect(myBtn,&QPushButton::clicked,this,[m] ()mutable { m = 100 + 10; qDebug() << m; });

    connect(myBtn2,&QPushButton::clicked,this,[=] ()  { qDebug() << m; });

    qDebug() << m;
```

④ 函数返回值；

​	->返回值类型，标识函数返回值的类型，当返回值为void，或者函数体中只有一处return的地方（此时编译器可以自动推断出返回值类型）时，这部分可以省略。

⑤ 是函数体；

​	{}，标识函数的实现，这部分不能省略，但函数体可以为空。



**项目名称：02_Singan_And_Slot**

![](qt_picture/13.png)



**student.h**

```c
#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    //早期Qt版本必须要写到public  slots下，高级版本可以写到public或者全局下
    //返回值void，需要声明，也需要实现
    //可以有参数，可以发生重载
    void treat();

    void treat(QString foodName);
signals:

};

#endif // STUDENT_H

```

**student.cpp**

```c
#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName)
{
    //QString -> char *:先转成 QByteArray (.toUtf8()),再转 char* (.data);
    qDebug()<<"请老师吃饭，老师要吃:"<<foodName.toUtf8().data();
    qDebug()<<foodName;
}

```

**teacher.h**

```c
#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号 写到signals下
    //返回值是void，只需要声明，不需要实现
    //可以有参数，可以重载
    void hungry();

    void hungry(QString foodName);

};

#endif // TEACHER_H

```

**teacher.cpp**

```c
#include "teacher.h"

Teacher::Teacher(QObject *parent) : QObject(parent)
{

}

```

**widget.h**

```c
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"teacher.h"
#include"student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Teacher *zt;
    Student *st;

    void classIsOver();
};

#endif // WIDGET_H

```

**widget.cpp**

```c++
#include "widget.h"
#include "ui_widget.h"
#include<QWidget>
#include"teacher.h"
#include"student.h"
#include<QPushButton>
#include<QDebug>

//Teacher类  老师类
//Student类  学生类
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);   //创建对象时利用this将其挂在对象树上

    //创建一个学生对象
    this->st = new Student(this);



//    //老师饿了，让学生请课的连接
//    connect(zt,&Teacher::hungry,st,&Student::treat);

//    //调用下课函数
//     classIsOver();

    //连接带参数的  信号和槽
    //指针 -> 地址
    //函数指针 -> 函数地址
    void (Teacher::*teachersignal)(QString) = &Teacher::hungry;
    void(Student::*studentSlot)(QString) = &Student::treat;
    connect(zt,teachersignal,st,studentSlot);
//    classIsOver();

    //点击一个下课按钮，再触发下课
    QPushButton *btn = new QPushButton("下课",this);

    //重置窗口大小
    this->resize(800,400);
    //点击按钮，触发下课
//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    //无参信号和槽连接
    void (Teacher::*teachersignal2)(void) = &Teacher::hungry;
//    void(Student::*studentSlot2)(void) = &Student::treat;
//    connect(zt,teachersignal2,st,studentSlot2);

    //信号连接信号
    connect(btn,&QPushButton::clicked,zt,teachersignal2);

    //断开信号
//    disconnect(zt,teachersignal2,st,studentSlot2);

    //拓展
    //1、信号可以连接信号
    //2、一个信号可以连接对个槽函数
    //3、多个信号可以连接到同一个槽函数
    //4、信号和槽函数的参数  必须类型一 一对应
    //5、信号和槽的参数个数 是不是要一致？信号的参数个数 可以多于槽函数的参数个数

    //Qt4版本以前的信号和槽连接方式
    //利用Qt4信号槽 连接无参版本
    //Qt4版本 底层SIGNAL("hungry") SLOT("treat")
    connect(zt,SIGNAL(hungry()),st,SLOT(treat()));
    //Qt4 版本优点：参数直观，缺点，类型不做检测
    //Qt5以上版本支持Qt4的版本写法，反之不支持

//    QPushButton *btn2 = new QPushButton;
//    [btn](){
//        btn->setText("aaaaa");
//        btn2->setText("bbbb");  //只能看到btn，看不到btn2
//    }();

    //mutable关键字 用于修饰值传递的变量，修改的是拷贝，而不是本体
//    QPushButton *myBtn = new QPushButton(this);
//    QPushButton *myBtn2 = new QPushButton(this);
//    myBtn2->move(100,200);
//    int m = 10;
//    connect(myBtn,&QPushButton::clicked,this,[m]()mutable { m = 100+10;qDebug()<<m;});
//    connect(myBtn2,&QPushButton::clicked,this,[=](){qDebug()<<m;});
//    qDebug()<<m;

       //返回什么类型就用指针指向什么类型
//       int ret = []()->int{return 1000;}();
//       qDebug()<<"ret = "<<ret;

       //利用lambda表达式  实现点击按钮关闭窗口
       QPushButton *btn2 = new QPushButton;
       btn2->setText("关闭");
       btn2->move(100,0);
       btn2->setParent(this);

       //使用[=]，不要用[&]以免发生错误
       connect(btn2,&QPushButton::clicked,this,[=](){
//           this->close();
//           emit zt->hungry("小鸡炖蘑菇");
           btn2->setText("aabb");
       });

       //lambda表达式 最常用 [=](){}
}

void Widget::classIsOver()
{
    //下课函数，调用后触发老师饿了的信号
//    emit zt->hungry();
    emit zt->hungry("小鸡炖蘑菇");
}

Widget::~Widget()
{
    delete ui;
}


```





## 5	QMainWindow

QMainWindow是一个为用户提供主窗口程序的类，包含一个菜单栏(menu bar)、多个工具栏（tool bars）,多个锚接部件（dockwidgets）、一个状态栏（status bar）及一个中心部件（central widget），是许多应用程序的基础，如文本框编辑器，图片编辑器等

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml10308\wps1.jpg)



### 5.1	菜单栏

一个主窗口最多只有一个菜单栏。位于主窗口顶部、主窗口标题栏下面。

1.  创建菜单栏，通过QMainWindow类的menubar（）函数获取主窗口菜单栏指针

   > QMenuBar *	menuBar() const

2.  创建菜单，调用QMenu的成员函数addMenu来添加菜单

   > QAction* addMenu(QMenu * menu)
   >
   > QMenu* addMenu(const QString & title)
   >
   > QMenu* addMenu(const QIcon & icon, const QString & title)

3.  创建菜单项，调用QMenu的成员函数addAction来添加菜单项

   > QAction* activeAction() const
   >
   > QAction* addAction(const QString & text)
   >
   > QAction* addAction(const QIcon & icon, const QString & text)
   >
   > QAction* addAction(const QString & text, const QObject * receiver,
   >
   >  const char * member, const QKeySequence & shortcut = 0)
   >
   > QAction* addAction(const QIcon & icon, const QString & text, 
   >
   > const QObject * receiver, const char * member, 
   >
   > const QKeySequence & shortcut = 0)

Qt 并没有专门的菜单项类，只是使用一个QAction类，抽象出公共的动作。当我们把QAction对象添加到菜单，就显示成一个菜单项，添加到工具栏，就显示成一个工具按钮。用户可以通过点击菜单项、点击工具栏按钮、点击快捷键来激活这个动作。

### 5.2	工具栏

主窗口的工具栏上可以有多个工具条，通常采用一个菜单对应一个工具条的的方式，也可根据需要进行工具条的划分。

-  直接调用QMainWindow类的addToolBar（）函数获取主窗口的工具条对象，每增加一个工具条都需要调用一次该函数。

-  插入属于工具条的动作，即在工具条上添加操作。通过QToolBar类的addAction函数添加。

-  工具条是一个可移动的窗口，它的停靠区域由QToolBar的allowAreas决定，包括：

  ```c
  Qt::LeftToolBarArea		停靠在左侧
  Qt::RightToolBarArea		停靠在右侧
  Qt::TopToolBarArea		停靠在顶部
  Qt::BottomToolBarArea   	停靠在底部
  Qt::AllToolBarAreas		以上四个位置都可停靠
  
  使用setAllowedAreas（）函数指定停靠区域：
  
  setAllowedAreas（Qt::LeftToolBarArea | Qt::RightToolBarArea）
  
  使用setMoveable（）函数设定工具栏的可移动性：
  
  setMoveable（false）//工具条不可移动, 只能停靠在初始化的位置上
  ```

mainwindow.cpp:

```c
#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(800,400);

    //菜单栏创建 最多只能有一个
    QMenuBar *bar = menuBar();

    //将菜单栏放入到窗口中
    setMenuBar(bar);
    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    //创建菜单项
    QAction *newAction = fileMenu->addAction("新建");
    QAction *openAction = fileMenu->addAction("打开");
    //添加分隔符
    fileMenu->addSeparator();
    fileMenu->addAction("退出");

    //工具栏   可以有多个
    QToolBar * toolBar = new QToolBar(this);
    addToolBar(Qt::RightToolBarArea,toolBar);

    //后期设置，只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolBar->setFloatable(false);

    //设置移动（总开关）
    toolBar->setMovable(false);

    //工具栏中可以设置内容
    toolBar->addAction(newAction);
    //添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    //工具栏中添加控件
    QPushButton *btn = new QPushButton("按钮");
    toolBar->addWidget(btn);
}

MainWindow::~MainWindow()
{
}


```

运行结果：

![05](picture\05.png)



### 5.3	状态栏

- n 派生自QWidget类，使用方法与QWidget类似，QStatusBar类常用成员函数：

- n 状态栏也只能最多有一个

  > //添加小部件
  >
  > void addWidget(QWidget * widget, int stretch = 0)
  >
  > //插入小部件
  >
  > int	insertWidget(int index, QWidget * widget, int stretch = 0)
  >
  > //删除小部件
  >
  > void removeWidget(QWidget * widget)



### 5.4	铆接部件

铆接部件 QDockWidget，也称浮动窗口，可以有多个。

```c
QDockWidget * dock = new QDockWidget("标题",this);
addDockWidget(Qt::LeftDockWidgetArea,dock);
dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::TopDockWidgetArea);  设置区域范围
```



### 5.5	核心部件（中心部件）

除了以上几个部件，中心显示的部件都可以作为核心部件，例如一个记事本文件，可以利用QTextEdit做核心部件

> QTextEdit * edit = new QTextEdit(this);
>
>   setCentralWidget(edit);



### 5.6	资源文件

Qt 资源系统是一个跨平台的资源机制，用于将程序运行时所需要的资源以二进制的形式存储于可执行文件内部。如果你的程序需要加载特定的资源（图标、文本翻译等），那么，将其放置在资源文件中，就再也不需要担心这些文件的丢失。也就是说，如果你将资源以资源文件形式存储，它是会编译到可执行文件内部。

使用 Qt Creator 可以很方便地创建资源文件。我们可以在工程上点右键，选择“添加新文件…”，可以在 Qt 分类下找到“Qt 资源文件”：

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml10308\wps2.jpg) 

点击“选择…”按钮，打开“新建 Qt 资源文件”对话框。在这里我们输入资源文件的名字和路径：

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml10308\wps3.jpg) 

点击下一步，选择所需要的版本控制系统，然后直接选择完成。我们可以在 Qt Creator 的左侧文件列表中看到“资源文件”一项，也就是我们新创建的资源文件：

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml10308\wps4.jpg) 

右侧的编辑区有个“添加”，我们首先需要添加前缀，比如我们将前缀取名为 images。然后选中这个前缀，继续点击添加文件，可以找到我们所需添加的文件。这里，我们选择 document-open.png 文件。当我们完成操作之后，Qt Creator 应该是这样子的：

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml10308\wps5.jpg) 

接下来，我们还可以添加另外的前缀或者另外的文件。这取决于你的需要。当我们添加完成之后，我们可以像前面一章讲解的那样，通过使用 : 开头的路径来找到这个文件。比如，我们的前缀是 /images，文件是 document-open.png，那么就可以使用:/images/document-open.png找到这个文件。

这么做带来的一个问题是，如果以后我们要更改文件名，比如将 docuemnt-open.png 改成 docopen.png，那么，所有使用了这个名字的路径都需要修改。所以，更好的办法是，我们给这个文件去一个“别名”，以后就以这个别名来引用这个文件。具体做法是，选中这个文件，添加别名信息：

![img](file:///C:\Users\dfghkl\AppData\Local\Temp\ksohtml10308\wps6.jpg) 

这样，我们可以直接使用:/images/doc-open引用到这个资源，无需关心图片的真实文件名。

如果我们使用文本编辑器打开 res.qrc 文件，就会看到一下内容：

​		我们可以对比一下，看看 Qt Creator 帮我们生成的是怎样的 qrc 文件。当我们编译工程之后，我们可以在构建目录中找到 qrc_res.cpp 文件，这就是 Qt 将我们的资源编译成了 C++ 代码。

```c
<RCC>
    	<qresource prefix="/images">
        	<file alias="doc-open">document-open.png</file>
    	</qresource>
    	<qresource prefix="/images/fr" lang="fr">
        	<file alias="doc-open">document-open-fr.png</file>
    	</qresource>
</RCC>
```

我们可以对比一下，看看 Qt Creator 帮我们生成的是怎样的 qrc 文件。当我们编译工程之后，我们可以在构建目录中找到 qrc_res.cpp 文件，这就是 Qt 将我们的资源编译成了 C++ 代码。

mainwindow.cpp

```c
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->actionnew->setIcon(QIcon("E:/qt_picture/Luffy.png"));

    //使用添加Qt资源": + 前缀名 + 文件名"
    ui->actionnew->setIcon(QIcon(":/new/prefix1/Image/down.png"));
    ui->actionopen->setIcon(QIcon(":/new/prefix1/Image/LuffyQ.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


```

![](qt_picture/07.png)

**运行效果图：**

![](qt_picture/08.png)







**总结：**

```c

1	QMainWindow	
	1.1菜单栏 最多有一个
		1.1.1 QMenuBar * bar = MenuBar();
        1.1.2 setMenuBar( bar ) 
        1.1.3 QMenu * fileMenu = bar -> addMenu(“文件”)   创建菜单
        1.1.4 QAction * newAction =  fileMenu ->addAction(“新建”); 创建菜单项
        1.1.5 添加分割线 fileMenu->addSeparator();
        
	1.2工具栏 可以有多个
        1.2.1QToolBar * toolbar = new QToolBar(this);
        1.2.2addToolBar( 默认停靠区域， toolbar );  Qt::LeftToolBarArea
        1.2.3设置  后期停靠区域，设置浮动，设置移动
        1.2.4添加菜单项 或者添加 小控件
        
	1.3状态栏  最多一个
        1.3.1  QStatusBar * stBar = statusBar();
        1.3.2  设置到窗口中 setStatusBar(stBar);
        1.3.3  stBar->addWidget(label);放左侧信息
        1.3.4  stBar->addPermanentWidget(label2); 放右侧信息
	1.4铆接部件  浮动窗口  可以多个
        1.4.1QDockWidget 
        1.4.2addDockWidget( 默认停靠区域，浮动窗口指针)
        1.4.3设置后期停靠区域
	1.5设置核心部件  只能一个
		1.5.1setCentralWidget(edit);
		
2资源文件
    2.1将图片文件 拷贝到项目位置下
    2.2右键项目->添加新文件 –>  Qt - > Qt recourse File   - >给资源文件起名
    2.3res 生成  res.qrc  
    2.4open in editor  编辑资源
    2.5添加前缀  添加文件
    2.6使用  “ : + 前缀名 + 文件名 ”
    
3对话框
	3.1分类 ： 
		3.1.1模态对话框   不可以对其他窗口进行操作 阻塞
            3.1.1.1QDialog  dlg(this)
            3.1.1.2dlg.exec();
            
		3.1.2非模态对话框  可以对其他窗口进行操作
            3.1.2.1防止一闪而过 创建到堆区
            3.1.2.2QDialog * dlg = new QDialog(this)
            3.1.2.3dlg->show();
            3.1.2.4dlg2->setAttribute(Qt::WA_DeleteOnClose); //55号 属性
	3.2标准对话框 --  消息对话框
        3.2.1QMessageBox 静态成员函数  创建对话框
        3.2.2错误、信息、提问、警告
        3.2.3参数1  父亲 参数2  标题  参数3  显示内容 参数4  按键类型  参数5 默认关联回车按键
        3.2.4返回值 也是StandardButton类型，利用返回值判断用户的输入
        
	3.3其他标准对话框
        3.3.1颜色对话框  QColorDialog：：getColor 
        3.3.2文件对话框  QFileDialog：：getOpenFileName(父亲，标题，默认路径，过滤文件)
        3.3.3字体对话框  QFontDialog：：getFont 
        
4界面布局
    4.1实现登陆窗口
    4.2利用布局方式 给窗口进行美化
    4.3选取 widget  进行布局 ，水平布局、垂直布局、栅格布局
    4.4给用户名、密码、登陆、退出按钮进行布局
    4.5默认窗口和控件之间 有9间隙，可以调整 layoutLeftMargin
    4.6利用弹簧进行布局
    
5控件
	5.1按钮组
        5.1.1 QPushButton  常用按钮 
        5.1.2 QToolButton  工具按钮  用于显示图片，如图想显示文字，修改风格：toolButtonStyle ， 凸起风格autoRaise
        5.1.3 radioButton  单选按钮，设置默认 ui->rBtnMan->setChecked(true); 
        5.1.4 checkbox多选按钮，监听状态，2 选中  1 半选 0 未选中
	5.2QListWidget 列表容器
        5.2.1QListWidgetItem * item 一行内容 
        5.2.2ui->listWidget ->addItem ( item )
        5.2.3设置居中方式item->setTextAlignment(Qt::AlignHCenter);
        5.2.4可以利用addItems一次性添加整个诗内容
	5.3QTreeWidget 树控件
		5.3.1设置头  
            5.3.1.1ui->treeWidget->setHeaderLabels(QStringList()<< "英雄"<< "英雄介绍");
        5.3.2创建根节点
            5.3.2.1QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList()<< "力量");
            
		5.3.3添加根节点 到 树控件上
			5.3.3.1ui->treeWidget->addTopLevelItem(liItem);
		5.3.4添加子节点
			5.3.4.1liItem->addChild(l1);
	5.4QTableWidget 表格控件
        5.4.1设置列数 
        	5.4.1.1ui->tableWidget->setColumnCount(3);
        5.4.2设置水平表头
        	5.4.2.1ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<< "性别"<< "年龄");
        5.4.3设置行数 
        	5.4.3.1ui->tableWidget->setRowCount(5);
        5.4.4设置正文
        	5.4.4.1ui->tableWidget->setItem(0,0, new QTableWidgetItem("亚瑟"));
        	
5.5其他控件介绍

        5.5.1stackedWidget  栈控件
        	5.5.1.1ui->stackedWidget->setCurrentIndex(1);
        5.5.2下拉框
        	5.5.2.1ui->comboBox->addItem("奔驰");
        5.5.3QLabel 显示图片
        	5.5.3.1ui->lbl_Image->setPixmap(QPixmap(":/Image/butterfly.png"))
        5.5.4QLabel显示动图  gif图片
            5.5.4.1ui->lbl_movie->setMovie(movie);
            5.5.4.2movie->start();
5.6
```





**普通人看见而相信，我是因为相信而看见**

```
2	资源文件
	2.1	将图片拷贝到项目地址下（右键点击Source里面的.cpp文件）
	2.2	右键项目->添加新文件->Qt->Qt recourse File ->给资源文件起名
	2.3	resource 生成 resource.qrc
	2.4	右键点击resource.qrc 选择open In editor 
	2.5	添加前缀，添加文件
	2.6	使用": + 前缀 + 文件名"
```



## 6	对话框QDialog

### 6.1	基本概念

对话框是 GUI 程序中不可或缺的组成部分。很多不能或者不适合放入主窗口的功能组件都必须放在对话框中设置。对话框通常会是一个顶层窗口，出现在程序最上层，用于实现短期任务或者简洁的用户交互。

Qt 中使用QDialog类实现对话框。就像主窗口一样，我们通常会设计一个类继承QDialog。QDialog（及其子类，以及所有Qt::Dialog类型的类）的对于其 parent 指针都有额外的解释：**如果 parent 为 NULL，则该对话框会作为一个顶层窗口，否则则作为其父组件的子对话框（此时，其默认出现的位置是 parent 的中心）**。顶层窗口与非顶层窗口的区别在于，顶层窗口在任务栏会有自己的位置，而非顶层窗口则会共享其父组件的位置。

**对话框分为模态对话框和非模态对话框。**

- **模态对话框**，就是会阻塞同一应用程序中其它窗口的输入。

模态对话框很常见，比如“打开文件”功能。你可以尝试一下记事本的打开文件，当打开文件对话框出现时，我们是不能对除此对话框之外的窗口部分进行操作的。

- 与此相反的是**非模态对话框**，例如查找对话框，我们可以在显示着查找对话框的同时，继续对记事本的内容进行编辑。



### 6.2	模态对话框

所谓标准对话框，是 Qt 内置的一系列对话框，用于简化开发。事实上，有很多对话框都是通用的，比如打开文件、设置颜色、打印设置等。这些对话框在所有程序中几乎相同，因此没有必要在每一个程序中都自己实现这么一个对话框。

Qt 的内置对话框大致分为以下几类：

- QColorDialog：		 选择颜色；

- QFileDialog：			选择文件或者目录；

- QFontDialog：		  选择字体；

- QInputDialog：		 允许用户输入一个值，并将其值返回；

- **QMessageBox**：			模态对话框，用于显示信息、询问问题等；

- QPageSetupDialog：	为打印机提供纸张相关的选项；

- QPrintDialog：		打印机配置；

- QPrintPreviewDialog：打印预览；

- QProgressDialog：		显示操作过程。



### 6.3	自定义消息框

Qt支持模态对话框和非模态对话框

模态与非模态的实现：

- 使用QDialog::exec()实现应用程序级别的模态对话框
-  QDialog::show()实现非模态对话框。

#### 6.3.1	**模态对话框**

- Qt 有两种级别的模态对话框：

  - 应用程序级别的模态

    当该种模态的对话框出现时，用户必须首先对对话框进行交互，直到关闭对话框，然后才能访问程序中其他的窗口。


- 窗口级别的模态

  该模态仅仅阻塞与对话框关联的窗口，但是依然允许用户与程序中其它窗口交互。窗口级别的模态尤其适用于**多窗口模式**。

一般默认是应用程序级别的模态。

在下面的示例中，我们调用了exec()将对话框显示出来，因此这就是一个模态对话框。当对话框出现时，我们不能与主窗口进行任何交互，直到我们关闭了该对话框。

```c
QDialog dialog;
dialog.setWindowTitle(tr("Hello, dialog!"));
dialog.exec();
```

#### 6.3.2	非模态对话框

下面我们试着将exec()修改为show()，看看非模态对话框：

```c
    	QDialog dialog(this);
    	dialog.setWindowTitle(tr("Hello, dialog!"));
   	 	dialog.show();
```

是不是事与愿违？对话框竟然一闪而过！这是因为，**show()函数不会阻塞当前线程，对话框会显示出来，然后函数立即返回，代码继续执行。**注意，dialog 是建立在栈上的，show()函数返回，MainWindow::open()函数结束，dialog 超出作用域被析构，因此对话框消失了。知道了原因就好改了，我们将 dialog 改成堆上建立，当然就没有这个问题了：

```c
    QDialog *dialog = new QDialog;
    dialog->setWindowTitle(tr("Hello, dialog!"));
    dialog->show();
```

如果你足够细心，应该发现上面的代码是有问题的：dialog 存在内存泄露！dialog 使用 new 在堆上分配空间，却一直没有 delete。解决方案也很简单：将 MainWindow 的指针赋给 dialog 即可。还记得我们前面说过的 Qt 的对象系统吗？

不过，这样做有一个问题：如果我们的对话框不是在一个界面类中出现呢？由于QWidget的 parent 必须是QWidget指针，那就限制了我们不能将一个普通的 C++ 类指针传给 Qt 对话框。另外，如果对内存占用有严格限制的话，当我们将主窗口作为 parent 时，主窗口不关闭，对话框就不会被销毁，所以会一直占用内存。在这种情景下，我们可以设置 dialog 的WindowAttribute：

```c
    	QDialog *dialog = new QDialog;
    	dialog->setAttribute(Qt::WA_DeleteOnClose);
    	dialog->setWindowTitle(tr("Hello, dialog!"));
    	dialog->show();
```

**setAttribute()函数设置对话框关闭时，自动销毁对话框。**

### 6.4	消息对话框

QMessageBox用于显示消息提示。我们一般会使用其提供的几个 static 函数：

- 显示关于对话框。

  > void about(QWidget * parent, const QString & title, const QString & text)

这是一个最简单的对话框，其标题是 title，内容是 text，父窗口是 parent。对话框只有一个 OK 按钮。

- 显示关于 Qt 对话框。该对话框用于显示有关 Qt 的信息。

  > void aboutQt(QWidget * parent, const QString & title = QString())： 

-  显示严重错误对话框。

  > StandardButton critical(QWidget * parent, 
  >
  > const QString & title, 
  >
  > const QString & text, 
  >
  > StandardButtons buttons = Ok, 
  >
  > StandardButton defaultButton = NoButton)：

这个对话框将显示一个红色的错误符号。我们可以通过 buttons 参数指明其显示的按钮。默认情况下只有一个 Ok 按钮，我们可以使用StandardButtons类型指定多种按钮。

- 与QMessageBox::critical()类似，不同之处在于这个对话框提供一个普通信息图标。

  > StandardButton information(QWidget * parent, 
  >
  > const QString & title, 
  >
  > const QString & text, 
  >
  > StandardButtons buttons = Ok, 
  >
  > StandardButton defaultButton = NoButton)

- 与QMessageBox::critical ()类似，不同之处在于这个对话框提供一个问号图标，并且其显示的按钮是“是”和“否”。

  > StandardButton question(QWidget * parent,
  >
  > const QString & title, 
  >
  > const QString & text, 
  >
  > StandardButtons buttons = StandardButtons( Yes | No ), 
  >
  > StandardButton defaultButton = NoButton) 

- 与QMessageBox::critical()类似，不同之处在于这个对话框提供一个黄色叹号图标。

  > StandardButton warning(QWidget * parent, 
  >
  > const QString & title, 
  >
  > const QString & text, 
  >
  > StandardButtons buttons = Ok, 
  >
  > StandardButton defaultButton = NoButton)

我们可以通过下面的代码来演示下如何使用QMessageBox。

```c
if (QMessageBox::Yes == QMessageBox::question(this,
              tr("Question"), tr("Are you OK?"),
              QMessageBox::Yes | QMessageBox::No,
              QMessageBox::Yes)) 
{
    QMessageBox::information(this, tr("Hmmm..."), 
tr("I'm glad to hear that!"));
} 
else 
{
    QMessageBox::information(this, tr("Hmmm..."), 
tr("I'm sorry!"));
}
```

我们使用QMessageBox::question()来询问一个问题。

l 这个对话框的父窗口是 this。

QMessageBox是QDialog的子类，这意味着它的初始显示位置将会是在 parent 窗口的中央。

l 第二个参数是对话框的标题。

l 第三个参数是我们想要显示的内容。

l 第四个参数是关联的按键类型，我们可以使用或运算符（|）指定对话框应该出现的按钮。比如我们希望是一个 Yes 和一个 No。

l 最后一个参数指定默认选择的按钮。

这个函数有一个返回值，用于确定用户点击的是哪一个按钮。按照我们的写法，应该很容易的看出，这是一个模态对话框，因此我们可以直接获取其返回值。

QMessageBox类的 static 函数优点是方便使用，缺点也很明显：非常不灵活。我们只能使用简单的几种形式。为了能够定制QMessageBox细节，我们必须使用QMessageBox的属性设置 API。如果我们希望制作一个询问是否保存的对话框，我们可以使用如下的代码：

```c
QMessageBox msgBox;
msgBox.setText(tr("The document has been modified."));
msgBox.setInformativeText(tr("Do you want to save your changes?"));
msgBox.setDetailedText(tr("Differences here..."));
msgBox.setStandardButtons(QMessageBox::Save
                          | QMessageBox::Discard
                          | QMessageBox::Cancel);
msgBox.setDefaultButton(QMessageBox::Save);
int ret = msgBox.exec();
switch (ret) 
{
case QMessageBox::Save:
    qDebug() << "Save document!";
    break;
case QMessageBox::Discard:
    qDebug() << "Discard changes!";
    break;
case QMessageBox::Cancel:
    qDebug() << "Close document!";
    break;
}
```

msgBox 是一个建立在栈上的QMessageBox实例。我们设置其主要文本信息为“The document has been modified.”，informativeText 则是会在对话框中显示的简单说明文字。下面我们使用了一个detailedText，也就是详细信息，当我们点击了详细信息按钮时，对话框可以自动显示更多信息。我们自己定义的对话框的按钮有三个：保存、丢弃和取消。然后我们使用了exec()是其成为一个模态对话框，根据其返回值进行相应的操作。

### 6.5	标准文件对话框

QFileDialog，也就是文件对话框。在本节中，我们将尝试编写一个简单的文本文件编辑器，我们将使用QFileDialog来打开一个文本文件，并将修改过的文件保存到硬盘。

首先，我们需要创建一个带有文本编辑功能的窗口。借用我们前面的程序代码，应该可以很方便地完成：

```c
openAction = new QAction(QIcon(":/images/file-open"),tr("&Open..."), this);
openAction->setStatusTip(tr("Open an existing file"));

saveAction = new QAction(QIcon(":/images/file-save"), tr("&Save..."), this);
saveAction->setStatusTip(tr("Save a new file"));

QMenu *file = menuBar()->addMenu(tr("&File"));
file->addAction(openAction);
file->addAction(saveAction);

QToolBar *toolBar = addToolBar(tr("&File"));
toolBar->addAction(openAction);
toolBar->addAction(saveAction);

textEdit = new QTextEdit(this);
setCentralWidget(textEdit);
```

我们在菜单和工具栏添加了两个动作：打开和保存。接下来是一个QTextEdit类，这个类用于显示富文本文件。也就是说，它不仅仅用于显示文本，还可以显示图片、表格等等。不过，我们现在只用它显示纯文本文件。QMainWindow有一个setCentralWidget()函数，可以将一个组件作为窗口的中心组件，放在窗口中央显示区。显然，在一个文本编辑器中，文本编辑区就是这个中心组件，因此我们将QTextEdit作为这种组件。

我们使用connect()函数，为这两个QAction对象添加响应的动作：

```c
connect(openAction, &QAction::triggered, 
this, &MainWindow::openFile);
connect(saveAction, &QAction::triggered, 
this, &MainWindow::saveFile);
```

下面是最主要的openFile()和saveFile()这两个函数的代码：

```c
//打开文件
void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
               tr("Open File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()) 
{
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
{
            QMessageBox::warning(this, tr("Read File"),
                         tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    } 
else 
{
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
     }
}

//保存文件
void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,
               tr("Open File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()) 
{
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) 
{
            QMessageBox::warning(this, tr("Write File"),
                         tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    } 
else 
{
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}
```

在openFile()函数中，我们使用QFileDialog::getOpenFileName()来获取需要打开的文件的路径。这个函数原型如下：

```c
QString getOpenFileName(QWidget * parent = 0,
                        const QString & caption = QString(),
                        const QString & dir = QString(),
                        const QString & filter = QString(),
                        QString * selectedFilter = 0,
                        Options options = 0)
```

不过注意，它的所有参数都是可选的，因此在一定程度上说，这个函数也是简单的。这六个参数分别是：

- parent：父窗口。

​		Qt 的标准对话框提供静态函数，用于返回一个模态对话框；

- caption：对话框标题；

- dir：对话框打开时的默认目录

  - “.” 代表程序运行目录

  - “/” 代表当前盘符的根目录（特指 Windows 平台；Linux 平台当然就是根目录），这个参数也可以是平台相关的，比如“C:\\”等；

- filter：过滤器。

​		我们使用文件对话框可以浏览很多类型的文件，但是，很多时候我们仅希望打开特定类型的文件。比如，文本编辑器希望打开文本文件，图片浏览器希望打开图片文件。**过滤器就是用于过滤特定的后缀名**。如果我们使用“Image Files(*.jpg *.png)”，则只能显示后缀名是 jpg 或者 png 的文件。**如果需要多个过滤器，使用“;;”分割**，比如“JPEG Files(*.jpg);;PNG Files(*.png)”；

- selectedFilter：默认选择的过滤器；

- options：对话框的一些参数设定

比如只显示文件夹等等，它的取值是enum QFileDialog::Option，每个选项可以使用 | 运算组合起来。

**QFileDialog::getOpenFileName()返回值是选择的文件路径。**我们将其赋值给 path。通过判断 path 是否为空，可以确定用户是否选择了某一文件。只有当用户选择了一个文件时，我们才执行下面的操作。

在saveFile()中使用的QFileDialog::getSaveFileName()也是类似的。使用这种静态函数，在 Windows、Mac OS 上面都是直接调用本地对话框，但是 Linux 上则是QFileDialog自己的模拟。这暗示了，如果你不使用这些静态函数，而是直接使用QFileDialog进行设置，那么得到的对话框很可能与系统对话框的外观不一致。这一点是需要注意的。

**项目名称：03_QDialog**

![](qt_picture/15.png)

```c
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮，弹出一个对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框   分类
        //1、模态对话框（不可以对其他窗口进行操作）
        //2、非模态对话框（可以对其他窗口进行操作）

        //模态创建
//        QDialog dlg(this);  //指定父亲
//        dlg.resize(800,480);//设置弹出的对话框大小
//        dlg.exec();           //阻塞在这里
//        qDebug()<<"模态对话框弹出了";

        //模态对话框
//        QDialog dlg2(this);   //局部变量执行完即是否内存，所以只看到窗口闪一下
//        QDialog *dlg2 = new QDialog(this); //将其创建在堆区
//        dlg2->resize(800,480);
//        dlg2->show();
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);  //55 属性  功能：关闭窗口就释放该对象内存，防止内存泄漏
//        qDebug()<<"非模态对话";     //打印一下提示信息

        //消息对话框

        //错误对话框
//        QMessageBox::critical(this,"critical","error");

        //信息对话框
//        QMessageBox::information(this,"info","信息");

        //提问对话框
        //参数1：父亲    参数2：标题  参数3：提示内容    参数4：按照类型    参数5：默认关联回车按键
//        if(QMessageBox::Save == QMessageBox::question(this,"question","提问",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
//        {
//            qDebug()<<"选择的是保存";

//        }
//        else
//        {
//            qDebug()<<"选择的是取消";
//        }

        //警告对话框
//        QMessageBox::warning(this,"warning","警告");

        //其他标准对话框
        //颜色对话框
//        QColor color = QColorDialog::getColor(QColor(0,255,0));
//        qDebug()<<"r = "<<color.red()<<" g = "<<color.green()<<" b = "<<color.blue();

        //文件对话框
        //参数1：父亲    参数2：标题  参数3：默认打开路径  参数4：过滤文件格式
        //返回值是选取的路径
//        QString str = QFileDialog::getOpenFileName(this,"打开文件","F:\\github\\小熊派笔记","(*.c)");
//        qDebug()<<str;

        //字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("宋体",4));
        qDebug()<<"字体："<<font.family().toUtf8().data()<<"字号："<<font.pointSize()<<" 是否加粗："<<font.bold()<<" 是否倾斜："<<font.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


```

****

运行结果：

![](qt_picture/16.png)



## 7	布局管理器

所谓 GUI 界面，归根结底，就是一堆组件的叠加。我们创建一个窗口，把按钮放上面，把图标放上面，这样就成了一个界面。在放置时，**组件的位置尤其重要**。我们必须要指定组件放在哪里，以便窗口能够按照我们需要的方式进行渲染。这就涉及到组件定位的机制。

**Qt 提供了两种组件定位机制：绝对定位和布局定位。**

-  绝对定位就是一种最原始的定位方法：给出这个组件的坐标和长宽值。

  这样，Qt 就知道该把组件放在哪里以及如何设置组件的大小。但是这样做带来的一个问题是，如果用户改变了窗口大小，比如点击最大化按钮或者使用鼠标拖动窗口边缘，采用绝对定位的组件是不会有任何响应的。这也很自然，因为你并没有告诉 Qt，在窗口变化时，组件是否要更新自己以及如何更新。或者，还有更简单的方法：禁止用户改变窗口大小。但这总不是长远之计。

- 布局定位：你只要把组件放入某一种布局，布局由专门的布局管理器进行管理。当需要调整大小或者位置的时候，Qt 使用对应的布局管理器进行调整。

布局定位完美的解决了使用绝对定位的缺陷。

Qt 提供的布局中以下三种是我们最常用的：

- QHBoxLayout：按照水平方向从左到右布局；

- QVBoxLayout：按照竖直方向从上到下布局；

- QGridLayout：在一个网格中进行布局，类似于 HTML 的 table；

### 7.1	系统提供的布局控件

![](qt_picture/17.png)

这4个为系统给我们提供的布局的控件，但是使用起来不是非常的灵活，这里就不详细介绍了。

### 7.2	利用widget做布局

第二种布局方式是利用控件里的widget来做布局，在Containers中

![](qt_picture/18.png)

在widget中的控件可以进行水平、垂直、栅格布局等操作，比较灵活。

再布局的同时我们需要灵活运用弹簧的特性让我们的布局更加的美观，下面是一个登陆窗口，利用widget可以搭建出如下登陆界面：

![](qt_picture/19.png)



## 8	常用控件

Qt为我们应用程序界面开发提供的一系列的控件，下面我们介绍两种最常用一些控件，所有控件的使用方法我们都可以通过帮助文档获取。

### 8.1	QLabel 控件使用

QLabel是我们最常用的控件之一，其功能很强大，我们可以用来显示文本，图片和动画等。

**1、显示文字（普通文本、html）**

通过QLabel类的setText函数设置显示的内容:

> void	setText(const QString &)

-  可以显示普通文本字符串

> QLable *label = new QLable;
>
> label->setText(“Hello, World!”);

-  可以显示HTML格式的字符串

  比如显示一个链接：

> QLabel * label = new QLabel(this);
>
> label ->setText("Hello, World");
>
> label ->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
>
> label ->setOpenExternalLinks(true);

其中setOpenExternalLinks()函数是用来设置用户点击链接之后是否自动打开链接，如果参数指定为true则会自动打开。

**2、显示动画**

可以使用QLabel 的成员函数setMovie加载动画，可以播放gif格式的文件

> void	setMovie(QMovie * movie)

首先定义QMovied对象，并初始化:

> QMovie *movie = new QMovie(":/Mario.gif");

播放加载的动画：

> movie->start();

将动画设置到QLabel中：

> QLabel *label = new QLabel；
>
> label->setMovie(movie);

### 8.2	QLineEdit

Qt提供的单行文本编辑框。

**1、设置/获取内容**

- 获取编辑框内容使用text（），函数声明如下：

>  QString	text() const

- 设置编辑框内容

> void	setText(const QString &)

**2、设置显示模式**

使用QLineEdit类的setEchoMode () 函数设置文本的显示模式,函数声明:

> void	setEchoMode(EchoMode mode)

EchoMode是一个枚举类型,一共定义了四种显示模式:

- QLineEdit::Normal	 模式显示方式，按照输入的内容显示。

- QLineEdit::NoEcho	不显示任何内容，此模式下无法看到用户的输入。

- QLineEdit::Password	密码模式，输入的字符会根据平台转换为特殊字符。

- QLineEdit::PasswordEchoOnEdit	编辑时显示字符否则显示字符作为密码。

另外，我们再使用QLineEdit显示文本的时候，希望在左侧留出一段空白的区域，那么，就可以使用QLineEdit给我们提供的setTextMargins函数：

> void setTextMargins(int left, int top, int right, int bottom)

用此函数可以指定显示的文本与输入框上下左右边界的间隔的像素数。

### 8.3	其他控件

Qt中控件的使用方法可参考Qt提供的帮助文档。

### 8.4	自定义控件

在搭建Qt窗口界面的时候，在一个项目中很多窗口，或者是窗口中的某个模块会被经常性的重复使用。一般遇到这种情况我们都会将这个窗口或者模块拿出来做成一个独立的窗口类，以备以后重复使用。

在使用Qt的ui文件搭建界面的时候，工具栏栏中只为我们提供了标准的窗口控件，如果我们想使用自定义控件怎么办？

例如：我们从QWidget派生出一个类SmallWidget，实现了一个自定窗口，

```c
// smallwidget.h
class SmallWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SmallWidget(QWidget *parent = 0);

signals:

public slots:
private:
    QSpinBox* spin;
    QSlider* slider;
};

// smallwidget.cpp
SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    spin = new QSpinBox(this);
    slider = new QSlider(Qt::Horizontal, this);

    // 创建布局对象
    QHBoxLayout* layout = new QHBoxLayout;
    // 将控件添加到布局中
    layout->addWidget(spin);
    layout->addWidget(slider);
    // 将布局设置到窗口中
    setLayout(layout);

    // 添加消息响应
    connect(spin, 
static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
 slider, &QSlider::setValue);
    connect(slider, &QSlider::valueChanged, 
spin, &QSpinBox::setValue);
}
```

![](qt_picture/20.png)

那么这个SmallWidget可以作为独立的窗口显示,也可以作为一个控件来使用：

打开Qt的.ui文件,因为SmallWidget是派生自Qwidget类,所以需要在ui文件中先放入一个QWidget控件, 然后再上边鼠标右键

![](qt_picture/21.png)

弹出提升窗口部件对话框

![](qt_picture/22.png)

添加要提升的类的名字,然后选择 添加 

![](qt_picture/23.png)

添加之后,类名会显示到上边的列表框中,然后单击提升按钮,完成操作.

我们可以看到, 这个窗口对应的类从原来的QWidget变成了SmallWidget

![](qt_picture/24.png)

再次运行程序,这个widget_3中就能显示出我们自定义的窗口了.

**项目名称：05_Qt_Contral**



![](qt_picture/25.png)

mainwindow.cpp

```c
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置单选按钮 默认选中男
    ui->rBtnMan->setChecked(true);

    //选中女后  打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug()<<"选中女了";
    });

    //多选按钮  选中老板人好后 打印一句话
    //选中返回2 未选中返回0
    connect(ui->cBox,&QCheckBox::stateChanged,[=](int state){
//        qDebug()<<"老板人好";
        qDebug()<<state;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


```

**运行效果图：**

![](qt_picture/26.png)



**2、再添加listWidget组件后**

mainwindow.cpp

```c
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置单选按钮 默认选中男
    ui->rBtnMan->setChecked(true);

    //选中女后  打印信息
    connect(ui->rBtnWoman,&QRadioButton::clicked,[=](){
        qDebug()<<"选中女了";
    });

    //多选按钮  选中老板人好后 打印一句话
    //选中返回2 未选中返回0
    connect(ui->cBox,&QCheckBox::stateChanged,[=](int state){
//        qDebug()<<"老板人好";
        qDebug()<<state;
    });

    //利用listWidget 写诗
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
//    //将一行诗放入到listWidget控件中
//    ui->listWidget->addItem(item);
//    //设置为水平居中
//    item->setTextAlignment(Qt::AlignHCenter);

    //QStringList   QList<QString>
    QStringList list;
    list<<"锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}


```

**运行效果图：**

![](qt_picture/27.png)



**项目名称：06_TreeWidget**

![](qt_picture/29.png)



widget.cpp

```c
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //treeWidget树控件使用

    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

    QTreeWidgetItem * LiItem = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * MinItem = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * ZhiItem = new QTreeWidgetItem(QStringList()<<"智力");

    //加载顶层的节点
    ui->treeWidget->addTopLevelItem(LiItem);
    ui->treeWidget->addTopLevelItem(MinItem);
    ui->treeWidget->addTopLevelItem(ZhiItem);

    //追加子节点
    QStringList heroL1,heroL2;
    heroL1<<"刚被猪"<<"前排坦克，能在吸收伤害的同时造成可观的范围输出";
    heroL2<<"船长"<<"前排坦克，能肉能输出能控场的全能英雄";
    QTreeWidgetItem * l1 = new QTreeWidgetItem(heroL1);
    QTreeWidgetItem * l2 = new QTreeWidgetItem(heroL2);
    LiItem->addChild(l1);
    LiItem->addChild(l2);

    QStringList heroM1,heroM2;
    heroM1<<"月骑"<<"中排物理输出，可以使用分裂利刃攻击多个目标";
    heroM2<<"小鱼人"<<"前排战士，擅长偷取敌人的属性来增强自身战力";
    QTreeWidgetItem * m1 = new QTreeWidgetItem(heroM1);
    QTreeWidgetItem * m2 = new QTreeWidgetItem(heroM2);
    MinItem->addChild(m1);
    MinItem->addChild(m2);

    QStringList heroZ1,heroZ2;
    heroZ1<<"死灵法师"<<"前排法师坦克，魔法抗性较高，拥有治疗技能";
    heroZ2<<"巫医"<<"后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";
    QTreeWidgetItem * z1 = new QTreeWidgetItem(heroZ1);
    QTreeWidgetItem * z2 = new QTreeWidgetItem(heroZ2);
    ZhiItem->addChild(z1);
    ZhiItem->addChild(z2);

}

Widget::~Widget()
{
    delete ui;
}


```

**运行效果图：**

![](qt_picture/28.png)



**项目名称：07_TableWidget**

![](qt_picture/30.png)

widget.cpp

```c
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget 控件
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");

    //设置行数
    ui->tableWidget->setRowCount(5);

    //设置正文
//    ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
    QStringList nameList;
    nameList<<"亚瑟"<<"赵云"<<"张飞"<<"关羽"<<"花木兰";

    QStringList sexList;
    sexList<<"男"<<"男"<<"男"<<"男"<<"女";

    for(int i = 0;i<5;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexList[i]));
        //int  转 QString
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number((i+18))));
    }
}

Widget::~Widget()
{
    delete ui;
}


```

**运行结果：**

![](qt_picture/31.png)



**项目名称：08_OtherControl**

![](qt_picture/32.png)

widget.cpp

```c
#include "widget.h"
#include "ui_widget.h"
#include<QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置默认值

    //栈控件使用
    //scrollArea按键
    connect(ui->btn_scrollArea,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(2);

    });

    //toolBox按钮
    connect(ui->btn_ToolBox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //TabWidget按钮
    connect(ui->btn_GroupBox,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(0);
    });

    //下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("特斯拉");

    //选中特斯拉
    connect(ui->btn_select,&QPushButton::clicked,[=](){
       ui->comboBox->setCurrentIndex(2);
    });

    //利用QLabel显示图片
    ui->lbl_Image->setPixmap(QPixmap(":/Image/butterfly.png"));

    //利用QLabel显示，GIF动态图片
    QMovie *movie = new QMovie(":/Image/mario.gif");
    ui->lbl_movie->setMovie(movie);
    //播放动图
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}


```

![](qt_picture/33.png)

**运行效果图**

![](qt_picture/34.png)



## 9	Qt消息机制和事件

### 9.1	事件

事件（event）是由系统或者 Qt 本身在不同的时刻发出的。当用户按下鼠标、敲下键盘，或者是窗口需要重新绘制的时候，都会发出一个相应的事件。一些事件在对用户操作做出响应时发出，如键盘事件等；另一些事件则是由系统自动发出，如计时器事件。

在前面我们也曾经简单提到，**Qt 程序**需要在main()函数创建一个QApplication对象，然后调用它的exec()函数。这个函数就是开始 Qt 的事件循环。在执行exec()函数之后，程序将进入事件循环来监听应用程序的事件。当事件发生时，Qt 将创建一个事件对象。**Qt 中所有事件类都继承于QEvent**。在事件对象创建完毕后，Qt 将这个事件对象传递给QObject的event()函数。**event()函数并不直接处理事件，而是按照事件对象的类型分派给特定的事件处理函数**（event handler），关于这一点，会在后边详细说明。

在所有组件的父类QWidget中，定义了很多事件处理的回调函数，如-

- keyPressEvent()

- keyReleaseEvent()

- mouseDoubleClickEvent()

- mouseMoveEvent()

- mousePressEvent()

- mouseReleaseEvent() 等。

这些函数都是 protected virtual 的，也就是说，我们可以在子类中重新实现这些函数。下面来看一个例子：

```c
class EventLabel : public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
 
void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
this->setText(QString("<center><h1>Move: (%1, %2)
</h1></center>").arg(QString::number(event->x()),
            QString::number(event->y())));
}
 
void EventLabel::mousePressEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Press:(%1, %2)
</h1></center>").arg(QString::number(event->x()),
                QString::number(event->y())));
}
 
void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h1>Release: (%d, %d)</h1></center>",
                event->x(), event->y());
    this->setText(msg);
}
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 
    EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300, 200);
    label->show();
 
    return a.exec();
}
```

- EventLabel继承了QLabel，覆盖了mousePressEvent()、mouseMoveEvent()和MouseReleaseEvent()三个函数。我们并没有添加什么功能，只是在鼠标按下（press）、鼠标移动（move）和鼠标释放（release）的时候，把当前鼠标的坐标值显示在这个Label上面。由于QLabel是支持 HTML 代码的，因此我们直接使用了 HTML 代码来格式化文字。

- QString的arg()函数可以自动替换掉QString中出现的占位符。其占位符以 % 开始，后面是占位符的位置，例如 %1，%2 这种。

> QString("[%1, %2]").arg(x).arg(y);

​	语句将会使用x替换 %1，y替换 %2，因此，生成的QString为[x, y]。

- 在mouseReleaseEvent()函数中，我们使用了另外一种QString的构造方法。我们使用类似 C 风格的格式化函数sprintf()来构造QString。

​	运行上面的代码，当我们点击了一下鼠标之后，label 上将显示鼠标当前坐标值。

![](qt_picture/35.png)

为什么要点击鼠标之后才能在mouseMoveEvent()函数中显示鼠标坐标值？

**这是因为QWidget中有一个mouseTracking属性，该属性用于设置是否追踪鼠标。只有鼠标被追踪时，mouseMoveEvent()才会发出。如果mouseTracking是 false（默认即是），组件在至少一次鼠标点击之后，才能够被追踪，也就是能够发出mouseMoveEvent()事件。如果mouseTracking为 true，则mouseMoveEvent()直接可以被发出。**

知道了这一点，我们就可以在main()函数中添加如下代码：

> label->setMouseTracking(true);

在运行程序就没有这个问题了。

### 9.2	event()

事件对象创建完毕后，Qt 将这个事件对象传递给QObject的event()函数。event()函数并不直接处理事件，而是将这些事件对象按照它们不同的类型，分发给不同的事件处理器（event handler）。

如上所述，**event()函数主要用于事件的分发**。所以，如果你希望在事件分发之前做一些操作，就可以重写这个event()函数了。例如，我们希望在一个QWidget组件中监听 tab 键的按下，那么就可以继承QWidget，并重写它的event()函数，来达到这个目的：

```c
bool CustomWidget::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if (keyEvent->key() == Qt::Key_Tab) {
            qDebug() << "You press tab.";
            return true;
        }
    }
    return QWidget::event(e);
}
```

CustomWidget是一个普通的QWidget子类。我们重写了它的event()函数，这个函数有一个QEvent对象作为参数，也就是需要转发的事件对象。函数返回值是 bool 类型。

- **如果传入的事件已被识别并且处理，则需要返回 true，否则返回 false。如果返回值是 true，那么 Qt 会认为这个事件已经处理完毕，不会再将这个事件发送给其它对象，而是会继续处理事件队列中的下一事件。**

- 在event()函数中，调用事件对象的accept()和ignore()函数是没有作用的，不会影响到事件的传播。

我们可以通过使用QEvent::type()函数可以检查事件的实际类型，其返回值是QEvent::Type类型的枚举。我们处理过自己感兴趣的事件之后，可以直接返回 true，表示我们已经对此事件进行了处理；对于其它我们不关心的事件，则需要调用父类的event()函数继续转发，否则这个组件就只能处理我们定义的事件了。为了测试这一种情况，我们可以尝试下面的代码：

```c
bool CustomTextEdit::event(QEvent *e)
{
   if (e->type() == QEvent::KeyPress) 
{
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
       if (keyEvent->key() == Qt::Key_Tab) 
{
            qDebug() << "You press tab.";
            return true;
       }
    }
    return false;
}
```

CustomTextEdit是QTextEdit的一个子类。我们重写了其event()函数，却没有调用父类的同名函数。这样，我们的组件就只能处理 Tab 键，再也无法输入任何文本，也不能响应其它事件，比如鼠标点击之后也不会有光标出现。这是因为我们只处理的KeyPress类型的事件，并且如果不是KeyPress事件，则直接返回 false，鼠标事件根本不会被转发，也就没有了鼠标事件。

通过查看QObject::event()的实现，我们可以理解，event()函数同前面的章节中我们所说的事件处理器有什么联系：

```c
//!!! Qt5
bool QObject::event(QEvent *e)
{
    switch (e->type()) {
    case QEvent::Timer:
        timerEvent((QTimerEvent*)e);
        break;

    case QEvent::ChildAdded:
    case QEvent::ChildPolished:
    case QEvent::ChildRemoved:
        childEvent((QChildEvent*)e);
        break;
    // ...
    default:
        if (e->type() >= QEvent::User) {
            customEvent(e);
            break;
        }
        return false;
    }
    return true;
}
```

这是 Qt 5 中QObject::event()函数的源代码（Qt 4 的版本也是类似的）。我们可以看到，同前面我们所说的一样，Qt 也是使用QEvent::type()判断事件类型，然后调用了特定的事件处理器。比如，如果event->type()返回值是QEvent::Timer，则调用timerEvent()函数。可以想象，QWidget::event()中一定会有如下的代码：

```c
switch (event->type()) {
    case QEvent::MouseMove:
        mouseMoveEvent((QMouseEvent*)event);
        break;
    // ...
}
```

事实也的确如此。timerEvent()和mouseMoveEvent()这样的函数，就是我们前面章节所说的事件处理器 event handler。也就是说，**event()函数中实际是通过事件处理器来响应一个具体的事件。这相当于event()函数将具体事件的处理“委托”给具体的事件处理器。而这些事件处理器是 protected virtual 的，因此，我们重写了某一个事件处理器，即可让 Qt 调用我们自己实现的版本。**

由此可以见，event()是一个集中处理不同类型的事件的地方。如果你不想重写一大堆事件处理器，就可以重写这个event()函数，通过QEvent::type()判断不同的事件。鉴于重写event()函数需要十分小心注意父类的同名函数的调用，一不留神就可能出现问题，所以一般还是建议只重写事件处理器（当然，也必须记得是不是应该调用父类的同名处理器）。这其实暗示了event()函数的另外一个作用：屏蔽掉某些不需要的事件处理器。正如我们前面的CustomTextEdit例子看到的那样，我们创建了一个只能响应 tab 键的组件。这种作用是重写事件处理器所不能实现的。

### 9.3	事件过滤器

![](qt_picture/39.png)

有时候，对象需要查看、甚至要拦截发送到另外对象的事件。例如，对话框可能想要拦截按键事件，不让别的组件接收到；或者要修改回车键的默认处理。

 

通过前面的章节，我们已经知道，Qt 创建了QEvent事件对象之后，会调用QObject的event()函数处理事件的分发。显然，我们可以在event()函数中实现拦截的操作。由于event()函数是 protected 的，因此，需要继承已有类。如果组件很多，就需要重写很多个event()函数。这当然相当麻烦，更不用说重写event()函数还得小心一堆问题。好在 Qt 提供了另外一种机制来达到这一目的：事件过滤器。

QObject有一个eventFilter()函数，用于建立事件过滤器。函数原型如下：

virtual bool QObject::eventFilter ( QObject * watched, QEvent * event );

这个函数正如其名字显示的那样，是一个“事件过滤器”。所谓事件过滤器，可以理解成一种过滤代码。事件过滤器会检查接收到的事件。如果这个事件是我们感兴趣的类型，就进行我们自己的处理；如果不是，就继续转发。这个函数返回一个 bool 类型，如果你想将参数 event 过滤出来，比如，**不想让它继续转发，就返回 true，否则返回 false。**事件过滤器的调用时间是目标对象（也就是参数里面的watched对象）接收到事件对象之前。也就是说，如果你在事件过滤器中停止了某个事件，那么，watched对象以及以后所有的事件过滤器根本不会知道这么一个事件。

我们来看一段简单的代码：

```c
class MainWindow : public QMainWindow
 {
 public:
     MainWindow();
 protected:
     bool eventFilter(QObject *obj, QEvent *event);
 private:
     QTextEdit *textEdit;
 };
 
 MainWindow::MainWindow()
 {
     textEdit = new QTextEdit;
     setCentralWidget(textEdit);
 
     textEdit->installEventFilter(this);
 }
 
 bool MainWindow::eventFilter(QObject *obj, QEvent *event)
 {
     if (obj == textEdit) {
         if (event->type() == QEvent::KeyPress) {
             QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
             qDebug() << "Ate key press" << keyEvent->key();
             return true;
         } else {
             return false;
         }
     } else {
         // pass the event on to the parent class
         return QMainWindow::eventFilter(obj, event);
     }
 }
```

- MainWindow是我们定义的一个类。我们重写了它的eventFilter()函数。为了过滤特定组件上的事件，首先需要判断这个对象是不是我们感兴趣的组件，然后判断这个事件的类型。在上面的代码中，我们不想让textEdit组件处理键盘按下的事件。所以，首先我们找到这个组件，如果这个事件是键盘事件，则直接返回 true，也就是过滤掉了这个事件，其他事件还是要继续处理，所以返回 false。对于其它的组件，我们并不保证是不是还有过滤器，于是最保险的办法是调用父类的函数。

- eventFilter()函数相当于创建了过滤器，然后我们需要安装这个过滤器。安装过滤器需要调用QObject::installEventFilter()函数。函数的原型如下：

> void QObject::installEventFilter ( QObject * filterObj )

这个函数接受一个QObject *类型的参数。记得刚刚我们说的，eventFilter()函数是QObject的一个成员函数，因此，任意QObject都可以作为事件过滤器（问题在于，如果你没有重写eventFilter()函数，这个事件过滤器是没有任何作用的，因为默认什么都不会过滤）。已经存在的过滤器则可以通过QObject::removeEventFilter()函数移除。

- 我们可以向一个对象上面安装多个事件处理器，只要调用多次installEventFilter()函数。如果一个对象存在多个事件过滤器，那么，最后一个安装的会第一个执行，也就是后进先执行的顺序。

还记得我们前面的那个例子吗？我们使用event()函数处理了 Tab 键：

```c
bool CustomWidget::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if (keyEvent->key() == Qt::Key_Tab) {
            qDebug() << "You press tab.";
            return true;
        }
    }
    return QWidget::event(e);
}
```

现在，我们可以给出一个使用事件过滤器的版本：

```c
bool FilterObject::eventFilter(QObject *object, QEvent *event)
{
    if (object == target && event->type() == QEvent::KeyPress) 
{
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Tab) {
            qDebug() << "You press tab.";
            return true;
        } else {
            return false;
        }
    }
    return false;
}
```

事件过滤器的强大之处在于，我们可以为整个应用程序添加一个事件过滤器。记得，installEventFilter()函数是QObject的函数，QApplication或者QCoreApplication对象都是QObject的子类，因此，我们可以向QApplication或者QCoreApplication添加事件过滤器。**这种全局的事件过滤器将会在所有其它特性对象的事件过滤器之前调用。尽管很强大，但这种行为会严重降低整个应用程序的事件分发效率。**因此，除非是不得不使用的情况，否则的话我们不应该这么做。

**注意:**

**事件过滤器和被安装过滤器的组件必须在同一线程，否则，过滤器将不起作用。另外，如果在安装过滤器之后，这两个组件到了不同的线程，那么，只有等到二者重新回到同一线程的时候过滤器才会有效。**



### 9.4 总结



Qt 的事件是整个 Qt 框架的核心机制之一，也比较复杂。说它复杂，更多是因为它涉及到的函数众多，而处理方法也很多，有时候让人难以选择。现在我们简单总结一下 Qt 中的事件机制。

Qt 中有很多种事件：鼠标事件、键盘事件、大小改变的事件、位置移动的事件等等。如何处理这些事件，实际有两种选择：

- 所有事件对应一个事件处理函数，在这个事件处理函数中用一个很大的分支语句进行选择，其代表作就是 win32 API 的WndProc()函数：

```c
LRESULT CALLBACK WndProc(HWND hWnd,
                         UINT message,
                         WPARAM wParam,
                         LPARAM lParam)
```

在这个函数中，我们需要使用switch语句，选择message参数的类型进行处理，典型代码是：

```c
switch(message)
{
    case WM_PAINT:
        // ...
        break;
    case WM_DESTROY:
        // ...
        break;
    ...
}
```

- 每一种事件对应一个事件处理函数。Qt 就是使用的这么一种机制：

- mouseEvent()

- keyPressEvent()

- …

Qt 具有这么多种事件处理函数，肯定有一个地方对其进行分发，否则，Qt 怎么知道哪一种事件调用哪一个事件处理函数呢？这个分发的函数，就是event()。显然，当QMouseEvent产生之后，event()函数将其分发给mouseEvent()事件处理器进行处理。

event()函数会有两个问题：

- event()函数是一个 protected 的函数，这意味着我们要想重写event()，必须继承一个已有的类。试想，我的程序根本不想要鼠标事件，程序中所有组件都不允许处理鼠标事件，是不是我得继承所有组件，一一重写其event()函数？protected 函数带来的另外一个问题是，如果我基于第三方库进行开发，而对方没有提供源代码，只有一个链接库，其它都是封装好的。我怎么去继承这种库中的组件呢？

- event()函数的确有一定的控制，不过有时候我的需求更严格一些：我希望那些组件根本看不到这种事件。event()函数虽然可以拦截，但其实也是接收到了QMouseEvent对象。我连让它收都收不到。这样做的好处是，模拟一种系统根本没有那个事件的效果，所以其它组件根本不会收到这个事件，也就无需修改自己的事件处理函数。这种需求怎么办呢？

这两个问题是event()函数无法处理的。于是，Qt 提供了另外一种解决方案：事件过滤器。事件过滤器给我们一种能力，让我们能够完全移除某种事件。事件过滤器可以安装到任意QObject类型上面，并且可以安装多个。如果要实现全局的事件过滤器，则可以安装到QApplication或者QCoreApplication上面。这里需要注意的是，如果使用installEventFilter()函数给一个对象安装事件过滤器，那么该事件过滤器只对该对象有效，只有这个对象的事件需要先传递给事件过滤器的eventFilter()函数进行过滤，其它对象不受影响。如果给QApplication对象安装事件过滤器，那么该过滤器对程序中的每一个对象都有效，任何对象的事件都是先传给eventFilter()函数。

**事件过滤器可以解决刚刚我们提出的event()函数的两点不足：**

- **首先，事件过滤器不是 protected 的，因此我们可以向任何QObject子类安装事件过滤器；**

- **其次，事件过滤器在目标对象接收到事件之前进行处理，如果我们将事件过滤掉，目标对象根本不会见到这个事件。**

事实上，还有一种方法，我们没有介绍。Qt 事件的调用最终都会追溯到QCoreApplication::notify()函数，因此，最大的控制权实际上是重写QCoreApplication::notify()。这个函数的声明是：

virtual bool QCoreApplication::notify ( QObject * receiver,

​                    QEvent * event );

该函数会将event发送给receiver，也就是调用receiver->event(event)，其返回值就是来自receiver的事件处理器。注意，这个函数为任意线程的任意对象的任意事件调用，因此，它不存在事件过滤器的线程的问题。不过我们并不推荐这么做，因为notify()函数只有一个，而事件过滤器要灵活得多。

 

**现在我们可以总结一下 Qt 的事件处理，实际上是有五个层次：**

- 重写paintEvent()、mousePressEvent()等事件处理函数。这是最普通、最简单的形式，同时功能也最简单。

- 重写event()函数。event()函数是所有对象的事件入口，QObject和QWidget中的实现，默认是把事件传递给特定的事件处理函数。

- 在特定对象上面安装事件过滤器。该过滤器仅过滤该对象接收到的事件。

- 在QCoreApplication::instance()上面安装事件过滤器。该过滤器将过滤所有对象的所有事件，因此和notify()函数一样强大，但是它更灵活，因为可以安装多个过滤器。全局的事件过滤器可以看到 disabled 组件上面发出的鼠标事件。全局过滤器有一个问题：只能用在主线程。

- 重写QCoreApplication::notify()函数。这是最强大的，和全局事件过滤器一样提供完全控制，并且不受线程的限制。但是全局范围内只能有一个被使用（因为QCoreApplication是单例的）。-

**项目名称：02_QtEvent2**

**mylabel.h**

```c
#ifndef MYLABEL_H
#define MYLABEL_H
#include<QLabel>
#include <QWidget>

class myLabel : public QLabel
{
public:
    explicit myLabel(QWidget *parent = nullptr);

    //鼠标进入事件
    void enterEvent(QEvent *event);

    //鼠标离开事件
    void leaveEvent(QEvent *);

    //鼠标移动
    virtual void mouseMoveEvent(QMouseEvent *ev);

    //鼠标按下
    virtual void mousePressEvent(QMouseEvent *ev);

    //鼠标释放
    virtual void mouseReleaseEvent(QMouseEvent *ev);

signals:

};

#endif // MYLABEL_H

```

**mylabel.cpp**

```c
#include "mylabel.h"
#include<QDebug>
#include<QMouseEvent>
myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追逐
    setMouseTracking(true);
}

//鼠标进入事件
void myLabel::enterEvent(QEvent *event)
{
//    qDebug()<<"鼠标进入了";
}

//鼠标离开事件
void myLabel::leaveEvent(QEvent *)
{
//    qDebug()<<"鼠标离开了";
}

//鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
//    if(ev->buttons() & Qt::LeftButton)
//    {
        QString str = QString("鼠标滚轮移动了 x =%1 y =%2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    //    qDebug()<<"鼠标移动了";
        qDebug()<<str;
//    }

}

//鼠标按下
void myLabel::mousePressEvent(QMouseEvent *ev)
{
//    if(ev->button() == Qt::LeftButton)
//    {
        QString str = QString("鼠标左键按下了 x =%1 y =%2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    //    qDebug()<<"鼠标按下了";
        qDebug()<<str;
//    }

}

//鼠标释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
//    if(ev->button() == Qt::RightButton)
//    {
        QString str = QString("鼠标右键按下并释放了 x =%1 y =%2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    //    qDebug()<<"鼠标释放了";
        qDebug()<<str;
//    }

}

```

Ui设计：

![](qt_picture/37.png)

**运行结果：** 

![](qt_picture/36.png)



## 10	绘图和绘图设备

### 10.1	QPainter

Qt 的绘图系统允许使用相同的 API 在屏幕和其它打印设备上进行绘制。整个绘图系统基于QPainter，QPainterDevice和QPaintEngine三个类。

**QPainter**用来执行绘制的操作；**QPaintDevice**是一个二维空间的抽象，这个二维空间允许QPainter在其上面进行绘制，也就是QPainter工作的空间；**QPaintEngine**提供了画笔（QPainter）在不同的设备上进行绘制的统一的接口。QPaintEngine类应用于QPainter和QPaintDevice之间，通常对开发人员是透明的。除非你需要自定义一个设备，否则你是不需要关心QPaintEngine这个类的。我们可以把QPainter理解成画笔；把QPaintDevice理解成使用画笔的地方，比如纸张、屏幕等；而对于纸张、屏幕而言，肯定要使用不同的画笔绘制，为了统一使用一种画笔，我们设计了QPaintEngine类，这个类让不同的纸张、屏幕都能使用一种画笔。

下图给出了这三个类之间的层次结构:

![](qt_picture/40.png)

上面的示意图告诉我们，**Qt 的绘图系统实际上是，使用QPainter在QPainterDevice上进行绘制，它们之间使用QPaintEngine进行通讯（也就是翻译QPainter的指令）。**

下面我们通过一个实例来介绍QPainter的使用：

```c
class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    PaintedWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
}
```

注意我们重写了QWidget的paintEvent()函数。接下来就是PaintedWidget的源代码：

```c
PaintedWidget::PaintedWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(800, 600);
    setWindowTitle(tr("Paint Demo"));
}
void PaintedWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawLine(80, 100, 650, 500);
    painter.setPen(Qt::red);
    painter.drawRect(10, 10, 100, 400);
    painter.setPen(QPen(Qt::green, 5));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(50, 150, 400, 200);
}
```

在构造函数中，我们仅仅设置了窗口的大小和标题。而paintEvent()函数则是绘制的代码。首先，我们在栈上创建了一个QPainter对象，也就是说，每次运行paintEvent()函数的时候，都会重建这个QPainter对象。注意，这一点可能会引发某些细节问题：由于我们每次重建QPainter，因此第一次运行时所设置的画笔颜色、状态等，第二次再进入这个函数时就会全部丢失。有时候我们希望保存画笔状态，就必须自己保存数据，否则的话则需要将QPainter作为类的成员变量。

QPainter接收一个QPaintDevice指针作为参数。QPaintDevice有很多子类，比如QImage，以及QWidget。注意回忆一下，QPaintDevice可以理解成要在哪里去绘制，而现在我们希望画在这个组件，因此传入的是 this 指针。

QPainter有很多以 draw 开头的函数，用于各种图形的绘制，比如这里的drawLine()，drawRect()以及drawEllipse()等。当绘制轮廓线时，使用QPainter的pen()属性。比如，我们调用了painter.setPen(Qt::red)将 pen 设置为红色，则下面绘制的矩形具有红色的轮廓线。接下来，我们将 pen 修改为绿色，5 像素宽（painter.setPen(QPen(Qt::green, 5))），又设置了画刷为蓝色。这时候再调用 draw 函数，则是具有绿色 5 像素宽轮廓线、蓝色填充的椭圆。

**项目名称：03_QPainter**

![](qt_picture/44.png)

widget.h

```c
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //绘图事件
    void paintEvent(QPaintEvent *event);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

```



widget.cpp

```c
#include "widget.h"
#include "ui_widget.h"
#include<QPainter>  //画家类

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

//绘图事件
void Widget::paintEvent(QPaintEvent *event)
{
    //实例化画家对象，this指定的是绘图设备
    QPainter painter(this);

    //设置画笔 红色
    QPen pen(QColor(255,5,0));
    //设置画笔宽度
    pen.setWidth(2);
    //设置画笔风格
    pen.setStyle(Qt::DotLine);
    //让画家  使用这个笔
    painter.setPen(pen);

    //设置画刷
    QBrush brush(Qt::blue);
    //设置画刷风格
    brush.setStyle(Qt::Dense7Pattern);
    painter.setBrush(brush);

    //画线
    painter.drawLine(QPoint(0,0),QPoint(100,100));

    //画圆 椭圆
    painter.drawEllipse(QPoint(100,100),50,50);

    //画矩形
    painter.drawRect(20,20,40,40);

    //画文字
    painter.drawText(QRect(20,200,300,50),"never，never，never，never give up");

}

Widget::~Widget()
{
    delete ui;
}


```

**运行结果：**

![](qt_picture/45.png)



### 10.2	绘图设备

**绘图设备是指继承QPainterDevice的子类。**Qt一共提供了四个这样的类，分别是QPixmap、QBitmap、QImage和 QPicture。其中：-

- QPixmap专门为图像在屏幕上的显示做了优化

- QBitmap是QPixmap的一个子类，它的色深限定为1，可以使用 QPixmap的isQBitmap()函数来确定这个QPixmap是不是一个QBitmap。

- QImage专门为图像的像素级访问做了优化。 

QPicture则可以记录和重现QPainter的各条命令



widget.cpp

```c
    QPainter painter(this);
   //画矩形
    painter.drawRect(QRect(40,50,40,60));

    //移动画家
    painter.translate(100,0);

    //保全画家状态
    painter.save();
    painter.drawRect(QRect(40,50,40,60));

    painter.translate(100,0);

    //还原画家保存状态 将会回到第二个画矩形的位置
    painter.restore();
    painter.drawRect(QRect(40,50,40,60));
```

**运行结果：**

![](qt_picture/46.png)

#### 10.2.1 QPixmap、QBitmap、QImage

QPixmap继承了QPaintDevice，因此，你可以使用QPainter直接在上面绘制图形。QPixmap也可以接受一个字符串作为一个文件的路径来显示这个文件，比如你想在程序之中打开png、jpeg之类的文件，就可以使用 QPixmap。使用QPainter的drawPixmap()函数可以把这个文件绘制到一个QLabel、QPushButton或者其他的设备上面。**QPixmap是针对屏幕进行特殊优化的，因此，它与实际的底层显示设备息息相关。**注意，这里说的显示设备并不是硬件，而是操作系统提供的原生的绘图引擎。所以，在不同的操作系统平台下，QPixmap的显示可能会有所差别。

**QBitmap继承自QPixmap，因此具有QPixmap的所有特性，提供单色图像**。QBitmap的色深始终为1. 色深这个概念来自计算机图形学，是指用于表现颜色的二进制的位数。我们知道，计算机里面的数据都是使用二进制表示的。为了表示一种颜色，我们也会使用二进制。比如我们要表示8种颜色，需要用3个二进制位，这时我们就说色深是3. 因此，所谓色深为1，也就是使用1个二进制位表示颜色。1个位只有两种状态：0和1，因此它所表示的颜色就有两种，黑和白。所以说，**QBitmap实际上是只有黑白两色的图像数据。**

**由于QBitmap色深小，因此只占用很少的存储空间，所以适合做光标文件和笔刷。**

下面我们来看同一个图像文件在QPixmap和QBitmap下的不同表现：

```c
void PaintWidget::paintEvent(QPaintEvent *)
{
    QPixmap pixmap(":/Image/butterfly.png");
    QPixmap pixmap1(":/Image/butterfly1.png");
    QBitmap bitmap(":/Image/butterfly.png");
    QBitmap bitmap1(":/Image/butterfly1.png");

    QPainter painter(this);
    painter.drawPixmap(0, 0, pixmap);
    painter.drawPixmap(200, 0, pixmap1);
    painter.drawPixmap(0, 130, bitmap);
    painter.drawPixmap(200, 130, bitmap1);
}
```

![](qt_picture/41.png)

这里我们给出了两张png图片。butterfly1.png是没有透明色的纯白背景，而butterfly.png是具有透明色的背景。我们分别使用QPixmap和QBitmap来加载它们。注意看它们的区别：白色的背景在QBitmap中消失了，而透明色在QBitmap中转换成了黑色；其他颜色则是使用点的疏密程度来体现的。

QPixmap使用底层平台的绘制系统进行绘制，无法提供像素级别的操作，而**QImage则是使用独立于硬件的绘制系统，实际上是自己绘制自己，因此提供了像素级别的操作，并且能够在不同系统之上提供一个一致的显示形式。**

我们声明了一个QImage对象，大小是300 x 300，颜色模式是RGB32，即使用32位数值表示一个颜色的RGB值，也就是说每种颜色使用8位。然后我们对每个像素进行颜色赋值，从而构成了这个图像。我们可以把QImage想象成一个RGB颜色的二维数组，记录了每一像素的颜色。

```c
void PaintWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QImage image(300, 300, QImage::Format_RGB32);
    QRgb value;

    //将图片背景填充为白色
    image.fill(Qt::white);

    //改变指定区域的像素点的值
    for(int i=50; i<100; ++i)
    {
        for(int j=50; j<100; ++j)
        {
            value = qRgb(255, 0, 0); // 红色
            image.setPixel(i, j, value);
        }
    }

    //将图片绘制到窗口中
    painter.drawImage(QPoint(0, 0), image);
}
```

![](qt_picture/42.png)

QImage与QPixmap的区别:-

- QPixmap主要是用于绘图，针对屏幕显示而最佳化设计，QImage主要是为图像I/O、图片访问和像素修改而设计的

- QPixmap依赖于所在的平台的绘图引擎，故例如反锯齿等一些效果在不同的平台上可能会有不同的显示效果，QImage使用Qt自身的绘图引擎，可在不同平台上具有相同的显示效果

- 由于QImage是独立于硬件的，也是一种QPaintDevice，因此我们可以在另一个线程中对其进行绘制，而不需要在GUI线程中处理，使用这一方式可以很大幅度提高UI响应速度。

- QImage可通过setPixpel()和pixel()等方法直接存取指定的像素。

QImage与QPixmap之间的转换:

- QImage转QPixmap

使用QPixmap的静态成员函数: fromImage()

>  QPixmap	fromImage(const QImage & image, 
>
> ​						Qt::ImageConversionFlags flags = Qt::AutoColor)



- QPixmap转QImage:

​	使用QPixmap类的成员函数: toImage()

>  QImage toImage() const

#### 10.2.2 QPicture



最后一个需要说明的是QPicture。**这是一个可以记录和重现QPainter命令的绘图设备。** **QPicture将QPainter的命令序列化到一个IO设备，保存为一个平台独立的文件格式。**这种格式有时候会是“元文件(meta- files)”。Qt的这种格式是二进制的，不同于某些本地的元文件，Qt的pictures文件没有内容上的限制，只要是能够被QPainter绘制的元素，不论是字体还是pixmap，或者是变换，都可以保存进一个picture中。

**QPicture是平台无关的**，因此它可以使用在多种设备之上，比如svg、pdf、ps、打印机或者屏幕。回忆下我们这里所说的QPaintDevice，实际上是说可以有QPainter绘制的对象。QPicture使用系统的分辨率，并且可以调整 QPainter来消除不同设备之间的显示差异。

如果我们要记录下QPainter的命令，首先要使用QPainter::begin()函数，将QPicture实例作为参数传递进去，以便告诉系统开始记录，记录完毕后使用QPainter::end()命令终止。代码示例如下：

```c
void PaintWidget::paintEvent(QPaintEvent *)
{
    QPicture pic;
    QPainter painter;
	 //将图像绘制到QPicture中,并保存到文件
    painter.begin(&pic);
    painter.drawEllipse(20, 20, 100, 50);
    painter.fillRect(20, 100, 100, 100, Qt::red);
    painter.end();
    pic.save("D:\\drawing.pic");

	 //将保存的绘图动作重新绘制到设备上
    pic.load("D:\\drawing.pic");
    painter.begin(this);
    painter.drawPicture(200, 200, pic);
    painter.end();
}
```

**项目名称：04_QtPainDevice**

widget.h

```c
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //绘图事件
    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

```

widget.cpp

```c
#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>
#include<QImage>
#include<QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
//    this->resize(600,600);
//    ui->setupUi(this);

//    //Pixmap绘图设备  专门为平台做了显示的优化
//    QPixmap pix(300,300);

//    //填充背景颜色
//    pix.fill(Qt::white);
//    //声明画家
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    //保存
//    pix.save("E:\\pix.png");


    //QImage  绘图设备

//    QImage img(300,300,QImage::Format_RGB32);
//    img.fill(Qt::white);

//    //声明画家
//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::red));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    //保存
//    img.save("E:\\img.png");

    //QPicture 绘图设备 可以记录和重现绘制指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);   //开始往pic上画
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(150,150),100,100);

    painter.end();  //结束画画
    //保存到磁盘
    pic.save("E:\\pic.zt");


}

//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);

//    //利用QImage  对像素进行修改
//    QImage img;
//    img.load(":/Image/Frame.jpg");
//    //修改像素点
//    for(int i = 50;i < 100;i++)
//    {
//        for(int j =50; j<100;j++)
//        {
//            QRgb value = qRgb(255,0,0);
//            img.setPixel(i,j,value);
//        }
//    }
//    //绘制图片
//    painter.drawImage(0,0,img);


    QPainter painter(this);
    //重现QPicture的绘图指令
    QPicture pic;
    pic.load("E:\\pic.zt");
    painter.drawPicture(0,0,pic);

}

Widget::~Widget()
{
    delete ui;
}


```

**运行结果：**

![](qt_picture/47.png)





## 11	文件系统

文件操作是应用程序必不可少的部分。Qt 作为一个通用开发库，提供了跨平台的文件操作能力。Qt 通过QIODevice提供了对 I/O 设备的抽象，这些设备具有读写字节块的能力。下面是 I/O 设备的类图（Qt5）：

![](qt_picture/43.png)

- QIODevice：所有 I/O 设备类的父类，提供了字节块读写的通用操作以及基本接口；

- QFileDevice：Qt5新增加的类，提供了有关文件操作的通用实现。

- QFlie：访问本地文件或者嵌入资源；

- QTemporaryFile：创建和访问本地文件系统的临时文件；

- QBuffer：读写QbyteArray, 内存文件；

- QProcess：运行外部程序，处理进程间通讯；

- QAbstractSocket：所有套接字类的父类；

- QTcpSocket：TCP协议网络数据传输；

- QUdpSocket：传输 UDP 报文；

- QSslSocket：使用 SSL/TLS 传输数据；

### 11.1	文件系统分类

- 顺序访问设备:

是指它们的数据只能访问一遍：从头走到尾，从第一个字节开始访问，直到最后一个字节，中途不能返回去读取上一个字节，这其中，QProcess、QTcpSocket、QUdpSoctet和QSslSocket是顺序访问设备。

- 随机访问设备:

可以访问任意位置任意次数，还可以使用QIODevice::seek()函数来重新定位文件访问位置指针，QFile、QTemporaryFile和QBuffer是随机访问设备， 

### 11.2	基本文件操作

文件操作是应用程序必不可少的部分。Qt 作为一个通用开发库，提供了跨平台的文件操作能力。在所有的 I/O 设备中，文件 I/O 是最重要的部分之一。因为我们大多数的程序依旧需要首先访问本地文件（当然，在云计算大行其道的将来，这一观点可能改变）。**QFile提供了从文件中读取和写入数据的能力。**

**我们通常会将文件路径作为参数传给QFile的构造函数。不过也可以在创建好对象最后，使用setFileName()来修改**。QFile需要使用 / 作为文件分隔符，不过，它会自动将其转换成操作系统所需要的形式。例如 C:/windows 这样的路径在 Windows 平台下同样是可以的。

QFile主要提供了有关文件的各种操作，比如打开文件、关闭文件、刷新文件等。**我们可以使用QDataStream或QTextStream类来读写文件，也可以使用QIODevice类提供的read()、readLine()、readAll()以及write()这样的函数。**值得注意的是，**有关文件本身的信息，比如文件名、文件所在目录的名字等，则是通过QFileInfo获取**，而不是自己分析文件路径字符串。

下面我们使用一段代码来看看QFile的有关操作：

```c
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
 
    QFile file("in.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Open file failed.";
        return -1;
    } else {
        while (!file.atEnd()) {
            qDebug() << file.readLine();
        }
    }
  	QFileInfo info(file);
    qDebug() << info.isDir();
    qDebug() << info.isExecutable();
    qDebug() << info.baseName();
    qDebug() << info.completeBaseName();
    qDebug() << info.suffix();
    qDebug() << info.completeSuffix();
 
    return app.exec();
}   
```

- 我们首先使用QFile创建了一个文件对象。

这个文件名字是 in.txt。如果你不知道应该把它放在哪里，可以使用QDir::currentPath()来获得应用程序执行时的当前路径。只要将这个文件放在与当前路径一致的目录下即可。

- 使用open()函数打开这个文件，打开形式是只读方式，文本格式。

这个类似于fopen()的 r 这样的参数。open()函数返回一个 bool 类型，如果打开失败，我们在控制台输出一段提示然后程序退出。否则，我们利用 while 循环，将每一行读到的内容输出。

- 可以使用QFileInfo获取有关该文件的信息。

​	QFileInfo有很多类型的函数，我们只举出一些例子。比如：

	- isDir()检查该文件是否是目录；
	
	- isExecutable()	检查该文件是否是可执行文件等。
	
	- baseName()		可以直接获得文件名；
	
	- completeBaseName() 	获取完整的文件名
	
	- suffix()	则直接获取文件后缀名。
	
	- completeSuffix() 	获取完整的文件后缀

我们可以由下面的示例看到，baseName()和completeBaseName()，以及suffix()和completeSuffix()的区别：

```c
QFileInfo fi("/tmp/archive.tar.gz");
QString base  = fi.baseName();  // base = "archive"
QString base  = fi.completeBaseName();  // base = "archive.tar"
QString ext   = fi.suffix();  // ext = "gz"
QString ext   = fi.completeSuffix();  // ext = "tar.gz"
```



### 11.3	二进制文件读写

**QDataStream**提供了基于QIODevice的二进制数据的序列化。数据流是一种二进制流，这种流**完全不依赖**于底层操作系统、CPU 或者字节顺序（大端或小端）。例如，在安装了 Windows 平台的 PC 上面写入的一个数据流，可以不经过任何处理，直接拿到运行了 Solaris 的 SPARC 机器上读取。由于数据流就是二进制流，因此我们也可以**直接读写没有编码的二进制数据，例如图像、视频、音频**等。

**QDataStream既能够存取 C++ 基本类型，如 int、char、short 等，也可以存取复杂的数据类型，例如自定义的类。实际上，QDataStream对于类的存储，是将复杂的类分割为很多基本单元实现的。**

结合QIODevice，QDataStream可以很方便地对文件、网络套接字等进行读写操作。我们从代码开始看起：

```c
QFile file("file.dat");
file.open(QIODevice::WriteOnly);
QDataStream out(&file);
out << QString("the answer is");
out << (qint32)42;
```

- 在这段代码中，我们首先打开一个名为 file.dat 的文件（注意，我们为简单起见，并没有检查文件打开是否成功，这在正式程序中是不允许的）。然后，我们将刚刚创建的file对象的指针传递给一个QDataStream实例out。类似于std::cout标准输出流，QDataStream也重载了输出重定向<<运算符。后面的代码就很简单了：将“the answer is”和数字 42 输出到数据流。由于我们的 out 对象建立在file之上，因此相当于将问题和答案写入file。

- 需要指出一点：最好使用 Qt 整型来进行读写，比如程序中的qint32。这保证了在任意平台和任意编译器都能够有相同的行为。

如果你直接运行这段代码，你会得到一个空白的 file.dat，并没有写入任何数据。这是因为我们的file没有正常关闭。**为性能起见，数据只有在文件关闭时才会真正写入**。因此，我们必须在最后添加一行代码：

> file.close(); // 如果不想关闭文件，可以使用 file.flush();

接下来我们将存储到文件中的答案取出来

```c
QFile file("file.dat");
file.open(QIODevice::ReadOnly);
QDataStream in(&file);
QString str;
qint32 a;
in >> str >> a;
```

**唯一需要注意的是，你必须按照写入的顺序，将数据读取出来。顺序颠倒的话，程序行为是不确定的，严重时会直接造成程序崩溃。**

那么，既然QIODevice提供了read()、readLine()之类的函数，为什么还要有QDataStream呢？QDataStream同QIODevice有什么区别？区别在于，**QDataStream提供流的形式，性能上一般比直接调用原始 API 更好一些。**我们通过下面一段代码看看什么是流的形式：

```c
QFile file("file.dat");
file.open(QIODevice::ReadWrite);
 
QDataStream stream(&file);
QString str = "the answer is 42";

stream << str;
```



### 11.4	文本文件读写

上一节我们介绍了有关二进制文件的读写。二进制文件比较小巧，却不是人可读的格式。而文本文件是一种人可读的文件。为了操作这种文件，我们需要使用QTextStream类。QTextStream和QDataStream的使用类似，只不过它是操作纯文本文件的。

QTextStream会自动将 Unicode 编码同操作系统的编码进行转换，这一操作对开发人员是透明的。它也会将换行符进行转换，同样不需要自己处理。**QTextStream使用 16 位的QChar作为基础的数据存储单位，同样，它也支持 C++ 标准类型，如 int 等。实际上，这是将这种标准类型与字符串进行了相互转换。**

QTextStream同QDataStream的使用基本一致，例如下面的代码将把“The answer is 42”写入到 file.txt 文件中：

```c
QFile data("file.txt");
if (data.open(QFile::WriteOnly | QIODevice::Truncate)) 
{
    QTextStream out(&data);
    out << "The answer is " << 42;
}
```

> 这里，我们在open()函数中增加了QIODevice::Truncate打开方式。我们可以从下表中看到这些打开方式的区别：
>
> 枚举值	      				  描述
>
>  QIODevice::NotOpen		未打开
>
>  QIODevice::ReadOnly		以只读方式打开
>
>  QIODevice::WriteOnly		以只写方式打开
>
>  QIODevice::ReadWrite		以读写方式打开
>
>  QIODevice::Append			以追加的方式打开，
>
> 新增加的内容将被追加到文件末尾
>
>  QIODevice::Truncate		以重写的方式打开，在写入新的数据时会将原有
>
> ​										数据全部清除，游标设置在文件开头。
>
>  QIODevice::Text			在读取时，将行结束符转换成 \n；在写入时，
>
> ​										将行结束符转换成本地格式，例如 Win32 平台
>
> ​										上是 \r\n
>
>  QIODevice::Unbuffered	忽略缓存
>
> 我们在这里使用了QFile::WriteOnly | QIODevice::Truncate，也就是以只写并且覆盖已有内容的形式操作文件。注意，QIODevice::Truncate会直接将文件内容清空。
>
>  

虽然QTextStream的写入内容与QDataStream一致，但是读取时却会有些困难：

```c
QFile data("file.txt");
if (data.open(QFile::ReadOnly)) 
{
    QTextStream in(&data);
    QString str;
    int ans = 0;
    in >> str >> ans;
}
```

在使用QDataStream的时候，这样的代码很方便，但是使用了QTextStream时却有所不同：读出的时候，str 里面将是 The answer is 42，ans 是 0。这是因为**当使用QDataStream写入的时候，实际上会在要写入的内容前面，额外添加一个这段内容的长度值。而以文本形式写入数据，是没有数据之间的分隔的。**因此，使用文本文件时，很少会将其分割开来读取，而是使用诸如使用：

- QTextStream::readLine()	读取一行

- QTextStream::readAll()读取所有文本

这种函数之后再对获得的QString对象进行处理。

默认情况下，QTextStream的编码格式是 Unicode，如果我们需要使用另外的编码，可以使用：

> stream.setCodec("UTF-8");

这样的函数进行设置。

**项目名称：05_Qt_QFile**

![](qt_picture/50.png)

widget.h

````c
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

````

widget.cpp

```c
#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QTextCodec>
#include<QFileInfo>
#include<QDebug>
#include<QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击选取文件按钮，弹出文件对话框
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path= QFileDialog::getOpenFileName(this,"打开文件","E:\\");
        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        //编码格式类
        QTextCodec * codec = QTextCodec::codecForName("gbk");
        //读取内容  放入到textEdit中
        //QFile 默认支持的格式是utf-8

        QFile file(path);   //参数就是读取文件的路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);

//        QByteArray array = file.readAll();


        QByteArray array;
        while(!file.atEnd())  //循环读取
        {
            //按行读取
            array += file.readLine();
        }


        //将读取到的数据放入到 textEdit 中
//        ui->textEdit->setText(array);
        ui->textEdit->setText(codec->toUnicode(array));

        //对文件对象进行关闭
        file.close();

        //进行写文件
//        file.open(QIODevice::Append);  //追加方式进行写
//        file.write("我要变成强，我要成为强者，我要实现我的愿望");
//        file.close();

        //QFileInfo  文件信息
        QFileInfo info(path);
        qDebug()<<"大小："<<info.size()<<"后缀名："<<info.suffix()<<"文件名称："<<info.fileName()<<"文件路径："<<info.filePath();
        qDebug()<<"创建日期："<<info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug()<<"最后修改日期："<<info.lastModified().toString("yyyy-MM-dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}


```

**运行结果：**

![](qt_picture/51.png)



```
6.1	分类
	6.1.1	模态对话框（不可以对其他窗口进行操作、阻塞）
		6.1.1.1	QDialog dlg(this)
		6.1.1.2	dlg.exec()
	6.1.2	非模态对话框（可以对其他窗口进行操作）
		6.1.2.1	防止一闪而过，把它创建在堆区
		6.1.2.2	QDialog *dlg = newQDialog(this)
		6.1.2.3	dlg->show()
		6.1.2.4	dlg>setAttribute(Qt::WA_DeleteOnClose);
6.2	标准对话框 -- 消息对话框
	6.2.1	QMessageBox 静态成员函数	创建对话框
	6.2.2	错误、提问、信息、警告
	6.2.3	参数1：父亲	参数2：标题	参数3：显示内容	参数4：按键类型	参数5：默认回车按键
	6.2.4	返回值也是 StandarButton,利用返回值判断用户的输入
6.3	其他标准对话框
	6.3.1	颜色对话框 QColorDialog::getColor
	6.3.2	文件对话框	QFileDialog::getOpenFileName(父亲，标题，默认路径，过滤，文件)
	6.3.3	字体对话框	QFontDialog::getFont

7	界面布局
	7.1	实现登录窗口
	7.2	利用布局方式，给窗口进行美化
	7.3	选取widget 进行布局，有水平布局、垂直布局、网格布局
	7.4	给用户名、登录、退出按钮进行布局
	4.5	默认窗口和控件之间有9间隙，可以调整layoutLeftMargin
	4.6	利用弹簧进行布局
	
8	控件
	8.1	按钮组件
		5.1.1	QPushButton	常用按钮
		5.1.2	QToolButton	工具按钮，可用于显示图片，如图想显示文字，修改风格；toolButton，凸起风格autoRaise
		5.1.3	radioButton 单选按钮，设置默认ui->rBtnMan->setChecked(true);
		5.1.4	checkBox 多选按钮，监听状态 2：选中  1：半选	0未选中
	8.2	QListWidget	列表容器
        8.2.1	QListWidgetItem 一行内容
        8.2.2	ui->listWidget->addItem(item);
        8.2.3	设置居中方式 item->setTextAlignment(Qt::AlignHCenter);
        8.2.4	可以利用addItems一次性添加整个诗内容
	8.3	QTreeWidget 树控件
		8.3.1	设置头
			8.3.1.1	ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");
		8.3.2	创建根节点
			8.3.2.1	QTreeWidgetItem * LiItem = new QTreeWidgetItem(QStringList()<<"力量");
		8.3.3	添加根节点到树控件上
			8.3.3.1	ui->treeWidget->addTopLevelItem(LiItem);
		8.3.4	添加子节点
			8.3.4.1	LiItem->addChild(l2);
			
	8.4	QTableWidget	表格控件
		8.4.1	设置列数
			8.4.1.1	ui->tableWidget->setColumnCount(3);
		8.4.2	设置水平头
			8.4.2.1	ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
		8.4.3	设置行数
			8.4.3.1	ui->tableWidget->setRowCount(5);
		8.4.4	设置正文
			8.4.4.1	ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
		
	8.5	其他控件介绍
		8.5.1	stackedWidget控件介绍
			8.5.1.1		ui->stackedWidget->setCurrentIndex(2);
		8.5.2	下拉框
			8.5.2.1	ui->comboBox->addItem("奔驰");
		8.5.3	QLabel显示图片
        	8.5.3.1	ui->lbl_Image->setPixmap(QPixmap(":/Image/butterfly.png"));
        8.5.4	QLabel显示，GIF动态图片
        	8.5.4.1	ui->lbl_movie->setMovie(movie);
        	8.5.4.2	movie->start();
        	
    8.6	自定义控件封装
    	8.6.1	添加新文件，Qt - 设计师界面类(.h .cpp .ui)
    	8.6.2	.ui中设计QSpinBox和QSlider两个控件
    	8.6.3	Widget中使用自定义控件，拖拽一个Widget,点击提升为->点击添加->点击提升
    	8.6.4	实现功能，改变数字，滑动条跟着移动，信号槽监听
    	8.6.5	提供getNum 和 setNum对外接口
    	8.6.6	测试接口
    	
 9	Qt消息机制事件
 	9.1	Qt事件
 		9.1.1	鼠标事件
 				鼠标离开事件 leaveEvent
 				鼠标进入事件 enterEvent
 				鼠标按下	mousePressEvent(QMouseEvent ev)
 				鼠标释放	mouseReleaseEvent
 				鼠标移动	mouseMoveEvent
 				x坐标：ev->x() y坐标：ev->y()
 				ev->button() 可以判定所有按键 Qt::LeftButton  Qt::RightButton
 				ev->buttons() 判断组合按键  判断move时候的左右按键 结合 & 操作符
 				格式化字符串  QString("%1  %2....").arg(222)
 	
 	9.2	定时器
    	9.2.1	定时器1
        		1.	利用事件 void timerEvent(QTimerEvent *ev);
        		2.	启动定时器startTimer(1000)毫秒单位
        		3.	timerEvent的返回值是定时器的唯一标示，可以和ev->timerId做比较
        		
    	9.2.2	定时器2
    			1.	利用定时器类QTimer
    			2.	创建定时器对象 QT* timer = new QTimer(this)
    			3.	启动定时器 timer->start()
    			4.	每隔一定毫秒，发送信号 timeout，进行监听
    			5.	暂停 timer-stop
    			
    9.3	event事件
    		1.用途：用于事件的分发
    		2.也可以做拦截操作，不建议使用
    		3.bool event(QEvent *ev); 返回值如果是true代表用户处理这个事件，不用向下分发了
    		4.e->type() == 鼠标按下
    9.4	事件过滤器
    		
    		9.4.1 在程序将时间分发到事件分发器前，可以利用过滤器做拦截
    		9.4.2 步骤
    				1.给控件安装事件过滤器
    				2.重写eventFilter函数(obj,ev)
    				
10	QPainter 绘图
		10.1	QPainter 
				1.绘图事件 void paintEvent()
				2.声明一个画家对象 QPainter painter(this) this指定绘图设备为该为widget
				3.画线、画圆、画矩形、画文字
				4.设置画笔 QPen 设置画笔高度、风格
				5.设置画刷QBrush 设置画刷 风格 
	
		10.2	QPainter 高级设置
				1.抗锯齿但效率低
					painter.setRenderHint(QPainter::Antialiasing);    //不知道里面参数应该填写什么，可以查看帮助文档
				2.对画家进行移动
					painter.translate(100,0);
					保存画家状态 painter.save();
					还原画家状态 painter.restore();
    			3.如果想手动调用绘图事件  利用update
    			4.利用画家画图片	 painter.drawPixmap(posX,posY,QPixmap(":/Image/Luffy.png"));
    	
    	10.3	QPainter高级设备
    			10.3.1	QPixmap  QImage	QBitmap(黑白色)	QPicture	QWidget
    			10.3.2	QPixmap 对不同平台做了显示的优化
                		1.QPixmap pix(300,300);
                		2.pix.fill(Qt::white);  //填充背景颜色
                		3.利用画家往pix上画画  QPainter painter(&pix);
                		4.保存 pix.save("路径");
                10.3.3	利用QImage  对像素进行修改
                		1.使用和QPixmap差不多 Image img(300,300,QImage::Format_RGB32);
                		2.其他流程和QPixmap一样
                		3.可以对像素进行修改 img.setPixel(i,j,value);
                10.3.4	QPicture  记录和重现绘图指令
                		1.QPicture pic
                		2.painter.begin(&pic);
                		3.保存 pic.save("路径"); 注意后缀名
                		4.重现 利用画家可以重现painter.drawPicture(0,0,pic);
                		
11	QFile 对文件进行读写操作
	11.1.	QFile进行读写操作
	11.2.	QFile file(path 文件路径)
	11.3	读
			1.file.open打开方式  file.open(QIODevice::ReadOnly);
			2.全部读取  file.readAll(); 按行读取 file.readLine(); file.atEnd() 判断是否读到尾
			3.默认支持编码格式 utf-8
			4.利用编码格式类 指定格式QTextCodec
			5.QTextCodec * codec = QTextCodec::codecForName("gbk");
			6. ui->textEdit->setText(array);
			7.对文件对象进行关闭 file.close();
			
	11.4	写
    		1.file.open(QIODevice::writeOnly|Append);  //追加方式进行写
    		2.file.write(内容)
    		3.file.close();  关闭文件
    		
    11.5	QFileInfo 读取文件信息
    		1.QFileInfo info(path);  //读取文件路径
    		2.qDebug()<<"大小："<<info.size()<<"后缀名："<<info.suffix()<<"文件名称："<<info.fileName()<<"文件路径："<<info.filePath();
        qDebug()<<"创建日期："<<info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug()<<"最后修改日期："<<info.lastModified().toString("yyyy-MM-dd hh:mm:ss");

	
    			
```



```
11	QFile 对文件进行读写操作
	11.1.	QFile进行读写操作
	11.2.	QFile file(path 文件路径)
	11.3	读
			1.file.open打开方式  file.open(QIODevice::ReadOnly);
			2.全部读取  file.readAll(); 按行读取 file.readLine(); file.atEnd() 判断是否读到尾
			3.默认支持编码格式 utf-8
			4.利用编码格式类 指定格式QTextCodec
			5.QTextCodec * codec = QTextCodec::codecForName("gbk");
			6. ui->textEdit->setText(array);
			7.对文件对象进行关闭 file.close();
			
	11.4	写
    		1.file.open(QIODevice::writeOnly|Append);  //追加方式进行写
    		2.file.write(内容)
    		3.file.close();  关闭文件
    		
    11.5	QFileInfo 读取文件信息
    		1.QFileInfo info(path);  //读取文件路径
    		2.qDebug()<<"大小："<<info.size()<<"后缀名："<<info.suffix()<<"文件名称："<<info.fileName()<<"文件路径："<<info.filePath();
        qDebug()<<"创建日期："<<info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug()<<"最后修改日期："<<info.lastModified().toString("yyyy-MM-dd hh:mm:ss");

	
    			
```





```
1	项目简介
2	创建项目、添加项目资源
3	项目 基本配置
	3.1 设置背景图标
	3.2	设置固定大小
	3.3	设置项目标题
	3.4	设置背景
	3.5	设置背景标题
	3.6	开始菜单 - 退出功能

4	创建开始按钮
	4.1	封装自定义按钮  MyPushButton
	4.2	构造函数（默认显示图片，按下后显示的图片）
	4.3	测试开始按钮
	4.4	开始制作特效
	4.5	zoom1向下跳
	4.6	zoom2向上跳
	
5	创建选择关卡场景
	5.1	点击开始按钮后，延时进入到选择关卡场景
	5.2	配置选择关卡场景（图标、标题、大小）
	5.3	设置背景图片、设置标题图片
	5.4	创建返回按钮
	
6	选择关卡的返回按钮特效制作
	6.1	点击切换到另一个图片
	6.2	重写 void mousePressEvent
	6.3	重写 void mouseReleaseEvent
	
7	开始场景与选择关卡场景切换
	7.1	点击选择关卡场景的返回按钮，发送一个自定义信号
	7.2	在主场景中监听这个信号，并且当出发信号后，重写显示主场景，隐藏掉选择关卡的场景

8	选择关卡中的 按钮创建
	8.1	利用一个for循环将所有按钮布置到场景中
	8.2	在按钮上面 设置一个QLabel显示关卡数
		1 QLabel 设置大小、显示文字、对齐方式、鼠标穿透
	8.3	给每个按钮监听点击事件

9	翻金币场景创建
	9.1	点击选择关卡按钮后，进入
	9.2	配置翻金币游戏场景，设置标题、图标、大小、设置背景
	9.3	实现返回按钮，可以返回到上一个场景（选关场景）
	9.4	实现三个场景之间的切换

10	实现显示关卡标签
	10.1 在左下角显示玩家具体的关卡标签
	10.2 QLabel创建设置大小和位置 label->setGeometry(40,this->height()-200,140,100);
	10.3 QFont font设置字体以及字号
	10.4 QLabel设置字体setFont(font);

11	创建金币类
	1.1 先将金币的背景图案放入到PlayScene中
	1.2	创建MyCoin自定义金币按钮类
	1.3 MyCoin::MyCoin(QString btnImg)构造函数中传入默认显示的图片金币
	1.4 在PlayScene创建所有的金币按钮
	
12	每个关卡的默认显示
	12.1 先引入dataConfig.h 和 dataConfig.cpp 文件到项目中
	12.2 在PlayScene中写了 int gameArray[4][4]的数组，维护每个关卡的金币状态
	12.3 初始化每个关卡的显示
	
13	金币翻转特效
	13.1 给每个硬币加属性，posX坐标x  posY坐标Y，bool flag 正反面标志
	13.2 给MyCoin加函数 changFlag 改变标志
		 1 如果是flag为true改为false，并且开启定时器 1 （正面翻反面）
		 2 如果flag为false，改为true，并且开启定时器 2  (反面翻正面)
		 3 实现定时器中的内容
	13.3 测试 金币翻银币 以及 银币翻金币
    
14	解决开始点击的效果不好
	14.1 在MyCoin中加入了isAnimation判断，是否正在做动画条件
	14.2 当按下MyCoin判断是否在做动画，如果做动画，直接return，保证金币和银币动态切换的完整效果
	
15	翻转周围的金币
	15.1 点击金币后，延时翻转周围金币实现

16	判断胜利
	16.1 PlayScene中，添加 isWin 的标志来判断是否胜利
	16.2 如果胜利了，打印胜利信息
	16.3 将所有按钮屏蔽掉点击
	
17	胜利图片特效
	17.1 将胜利图片放入到游戏场景外
	17.1 当游戏胜利时，移动到屏幕中央，做胜利效果
	
18	添加音乐资源
	18.1 QSound 所属模块 multimedia 需要在Pro文件中加入这个模块
	18.2 在三个场景中添加音效 QSound *s = new QSound("资源")
	18.3 播放 s->play
	18.4 s->setLoop()设置播放次数 -1代表无限循环播放

19	项目的优化
	9.1 将三个场景的切换位置一致

20	项目打包发布 以及游戏扩展玩法简介
```















**如果对你有帮助的话，请不要忘了给我一点点点...........支持 \( ^ o ^)/~**































# Day1

## 7、自定义信号和槽

### 7.1	自定义信号 signal

> 返回void
>
> 需要声明，不需要实现
>
> 可以有参数

### 7.2	自定义槽函数 slot

> 返回 void
>
> 需要声明，也需要实现
>
> 可以有参数，可以重载
>
> 写到public slot下，或者public或者全局函数

### 7.3	触发自定义的信号

> emit	自定义信号

### 7.4	案例：

下课后（发出者），老师饿了（信号），学生响应信号，请客吃饭





## 8	当自定义信号和槽出现重载

1. 需要利用函数指针，明确执行函数的地址

2. void (Teacher:: *tSignal)(QString) = &Teacher::hungry;

3. 去掉string字符串打印出的""  方法：

   - .toUtf8()  --- 转化为数组
   - .data()  --- 转为char *

4. 信号可以连接信息

5. 信号断开使用disconnect

   

main.cpp

```c
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

```



student.h

```c
#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    //早期Qt版本必须要写到public  slots下，高级版本可以写到public或者全局下
    //返回值void，需要声明，也需要实现
    //可以有参数，可以发生重载
    void treat();

    void treat(QString foodName);
signals:

};

#endif // STUDENT_H

```

student.cpp

```c
#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName)
{
    //QString -> char *:先转成 QByteArray (.toUtf8()),再转 char* (.data);
    qDebug()<<"请老师吃饭，老师要吃:"<<foodName.toUtf8().data();
    qDebug()<<foodName;
}

```

teacher.h

```c
#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号 写到signals下
    //返回值是void，只需要声明，不需要实现
    //可以有参数，可以重载
    void hungry();

    void hungry(QString foodName);

};

#endif // TEACHER_H

```

teacher.cpp

```c
#include "teacher.h"

Teacher::Teacher(QObject *parent) : QObject(parent)
{

}

```

widget.h

```c
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"teacher.h"
#include"student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Teacher *zt;
    Student *st;

    void classIsOver();
};
#endif // WIDGET_H

```

widget.cpp

```c
#include "widget.h"
#include "ui_widget.h"
#include<QWidget>
#include"teacher.h"
#include"student.h"

//Teacher类  老师类
//Student类  学生类
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);   //创建对象时利用this将其挂在对象树上

    //创建一个学生对象
    this->st = new Student(this);



//    //老师饿了，让学生请课的连接
//    connect(zt,&Teacher::hungry,st,&Student::treat);

//    //调用下课函数
//     classIsOver();

    //连接带参数的  信号和槽
    //指针 -> 地址
    //函数指针 -> 函数地址
    void (Teacher::*teachersignal)(QString) = &Teacher::hungry;
    void(Student::*studentSlot)(QString) = &Student::treat;
    connect(zt,teachersignal,st,studentSlot);

    classIsOver();

}

void Widget::classIsOver()
{
    //下课函数，调用后触发老师饿了的信号
//    emit zt->hungry();
    emit zt->hungry("小鸡炖蘑菇");
}

Widget::~Widget()
{
    delete ui;
}


```



![](picture\02.png)



## 9	拓展

1. 一个信号可以连接多个槽函数
2. 多个信号可以连接同一个槽函数
3. 信号和槽函数的**参数** 必须 类型一 一对应
4. 信号和槽的参数个数  是不是要一致？信号的参数个数 可以多于槽函数的参数个数



## 10	Qt4 版本写法

1. connect(信号的发送者，发送的信号SIGNAL(信号),信号接受者,槽函数SLOT(槽函数))
   - 优点：参数直观
   - 缺点：编译器不会检测参数类型是否一致

## 11	lambda表达式

1. [] 标识符  匿名函数

   - = 值传递
   - & 引用传递

2. （）参数

3. {} 实现题

4. mutable 修饰传递变量，可以修改拷贝出的数据，改变不了本体

5. 返回值[]()->{}

   

6. ```
   lambda表达式 最常用 [=](){}
   ```

**项目代码如下：**

main.cpp

```c
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

```



student.h

```c
#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    //早期Qt版本必须要写到public  slots下，高级版本可以写到public或者全局下
    //返回值void，需要声明，也需要实现
    //可以有参数，可以发生重载
    void treat();

    void treat(QString foodName);
signals:

};

#endif // STUDENT_H

```

student.cpp

```c
#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName)
{
    //QString -> char *:先转成 QByteArray (.toUtf8()),再转 char* (.data);
    qDebug()<<"请老师吃饭，老师要吃:"<<foodName.toUtf8().data();
    qDebug()<<foodName;
}

```

teacher.h

```c
#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号 写到signals下
    //返回值是void，只需要声明，不需要实现
    //可以有参数，可以重载
    void hungry();

    void hungry(QString foodName);

};

#endif // TEACHER_H

```

teacher.cpp

```c
#include "teacher.h"

Teacher::Teacher(QObject *parent) : QObject(parent)
{

}

```

widget.h

```c
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"teacher.h"
#include"student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Teacher *zt;
    Student *st;

    void classIsOver();
};
#endif // WIDGET_H

```

widget.cpp

```c
#include "widget.h"
#include "ui_widget.h"
#include<QWidget>
#include"teacher.h"
#include"student.h"
#include<QPushButton>
#include<QDebug>

//Teacher类  老师类
//Student类  学生类
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);   //创建对象时利用this将其挂在对象树上

    //创建一个学生对象
    this->st = new Student(this);



//    //老师饿了，让学生请课的连接
//    connect(zt,&Teacher::hungry,st,&Student::treat);

//    //调用下课函数
//     classIsOver();

    //连接带参数的  信号和槽
    //指针 -> 地址
    //函数指针 -> 函数地址
    void (Teacher::*teachersignal)(QString) = &Teacher::hungry;
    void(Student::*studentSlot)(QString) = &Student::treat;
    connect(zt,teachersignal,st,studentSlot);
//    classIsOver();

    //点击一个下课按钮，再触发下课
    QPushButton *btn = new QPushButton("下课",this);

    //重置窗口大小
    this->resize(800,400);
    //点击按钮，触发下课
//    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    //无参信号和槽连接
    void (Teacher::*teachersignal2)(void) = &Teacher::hungry;
//    void(Student::*studentSlot2)(void) = &Student::treat;
//    connect(zt,teachersignal2,st,studentSlot2);

    //信号连接信号
    connect(btn,&QPushButton::clicked,zt,teachersignal2);

    //断开信号
//    disconnect(zt,teachersignal2,st,studentSlot2);

    //拓展
    //1、信号可以连接信号
    //2、一个信号可以连接对个槽函数
    //3、多个信号可以连接到同一个槽函数
    //4、信号和槽函数的参数  必须类型一 一对应
    //5、信号和槽的参数个数 是不是要一致？信号的参数个数 可以多于槽函数的参数个数

    //Qt4版本以前的信号和槽连接方式
    //利用Qt4信号槽 连接无参版本
    //Qt4版本 底层SIGNAL("hungry") SLOT("treat")
    connect(zt,SIGNAL(hungry()),st,SLOT(treat()));
    //Qt4 版本优点：参数直观，缺点，类型不做检测
    //Qt5以上版本支持Qt4的版本写法，反之不支持

//    QPushButton *btn2 = new QPushButton;
//    [btn](){
//        btn->setText("aaaaa");
//        btn2->setText("bbbb");  //只能看到btn，看不到btn2
//    }();

    //mutable关键字 用于修饰值传递的变量，修改的是拷贝，而不是本体
//    QPushButton *myBtn = new QPushButton(this);
//    QPushButton *myBtn2 = new QPushButton(this);
//    myBtn2->move(100,200);
//    int m = 10;
//    connect(myBtn,&QPushButton::clicked,this,[m]()mutable { m = 100+10;qDebug()<<m;});
//    connect(myBtn2,&QPushButton::clicked,this,[=](){qDebug()<<m;});
//    qDebug()<<m;

       //返回什么类型就用指针指向什么类型
//       int ret = []()->int{return 1000;}();
//       qDebug()<<"ret = "<<ret;

       //利用lambda表达式  实现点击按钮关闭窗口
       QPushButton *btn2 = new QPushButton;
       btn2->setText("关闭");
       btn2->move(100,0);
       btn2->setParent(this);

       //使用[=]，不要用[&]以免发生错误
       connect(btn2,&QPushButton::clicked,this,[=](){
//           this->close();
//           emit zt->hungry("小鸡炖蘑菇");
           btn2->setText("aabb");
       });

       //lambda表达式 最常用 [=](){}
}

void Widget::classIsOver()
{
    //下课函数，调用后触发老师饿了的信号
//    emit zt->hungry();
    emit zt->hungry("小鸡炖蘑菇");
}

Widget::~Widget()
{
    delete ui;
}


```







