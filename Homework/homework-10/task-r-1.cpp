#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <functional>
#include <algorithm>

auto calcTime(void func(std::vector<int>& vec)){

    auto inner_func = [func](std::vector<int>& vec){
        std::cout << "Started sorting..." << std::endl;
        auto start {std::chrono::high_resolution_clock::now()};
        func(vec);
        auto end {std::chrono::high_resolution_clock::now()};
        std::cout << "Time taken is " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end-start) <<
        " or " << std::chrono::duration_cast<std::chrono::seconds>(end-start) << std::endl;
    };

    return inner_func;
}

void bubbleSort(std::vector<int>& data) {
    size_t len = data.size();
    if (len < 2) return;
    for (size_t i = 0; i < len - 1; ++i) {
        for (size_t j = 0; j < len - 1 - i; ++j) {
            if (data[j] > data[j + 1]) std::swap(data[j], data[j + 1]);
        }
    }
}

void insertionSort(std::vector<int>& data) {
    size_t len = data.size();
    if (len < 2) return;
    for (size_t i = 1; i < len; ++i) {
        int key = data[i];
        int j = static_cast<int>(i) - 1;
        while (j >= 0 && data[static_cast<size_t>(j)] > key) {
            data[static_cast<size_t>(j) + 1] = data[static_cast<size_t>(j)];
            --j;
        }
        data[static_cast<size_t>(j) + 1] = key;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (right - left <= 1) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid, right);
    merge(arr, left, mid, right);
}

void mergeSortStarter(std::vector<int>& data) {
    mergeSort(data, 0, static_cast<int>(data.size()));
}

int partition(std::vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (vec[j] <= pivot) {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quickSort(std::vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

void quickSortStarter(std::vector<int>& vec) {
    if (!vec.empty())
        quickSort(vec, 0, static_cast<int>(vec.size()) - 1);
}

void stdSort(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

int main() {

    long long unsigned int n{200000};
    std::vector<int> data{};
    std::random_device rd;
    std::mt19937 gen(rd());

    auto bubbleTimer = calcTime(bubbleSort);
    auto insertionTimer = calcTime(insertionSort);
    auto mergeTimer = calcTime(mergeSortStarter);
    auto quickTimer = calcTime(quickSortStarter);
    auto stdTimer = calcTime(stdSort);

    for (size_t i{}; i < n; i++) {
        data.push_back(gen());
    }

    std::vector<int> copyData {data};

    bubbleTimer(copyData);
    
    copyData = data;
    
    insertionTimer(copyData);
    
    copyData = data;
    
    mergeTimer(copyData);
    
    copyData = data;
    
    quickTimer(copyData);
    
    copyData = data;
    data.clear();

    stdTimer(copyData);
    
    copyData.clear();

    return 0;
}