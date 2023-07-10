#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public TableModel
{
    Q_OBJECT

public:
    MainWindow(int argc, char *argv[],QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *_ui() const;

private slots:
    void on_add_pb_clicked();

    void on_delete_pb_clicked();

private:
    Ui::MainWindow *ui;
    void initWidgits();
    void readCSV(int, char**);
    TableModel *tableModel;

};
#endif // MAINWINDOW_H
