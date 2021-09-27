#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    // declaring function for gender selection

    void gender_selection();
    void action_reset();
    void BMI_interpretation();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
