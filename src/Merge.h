#ifndef _MERGE_H
#define _MERGE_H

#include "SortTech.h"
#include "SortError.h"
#include "SortData.h"

template<class T, template<typename...> class Container>
class Merge : public SortTech<T, Container> {
public:
    inline SortError sort(SortData<T, Container>& data) override;

private:
    void mergeSort(SortData<T, Container>& data, size_t left, size_t right);
    void merge(SortData<T, Container>& data, size_t left, size_t mid, size_t right);
};

template<class T, template<typename...> class Container>
inline SortError Merge<T, Container>::sort(SortData<T, Container>& data) {
    if (data.size() == 0)
        return SE_EMPTY;

    mergeSort(data, 0, data.size() - 1);
    return SE_SUCCESS;
}

template<class T, template<typename...> class Container>
void Merge<T, Container>::mergeSort(SortData<T, Container>& data, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

template<class T, template<typename...> class Container>
void Merge<T, Container>::merge(SortData<T, Container>& data, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (size_t i = 0; i < n1; ++i) L[i] = data[left + i];
    for (size_t j = 0; j < n2; ++j) R[j] = data[mid + 1 + j];

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k++] = L[i++];
        } else {
            data[k++] = R[j++];
        }
    }
    while (i < n1) data[k++] = L[i++];
    while (j < n2) data[k++] = R[j++];
}

#endif
