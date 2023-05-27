#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Media {
protected:
    string name;
    float price;

public:
    Media(string name = "", float price = 0.0) {
        this->name = name;
        this->price = price;
    }

    virtual void input(ifstream& inFile) {
        getline(inFile >> ws, name);
        inFile >> price;
        inFile.ignore();
    }

    virtual void display(ofstream& outFile) {
        outFile << "Name: " << name << endl;
        outFile << "Price: " << price << endl;
    }

    virtual string getName() {
        return name;
    }

    virtual float getPrice() {
        return price;
    }
};

class Book : public Media {
private:
    int numPages;
    string author;

public:
    Book(string name = "", float price = 0.0, int numPages = 0, string author = "")
        : Media(name, price) {
        this->numPages = numPages;
        this->author = author;
    }

    void input(ifstream& inFile) {
        Media::input(inFile);
        inFile >> numPages;
        inFile.ignore();
        getline(inFile >> ws, author);
    }

    void display(ofstream& outFile) {
        Media::display(outFile);
        outFile << "Number of pages: " << numPages << endl;
        outFile << "Author: " << author << endl;
    }

    bool operator>=(const Book& other) {
        return numPages >= other.numPages;
    }
};

class Video : public Media {
private:
    float runningTime;

public:
    Video(string name = "", float price = 0.0, float runningTime = 0.0)
        : Media(name, price) {
        this->runningTime = runningTime;
    }

    void input(ifstream& inFile) {
        Media::input(inFile);
        inFile >> runningTime;
        inFile.ignore();
    }

    void display(ofstream& outFile) {
        Media::display(outFile);
        outFile << "Running time: " << runningTime << endl;
    }

    bool operator>=(const Video& other) {
        return runningTime >= other.runningTime;
    }
};

void sortMedia(Media** mediaArray, int numMedia) {
    for (int i = 0; i < numMedia - 1; i++) {
        for (int j = i + 1; j < numMedia; j++){
            if (*mediaArray[i] >= *mediaArray[j]) {
                swap(mediaArray[i], mediaArray[j]);
            }
        }
    }
}
void displayMedia(Media** mediaArray, int numMedia, ofstream& outFile) {
    for (int i = 0; i < numMedia; i++) {
        mediaArray[i]->display(outFile);
        outFile << endl;
    }
}

void readMediaData(Media** mediaArray, int numMedia, ifstream& inFile) {
    for (int i = 0; i < numMedia; i++) {
        char type;
        inFile >> type;
        inFile.ignore();
        if (type == 'B') {
            mediaArray[i] = new Book();
        } else if (type == 'V') {
            mediaArray[i] = new Video();
        }

        mediaArray[i]->input(inFile);
    }
}
void writeMediaData(Media** mediaArray, int numMedia, ofstream& outFile) {
    for (int i = 0; i < numMedia; i++) {
        if (dynamic_cast<Book*>(mediaArray[i])) {
            outFile << "B" << endl;
        } else if (dynamic_cast<Video*>(mediaArray[i])) {
            outFile << "V" << endl;
        }   
        mediaArray[i]->display(outFile);
    }
}
int main() {
int numBooks, numVideos;
// Đọc số lượng sách và video từ tệp văn bản
ifstream inFile("input.txt");
if (inFile.is_open()) {
    inFile >> numBooks;
    inFile >> numVideos;
    inFile.ignore();
} else {
    cout << "Unable to open file for reading!" << endl;
    return 1;
}

// Tạo mảng con trỏ đối tượng Media
Media** mediaArray = new Media*[numBooks + numVideos];

// Đọc dữ liệu từ tệp văn bản
readMediaData(mediaArray, numBooks + numVideos, inFile);
inFile.close();

// Mở tệp văn bản để ghi kết quả
ofstream outFile("output.txt");
if (outFile.is_open()) {
    // Hiển thị thông tin sách và video
    outFile << "Information for books:" << endl;
    displayMedia(mediaArray, numBooks, outFile);
    outFile << endl;

    outFile << "Information for videos:" << endl;
    displayMedia(mediaArray + numBooks, numVideos, outFile);
    outFile << endl;

    // Sắp xếp sách và video theo tiêu chí tương ứng
    sortMedia(mediaArray, numBooks + numVideos);

    outFile << "Sorted information for books:" << endl;
    displayMedia(mediaArray, numBooks, outFile);
    outFile << endl;

    outFile << "Sorted information for videos:" << endl;
    displayMedia(mediaArray + numBooks, numVideos, outFile);
    outFile << endl;

    outFile.close();
} else {
    cout << "Unable to open file for writing!" << endl;
    return 1;
}

// Giải phóng bộ nhớ
for (int i = 0; i < numBooks + numVideos; i++) {
    delete mediaArray[i];
}
delete[] mediaArray;

return 0;
}