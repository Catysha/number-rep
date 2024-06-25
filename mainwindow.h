#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void calculatePower();
    void clearResult();
private:
    Ui::MainWindow *ui;
    QLineEdit *numberInput;
    QPushButton *calculateButton;
    QLabel *resultLabel;
};
#endif // MAINWINDOW_H

