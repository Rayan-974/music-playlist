#include "header.h"
#include <conio.h>
#include <graphics.h>
#include <iostream>
using namespace std;

void Playlist::createList(string snm, string sn, int sz, int sid) {
    Node *temp = new Node;
    temp->SongName = snm;
    temp->SingerName = sn;
    temp->SizeOfSong = sz;
    temp->songID = sid;
    temp->next = NULL;

    if (start == NULL) {
        temp->prev = NULL;
        start = temp;
    } else {
        Node *q = start;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = temp;
        temp->prev = q;
    }
}

void Playlist::del(int n) {
    if (start == NULL) {
    	outtextxy(100,150,"Playlist is already empty. Cannot delete.");
//        cout << "\t\t\t\t\tPlaylist is already empty. Cannot delete.\n\n";
        return;
    }

    Node *temp, *q;

    if (start->songID == n) {
        temp = start;
        start = start->next;

        if (start != NULL) {
            start->prev = NULL;
        }

        delete temp;
        outtextxy(100,150,"Song deleted Successfully.");
//        cout << "\n\t\t\t\t\tSong deleted successfully.\n\n";
        return;
    }

    q = start;
    while (q->next != NULL) {
        if (q->next->songID == n) {
            temp = q->next;
            q->next = temp->next;

            if (temp->next != NULL) {
                temp->next->prev = q;
            }

            delete temp;
            outtextxy(100,150,"Song deleted Successfully.");
//            cout << "\n\t\t\t\t\tSong deleted successfully.\n\n";
            return;
        }
        q = q->next;
    }
    outtextxy(70,50,"Song not found.");
//    cout << "\n\t\t\t\t\tSong Not Found.\n";
}
void Playlist::accending_order() {
    if (start == NULL || start->next == NULL) {
        return;
    }

    Node* i = start;
    while (i != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (i->SongName > j->SongName) {
                swap(i->SongName, j->SongName);
                swap(i->SingerName, j->SingerName);
                swap(i->SizeOfSong, j->SizeOfSong);
                swap(i->songID, j->songID);
            }
            j = j->next;
        }
        i = i->next;
    }
}

void Playlist::decendingOrder() {
    if (start == NULL || start->next == NULL) {
		return;
    }

    Node* i = start;
    while (i != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (i->SongName < j->SongName) {
                swap(i->SongName, j->SongName);
                swap(i->SingerName, j->SingerName);
                swap(i->SizeOfSong, j->SizeOfSong);
                swap(i->songID, j->songID);
            }
            j = j->next;
        }
        i = i->next;
    }
}



int customRandom(int max) {
    static unsigned long seed = 1; // Initialize seed with a constant value
    seed = (1103515245 * seed + 12345) & 0x7FFFFFFF; // Generate the next seed using a linear congruential generator
    return static_cast<int>(seed % max); // Return a random number within the range [0, max)
}


Node* Playlist::getNodeAt(int index) {
    Node* current = start;
    int count = 0;
    while (current != NULL && count < index) {
        current = current->next;
        count++;
    }
    return current;
}

void Playlist::shuffleList() {
    if (start == NULL || start->next == NULL) {
        return;
    }

    int count = 0;
    Node* current = start;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    for (int i = 0; i < count * 2; ++i) {
        int randomIndex1 = customRandom(count);
        int randomIndex2 = customRandom(count);

        if (randomIndex1 != randomIndex2) {
            Node* node1 = getNodeAt(randomIndex1);
            Node* node2 = getNodeAt(randomIndex2);

            swap(node1->SongName, node2->SongName);
            swap(node1->SingerName, node2->SingerName);
            swap(node1->SizeOfSong, node2->SizeOfSong);
            swap(node1->songID, node2->songID);
        }
    }
}

void Playlist::getInput(int x, int y, char* input, int maxLength) {
    int index = 0;
    char ch;

    while (true) {
        ch = getch();
        if (ch == 13) {
            input[index] = '\0';
            break;
        } else if (ch == 8 && index > 0) {
            index--;
            input[index] = '\0';
            setcolor(BLACK);
            outtextxy(x, y, "                         ");
            setcolor(WHITE);
            outtextxy(x, y, input);
        } else if (ch >= 32 && ch <= 126 && index < maxLength - 1) {
            input[index++] = ch;
            input[index] = '\0';
            outtextxy(x, y, input);
        }
    }
}

// Display all songs in the playlist
void Playlist::display() {
    int y = 50;
    if (start == NULL) {
        outtextxy(50, y, "Playlist is empty!");
        return;
    }

    Node* q = start;
    while (q != NULL) {
        char details[100];
        sprintf(details, "ID: %d, Name: %s, Singer: %s, Size: %dMB",
                q->songID, q->SongName.c_str(), q->SingerName.c_str(), q->SizeOfSong);
        outtextxy(50, y, details);
        y += 30;
        q = q->next;
    }
    
    
    
}
