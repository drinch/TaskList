#include "taskbox.h"
#include "ui_taskbox.h"
#include <QSize>
#include <QPushButton>
#include <QLayout>

TaskBox::TaskBox(QWidget * parent,Task task_):
    QWidget(parent),
    ui(new Ui::TaskBox),
    task(task_)
{
    ui->setupUi(this);
    this->setSize(150,150);
    this->updateTask();
}
TaskBox::~TaskBox(){
    delete ui;
}
void TaskBox::setTask(Task& task_){
    this->task=task_;
    this->updateTask();
}
Task& TaskBox::getTask(){
    return this->task;
}
void TaskBox::updateTask(){
    ui->titlelabel->setText(this->task.getTitle());
    ui->infolabel->setText(this->task.getInfo());
    ui->datelabel->setText(this->task.dateText());
}
void TaskBox::mouseDoubleClickEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton)emit this->edit();
}
void TaskBox::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::RightButton)emit this->finished();
}
void TaskBox::setSize(int w,int h){
    this->setMinimumSize(QSize(w,h));
    this->setMaximumSize(QSize(w,h));
    this->resize(w,h);
    updateSpacing();
}
void TaskBox::setSize(int l){
    this->setSize(l,l);
}
void TaskBox::setSpacing(int s){
    this->spacing=s;
    this->setContentsMargins(this->spacing,this->spacing,this->spacing,this->spacing);
    ui->verticalLayout->setSpacing(this->spacing);
}
int TaskBox::getSpacing(){
    return this->spacing;
}
void TaskBox::updateSpacing(){
    ui->titlelabel->resize(this->width()-2*this->spacing,this->height()/5);
    ui->datelabel->resize(this->width()-2*this->spacing,this->height()/5);
    ui->infolabel->resize(this->width()-2*this->spacing,this->height()-4*this->spacing-ui->titlelabel->height()-ui->datelabel->height());
}
