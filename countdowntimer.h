#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QSound>

namespace Ui {
class CountdownTimer;
}

class CountdownTimer : public QMainWindow
{
    Q_OBJECT

public:
    QTime *displayTime = new QTime;
    QTimer *timer = new QTimer;
    QSound alarm = ("F:\\Actual Documents\\Tomson's Scripts\\Countdown Timer\\Alarm.wav");
    bool buttonStart = true;

public:
    explicit CountdownTimer(QWidget *parent = 0);
    ~CountdownTimer();

protected slots:
    void updateTime();

private slots:
    void on_startButton_clicked();

private:
    Ui::CountdownTimer *ui;
};

#endif // COUNTDOWNTIMER_H
