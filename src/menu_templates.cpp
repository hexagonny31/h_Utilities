#include <iostream>
#include <vector>

#include "hutils.h"

using namespace hUtils;

struct Humanoid {
    //  Information.
    std::string name = "hexagonny";
    std::string charClass = "Thief";
    char rank = 'D';

    //  Experience Points.
    double points_progress = 10;
    double required_points = 100;
    int level = 1; 

    //  Heath Points.
    double current_hp = 42.5;
    double max_hp = 120;

    std::vector<std::string> items = {"Empty Flask", "Rusty Dagger", "Worthless stick",
                                      "Sword", "Shield", "Health Potion", "Bow", "Arrow",
                                      "Magic Scroll", "Helmet", "Armor", "Boots", "Ring",
                                      "Torch", "Rope", "Pickaxe", "Mana Potion"};
};

void itemListMenu(){
    Humanoid player;

    text.toLine();
    text.toCentered("Inventory", 93);
    for(int i = 0; i < player.items.size(); i++){
        text.toLeft(player.items[i], {}, i + 1);
    }
    text.toLine();
}

void itemPaginatedMenu(){
    Humanoid player;
    const int PAGE_LIMIT = 5;
    int totalItems = player.items.size();
    int totalPages = (totalItems + PAGE_LIMIT - 1) / PAGE_LIMIT;
    int currentPage = 1;
    char choice;

    do{
        text.clearAll();
        
        text.toLine();
        text.toCentered("Inventory (Page " + std::to_string(currentPage) +
                   " of " + std::to_string(totalPages) + ")", 93);

        int start_index = (currentPage - 1) * PAGE_LIMIT;
        int end_index = (start_index + PAGE_LIMIT < totalItems) ? (start_index + PAGE_LIMIT) : totalItems;

        for (int i = start_index; i < end_index; i++) {
            text.toLeft(player.items[i], {}, i + 1);
        }

        std::cout<<'\n';
        text.toCentered("[N] Next Page | [P] Previous Page | [E] Exit");
        std::cout<< text.color(93) + "Choose: " + text.defaultText();
        std::cin >> choice;
        choice = tolower(choice);

        if (choice == 'n' && currentPage < totalPages) {
            currentPage++;
        } else if (choice == 'p' && currentPage > 1) {
            currentPage--;
        }
    }while(choice != 'e');
}

void infoMenu(){
    Humanoid player;

    text.toLine();
    text.toCentered("Player Info", 93);
    text.toLeft("Name: "  + player.name      + '\n' +
           "Class: " + player.charClass + '\n' +
           "Rank: "  + player.rank              );
           text.toLine();
}

void nestedMenus(){
    char choice;
    bool stay = true;

    while(stay){
        text.clearAll();
        text.toLine();

        text.toCentered("Main Menu", 93);
        text.toCentered("[C] Character Sheet | [I] Inventory | [U] Use Item | [E] Exit");
        std::cout << text.color(93) + "\nPick a menu: " + text.defaultText();
        std::cin >> choice;
        choice = tolower(choice);

        switch(choice){
            case 'c': infoMenu(); break;
            case 'i': itemPaginatedMenu(); break;
            case 'u': itemListMenu(); break;
            case 'e': stay = false; break;
            default: continue;
        };

        pause();
    }
}

void tableMenu(){
    text.toLeft("   Character Skill Sheet:", 93);
    text.toLine();
    table.setElements(
        "Spells", "Skills", "Status",
        text.color(31) + "Fire Ball"   + text.defaultText(),
        text.color(34) + "Destruction" + text.defaultText(),
        text.color(32) + "Poisoned"    + text.defaultText()
    );
    table.toColumn("left", 15, 3);
    text.toLine();

    pause();
}

void progressBar(bool increasing){
    Humanoid player;
    double maxPoints, progress, step = 1;

    if (increasing) {
        maxPoints = player.max_hp;
        progress = player.current_hp; 
    } else {
        maxPoints = player.required_points;
        progress = player.points_progress;
    }

    do {
        text.clearAll();
        if (increasing) {
            bar.setBar(progress, maxPoints, 124);
            progress -= step;
            if (progress <= 0) {
                text.clearAll();
                bar.setBar(0, maxPoints, 124);
                break;
            }
        } else {
            bar.setBar(progress, maxPoints, 112);
            progress += step;
            if (progress >= maxPoints) {
                text.clearAll();
                bar.setBar(maxPoints, maxPoints, 112);
                break;
            }
        }
    } while (true);
} 