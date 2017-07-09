/* ----------------------------------------------------------------------------
 *   Pipes  by  Simon Holmes, 2017 
 * ---------------------------------------------------------------------------- 
 */
#include <Arduboy2.h> 
#include "Images.h"
#include "Puzzles.h"

#define NODE                         15
#define GRID_WIDTH                   11
#define GRID_HEIGHT                  11

#define PUZZLE_X                     5
#define PUZZLE_Y                     5

#define STATE_INTRO                  0
#define STATE_INIT_GAME              1
#define STATE_PLAY_GAME              2
#define STATE_GAME_OVER              3 

Arduboy2 arduboy;
Sprites sprites;

const byte* nodes[] = {0, node_1, node_2, node_3, node_4, node_5, node_6, node_7, node_8, node_9, node_10 };
byte frame = 0;
byte board[5][5];
byte gameState = STATE_INTRO;
  

/* ----------------------------------------------------------------------------
 *   Initialise the Arduboy and get ready ..
 */
void setup() {

  arduboy.begin();
  arduboy.clear();

}


/* ----------------------------------------------------------------------------
 *  Play pipes !
 */
void loop() {

  arduboy.pollButtons();

  switch (gameState) {

    case STATE_INTRO:
      drawSplash();
      break;

    case STATE_INIT_GAME:
      play_InitGame();
      break;
      
    case STATE_PLAY_GAME:
      play_DisplayBoard();
      break;
      
    case STATE_GAME_OVER:
      play_GameOver();
      break;
      
  }

  arduboy.display();
  
}


void play_InitGame() {

  arduboy.clear();
  initBoard(0);
  gameState = STATE_PLAY_GAME;
  
}

void play_GameOver() {

  gameState = STATE_INTRO;
  
}

void play_DisplayBoard() {
  
  renderBoard();
  arduboy.display();
  arduboy.delayShort(5000);
  gameState = STATE_INTRO;

}

void drawSplash() { 
  
  arduboy.clear(); 
    
  sprites.drawOverwrite(112,  0, logo_straight_TB_noflange, frame);
  sprites.drawOverwrite(112, 16, logo_elbow_TL, frame);
  sprites.drawOverwrite(96,  16, logo_elbow_TR, frame);
  sprites.drawOverwrite(96,   0, logo_elbow_LB, frame);
  sprites.drawOverwrite(80,   0, logo_straight_LR_noflange, frame);
  sprites.drawOverwrite(64,   0, logo_straight_LR, frame);
  sprites.drawOverwrite(48,   0, logo_elbow_RB, frame);
  sprites.drawOverwrite(48,  16, logo_straight_TB_noflange, frame);
  sprites.drawOverwrite(48,  32, logo_elbow_TR, frame);
  sprites.drawOverwrite(64,  32, logo_elbow_LB, frame);
  sprites.drawOverwrite(64,  48, logo_straight_TB_noflange, frame);

  sprites.drawOverwrite(0,    0, logo_straight_TB_noflange, frame);
  sprites.drawOverwrite(0,   16, logo_straight_TB, frame);
  sprites.drawOverwrite(0,   32, logo_elbow_TR, frame);
  sprites.drawOverwrite(16,  32, logo_straight_LR, frame);
  sprites.drawOverwrite(32,  32, logo_elbow_TL, frame);
  sprites.drawOverwrite(32,  16, logo_elbow_RB, frame);
  sprites.drawOverwrite(48,  16, logo_cross_underlap_hflange, frame);
  sprites.drawOverwrite(64,  16, logo_straight_LR_noflange, frame);
  sprites.drawOverwrite(80,  16, logo_elbow_LB, frame);
  sprites.drawOverwrite(80,  32, logo_elbow_TR, frame);
  sprites.drawOverwrite(96,  32, logo_straight_LR, frame);
  sprites.drawOverwrite(112, 32, logo_straight_LR_noflange, frame);

  sprites.drawOverwrite(0,    0, logo_cross_underlap, frame);
  sprites.drawOverwrite(16,   0, logo_elbow_LB, frame);
  sprites.drawOverwrite(16,  16, logo_straight_TB, frame);
  sprites.drawOverwrite(16,  32, logo_cross_overlap_hflange, frame);
  sprites.drawOverwrite(16,  48, logo_elbow_TR, frame);
  sprites.drawOverwrite(32,  48, logo_straight_LR, frame);
  sprites.drawOverwrite(48,  48, logo_straight_LR_noflange, frame);
  sprites.drawOverwrite(64,  48, logo_cross_underlap_hflange, frame);
  sprites.drawOverwrite(80,  48, logo_straight_LR_noflange, frame);
  sprites.drawOverwrite(96,  48, logo_elbow_LB, frame);

  arduboy.display();
  arduboy.delayShort(2000);

  arduboy.fillRect(19, 18, 92, 30, BLACK);
  drawHorizontalDottedLine(20, 110, 19);
  drawHorizontalDottedLine(20, 110, 46);
  sprites.drawOverwrite(23, 21, logo, frame);
  arduboy.display();

  arduboy.delayShort(2000);

  gameState = STATE_INIT_GAME;
  
}


