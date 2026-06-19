#include "header.h"
#include <iostream>
#include <graphics.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Playlist playlist;
    int choice;
    char input[30];

    while (true) {
        cleardevice();

        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        setcolor(GREEN);
        outtextxy(70, 70, "Press 1 to Add Song");
        outtextxy(70, 100, "Press 2 to Delete Song");
        outtextxy(70, 130, "Press 3 to Display Playlist");
        outtextxy(70, 160, "Press 4 to Shuffle In Ascending Order");
        outtextxy(70, 190, "Press 5 to Shuffle In Descending Order");
        outtextxy(70, 220, "Press 6 to Shuffle In Random Order");
        outtextxy(70, 250, "Press 7 to Exit");

        outtextxy(70, 280, "Enter your choice: ");
        playlist.getInput(250, 280, input, 5);
        choice = atoi(input);

        cleardevice();

        switch (choice) {
            case 1:
                
                char name[30], singer[30];
                int size, id;

                outtextxy(70, 100, "Enter Song Name: ");
                playlist.getInput(250, 100, name, 30);

                outtextxy(70, 130, "Enter Singer Name: ");
                playlist.getInput(250, 130, singer, 30);

                outtextxy(70, 160, "Enter Song Size (MB): ");
                playlist.getInput(250, 160, input, 5);
                size = atoi(input);

                outtextxy(70, 190, "Enter Song ID: ");
                playlist.getInput(250, 190, input, 5);
                id = atoi(input);

                playlist.createList(name, singer, size, id);
                outtextxy(100, 220, "Song added successfully!");
                delay(1500);
                break;
            
            case 2:
            {
                outtextxy(70, 100, "Enter Song ID to delete: ");
                playlist.getInput(280, 100, input, 5);
                int id = atoi(input);
                playlist.del(id);
                delay(1500);
                break;
            }
            case 3:                
                playlist.display();
                delay(2000);
                break;
            
            case 4:
                playlist.accending_order();

                setcolor(LIGHTGREEN);
                outtextxy(100, 200, "Playlist shuffled in ascending order!");
                delay(1500);
                cleardevice();
                break;
            
            case 5:
                playlist.decendingOrder();
                setcolor(LIGHTGREEN);
                outtextxy(100, 200, "Playlist shuffled in descending order!");
                delay(1500);
                cleardevice();
                break;
            
            case 6:
                playlist.shuffleList();
                setcolor(LIGHTMAGENTA);
                outtextxy(100, 200, "Playlist shuffled in random order!");
                delay(1500);
                cleardevice();
                break;
            
            case 7:
                setcolor(RED);
                outtextxy(100, 200, "Exiting... Thank you for using!");
                delay(2000);
                closegraph();
                return 0;
            
            default:
                setcolor(RED);
                outtextxy(100, 200, "Invalid choice! Try again.");
                delay(1500);
                cleardevice();
                break;
            
        }
    }
}

