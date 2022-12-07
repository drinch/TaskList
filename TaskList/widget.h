#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "task.h"
#include "taskbox.h"
#include <QMap>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void loadTaskFromFile(QString path);
    void saveTaskToFile(QString path);
    void updateTaskBoxList();
    void loadTaskToEditPage(Task* task);
    void addTask();
private:
    Ui::Widget *ui;
    QMap<Task*,double> tasklist;
    QList<TaskBox*> taskboxlist;
    QString savepath;
};
#endif // WIDGET_H
