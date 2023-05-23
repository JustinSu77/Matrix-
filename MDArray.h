//
// Created by justi on 5/23/2023.
//

#ifndef MDARRAY_H
#define MDARRAY_H
#include <iostream>
#include <initializer_list>
namespace justin_su
{
    template <class T>
    class MDArray
    {
        public:
            MDArray();
            MDArray(int rows, int columns);
            MDArray(const std::initializer_list<std::initializer_list<T>>& list);
            ~MDArray();
            void print();
            void fill(T value);
            void insertAt(int index, T value);
            void removeAt(int index);
            void sort();
            T valueAt(int row, int column);
            int numberOfRows();
            int numberOfColumns();
            void operator=(const MDArray<T>& arr);
            bool operator==(const MDArray<T>& arr);

        private:
            int rows;
            int columns;
            T** array;
    };

    template<class T>
    MDArray<T>::MDArray(const std::initializer_list<std::initializer_list<T>> &list): rows(list.size()), columns(list.begin()->size())
    {
        int row_elements = 0;
        int col_elements = 0;
        array = new T*[rows]{};
        for (int i = 0; i < rows; i++)
        {
            array[i] = new T[columns]{};
        }
        for (auto row : list)
        {
            for (auto element : row)
            {
                array[col_elements][row_elements] = element;
                row_elements++;
            }
            col_elements++;
            row_elements = 0;
        }
    }

    template<class T>
    MDArray<T>::MDArray(int rows, int columns): rows(rows), columns(columns)
    {
        array = new T*[rows]{};
        for (int i = 0; i < rows; i++)
        {
            array[i] = new T[columns]{};
        }

    }

    template<class T>
    MDArray<T>::~MDArray()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] array[i];
        }
        delete[] array;
    }

    template<class T>
    void MDArray<T>::print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;

        }
    }

    template<class T>
    MDArray<T>::MDArray(): rows(3), columns(3)
    {
        array = new T*[rows]{};
        for (int i = 0; i < rows; i++)
        {
            array[i] = new T[columns]{};
        }
    }

}



#endif //MDARRAY_H
