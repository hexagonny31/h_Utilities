#include "hutils.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

namespace hUtils {
    Table table;

    int Table::findMaxWidth() const
    {
        int width = 0;
        for(const auto& element : elements){
            std::string visible = text.stripAnsi(element);
            width = (std::max)(width, static_cast<int>(visible.length()));
        }
        return width;
    }

    void Table::toColumn(std::string orientation, int givenWidth, int numberOfColumns)
    {
        if(elements.empty()){
            std::cerr << "No elements to display.\n";
            return;
        }

        int maxWidth = findMaxWidth();
        int padding = (givenWidth != 0) ? (std::max)(givenWidth, maxWidth) : maxWidth;

        int rows = (elements.size() + numberOfColumns) / numberOfColumns;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < numberOfColumns; ++j){
                int index = j + i * numberOfColumns;

                if(index < static_cast<int>(elements.size())){
                    std::cout << std::setw(padding)
                              << ((orientation == "right") ? std::right : std::left)
                              << elements[index];
                    if(j < numberOfColumns - 1) std::cout << "|";
                }
            }
            std::cout << '\n';
        }
    }
}