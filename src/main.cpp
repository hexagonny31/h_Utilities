#include "hutils.h"
#include "menu_templates.h"

#include <iostream>

//  You can use "using namespace" to shorten code.
using namespace hUtils;  /* Best use for "using" is putting them
                         inside of source files. */

int main(){
    setConsoleWindowSize(); text.clearAll();
    
    text.toCentered("The hell. This window is paused and resized.");
    text.toCentered("This is a list.", 34, 1);
    text.toCentered("Item two.", 35, 2);
    text.toRight("Yo, Im right.");
    text.toLeft("Hey, Im left.");
    text.toLeft("I have an indent.", 1);
    text.toLeft("And I have a deeper indent", 2);

    pause(); text.clearAll();

    std::cout << text.color(92) + "This is bright green (92)\n"         + text.defaultText();
    std::cout << text.color(32) + "This is not bright but green (32)\n" + text.defaultText();
    
    pause();

    nestedMenus();

    text.clearAll();

    tableMenu();

    pause(); text.clearAll();

    progressBar(true);

    pause(); text.clearAll();

    progressBar(false);

    pause();

    return 0;
}