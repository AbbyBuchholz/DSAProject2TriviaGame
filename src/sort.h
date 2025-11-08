//
// Created by pokem on 11/8/2025.
//

#include "question.h"
#include "Bridges.h"
#include "DataSource.h"
#include "BSTElement.h"
#include <queue>
#include <list>
#include <fstream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#pragma once

using namespace std;

using namespace bridges;

void mergeM1(vector<Movies1>& arr, int left, int mid, int right);
void mergeM2(vector<Movies2>& arr, int left, int mid, int right);
void mergeSongs(vector<Songs>& arr, int left, int mid, int right);
void mergeBooks(vector<Books>& arr, int left, int mid, int right);
void mergeCities(vector<Cities>& arr, int left, int mid, int right);

void mergeSortM1(vector<Movies1>& arr, int left, int right);
void mergeSortM2(vector<Movies2>& arr, int left, int right);
void mergeSortSongs(vector<Songs>& arr, int left, int right);
void mergeSortBooks(vector<Books>& arr, int left, int right);
void mergeSortCities(vector<Cities>& arr, int left, int right);

bool compareQuickSortM1(Movies1& a, Movies1& b);
bool compareQuickSortM2(Movies2& a, Movies2& b);
bool compareQuickSortSongs(Songs& a, Songs& b);
bool compareQuickSortBooks(Books& a, Books& b);
bool compareQuickSortCities(Cities& a, Cities& b);

void quickSortM1(vector<Movies1>& arr, int low, int high);
void quickSortM2(vector<Movies2>& arr, int low, int high);
void quickSortSongs(vector<Songs>& arr, int low, int high);
void quickSortBooks(vector<Books>& arr, int low, int high);
void quickSortCities(vector<Cities>& arr, int low, int high);