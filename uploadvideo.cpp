#include "uploadvideo.h"
#include "qdebug.h"
#include "qlogging.h"
#include <globalvariable.h>
#include <iostream>
#include <fstream>
using namespace std;

UploadVideo::UploadVideo() {}

UploadVideo::UploadVideo(std::string name) {
    likes = 0;
    comments = 0;
    creatorname = name;
    views = 0;
}

string UploadVideo::uploadvideo(string name,string vt,string des,string vl,string cate,string restriction) {
    // int choice;
    // int choice12;

    creatorname = name;
    videotitle = vt;
    description = des;
    videolink = vl;
    category = cate;
    agerestriction = restriction;
    views = 0;
    likes = 0;

    std::fstream uploaddata("D:\\C++\\" + category + ".txt", std::ios::app);
    if (uploaddata.is_open()) {
        uploaddata << creatorname << std::endl;
        uploaddata << "&";
        uploaddata << videotitle << std::endl;
        uploaddata << description << std::endl;
        uploaddata << videolink << std::endl;
        uploaddata << agerestriction << std::endl;
        uploaddata << views << std::endl;
        uploaddata << likes << std::endl;
        return "Video Successfully uploaded!!";
    } else {
        return "Error!! Video unable to upload";
    }
}

void UploadVideo::performance(std::string name) {
    string uservideos[150];
    ifstream  entertainment("D:\\C++\\Entertainment.txt");
    ifstream  education("D:\\C++\\Education.txt");
    ifstream  gaming("D:\\C++\\Gaming.txt");
    ifstream  news("D:\\C++\\News and Politics.txt");
    string line;
    bool check=false;
    int linenum=0;
    int count=0;
    while (getline(entertainment, line))
    {
        linenum++;
        if (line==name)
        {
            check=true;
            break;
        }
    }
    entertainment.clear();
    entertainment.seekg(0,ios::beg);
    int index=0;
    if (check)
    {
        while (getline(entertainment,line))
        {
            index++;
            if ((index==linenum+1)&&(line.substr(0,1)=="&"))
            {
                string videotitle=line.substr(1);
                uservideos[count]=videotitle;
                // cout<<count+1<<".) "<<videotitle<<endl;
                count++;
            }
        }
    }
    check=false;
    linenum=0;
    while (getline(education, line))
    {
        linenum++;
        if (line==name)
        {
            check=true;
            break;
        }
    }
    education.clear();
    education.seekg(0,ios::beg);
    index=0;
    if (check)
    {
        while (getline(education,line))
        {
            index++;
            if ((index==linenum+1)&&(line.substr(0,1)=="&"))
            {
                string videotitle=line.substr(1);
                uservideos[count]=videotitle;
                // cout<<count+1<<".) "<<videotitle<<endl;
                count++;
            }
        }
    }
    check=false;
    linenum=0;
    while (getline(gaming, line))
    {
        linenum++;
        if (line==name)
        {
            check=true;
            break;
        }
    }
    gaming.clear();
    gaming.seekg(0,ios::beg);
    index=0;
    if (check)
    {
        while (getline(gaming,line))
        {
            index++;
            if ((index==linenum+1)&&(line.substr(0,1)=="&"))
            {
                string videotitle=line.substr(1);
                uservideos[count]=videotitle;
                // cout<<count+1<<".) "<<videotitle<<endl;
                count++;
            }
        }
    }
    check=false;
    linenum=0;
    while (getline(entertainment, line))
    {
        linenum++;
        if (line==name)
        {
            check=true;
            break;
        }
    }
    news.clear();
    news.seekg(0,ios::beg);
    index=0;
    if (check)
    {
        while (getline (news,line))
        {
            index++;
            if ((index==linenum+1)&&(line.substr(0,1)=="&"))
            {
                string videotitle=line.substr(1);
                uservideos[count]=videotitle;
                // cout<<count+1<<".) "<<videotitle<<endl;
                count++;
            }
        }
    }
    entertainment.close();
    education.close();
    news.close();
    gaming.close();
    // cout<<count<<endl;
    cvideosize = count;
    CreatersVideo = new string [count];
    for (int i = 0; i < count; i++) {
        CreatersVideo[i] = uservideos[i];
    }
    // int num;
    // cout<<"Enter the video : ";
    // cin>>num;
    // string video=uservideos[num-1];
    // return video;
}

std::string UploadVideo::specificcreator() {
    int i;
    std::cout << "Enter video title : ";
    std::cin >> i;
    std::string name;
    name = videotitle[i - 1];
    return name;
}









void UploadVideo::likevideo(string cvideo,bool check){

    // qDebug()<< "Function Executed";
    // qDebug()<<cvideo;
    ifstream  entertainment("D:\\C++\\Entertainment.txt");
    ifstream  education("D:\\C++\\Education.txt");
    ifstream  gaming("D:\\C++\\Gaming.txt");
    ifstream  news("D:\\C++\\News and Politics.txt");
    bool found = false;
    string type;
    int line_number = 0;
    string search,name;
    name="&"+cvideo;
    while (getline(education, search)) {
        line_number++;
        if (search == name) {
            found = true;
            type = "Education";
            break;
        }
    }

    if (!found) {
        line_number = 0;
        while (getline(entertainment, search)) {
            line_number++;
            if (search == name) {
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
            if (search == name) {
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
            if (search == name) {
                found = true;
                type = "News and Politics";
                break;
            }
        }
    }
    int index=0;
    string likes,file,views;
    if (type == "Education")
    {
        gaming.close();
        news.close();
        entertainment.close();
        education.clear();
        education.seekg(0, ios::beg);
        while (getline(education , file))
        {
            if (index == line_number + 3)
            {
                views = file;
            }
            if (index == line_number + 4)
            {
                likes = file;
            }
            index++;
        }
        if (!check)
        {
            double revenue=stoi(views);
            revenue*=0.01;
            createrviews = views;
            createrlikes=likes;
            createrrevenue = revenue;
        }
        if (check)
        {
            // cout<<endl<<"Like Added!!"<<endl;
            education.clear();
            education.seekg(0, ios::beg);
            int likecount=stoi(likes);
            likecount = likecount+1;
            // cout<<"Previous : "<<likes<<" Likes"<<endl;
            // cout<<"After    : "<<likecount<<" Likes"<<endl;
            // cout<<endl;
            string data;
            ofstream tempfile("D:\\C++\\tempfile.txt");
            int count = 0;
            while (getline(education,data)){
                if (count==line_number+4)
                {
                    tempfile<<likecount<<endl;
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
            if (index == line_number + 3)
            {
                views = file;
            }
            if (index == line_number + 4)
            {
                likes = file;
            }
            index++;
        }
        if (!check)
        {
            double revenue=stoi(views);
            revenue*=0.01;
            createrviews = views;
            createrlikes=likes;
            createrrevenue = revenue;
        }
        if (check)
        {
            // cout<<endl<<"Like Added!!"<<endl;
            gaming.clear();
            gaming.seekg(0, ios::beg);
            int likecount=stoi(likes);
            likecount = likecount+1;
            // cout<<"Previous : "<<likes<<" Likes"<<endl;
            // cout<<"After    : "<<likecount<<" Likes"<<endl;
            // cout<<endl;
            string data;
            ofstream tempfile("D:\\C++\\tempfile.txt");
            int count = 0;
            while (getline(gaming,data)){
                if (count==line_number+4)
                {
                    tempfile<<likecount<<endl;
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
            if (index == line_number + 3)
            {
                views = file;
            }
            if (index == line_number + 4)
            {
                likes = file;
            }
            index++;
        }
        // cout<<"Video found in entertainment file with likes : "<<likes<<endl;
        if (!check)
        {
            double revenue=stoi(views);
            revenue*=0.01;
            createrviews = views;
            createrlikes=likes;
            createrrevenue = revenue;
            // qDebug()<<"Variables not getting values";
        }
        if (check)
        {
            qDebug("Wrong Check Statement");
            cout<<endl<<"Like Added!!"<<endl;
            entertainment.clear();
            entertainment.seekg(0, ios::beg);
            int likecount=stoi(likes);
            likecount=likecount+1;
            // cout<<"Previous : "<<likes<<" Likes"<<endl;
            // cout<<"After    : "<<likecount<<" Likes"<<endl;
            // cout<<endl;
            string data;
            ofstream tempfile("D:\\C++\\tempfile.txt");
            int count = 0;
            while (getline(entertainment,data)){
                if (count==line_number+4)
                {
                    tempfile<<likecount<<endl;
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
            if (index == line_number + 3)
            {
                views = file;
            }
            if (index == line_number + 4)
            {
                likes = file;
            }
            index++;
        }
        if (!check)
        {
            double revenue=stoi(views);
            revenue*=0.01;
            createrviews = views;
            createrlikes=likes;
            createrrevenue = revenue;
        }
        if (check)
        {
            // cout<<endl<<"Like Added!!"<<endl;
            news.clear();
            news.seekg(0, ios::beg);
            int likecount=stoi(likes);
            likecount = likecount+1;
            // cout<<"Previous : "<<likes<<" Likes"<<endl;
            // cout<<"After    : "<<likecount<<" Likes"<<endl;
            // cout<<endl;
            string data;
            ofstream tempfile("D:\\C++\\tempfile.txt");
            int count = 0;
            while (getline(news,data)){
                if (count==line_number+4)
                {
                    tempfile<<likecount<<endl;
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
    }
    // qDebug()<<"Video Not Found";
}
