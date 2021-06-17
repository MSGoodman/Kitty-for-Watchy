#include "Ghost.h"

/* Set this to true if you want a 24-hour clock, or false if you want a 12-hour clock with AM/PM display */
const bool MILITARY_TIME = false;

const int TIME_X_OFFSET = -33;
const int TIME_Y_OFFSET = 80; 
const int DAY_DATE_X_OFFSET = 8;
const int DAY_Y_OFFSET = -93;
const int DATE_Y_OFFSET = -73;

Ghost::Ghost(){} 

int Ghost::getCenteredTextRightBound(String toCenter, int xOffset)
{
    int16_t  x1, y1;
    uint16_t w, h;

    display.getTextBounds(toCenter, 0, 0, &x1, &y1, &w, &h);
    int rightBound = xOffset + 100-w/2;
    return rightBound;
}

void Ghost::drawCentered(String toCenter, int xOffset, int yOffset){
    int16_t  x1, y1;
    uint16_t w, h;
    
    display.getTextBounds(toCenter, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(xOffset + 100-w/2, yOffset + 100+h/2);
    display.print(toCenter);  
}

String Ghost::getTimeString(bool useMilitary) {
    String timeString;
    if (useMilitary) {
        timeString = currentTime.Hour;
    }
    else {
        timeString = currentTime.Hour <= 12 ? currentTime.Hour : currentTime.Hour - 12;
    }
    timeString += ":";
    if (currentTime.Minute < 10){
    timeString += "0";
    }
    timeString += currentTime.Minute;
    return timeString;
}

void Ghost::drawWatchFace() { 
    int16_t  x1, y1;
    uint16_t w, h;
    String textToDraw;

    // Draw the cat, Ghost
    display.drawBitmap(0, 0, ghostImage, DISPLAY_WIDTH, DISPLAY_HEIGHT, GxEPD_WHITE);
    
    // Draw time
    display.setFont(&Montserrat_Medium20pt7b);
    textToDraw = getTimeString(MILITARY_TIME);
    drawCentered(textToDraw, TIME_X_OFFSET, TIME_Y_OFFSET);

    if (MILITARY_TIME == false)
    {
        int meridiemIndicatorXOffset = getCenteredTextRightBound(textToDraw, TIME_X_OFFSET) + 10;
        display.setFont(&Montserrat_Medium10pt7b);
        textToDraw = currentTime.Hour <= 12 ? "AM" : "PM";
        drawCentered(textToDraw, meridiemIndicatorXOffset, TIME_Y_OFFSET + 2);
    }

    // Draw day
    display.setFont(&RobotoCondensed_Light7pt7b);
    textToDraw = dayStr(currentTime.Wday);
    drawCentered(textToDraw, DAY_DATE_X_OFFSET, DAY_Y_OFFSET);
    
    // Draw date
    display.setFont(&RobotoCondensed_Bold13pt7b);
    textToDraw = monthShortStr(currentTime.Month);
    textToDraw += " ";
    textToDraw += currentTime.Day;
    drawCentered(textToDraw, DAY_DATE_X_OFFSET, DATE_Y_OFFSET);
}
