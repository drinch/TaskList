#include "widget.h"
#include "ui_widget.h"
#include "task.h"
#include "taskbox.h"
#include <QDate>
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Task List");
    this->resize(810,490);
    ui->addtaskbutton->resize(150,150);
    this->savepath=QDir::currentPath()+"/taskdata.txt";
    ui->stackedwidget->setCurrentIndex(0);
    this->loadTaskFromFile(this->savepath);
    this->updateTaskBoxList();
    connect(ui->addtaskbutton,&QPushButton::clicked,[=](){
        Task* task_=new Task();
        this->tasklist.insert(task_,0);
        this->loadTaskToEditPage(task_);
        ui->stackedwidget->setCurrentIndex(1);
    });
    connect(ui->taskPage,&TaskPage::back,[=](){
        ui->taskPage->saveTask();
        this->updateTaskBoxList();
        ui->stackedwidget->setCurrentIndex(0);
    });
}
Widget::~Widget()
{
    this->saveTaskToFile(this->savepath);
    delete ui;
}
void Widget::loadTaskFromFile(QString path){
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QString loadtaskstring=QString::fromUtf8(file.readAll());
    int st=0;
    for(int i=st;i<loadtaskstring.length();i++){
        if(loadtaskstring[i]=='\n'){
            Task* task=new Task();
            task->loadTask(loadtaskstring.mid(st,i-st));
            this->tasklist.insert(task,0);
            st=i+1;
        }
    }
    file.close();
}
void Widget::saveTaskToFile(QString path){
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QString savetaskstring;
    QMap<Task*,double>::const_iterator it=this->tasklist.begin();
    while(it!=tasklist.end()){
        Task* task=it.key();
        savetaskstring+=task->saveTask()+"\n";
        ++it;
    }
    file.write(savetaskstring.toUtf8());
    file.close();
}
void Widget::updateTaskBoxList(){
    for(int i=0;i<taskboxlist.size();i++){
        delete taskboxlist[i];
    }
    this->taskboxlist.clear();
    int num=this->tasklist.size();
    if(num>14) num=14;
    ui->addtaskbutton->move(((num)%5+1)*160-150,((num)/5+1)*160-150);
    QMap<Task*,double>::const_iterator it=this->tasklist.begin();
    for(int i=0;i<num;i++){
        taskboxlist.push_back(new TaskBox(ui->taskListPage,it.key()));
        taskboxlist[i]->move((i%5+1)*160-150,(i/5+1)*160-150);
        taskboxlist[i]->show();
        connect(taskboxlist[i],&TaskBox::edit,[=](){
            Task* task_=taskboxlist[i]->getTask();
            this->loadTaskToEditPage(task_);
            ui->stackedwidget->setCurrentIndex(1);
        });
        connect(taskboxlist[i],&TaskBox::finished,[=](){
            Task* task_=taskboxlist[i]->getTask();
            tasklist.take(task_);
            this->updateTaskBoxList();
        });
        it++;
    }
}
void Widget::loadTaskToEditPage(Task* task){
    ui->taskPage->loadTask(task);
}
void Widget::addTask(){
//    this->tasklist.insert(getNewTaskInfo(),0);
    this->updateTaskBoxList();
    ui->stackedwidget->setCurrentIndex(0);
}

