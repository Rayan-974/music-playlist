#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <string>
using namespace std;

struct Node {
    Node *prev;
    Node *next;
    string SongName;
    string SingerName;
    int SizeOfSong,songID;
    
};

class Playlist {
private:
    Node *start;

public:
    Playlist() : start(NULL) {}
    void createList(string snm, string sn, int sz,int sid);
    void display();
    void del(int n);
    void accending_order();
    void decendingOrder();
    void shuffleList();
    Node* getNodeAt(int index);
    void getInput(int x, int y, char* input, int maxLength);
};

#endif

