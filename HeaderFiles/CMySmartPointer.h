#ifndef GENETICALGORITHM_CMYSMARTPOINTER_H
#define GENETICALGORITHM_CMYSMARTPOINTER_H

class RefCounter {

private:
    int i_count;

public:
    RefCounter() { i_count = 0; }

    int iAdd() { return (++i_count); }

    int iDec() { return (--i_count); }

    int iGet() { return (i_count); }

};

template<typename T>
class CMySmartPointer {

private:
    T *pc_pointer;
    RefCounter *pc_counter;

public:
    CMySmartPointer(T *pcPointer);

    CMySmartPointer(const CMySmartPointer &pcOther);

    ~CMySmartPointer();

    CMySmartPointer<T> &operator=(const CMySmartPointer<T> &pcOther);

    T &operator*();

    T *operator->();

    CMySmartPointer<T> cDuplicate();

    RefCounter *getCounter();

};

template<typename T>
CMySmartPointer<T>::CMySmartPointer(T *pcPointer) {
    pc_pointer = pcPointer;
    pc_counter = new RefCounter();
    pc_counter->iAdd();
}

template<typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer &pcOther) {
    pc_pointer = pcOther.pc_pointer;
    pc_counter = pcOther.pc_counter;
    pc_counter->iAdd();
}

template<typename T>
CMySmartPointer<T>::~CMySmartPointer() {
    if (pc_counter->iDec() == 0) {
        delete pc_pointer;
        delete pc_counter;
    }
}

template<typename T>
CMySmartPointer<T> &CMySmartPointer<T>::operator=(const CMySmartPointer<T> &pcOther) {
    if (this == &pcOther) return *this;
    if (pc_counter->iDec() == 0) {
        delete pc_pointer;
        delete pc_counter;
    }
    pc_pointer = pcOther.pc_pointer;
    pc_counter = pcOther.pc_counter;
    pc_counter->iAdd();

    return *this;
}

template<typename T>
T &CMySmartPointer<T>::operator*() {
    return (*pc_pointer);
}

template<typename T>
T *CMySmartPointer<T>::operator->() {
    return (pc_pointer);
}

template<typename T>
RefCounter *CMySmartPointer<T>::getCounter() {
    return pc_counter;
}

template<typename T>
CMySmartPointer<T> CMySmartPointer<T>::cDuplicate() {
    return CMySmartPointer<T>(*this);
}

#endif //GENETICALGORITHM_CMYSMARTPOINTER_H
