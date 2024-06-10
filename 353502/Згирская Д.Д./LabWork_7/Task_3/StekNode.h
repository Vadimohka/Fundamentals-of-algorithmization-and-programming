//
// Created by zgdarya on 5/30/24.
//

#ifndef L7_T3_STEKNODE_H
#define L7_T3_STEKNODE_H


class StekNode {
public:
    StekNode* next;
    StekNode* previous;
    int value;

    StekNode();
    StekNode(int value);
};


#endif //L7_T3_STEKNODE_H
