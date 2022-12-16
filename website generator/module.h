// antanas.vasiliauskas@mif.stud.vu.lt
#ifndef MODULE_H
#define MODULE_H

// Adds "Accept cookies" pop-up dialog to your html page if one doesn't exist already.
// html_file_path can be relative, e.g. "./index.html", or full path, e.g. "C:\Users\USER\Desktop\project\index.html"
void add_cookies_popup(char *html_file_path);

// changes website cursor to minecraft sword, if it's not already added.
// html_file_path can be relative, e.g. "./index.html", or full path, e.g. "C:\Users\USER\Desktop\project\index.html"
void change_cursor(char *html_file_path);

// repeats the same section of text several times using keywords (repeat) and (endrep)
// also replaces | symbols with lines from the database file
// example:
//-----------original html file----------
// (repeat) 3
// text here |
// (endrep)
// --------------------------------------
//-----------database file---------------
// variable_name_1
// variable_name_2
// variable_name_3
//---------------------------------------
// is changed to
//-----------changed html file-----------
// text here variable_name_1
// text here variable_name_2
// text here variable_name_3
//---------------------------------------
void htmlEdit(FILE *file, FILE *db);
#endif
