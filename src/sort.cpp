//
// Created by pokem on 11/8/2025.
//
#include "question.h"
#include "Bridges.h"
#include "DataSource.h"
#include "BSTElement.h"
#include "sort.h"
#include <queue>
#include <list>
#include <fstream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

using namespace bridges;

// the merge functions that merge the split vectors (does the actual sorting)
void mergeM1(vector<Movies1>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Movies1> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].title < rightVector[j].title)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].title > rightVector[j].title)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].actorLastName <= rightVector[j].actorLastName)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}
void mergeM2(vector<Movies2>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Movies2> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].title < rightVector[j].title)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].title > rightVector[j].title)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].actorLastName <= rightVector[j].actorLastName)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}
void mergeSongs(vector<Songs>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Songs> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].title < rightVector[j].title)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].title > rightVector[j].title)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].artist <= rightVector[j].artist)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}
void mergeBooks(vector<Books>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Books> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].title < rightVector[j].title)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].title > rightVector[j].title)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].authorLastName <= rightVector[j].authorLastName)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}
void mergeCities(vector<Cities>& qVector, int leftIndex, int midIndex, int rightIndex)
{
    // "First quadrant"
    int pt1Index = midIndex - leftIndex + 1;
    // "Third quadrant"
    int pt2Index = rightIndex - midIndex;
    vector<Cities> leftVector, rightVector;

    for(int x = 0; x < pt1Index; x++)
    {
        leftVector.push_back(qVector[leftIndex + x]);
    }
    for(int y = 0; y < pt2Index; y++)
    {
        rightVector.push_back(qVector[midIndex + 1 + y]);
    }
    int i = 0;
    int j = 0;
    int k = leftIndex;
    while(i < pt1Index && j < pt2Index)
    {
        if(leftVector[i].state < rightVector[j].state)
        {
            qVector[k] = leftVector[i];
            i++;
        }
        else if(leftVector[i].state > rightVector[j].state)
        {
            qVector[k] = rightVector[j];
            j++;
        }
        else
        {
            if(leftVector[i].name <= rightVector[j].name)
            {
                qVector[k] = leftVector[i];
                i++;
            }
            else
            {
                qVector[k] = rightVector[j];
                j++;
            }
        }
        k++;
    }
    while (i < pt1Index)
    {
        qVector[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < pt2Index)
    {
        qVector[k] = rightVector[j];
        j++;
        k++;
    }
}

// The original mergesort functions that keep splitting up the vectors
// Used in-class example as a base for the mergeSort function
void mergeSortM1(vector<Movies1>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortM1(qVector, left, mid);
        mergeSortM1(qVector, mid + 1, right);
        mergeM1(qVector, left, mid, right);
    }
}
void mergeSortM2(vector<Movies2>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortM2(qVector, left, mid);
        mergeSortM2(qVector, mid + 1, right);
        mergeM2(qVector, left, mid, right);
    }
}
void mergeSortSongs(vector<Songs>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortSongs(qVector, left, mid);
        mergeSortSongs(qVector, mid + 1, right);
        mergeSongs(qVector, left, mid, right);
    }
}
void mergeSortBooks(vector<Books>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortBooks(qVector, left, mid);
        mergeSortBooks(qVector, mid + 1, right);
        mergeBooks(qVector, left, mid, right);
    }
}
void mergeSortCities(vector<Cities>& qVector, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortCities(qVector, left, mid);
        mergeSortCities(qVector, mid + 1, right);
        mergeCities(qVector, left, mid, right);
    }
}

// These functions are used to compare ideal data, and if they're equal, they go to secondary data to compare & sort.
bool compareQuickSortM1(Movies1& ele, Movies1& pivot)
{
    if(ele.title == pivot.title)
    {
        return ele.actorLastName < pivot.actorLastName;
    }
    return ele.title < pivot.title;
}
bool compareQuickSortM2(Movies2& ele, Movies2& pivot)
{
    if(ele.title == pivot.title)
    {
        return ele.actorLastName < pivot.actorLastName;
    }
    return ele.title < pivot.title;
}
bool compareQuickSortSongs(Songs& ele, Songs& pivot)
{
    if(ele.title == pivot.title)
    {
        return ele.artist < pivot.artist;
    }
    return ele.title < pivot.title;
}
bool compareQuickSortBooks(Books& ele, Books& pivot)
{
    if(ele.title == pivot.title)
    {
        return ele.authorLastName < pivot.authorLastName;
    }
    return ele.title < pivot.title;
}
bool compareQuickSortCities(Cities& ele, Cities& pivot)
{
    if(ele.state == pivot.state)
    {
        return ele.name < pivot.name;
    }
    return ele.state < pivot.state;
}

// The original quickSort functions using the middle element as a partition
// Used https://www.algolist.net/Algorithms/Sorting/Quicksort as a base for the quickSort function
void quickSortM1(vector<Movies1>& qVector, int low, int high)
{
    Movies1 pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortM1(qVector[up], pivot))
            up++;
        while(compareQuickSortM1(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortM1(qVector, low, down);
    }
    if(up < high)
    {
        quickSortM1(qVector, up, high);
    }
}
void quickSortM2(vector<Movies2>& qVector, int low, int high)
{
    Movies2 pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortM2(qVector[up], pivot))
            up++;
        while(compareQuickSortM2(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortM2(qVector, low, down);
    }
    if(up < high)
    {
        quickSortM2(qVector, up, high);
    }
}
void quickSortSongs(vector<Songs>& qVector, int low, int high)
{
    Songs pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortSongs(qVector[up], pivot))
            up++;
        while(compareQuickSortSongs(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortSongs(qVector, low, down);
    }
    if(up < high)
    {
        quickSortSongs(qVector, up, high);
    }
}
void quickSortBooks(vector<Books>& qVector, int low, int high)
{
    Books pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortBooks(qVector[up], pivot))
            up++;
        while(compareQuickSortBooks(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortBooks(qVector, low, down);
    }
    if(up < high)
    {
        quickSortBooks(qVector, up, high);
    }
}
void quickSortCities(vector<Cities>& qVector, int low, int high)
{
    Cities pivot = qVector[(low + (high-low)/2)];
    int up = low, down = high;
    while (up <= down)
    {
        while(compareQuickSortCities(qVector[up], pivot))
            up++;
        while(compareQuickSortCities(pivot, qVector[down]))
            down--;
        if(up <= down)
        {
            swap(qVector[up], qVector[down]);
            up++;
            down--;
        }
    }

    if(low < down)
    {
        quickSortCities(qVector, low, down);
    }
    if(up < high)
    {
        quickSortCities(qVector, up, high);
    }
}

