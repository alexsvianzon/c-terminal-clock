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
  char buff_full[80]; // NEVER name the character buffer "time" -- been there before
  char buff_time[10]
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
    strftime(buff_time, sizeof(buff_time), "%I:%M:%S", fmttime);
   
    maxlines = LINES - 1;
    maxcols = COLS - 1;

    if (maxcols < 20 || maxlines < 20) {
      mvaddstr(1, 1, "terminal is too small!");
      mvaddstr(1, 2, "must be at least 20x20");
    } else {
      for (int i = 0; i < sizeof(buff_time), i++) {
        if (scanf("%d", &buff_time[i]) == 1) {
          const char **digit = digits[buff_time[i]];
        } else {
          const char **digit = digits[10];
        }

        for (int j = 0; j < 5; j++) {
          mvaddstr(i * 5 + i + 1, 1, digit[j];
        }
      }
    }

    refresh();

    ch = getch();
  }

  return 0;
}
