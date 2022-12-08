#include "../inc/pathfinder.h"

void mx_pop_bridge(t_bridge *bridge) {
    mx_strdel(&(bridge->start));
    mx_strdel(&(bridge->end));
}
