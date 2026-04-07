#include <stdio.h>
#include <time.h>
#include <curses.h>

// this should be a seperate file but its too late now!
const char *digits[11][5] {
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
    strftime(buff, sizeof(buff), "%c", fmttime);
    printf("The current time is: %s\n", buff);
    
    ch = getch();
  }

  return 0;
}
