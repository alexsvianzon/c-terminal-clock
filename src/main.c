#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>

int main(int argc, char *argv[]) {
  // had to try out argc and argv
  printf("Has %d arguments.\n", argc);

  // init some vars
  // time.h vars
  char buff_full[80]; // NEVER name the character buffer "time" -- been there before
  char buff_time[10];
  char time_last[10];
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
  while (ch != 113) {
    maxlines = LINES - 1;
    maxcols = COLS - 1;
    
    time(&rawtime);
    fmttime = localtime(&rawtime);
    strftime(buff_time, sizeof(buff_time), "%I:%M:%S", fmttime);

    if (strcmp(buff_time, time_last) != 0) {
      if (maxcols < 20 || maxlines < 20) {
        mvaddstr(1, 1, "terminal is too small!");
        mvaddstr(1, 2, "must be at least 20x20");
      } else {
        for (int i = 0; buff_time[i]; i++) {
          int d = (buff_time[i] >= '0' && buff_time[i] <= '9') ? buff_time[i] - '0' : 10;
          const char **digit = digits[d];

          for (int j = 0; j < 5; j++) {
            mvaddstr(j + 1, i * 6 + 1, digit[j]);
          }
        }

        strcpy(time_last, buff_time);
        refresh();
      }
    }

    ch = getch();
    napms(50);
  }

  endwin();

  return 0;
}
