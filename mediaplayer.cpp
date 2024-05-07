#include "mediaplayer.h"
#include "ui_mediaplayer.h"

MediaPlayer::MediaPlayer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MediaPlayer)
{
    ui->setupUi(this);
}

MediaPlayer::~MediaPlayer()
{
    delete ui;
}
