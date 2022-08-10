#pragma once
#include<iostream>
#include "Margin.h"

std::string proText(std::string a, int margin)
{
    std::string beautifulText = a;
    if (a.size() > margin) std::cout << "text size Error";
    else
    {
        for (int i = 0; i < (margin - (a.size())); i++)
        {
            beautifulText += " ";
        }
    }
    return beautifulText;
}