#ifndef TASKPAGE_H
#define TASKPAGE_H

#include <QWidget>
#include "task.h"

namespace Ui {
class TaskPage;
}

class TaskPage : public QWidget
{
    Q_OBJECT
public:
    explicit TaskPage(QWidget *parent = nullptr,Task *task_=nullptr);
    ~TaskPage();
    void saveTask();
    void loadTask(Task *task_);
private:
    Ui::TaskPage *ui;
    Task *task;
signals:
    void back();
};

#endif // TASKPAGE_H
