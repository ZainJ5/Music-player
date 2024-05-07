#ifndef UPLOADVIDEO_H
#define UPLOADVIDEO_H

#include <iostream>
#include <fstream>

class UploadVideo {
private:
    std::string videotitle;
    std::string videolink;
    std::string description;
    std::string agerestriction;
    int revenue;
    std::string creatorname;
    std::string category;
    int likes;
    int views;
    int comments;

public:
    UploadVideo();
    UploadVideo(std::string name);
    std::string uploadvideo(std::string name,std::string vt,std::string des,std::string vl,std::string cate,std::string restriction);
    void performance(std::string name);
    std::string specificcreator();
    void likevideo(std::string cvideo,bool check);
};

#endif // UPLOADVIDEO_H
