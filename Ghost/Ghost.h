#ifndef WATCHY_GHOST_H
#define WATCHY_GHOST_H

#include <Watchy.h>
#include "image.h"
#include "Montserrat_Medium20pt7b.h"
#include "Montserrat_Medium10pt7b.h"
#include "RobotoCondensed_Bold13pt7b.h"
#include "RobotoCondensed_Light7pt7b.h"

class Ghost : public Watchy{
    public:
        Ghost();
        String getTimeString(bool useMilitary);
        int getCenteredTextRightBound(String toCenter, int xOffset);
        void drawCentered(String toCenter, int xOffset, int yOffset);
		void drawWatchFace();
};

#endif
