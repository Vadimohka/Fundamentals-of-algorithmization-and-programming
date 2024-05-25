#ifndef VIEW_GRIDCELLTYPE_H_
#define VIEW_GRIDCELLTYPE_H_

namespace view {

enum class GridCellType {
    PathStart,
    PathEnd,
    Path,
    Free,
    Blocked,
    Occupied
};

}

#endif