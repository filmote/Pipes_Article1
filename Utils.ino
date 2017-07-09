/* ----------------------------------------------------------------------------
 *  Return the upper 4 bits of a byte.
 */
byte leftValue(byte val) {

  return val >> 4; 
      
}


/* ----------------------------------------------------------------------------
 *  Return the lower 4 bits of a byte.
 */
byte rightValue(byte val) {

  return val & 0x0F; 
      
}


/* ----------------------------------------------------------------------------
 *  Initialise the board.
 */
void initBoard(byte puzzleNumber) {

  byte x = 0;
  byte y = 0;
  byte byteRead = 0;

  for (int i = (puzzleNumber * 15); i < (puzzleNumber + 1) * 15; i++) {

  	byteRead = pgm_read_byte(&puzzles_5x5[i]);

  
    // Load up the left hand value ..

    puzzle.board[y][x] = 0;
    if (leftValue(byteRead) > 0) {
      puzzle.board[y][x] = 0xF0 | leftValue(byteRead);
    }
    x++;

  
    // Are we still in the confines of the board?

    if (x <= puzzle.maximum.x) {         
      puzzle.board[y][x] = 0;
      if (rightValue(byteRead) > 0) {
        puzzle.board[y][x] = 0xF0 | rightValue(byteRead);
      }
    }

      
    x++;
  	  
    if (x >= PUZZLE_X) { y++; x = 0; }
  		  
  }

}

/* ----------------------------------------------------------------------------
 *  Initialise the board.
 */
void renderBoard() { 

  arduboy.clear();


  // Draw nodes ..
  
  for (int y = 0; y < PUZZLE_Y; y++) {
      
    for (int x = 0; x < PUZZLE_X; x++) {
      
      if (isNode(x, y)) {
        
        sprites.drawOverwrite(x * GRID_WIDTH + 2, y * GRID_HEIGHT + 2, nodes[getNodeValue(x,y)], frame);
        
      }
        
    }
      
  }

  
  // Draw grid marks ..

  for (int y = 0; y <= PUZZLE_Y; y++) {
  
    for (int x = 0; x <= PUZZLE_X; x++) {
      
      arduboy.drawPixel(x * GRID_WIDTH, y * GRID_HEIGHT, WHITE);
      
    }

  }
    
}




/* ----------------------------------------------------------------------------
 *  Is the position nominated a node?
 */
bool isNode(byte x, byte y) {

  return (board[y][x] & 0xF0) == 0xF0;
  
}


/* ----------------------------------------------------------------------------
 *  Get the node value for the position.
 */
byte getNodeValue(byte x, byte y) {
  
  return (board[y][x] & 0x0F);

}


/* ----------------------------------------------------------------------------
 *  Draw a horizontal dotted line. 
 *  
 *  So much nicer than a solid line!
 */
void drawHorizontalDottedLine(int x1, int x2, int y) {

  for (int x3 = x1; x3 <= x2; x3+=2) {
    arduboy.drawPixel(x3, y, WHITE);
  }
  
}


