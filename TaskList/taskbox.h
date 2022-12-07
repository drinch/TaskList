#ifndef TASKBOX_H
#define TASKBOX_H

#include <QWidget>
#include "task.h"
#include <QMouseEvent>
#include <QSize>

namespace Ui {
class TaskBox;
}

class TaskBox : public QWidget
{
    Q_OBJECT
public:
    explicit TaskBox(QWidget * parent = nullptr,Task* task_=new Task());
    ~TaskBox();
    void setTask(Task* task_);
    Task* getTask();
    void updateTask();
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void setSize(int w,int h);
    void setSize(int l);
    void setSpacing(int s);
    int getSpacing();
    void updateSpacing();
private:
    Ui::TaskBox *ui;
    Task* task;
    int spacing;
signals:
    void edit();
    void finished();
};

#endif // TASKBOX_H
