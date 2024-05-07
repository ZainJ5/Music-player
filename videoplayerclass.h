#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QString>
#include <fstream>
#include <iostream>

class VideoPlayer
{
private:
    std::string videoname;
    char *vaddress;
    int commentno;
    std::string comment[3];
    int likes;
    int videonumber;
    int counting;
    std::string Restriction;
    std::string views;
    std::string creators[150];
    std::string *videotitles;
    int viewline;

public:
    VideoPlayer();
    ~VideoPlayer();

    void displayvideo();
    std::string VideoName(int videonum);
    std::string playvideo(int age,std::string uvideo);
    void checkcreators(void);
    std::string findVideoThumbnail(std::string targetVideo);
};

#endif // VIDEOPLAYER_H
