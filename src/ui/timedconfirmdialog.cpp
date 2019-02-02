#include <QTimer>
#include "core/logging.h"
#include "timedconfirmdialog.h"
#include "ui_timedconfirmdialog.h"


TimedConfirmDialog::TimedConfirmDialog(QWidget *parent, int timeout) :
    QDialog(parent),
    ui(new Ui::TimedConfirmDialog),
    timeout_(timeout) {
    ui->setupUi(this);
    update();
    timer_ = new QTimer(this);
    connect(timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_->start(1000);
}

TimedConfirmDialog::~TimedConfirmDialog() {
    delete ui;
    delete timer_;
}

void TimedConfirmDialog::update() {
    if (timeout_ >= 0) {
        ui->timeoutLabel->setText(QString::number(timeout_));
    } else {
        timer_->stop();
        qLog(Debug) << "Emit signal finished...";
        emit finished();
        close();
    }
    timeout_--;
}
