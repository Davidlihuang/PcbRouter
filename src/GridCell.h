#ifndef PCBROUTER_GRID_CELL_H
#define PCBROUTER_GRID_CELL_H

#include "globalParam.h"

enum GridCellType {
    VACANT,
    PAD,
    TRACE,
    VIA,
    VIA_FORBIDDEN,
    TARGET_PIN
};

class GridCell {
   public:
    //ctor
    GridCell() {}
    //dtor
    ~GridCell() {}

    friend class BoardGrid;

   private:
    float baseCost = 0.0;  //Record Routed Nets's traces
    //float viaCost = 0.0;   //Record Routed Nets's vias

    float workingCost = 0.0;  //Walked Cost

    //For incremental cost calculation
    float cachedTraceCost = -1.0;
    float cachedViaCost = -1.0;

    int cameFromId = -1;
    GridCellType cellType = VACANT;
    //bool targetedPin = false;
    //bool viaForbidden = false;
};

#endif