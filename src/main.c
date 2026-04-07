#include <stdio.h>
#include <time.h>
#include <curses.h>

// this should be a seperate file but its too late now!
const char *digits[11][5] = {
  {
    " ### ",
    "#   #",
    "#   #",
    "#   #",
    " ### "},
  {
    "  #  ",
    " ##  ",
    "  #  ",
    "  #  ",
    " ### "},
  {
    " ### ",
    "#  # ",
    "  #  ",
    " #   ",
    "#####"},
  {
    " ### ",
    "#   #",
    "   # ",
    "#   #",
    " ### "},
  {
    " #  #",
    "#   #",
    "#####",
    "    #",
    "    #"},
  {
    "#####",
    "#    ",
    "#### ",
    "    #",
    "#### "},
  {
    " ### ",
    "#    ",
    "#### ",
    "#   #",
    " ### "},
  {
    "#####",
    "    #",
    "   # ",
    "   # ",
    "   # "},
  {
    " ### ",
    "#   #",
    " ### ",
    "#   #",
    " ### "},
  {
    " ### ",
    "#   #",
    " ####",
    "    #",
    " ### "},
  {
    "     ",
    "  #  ",
    "     ",
    "  #  ",
    "     "}
};

int main(int argc, char *argv[]) {
  // had to try out argc and argv
  printf("Has %d arguments.\n", argc);

  // init some vars
  // time.h vars
  char buff[80]; // NEVER name the character buffer "time" -- been there before
  time_t rawtime;
  struct tm *fmttime;

  // ncurses/term screen related stuff
  int maxlines, maxcols;
  int ch;

  initscr();
  cbreak();
  noecho();

  clear();
  nodelay(stdscr, TRUE);
  
  ch = getch();
  while (ch == ERR) {
    // format and print time
    // strftime(buff, sizeof(buff), "%c", fmttime);
    // printf("The current time is: %s\n", buff);
   
    maxlines = LINES - 1;
    maxcols = COLS - 1;

    if (maxcols < 20 || maxlines < 20) {
      mvaddstr(1, 1, "terminal is too small!");
      mvaddstr(1, 2, "must be at least 20x20");
    } else {
      const char **letter = digits[0];
      for (int i = 0; i < 5; i++) {
        mvaddstr(i + 1, 1, letter[i]);
        // printf("%d\n", i);
        // printf("%s\n", letter[i]);
      }
    }

    refresh();

    ch = getch();
  }

  return 0;
}
