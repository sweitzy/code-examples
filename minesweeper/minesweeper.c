/* 
 * minesweeper.c: simple minesweeper game 
 *
 * See https://en.wikipedia.org/wiki/Minesweeper_(video_game)
 */

/*
 * Brief notes on coding style:
 *  - mixed case with initial lower for static vars/funcs
 *  - lower case with underscore for local params/vars
 *  - // for one-line debug comments
 *  - longer if/else style so debugger breakpoints can be used
 */

/* TODO: in some .h file? */
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

/* boolean type for documentation */ 
typedef int BOOL;

/* TODO: read other implementations */


/* base parameters of game */
/* TODO: these are hard-coded, could be params */
/* TODO: iOS version of this game keeps track of time, pretty cool */ 
static int numRows = 9;
static int numCols = 9;
static int numBombs = 10;
static int gameOver = FALSE;

/* one cell in the board */
typedef struct BoardCell {
  BOOL hasBomb; /* TRUE/FALSE */
  int numAdjBombs; /* 0-8 */
  BOOL visible; /* TRUE/FALSE: played or adjacent with no bombs */
  BOOL visited; /* TRUE/FALSE: for traversing board cells once */
} BoardCell;

static BoardCell **theBoard;

/* ======================================================================== */
/*..checkValidCell: check is a cell is valid */
static BOOL checkValidCell(int row, int col) {
  if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
    return TRUE;
  } else {
    return FALSE;
  }
} /* checkValidCell */

/* ======================================================================== */
/*..checkCellBomb: check adjacent cell for a bomb */
static BOOL checkCellBomb(int row, int col) {
  if (checkValidCell(row, col) && theBoard[row][col].hasBomb) {
    return TRUE;
  } else {
    return FALSE;
  }
} /* checkCellBomb */

/* ======================================================================== */
/*..checkCellClear: check adjacent cell for no adjacent bomb */
static BOOL checkCellClear(int row, int col) {
  if (checkValidCell(row, col) \
      && !theBoard[row][col].hasBomb \
      && !theBoard[row][col].visited) {

    /* non-bomb valid unvisited cell */
    if (0 == theBoard[row][col].numAdjBombs) {
      /* we want to play this next cell */
      return TRUE;
    } else {
      /* this cell has adjacent bombs, don't play it but make it visible */
      theBoard[row][col].visible = TRUE;
      return FALSE;
    }

  } else {
    return FALSE;
  }
} /* checkCellClear */

/* ======================================================================== */
/*..walkAdjCells: walk all adjacent cells, test and do action */
static void walkAdjCells(BOOL (*test_func)(int row, int col), void (*action_func)(int row, int col), int row, int col) {

#define TEST_ACTION(row, col) \
  if (test_func((row), (col))) { \
    action_func((row), (col)); \
  }

  /* diagonal upper left */
  TEST_ACTION(row - 1, col - 1);

  /* upper */
  TEST_ACTION(row - 1, col);
  
  /* diagonal upper right */
  TEST_ACTION(row - 1, col + 1);
  
  /* right */
  TEST_ACTION(row, col + 1);
  
  /* diagonal lower right */
  TEST_ACTION(row + 1, col + 1);
  
  /* lower */
  TEST_ACTION(row + 1, col);
  
  /* diagonal lower left */
  TEST_ACTION(row + 1, col - 1);
  
  /* left */
  TEST_ACTION(row, col - 1);
  
} /* walkAdjCells */ 

#if 0
/* ======================================================================== */
/*..incrAdjBombs: increment adj bombs counter */
static void incrAdjBombs(int row, int col) {
  theBoard[row][col].numAdjBombs++;
} /* incrAdjBombs */
#endif

/* ======================================================================== */
/*..initBoard: init the board */
static void initBoard(void) {
  int row, col;  /* loop variables */

  theBoard = malloc(numRows * sizeof(BoardCell *));
  for (row = 0; row < numRows; row++) {
    theBoard[row] = calloc(numCols, sizeof(BoardCell));
  }

  /* TODO: --norandom param */
#if 0 /* better randomness */
  sranddev();
#endif

  /* place the bombs */
  int bombsLeft = numBombs;
  while (bombsLeft > 0) {
    int randRow = rand() % numRows;
    int randCol = rand() % numCols;
    
    //    printf("Trying to place bomb at [%d][%d]\n", randRow, randCol);
    if (theBoard[randRow][randCol].hasBomb) {
      //      printf("  has bomb already\n");
      continue;
    } else {
      theBoard[randRow][randCol].hasBomb = TRUE;
      //      printf("  no bomb already\n");
      bombsLeft--; 
    }
  }

  /* init the board */
  for (row = 0; row < numRows; row++) {
    for (col = 0; col < numCols; col++) {
      /* count the number of adjacent bombs */
      if (!theBoard[row][col].hasBomb) {

#if 0 /* shoot have slightly different usage */
	walkAdjCells(checkCellBomb, incrAdjBombs, row, col);
#else
	/* diagonal upper left */
	if (checkCellBomb(row - 1, col - 1)) {
	    theBoard[row][col].numAdjBombs++;
	}

	/* upper */
	if (checkCellBomb(row - 1, col)) {
	  theBoard[row][col].numAdjBombs++;
	}

	/* diagonal upper right */
	if (checkCellBomb(row - 1, col + 1)) {
	  theBoard[row][col].numAdjBombs++;
	}

	/* right */
	if (checkCellBomb(row, col + 1)) {
	  theBoard[row][col].numAdjBombs++;
	}

	/* diagonal lower right */
	if (checkCellBomb(row + 1, col + 1)) {
	  theBoard[row][col].numAdjBombs++;
	}

	/* lower */
	if (checkCellBomb(row + 1, col)) {
	  theBoard[row][col].numAdjBombs++;
	}

	/* diagonal lower left */
	if (checkCellBomb(row + 1, col - 1)) {
	  theBoard[row][col].numAdjBombs++;
	}

	/* left */
	if (checkCellBomb(row, col - 1)) {
	  theBoard[row][col].numAdjBombs++;
	}
#endif
      }

    }
  }
} /* initBoard */

/* ======================================================================== */
/*..drawBoard: draw the board on the screen */
static void drawBoard(void) {
  int row, col;  /* loop variables */

  /* column header */
  printf(" ");
  for (col = 0; col < numCols; col++) {
    printf("%d", col);
  }
  printf("\n");

  /* TODO: mode for displaying board correctly or debug */

  /* TODO: doesn't display rows/cols >= 10 very well */ 

  for (row = 0; row < numRows; row++) {

    printf("%d", row);
    for (col = 0; col < numCols; col++) {
      if (theBoard[row][col].hasBomb) {
	printf("B");
	//printf("*");
      } else if (theBoard[row][col].visible) {
	if (theBoard[row][col].numAdjBombs == 0) {
	  printf(" ");
	} else {
	  printf("%d", theBoard[row][col].numAdjBombs);
	}
      } else {
	printf("*");
      }
    }
    printf("\n");
  }
} /* drawBoard */

/* ======================================================================== */
/*..getMove: get move from user */
static BOOL getMove(int *row, int *col) {
  char line[80];

  *row = -1;
  *col = -1;

  printf("Enter move (row col): ");
  fflush(stdout);

  if (fgets(line, sizeof(line), stdin) == NULL) {
    printf("EOF: quitting\n");
    exit(0);
    //    return FALSE;
  } 

  if (sscanf(line, "%d %d", row, col) != 2) {
    printf("INVALID MOVE\n");
    return FALSE;
  }

  //  printf("Got %d %d\n", *row, *col);
  if (*row >= 0 && *row < numRows && *col >= 0 && *col < numCols) {
    return TRUE;
  } else {
    printf("INVALID MOVE\n");
    return FALSE;
  }
} /* getMove */

/* ======================================================================== */
/*..resetVisited: mark entire board as not visited */
static void resetVisited(void) {
  int row;
  int col;

  for (row = 0; row < numRows; row++) {
    for (col = 0; col < numCols; col++) {
      theBoard[row][col].visited = FALSE;
    }
  }
} /* resetVisited */

/* ======================================================================== */
/*..playMove: play move from user */
static void playMove(int row, int col) {

  /* If user hit a bomb, game is over */
  if (theBoard[row][col].hasBomb) {
    printf("BOOM\n");
    gameOver = TRUE;
    /* TODO: display entire board now */
    return;
  }

  //  printf("playMove %d %d\n", row, col);

  theBoard[row][col].visible = TRUE;
  theBoard[row][col].visited = TRUE;
  
  /* If this cell has no adjacent bombs, then recursively play
     adjacent cells that we have not visited on this move. */
  if (0 == theBoard[row][col].numAdjBombs) {
    /* TODO: figure out how lamdba can help this? */

    walkAdjCells(checkCellClear, playMove, row, col);
  }

} /* playMove */

/* ======================================================================== */
/*..checkWin: check if only bombs are left */
static void checkWin(void) {
  int row, col;

  for (row = 0; row < numRows; row++) {
    for (col = 0; col < numCols; col++) {
      if (theBoard[row][col].visible == FALSE \
	  && theBoard[row][col].hasBomb == FALSE) {
	return;
      }
    }
  }

  printf("YOU WIN\n");
  gameOver = TRUE;
} /* checkWin */

/* ======================================================================== */
/*..main: main program */
int main(int argc, char **argv) {
  int row = -1;
  int col = -1;

  printf("Welcome to minesweeper.\n");

  initBoard();

  while (!gameOver) {
    drawBoard();
  
    while (!getMove(&row, &col)) {
      drawBoard();
    }

    resetVisited();

    playMove(row, col);

    checkWin();
  }

  return 0;
} /* main */

/* ======================================================================== */
/* minesweeper.c */
