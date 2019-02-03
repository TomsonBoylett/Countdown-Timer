#include "countdowntimer.h"
#include "ui_countdowntimer.h"

CountdownTimer::CountdownTimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CountdownTimer)
{
    ui->setupUi(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->setSingleShot(true);
}

CountdownTimer::~CountdownTimer()
{
    delete ui;
}

void CountdownTimer::on_startButton_clicked()
{
    if(buttonStart == true)
    {
        buttonStart = false;
        ui->startButton->setText("Stop");
        ui->timeEdit->setEnabled(false);
        *displayTime = ui->timeEdit->time();
        ui->timerLabel->setText(displayTime->toString("hh:mm:ss"));
        timer->start(1000);
    }
    else
    {
        buttonStart = true;
        ui->startButton->setText("Start");
        ui->timeEdit->setEnabled(true);
        ui->timeEdit->setTime(*displayTime);
        timer->stop();
    }
}

void CountdownTimer::updateTime()
{
    QTime newTime = displayTime->addSecs(-1);
    displayTime->setHMS(newTime.hour(),newTime.minute(),newTime.second());
    ui->timerLabel->setText(displayTime->toString("hh:mm:ss"));
    if(displayTime->hour() != 0 ||
            displayTime->minute() != 0 ||
            displayTime->second() != 0)
    {
        timer->start(1000);
    }
    else
    {
        alarm.play();
        buttonStart = true;
        ui->startButton->setText("Start");
        timer->stop();
    }
}
