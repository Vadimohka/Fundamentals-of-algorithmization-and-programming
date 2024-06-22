#ifndef AIRPORT_H
#define AIRPORT_H


struct Airport
{
    int count_of_flights;
    double road_length;
    bool is_international;
    char type;
    char airport_name[50];
    double size[3];
};

#endif // AIRPORT_H
