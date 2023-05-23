//
// Created by justi on 5/23/2023.
//

#ifndef MDARRAY_H
#define MDARRAY_H
#include <initializer_list>
namespace justin_su
{
    template <class T>
    class MDArray
    {
        public:
            MDArray();
            MDArray(int rows, int columns);
            MDArray(const std::initializer_list<T>& list);
            ~MDArray();
            void print();
            void fill(T value);
            void insertAt(int index, T value);
            void removeAt(int index);
            void sort();
            T valueAt(int row, int column);
            int numberOfRows();
            int numberOfColumns();
        private:
            int rows;
            int columns;
            int** array;
    };
}



#endif //MDARRAY_H
