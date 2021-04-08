#pragma once
#include<iostream>
class puzzle
{
    int arr[3][3];
public:
    puzzle();
    void show();
    bool move(int num);
    bool iswon();
    bool turn();
};