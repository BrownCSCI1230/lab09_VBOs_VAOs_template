#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glrenderer.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    void finish();

private:
    GLRenderer *glRenderer;
};
#endif // MAINWINDOW_H
