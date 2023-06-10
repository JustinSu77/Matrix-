//
// Created by Justin Su on 5/23/2023.
//

/**
 * Constructor
 *          Matrix();
            Matrix(int rows, int columns);
            Matrix(const std::initializer_list<std::initializer_list<T>>& list);
   Destructor

 */
#ifndef Matrix_H
#define Matrix_H
#include <iostream>
#include <initializer_list>
namespace justin_su
{
    template <class T>
    class Matrix
    {
        public:
            /**
             * Default constructor.
             * Creates a 3x3 matrix.
             */
            Matrix();

            /**
             * Creates a matrix with rows and columns.
             *
             * @param rows as the row of the matrix
             * @param columns as the column of the matrix
             */
            Matrix(int rows, int columns);


            /**
             * Constructor with initializer list.
             * @param list initializer list of initializer list of 2D array
             */
            Matrix(const std::initializer_list<std::initializer_list<T>>& list);

            /**
             * Destructor.
             */
            ~Matrix();

            /**
             * Outputs
             */
            void print();


            /**
             * Fill matrix with given value.
             * Precondition: Matrix has elements
             * Postcondition: Matrix is filled with given value
             * @param value as value matrix is to be filled with
             */
            void fill(T value);

            /**
             * Set the value at the given row and column to the given newValue.
             * Precondition: Matrix has some values
             * Postcondition: Element of the matrix at given row and column is changed to given newValue
             * @param row as row to insert newValue at
             * @param column as column to insert newValue at
             * @param newValue as given value to be inserted
             */
            void setValueAt(int row, int column, T newValue);

            /**
             * Sorts the value in the matrix
             * Precondition: Matrix is not empty
             * Postcondition: Matrix values are sorted in ascending order
             */
            void sort();

            /**
             * Returns the value at the given row and column.
             * @param row as the row of value to be returned
             * @param column as the column of value to be returned
             * @return the value at the given row and column
             */
            T valueAt(int row, int column);

            /**
             * Return the number of rows of Matrix.
             * @return number of rows as int
             */
            int numberOfRows();

            /**
             * Return the number of columns of Matrix.
             * @return number of columns as int
             */
            int numberOfColumns();

            /**
             * Sets rows, columns, and values to be the same as an existing instance of this class.
             * Precondition: Matrix has some rows, columns, and values
             * Postcondition: Matrix has the same rows, columns, and values
             * @param arr as existing instance of this class
             */
            void operator=(const Matrix<T>& arr);

            /**
             * Returns whether or not two instances of this class are equal.
             * Matrices are equal if their rows, columns, and values are the same
             * @param arr existing instance of this class
             * @return true if matrices are equal and false otherwise
             */
            bool operator==(const Matrix<T>& arr);

        private:
            int rows;
            int columns;
            T** array;
    };

    template<class T>
    Matrix<T>::Matrix(): rows(3), columns(3)
    {
        // Allocate columns
        array = new T*[columns]{};
        // allocate rows
        for (int i = 0; i < columns; i++)
        {
            array[i] = new T[rows]{};
        }
    }

    template<class T>
    Matrix<T>::Matrix(int rows, int columns): rows(rows), columns(columns)
    {
        // Allocate columns
        array = new T*[rows]{};
        // Allocate rows
        for (int i = 0; i < rows; i++)
        {
            array[i] = new T[columns]{};
        }

    }

    template<class T>
    Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>> &list): rows(list.size()), columns(list.begin()->size())
    {
        // Use for  range loop to access values in initializer list
        int row_elements = 0;
        int col_elements = 0;

        // Allocate 2d array
        array = new T*[rows]{};
        for (int i = 0; i < rows; i++)
        {
            array[i] = new T[columns]{};
        }

        // Loop through each column
        for (auto column : list)
        {
            // For each row assign value from initializer list
            for (auto element : column)
            {
                // Assign value at index
                array[col_elements][row_elements] = element;
                // Increment the row index
                row_elements++;
            }
            // Increment column index
            col_elements++;
            // Reset row index to 0
            row_elements = 0;
        }
    }


    template<class T>
    Matrix<T>::~Matrix()
    {
        // Deallocate rows
        for (int i = 0; i < columns; i++)
        {
            delete[] array[i];
        }
        // Deallocate
        delete[] array;
    }

    template<class T>
    void Matrix<T>::print()
    {
        // Loop through columns
        for (int i = 0; i < columns; i++)
        {
            // Loop through rows
            for (int j = 0; j < rows; j++)
            {
                // Print value at current index
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;

        }
        // Skip a line
        std::cout << std::endl;
    }


    template<class T>
    void Matrix<T>::operator=(const Matrix<T>& arr)
    {
        // Deallocate matrix
        for (int i = 0; i < columns; i++)
        {
            delete[] array[i];
        }
        delete[] array;

        // Reallocate matrix columns
        array = new T* [columns]{};
        for (int i = 0; i < columns; i++)
        {
            // Allocate matrix rows
            array[i] = new T[rows]{};
        }
        // Set columns equal to columns of existing columns
        columns = arr.columns;
        // Set rows equal to rows of existing columns
        rows = arr.rows;

        // Copy elements from existing instance of this class
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                array[i][j] = arr.array[i][j];
            }
        }
    }

    template<class T>
    bool Matrix<T>::operator==(const Matrix<T>& arr)
    {
        // Return false if rows or columns are not equal
        if ((rows != arr.rows) || (columns != arr.columns))
            return false;

        // Return false if an element is not the same
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (array[i][j] != arr.array[i][j])
                    return false;
            }
        }
        // Return false otherwise
        return true;
    }

    template<class T>
    int Matrix<T>::numberOfColumns()
    {

        return columns;
    }

    template<class T>
    int Matrix<T>::numberOfRows()
    {
        return rows;
    }

    template<class T>
    T Matrix<T>::valueAt(int row, int column)
    {
        // If given row is out of bounds, throw runtime error
        if (row < 0 || row > rows)
            throw std::runtime_error("valueAt: Given row is out of bounds");
        // If given column is out of bounds, throw runtime error
        if (column < 0 || column > columns)
            throw std::runtime_error("valueAt: Given column is out of bounds!");
        // Return value at given row and column
        return array[row][column];
    }

    template<class T>
    void Matrix<T>::sort()
    {
        // From geeksforgeeks: https://www.geeksforgeeks.org/sort-given-matrix/#

        // Number of elements of matrix
        int size = rows * columns;
        // Loop through elements
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                // Treat matrix elements like a 1d array
                // If current element is greater than next element, swap
                if (array[j / columns][j % columns] > array[(j + 1)/columns][(j + 1) % columns])
                {
                    // Swap elements
                   T temp = array[j/columns][j % columns];
                   array[j/columns][j % columns] = array[(j + 1)/ columns][(j + 1) % columns];
                    array[(j + 1)/ columns][(j + 1) % columns] = temp;
                }
            }

        }
    }


    template<class T>
    void Matrix<T>::setValueAt(int row, int column, T newValue)
    {
        // If given row is out of bounds, throw runtime error
        if (row < 0 || row > rows )
            throw std::runtime_error("insertAt: Given row is out of bounds");
        // if given column is out of bounds, throw runtime error
        if (column < 0 || column > columns)
            throw std::runtime_error("insertAt: Given column is out of bounds");
        // Set value at given row and column to given newValue
        array[row][column] = newValue;
    }

    template<class T>
    void Matrix<T>::fill(T value)
    {

        // Loop through columns
        for (int i = 0; i < columns; i++)
        {
            // Loop through rows
            for (int j = 0; j < rows; j++)
            {
                // Set current element to given value
                array[i][j] = value;
            }
        }
    }

}



#endif
