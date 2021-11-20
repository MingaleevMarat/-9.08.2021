// ДЗ 9.08.2021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void printArray(int* array, size_t size);
void ZapArray(int* array, size_t size);
int sumArray(int* array, size_t size);
int proizvArray(int* array, size_t size);
int minArray(int* array, size_t size);
int maxArray(int* array, size_t size);
int SredArray(int* array, size_t size);
int indexArray(int* array, size_t size, int number);
bool chekElement(int* array, size_t size, int value);
void bubbleSort(int* array, size_t size);
void selectionSort(int* array, size_t size);
void insertionSort(int* array, size_t size);
int* insert(int* arr, unsigned int n, int value, unsigned int index);
int* pop_back(int* array, unsigned int& n);
int main()
{
    unsigned int size = 10;
    int* array = new int[size] {};
    ZapArray(array, size);
    printArray(array, size);
   //2
    std::cout << "Sum of your array: " << sumArray(array, size)<<std::endl;
    //3
    std::cout << "Proizvedenie of your array: " << proizvArray(array,size) << std::endl;
    //4
    std::cout << "Min of your array: " << minArray(array, size) << std::endl;
    //5
    std::cout << "Max of your array: " << maxArray(array, size) << std::endl;
    //6
    std::cout << "SredArefm of your array: " << SredArray(array, size) << std::endl;
    //7
    int number;
    std::cout << "Enter number for search: ";
    std:: cin >> number;
    std::cout << std::endl;
    std::cout << "Index array value in massiv: " << indexArray(array, size, number) << std::endl;
    //8
    int value;
    std::cout << "Enter the elements for cheking: " <<std:: endl;
    std::cin >> value;
    std::cout << "Your check element in array: "<<chekElement(array, size, value) << std::endl;
    //9
    bubbleSort(array, size);
    std::cout << "Your bubble sorted array: " << std::endl;
    printArray(array, size);
    //10
    selectionSort(array, size);
    std::cout << "Your selection sorted array: " << std::endl;
    printArray(array, size);
    //11
    insertionSort(array, size);
    std::cout << "Your insert sorted array: " << std::endl;
    printArray(array, size);
    //12
    int value2;
    std::cout << "Enter value to insert: ";
    std::cin >> value2;
    size_t index;
   std:: cout << "Enter index of insertion element: ";
    std::cin >> index;
    array=insert(array, size, index, value2);
    std::cout << "Your inserted array: " << std::endl;
    printArray(array, size + 1);

    array = pop_back(array, size);
    printArray(array, size);
    delete[] array;
    return 0;
}

// Печать массива на экран :
void printArray(int* array, size_t size)
{
    std::cout << "Your array: " <<std:: endl;
    for (size_t i = 0; i < size; ++i)
        std:: cout << array[i] << " ";
    std::cout << std::endl;
}
void ZapArray(int* array, size_t size)
{
    srand(time(NULL));
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = rand() % 20;
    }
}

//2
int sumArray(int* array, size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}
//3
 int proizvArray(int* array, size_t size)
{
     int proizv = 1;
    for (size_t i = 0; i < size; i++)
    {
        proizv *= array[i];
    }
    return proizv;
}
 //4
 int minArray(int* array, size_t size)
 {
     int min = array[0];
     for (size_t i = 0; i < size; ++i)
     {
         if (min > array[i])
             min = array[i];
     }
     return min;
 }
 //5
 int maxArray(int* array, size_t size)
 {
     int max = array[0];
     for (size_t i = 0; i < size; ++i)
     {
         if (max < array[i])
             max = array[i];
     }
     return max;
 }
 //6
 int SredArray(int* array, size_t size)
 {
     return sumArray(array,size) / size;
 }

//7
 int indexArray(int* array, size_t size, int number)
 {
     int index = -1;
     for (size_t i = 0; i < size; i++)

         if (array[i] == number)
             return 1;
         else
             return index;
 }
 //8
 bool chekElement(int* array, size_t size, int value)
 {
     for (int i = 0; i < size; i++)
     {
         if (array[i])
             return true;
         else
             return false;
     }
 }
 //9
 void bubbleSort(int* array, size_t size)
 {

     bool flag;
     for (int i = 0; i < size; ++i)
     {
         flag = false;
         for (int j = 0; j < size - i - 1; ++j)
         {
             if (array[j] > array[j + 1])
             {
                 std::swap(array[j], array[j + 1]);
                 flag = true;

             }
         }
         if (!flag) break;
     }
 }
 //10
 void selectionSort(int* array, size_t size)
 {
     int tmp;
     int minIndex = 0;
     for (size_t i = 0; i < size; ++i)
     {
         minIndex = i;

         for (size_t s = i; s < size; ++s)

             if (array[minIndex] < array[s])
             {
                 minIndex = s;
             }
         tmp = array[minIndex];
         array[minIndex] = array[i];
         array[i] = tmp;
     }
 }
 //11
 void insertionSort(int* array, size_t size)
 {
     int tmp;
     int minIndex;
     for (size_t i = 1; i < size; ++i)
     {
         tmp = array[i];
         minIndex = i - 1;
         while (minIndex >= 0 && array[minIndex] > tmp)
         {
             array[minIndex + 1] = array[minIndex];
             array[minIndex] = tmp;
             minIndex--;
         }
     }
 }
 //12
 int* insert(int* arr, unsigned int n, int value, unsigned int index)
 {
     int* buffer = new int[n + 1]{};
     for (int i = 0; i < index; i++)
         buffer[i] = arr[i];
     for (int i = index; i < n; i++)
         buffer[i + 1] = arr[i];
     delete[] arr;
     arr = buffer;
     arr[index] = value;
     n++;
     return arr;
 }
 int* pop_back(int* array, unsigned int& n)
 {
     int* buffer = new int[n--]{};
     for (size_t i = 0; i < n; i++)
     {
         buffer[i] = array[i];
     }
     delete[] array;
     return buffer;
 }