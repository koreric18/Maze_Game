/*
 * MAZE Game Framework
 * Written by Dr. Dhanyu Amarasinghe Spring 2018
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <CommonThings.h>
#include<string.h>
#include<gl/gl.h>
#include<GL/glut.h>
#include<SOIL.h>
#include<iostream>
#include <Timer.h>
#include <math.h>       /* ceil */


using namespace std;

class Player
{
    public:
        Player();                          // Constructor
        virtual ~Player();                 // Deconstructor

        void drawplayer();                 // Draw Player image
        void drawArrow();                  // Draw Arrow
        void shootArrow();                 // Shoot arrow movement

        void initPlayer(int,int,char *);    // initialize the player with grid size, image, frames
        void placePlayer(int,int);          // place the player
        void movePlayer(int);               // move Player left,right,up,down
        void loadArrowImage(char *);        // set an image for the Arrow

        GridLoc getPlayerLoc();             // player current location
        GridLoc getArrowLoc();              // arrow current location

        int frames;                         // Number of frames for animation
        int playerDir;                      // direction of player face 0: UP, 1: DOWN, 2: LEFT, 3: RIGHT

        bool arrowStatus;                   // arrow is active or not
        bool livePlayer;                    // Player live or dead
        loc     plyLoc;                      // viewport location of the player
    protected:

        float   t;                            // Ticker for animation
        void    timer();                       // Timer for animation
        int     gridSize;                       // Grid Size
        float   unitWidth;                    // Unit width of the grid

    private:

    private:
        float   xmax, xmin,ymax,ymin;        // animation texture map
        GLuint  plyTex;                      // player image handler
        GLuint  arrowTex;                    // arrow image handler
        int     arrXdir;                     // arrow direction x;
        int     arrYdir;                     // arrow direction y
        float   arrAngle;                    // animation direction of the arrow
        loc     arrowLoc;                    // viewport location of the arrow
        loc     converter(int, int);         // convert Grid location to viewport
        int     stepsPerMove;                // animation steps
        bool    isPassingBorder;             // enemy is passing between two cells
        loc     targCellLoc;                 // target cell location
};

#endif // PLAYER_H
