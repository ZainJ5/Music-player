#include "videoplayerclass.h"
#include "videoplayer.h"
#include <globalvariable.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

VideoPlayer::VideoPlayer()
{
    vaddress = nullptr;
    videotitles = nullptr;
}

VideoPlayer::~VideoPlayer()
{
    delete[] vaddress;
    delete[] videotitles;
}

void VideoPlayer::displayvideo()
{
    string *temparray = new string [1500];
    ifstream  entertainment("D:\\C++\\Entertainment.txt");
    ifstream  education("D:\\C++\\Education.txt");
    ifstream  gaming("D:\\C++\\Gaming.txt");
    ifstream  news("D:\\C++\\News and Politics.txt");
    string video,videotitle;
    int i=0;
    while (getline(entertainment, video)) {
        if (video.substr(0, 1) == "&") {
            videotitle=video.substr(1);
            temparray[i]=videotitle;
            i++;
        }
    }
    while (getline(education, video)) {
        if (video.substr(0, 1) == "&") {
            videotitle=video.substr(1);
            temparray[i]=videotitle;
            i++;
        }
    }
    while (getline(gaming, video)) {
        if (video.substr(0, 1) == "&") {
            videotitle=video.substr(1);
            temparray[i]=videotitle;
            i++;
        }
    }
    while (getline(news, video)) {
        if (video.substr(0, 1) == "&") {
            videotitle=video.substr(1);
            temparray[i]=videotitle;
            i++;
        }
    }
    totalvideos = i;
    videonamesarray = new string [totalvideos];
    for (int i = 0; i < totalvideos; i++)
    {
        videonamesarray[i] = temparray[i];
    }
    delete []temparray;
}


string VideoPlayer::VideoName(int videonum)
{
    string videoname;
    int watch = videonum;

    if (watch >= 1 && watch <= totalvideos)
    {
        videoname = videonamesarray[watch - 1];
        return videoname;
    }
    return "";
}


string VideoPlayer::playvideo(int age,string uvideo) {
    ifstream  entertainment("D:\\C++\\Entertainment.txt");
    ifstream  education("D:\\C++\\Education.txt");
    ifstream  gaming("D:\\C++\\Gaming.txt");
    ifstream  news("D:\\C++\\News and Politics.txt");
    string cvideo="&"+uvideo;
    string type;
    bool found = false;
    int line_number = 0;
    string search;

    while (getline(education, search)) {
        line_number++;
        if (search == cvideo) {
            found = true;
            type = "Education";
            break;
        }
    }

    if (!found) {
        line_number = 0;
        while (getline(entertainment, search)) {
            line_number++;
            if (search == cvideo) {
                found = true;
                type = "Entertainment";
                break;
            }
        }
    }

    if (!found) {
        line_number = 0;
        while (getline(gaming, search)) {
            line_number++;
            if (search == cvideo) {
                found = true;
                type = "Gaming";
                break;
            }
        }
    }

    if (!found) {
        line_number = 0;
        while (getline(news, search)) {
            line_number++;
            if (search == cvideo) {
                found = true;
                type = "News and Politics";
                break;
            }
        }
    }
    // cout << "Video found in " << type << " category at line " << line_number << endl;
    const char *videolink;
    int index = 0;
    string file;
    string link;
    if (type == "Education")
    {
        gaming.close();
        news.close();
        entertainment.close();
        education.clear();
        education.seekg(0, ios::beg);
        while (getline(education, file))
        {
            if (index == line_number + 1)
            {
                link = file;
            }
             if (index == line_number + 2)
            {
                Restriction = file;
            }
            if (index == line_number + 3)
            {
                views = file;
            }
            index++;
        }
        education.clear();
        education.seekg(0, ios::beg);
        int viewcount=stoi(views);
        viewcount=viewcount+1;
        string data;
        ofstream tempfile("D:\\C++\\tempfile.txt");
        int count = 0;
        while (getline(education,data)){
            if (count==line_number+3)
            {
                tempfile<<viewcount<<endl;
            }
            else{
             tempfile<<data<<endl;
            }
            count++;
        }
        tempfile.close();
        education.close();
        remove("D:\\C++\\Education.txt");
        rename("D:\\C++\\tempfile.txt","D:\\C++\\Education.txt");
    }
    else if (type == "Gaming")
    {
        entertainment.close();
        education.close();
        news.close();
        gaming.clear();
        gaming.seekg(0, ios::beg);
        while (getline(gaming, file))
        {
            if (index == line_number + 1)
            {
                link = file;
            }
              if (index == line_number + 2)
            {
                Restriction = file;
            }
             if (index == line_number + 3)
            {
                views = file;
            }
            index++;
        }
        gaming.clear();
        gaming.seekg(0, ios::beg);
        int viewcount=stoi(views);
        viewcount=viewcount+1;
        string data;
        ofstream tempfile("D:\\C++\\tempfile.txt");
        int count = 0;
        while (getline(gaming,data)){
            if (count==line_number+3)
            {
                tempfile<<viewcount<<endl;
            }
            else{
             tempfile<<data<<endl;
            }
            count++;
        }
        tempfile.close();
        gaming.close();
        remove("D:\\C++\\Gaming.txt");
        rename("D:\\C++\\tempfile.txt","D:\\C++\\Gaming.txt");
    }
    else if (type == "Entertainment")
    {
        education.close();
        gaming.close();
        news.close();
        entertainment.clear();
        entertainment.seekg(0, ios::beg);
        while (getline(entertainment, file))
        {
            if (index == line_number + 1)
            {
                link = file;
            }
              if (index == line_number + 2)
            {
                Restriction = file;
            }
             if (index == line_number + 3)
            {
                views = file;
            }
            index++;
        }
        entertainment.clear();
        entertainment.seekg(0, ios::beg);
        int viewcount=stoi(views);
        viewcount=viewcount+1;
        string data;
        ofstream tempfile("D:\\C++\\tempfile.txt");
        int count = 0;
        while (getline(entertainment,data)){
            if (count==line_number+3)
            {
                tempfile<<viewcount<<endl;
            }
            else{
             tempfile<<data<<endl;
            }
            count++;
        }
        tempfile.close();
        entertainment.close();
        remove("D:\\C++\\Entertainment.txt");
        rename("D:\\C++\\tempfile.txt","D:\\C++\\Entertainment.txt");
    }
    else if (type == "News and Politics")
    {
        entertainment.close();
        education.close();
        gaming.close();
        news.clear();
        news.seekg(0, ios::beg);
        while (getline(news, file))
        {
            if (index == line_number + 1)
            {
                link = file;
            }
              if (index == line_number + 2)
            {
                Restriction = file;
            }
             if (index == line_number + 3)
            {
                views = file;
            }
            index++;
        }
        news.clear();
        news.seekg(0, ios::beg);
        int viewcount=stoi(views);
        viewcount=viewcount+1;
        string data;
        ofstream tempfile("D:\\C++\\tempfile.txt");
        int count = 0;
        while (getline(news,data)){
            if (count==line_number+3)
            {
                tempfile<<viewcount<<endl;
            }
            else{
             tempfile<<data<<endl;
            }
            count++;
        }
        tempfile.close();
        news.close();
        remove("D:\\C++\\News and Politics.txt");
        rename("D:\\C++\\tempfile.txt","D:\\C++\\News and Politics.txt");
    }

    // cout<<Restriction<<endl<<views<<endl<<link<<endl<<age<<endl;
    if (Restriction == "Restricted")
    {
      if (age>=18)
      {
        videolink=link.c_str();
          return videolink;
      }
      else
        return "Restricted content !!";
    }
    else if(Restriction=="Not Restricted"){
        videolink=link.c_str();
        return videolink;
    }
    return "";
}
void VideoPlayer::checkcreators() {
    ifstream creatordata("D:\\C++\\Creator's Data.txt");
    if (!creatordata) {
        cerr << "Error opening file." << endl;
        return;
    }

    string cname;
    int line_number = 0;
    int currentline = 0;
    int i = 0;

    cout << "\tAll Creator's List" << endl;

    while (getline(creatordata, cname)) {
        if (currentline == line_number) {
            cout << i + 1 << ".) " << cname << endl;
            creators[i] = cname;
            line_number += 6;
            i++;
        }
        currentline++;
    }

    casize = i;
    Allcreaters = new string[i];

    for (int j = 0; j < i; j++) {
        Allcreaters[j] = creators[j];
    }

    cout << endl;

}


std::string VideoPlayer::findVideoThumbnail(std::string targetVideo) {
    std::ifstream file("D:\\C++\\Video Thumbnails.txt");
    std::string line;
    bool found = false;
    while (getline(file, line)) {
        if (line == targetVideo) {
            if (getline(file, line)) {
                found = true;
                break;
            }
        }
    }
    file.close();
    if (found) {
        return line;
    } else {
        return "Video not found!";
    }
}
