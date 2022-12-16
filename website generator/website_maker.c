#include<stdio.h>
#include<stdlib.h>
#include "module.h"

void create1(int numb);
void create2(int numb);

int main(){
    FILE *db1 = fopen("database.txt", "r"), *main_file, *js, *db2 = fopen("databasejs.txt", "r");
    char num_string[10];
    int numb;
    fgets(num_string, 10, db1);
    numb = atoi(num_string);
    create1(numb);
    main_file = fopen("index.html", "r+");
    //htmlEdit(main_file, db1);
    create2(numb);
    js = fopen("./javascript/counter.js", "r+");
    //htmlEdit(js, db2);
    fclose(main_file);
    fclose(js);

    change_cursor("./index.html");
    add_cookies_popup("./index.html");
    return 0;
}
void create1(int numb){
    FILE *fp = fopen("index.html", "w");
    char *str = "<!DOCTYPE html>\n"
                "<html>\n"
                "\n"
                "\t<head>\n"
                "\t\t<!--Basic Stuff-->\n"
                "\t\t<meta charset=\"utf-8\">\n"
                "\t  \t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
                "\n"
                "\t\t<!--Libraries Links-->\n"
                "\t  \t<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css\">\n"
                "\t\t<script src=\"./javascript/counter.js\"></script>\n"
                "\t  \t<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js\"></script>\n"
                "\t  \t<script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js\"></script>\n"
                "\t  \t<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js\"></script>\n"
                "\t\t\n"
                "\n"
                "\t\t<link rel=\"stylesheet\" type=\"text/css\" href=\"./css/styles.css\">\n"
                "\t\t<title>Current Status Of Some Celebrities</title>\n"
                "\t</head>\n"
                "\n"
                "\t<body>\n"
                "\t\t\n"
                "\n"
                "\n"
                "\n"
                "\n"
                "\t\t\n"
                "\t\t<!--Navigation Bar-->\n"
                "\t<nav class=\"navbar navbar-expand-sm navbar-dark bg-dark fixed-top\">\n"
                "\t\t\t<a class=\"navbar-brand\" href=\"./index.html\">\n"
                "\t\t\t\t<img src=\"./images/icon.svg\" width=\"30\" height=\"30\" alt = \"\" loading=\"lazy\">\n"
                "\t\t\t\tCurrent Status Of Some Celebrities\n"
                "\t\t\t</a>\n"
                "\t\t\t<div class=\"collapse navbar-collapse justify-content-end\" id=\"collapsibleNavbar\">\n"
                "\t\t\t\t<ul class=\"navbar-nav\">\n"
                "\t\t\t\t\t<li class=\"nav-item\">\n"
                "\t\t\t\t      <a class=\"nav-link active\" href=\"./index.html\">Home</a>\n"
                "\t\t\t\t    </li>\n"
                "\t\t\t\t    <li class=\"nav-item\">\n"
                "\t\t\t\t      <a class=\"nav-link\" href=\"./about.html\">About Us</a>\n"
                "\t\t\t\t    </li>\n"
                "\t\t\t</div>\n"
                "\n"
                "\t\t\t<button class=\"navbar-toggler\" type=\"button\" data-toggle=\"collapse\" data-target=\"#collapsibleNavbar\">\n"
                "\t\t\t\t<span class=\"navbar-toggler-icon\"></span>\n"
                "\t\t\t</button>\n"
                "\t</nav>\n"
                "<style>\n"
                ".tooltip-wrapper {\n"
                "-webkit-transform: translateZ(0); /* webkit flicker fix */\n"
                "-webkit-font-smoothing: antialiased; /* webkit text rendering fix */\n"
                "}\n"
                "\n"
                ".tooltip-wrapper .tooltip {\n"
                "\tborder-radius: 4px;\n"
                "\tdisplay: block;\n"
                "\tbackground: #444;\n"
                "\tcolor: #fff;\t\n"
                "\topacity: 0;\n"
                "\tpointer-events: none;\n"
                "\tposition: absolute;\n"
                "\twidth: 200px;\n"
                "\t-webkit-transform: translateY(10px);\n"
                "  \t-moz-transform: translateY(10px);\n"
                "  \t-ms-transform: translateY(10px);\n"
                "   \t-o-transform: translateY(10px);\n"
                "    transform: translateY(10px);\n"
                "\t-webkit-transition: all .25s ease-out;\n"
                "  \t-moz-transition: all .25s ease-out;\n"
                "  \t-ms-transition: all .25s ease-out;\n"
                "   \t-o-transition: all .25s ease-out;\n"
                "    transition: all .25s ease-out;\n"
                "\t-webkit-box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.28);\n"
                "  \t-moz-box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.28);\n"
                "  \t-ms-box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.28);\n"
                "   \t-o-box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.28);\n"
                "    box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.28);\n"
                "    bottom: 100%%;\n"
                "    left: 0;\n"
                "    right: 0;\n"
                "    padding: 20px;\n"
                "    margin: auto;\n"
                "\tmargin-bottom: 15px;\n"
                "\t\n"
                "}\n"
                "\n"
                ".tooltip-wrapper .tooltip:before {\n"
                "\tbottom: -20px;\n"
                "\tcontent: \" \";\n"
                "\tdisplay: block;\n"
                "\theight: 20px;\n"
                "\tleft: 0;\n"
                "\tposition: absolute;\n"
                "\twidth: 100%%;\n"
                "}\n"
                "\n"
                ".tooltip-wrapper .tooltip:after {\n"
                "\tborder-left: solid transparent 10px;\n"
                "\tborder-right: solid transparent 10px;\n"
                "\tborder-top: solid #444 10px;\n"
                "\tbottom: -5px;\n"
                "\tcontent: \" \";\n"
                "\theight: 0;\n"
                "\tleft: 50%%;\n"
                "\tmargin-left: -13px;\n"
                "\tposition: absolute;\n"
                "\twidth: 0;\n"
                "}\n"
                ".tooltip-wrapper:hover .tooltip {\n"
                "\topacity: 1;\n"
                "\tpointer-events: auto;\n"
                "\t-webkit-transform: translateY(0px);\n"
                "  \t-moz-transform: translateY(0px);\n"
                "  \t-ms-transform: translateY(0px);\n"
                "   \t-o-transform: translateY(0px);\n"
                "    transform: translateY(0px);\n"
                "}\n"
                "\n"
                "</style>\n"
                "(repeat) %d\n"
                "\t\t<section class=\"imgbackground\" style=\"background-image: linear-gradient(rgba(0, 0, 0, 0.7), rgba(0, 0, 0, 0.7)),url(|);\">\n"
                "\t\t\t<h1 id=\"hello\" class=\"casscade\">|</h1>\n"
                "\t\t\t<p class=\"basic-text\">Current status</p>\n"
                "\t\t\t<h1 class=\"status-deceased\">|</h1>\n"
                "\t\t\t<p class=\"basic-text\">Person in this state for:</p>\n"
                "\t\t\t<h1 class=\"basic-text\" id=\"element_|\">0 days 0 hours 0 minutes 0 seconds</h1>\n"
                "\t\t</section>\n"
                "(endrep)\n"
                "\t</body>\n"
                "</html>";
    fprintf(fp, str, numb);
    fclose(fp);
}
void create2(int numb){
    FILE *fp = fopen("./javascript/counter.js", "w");
    char *str = "// Set the date we're counting down to\n"
                "var countDown = [\n"
                "(repeat) %d\n"
                "new Date(\"|\").getTime(),\n"
                "(endrep)\n"
                "];\n"
                "\n"
                "// Update the count down every 1 second\n"
                "var x = setInterval(function() {\n"
                "\n"
                "  // Get today's date and time\n"
                "  var now = new Date().getTime();\n"
                "\n"
                "  // Find the distance between now and the count down date\n"
                "  distance = []\n"
                "  for(var i = 0; i < countDown.length; i++){\n"
                "    distance.push(now - countDown[i]);\n"
                "  }\n"
                "\n"
                "  var days = [];\n"
                "  var hours = [];\n"
                "  var minutes = [];\n"
                "  var seconds = [];\n"
                "  for(var i = 0; i < countDown.length; i++){\n"
                "    days.push(Math.floor(distance[i] / (1000 * 60 * 60 * 24)));\n"
                "    hours.push(Math.floor((distance[i] %% (1000 * 60 * 60 * 24)) / (1000 * 60 * 60)));\n"
                "    minutes.push(Math.floor((distance[i] %% (1000 * 60 * 60)) / (1000 * 60)));\n"
                "    seconds.push(Math.floor((distance[i] %% (1000 * 60)) / 1000));\n"
                "  }\n"
                "\n"
                "  for (var i = 0; i < countDown.length; i++) {\n"
                "    document.getElementById(\"element_\" + i).innerHTML = days[i] + \" days \" + hours[i] + \" hours \"\n"
                "  + minutes[i] + \" minutes \" + seconds[i] + \" seconds \";\n"
                "  }\n"
                "}, 1000);";
    fprintf(fp, str, numb);
    fclose(fp);
}