#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Array
{
private:
    long* arr;
    int size;

public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }

    Array(int size)
    {
        if (size < 0)
            size = 0;

        this->size = size;
        arr = new long[this->size]();
    }


    Array(const Array& other)
    {
        size = other.size;
        arr = new long[size];

        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    ~Array()
    {
        delete[] arr;
    }

    void RandomFill()
    {
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 100;
    }

    void Input()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }


    void Show()
    {
        if (size == 0)
        {
            cout << "Array is empty!\n";
            return;
        }

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void Add(long value)
    {
        long* temp = new long[size + 1];

        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        temp[size] = value;

        delete[] arr;
        arr = temp;
        size++;
    }

    void DeleteIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index!\n";
            return;
        }

        long* temp = new long[size - 1];

        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != index)
                temp[j++] = arr[i];
        }

        delete[] arr;
        arr = temp;
        size--;
    }

    void DeleteValue(long value)
    {
        int index = -1;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Element not found!\n";
            return;
        }

        DeleteIndex(index);
    }

   
    void Sort(bool ascending)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if ((ascending && arr[j] > arr[j + 1]) ||
                    (!ascending && arr[j] < arr[j + 1]))
                {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

   
    long Min()
    {
        long min = arr[0];

        for (int i = 1; i < size; i++)
            if (arr[i] < min)
                min = arr[i];

        return min;
    }

    
    long Max()
    {
        long max = arr[0];

        for (int i = 1; i < size; i++)
            if (arr[i] > max)
                max = arr[i];

        return max;
    }

    
    double Average()
    {
        if (size == 0)
            return 0;

        double sum = 0;

        for (int i = 0; i < size; i++)
            sum += arr[i];

        return sum / size;
    }

    
    Array& operator=(const Array& other)
    {
        if (this == &other)
            return *this;

        long* temp = new long[other.size];

        for (int i = 0; i < other.size; i++)
            temp[i] = other.arr[i];

        delete[] arr;

        arr = temp;
        size = other.size;

        return *this;
    }

 
    int GetSize()
    {
        return size;
    }
};

int main()
{
    srand(time(0));

    int n;
    cout << "Enter array size: ";
    cin >> n;

    if (n < 0)
        n = 0;

    Array a(n);

    int choice;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Fill with random numbers\n";
        cout << "2. Fill from keyboard\n";
        cout << "3. Display array\n";
        cout << "4. Add an element\n";
        cout << "5. Delete by index\n";
        cout << "6. Delete by value\n";
        cout << "7. Sort ascending\n";
        cout << "8. Sort descending\n";
        cout << "9. Find minimum\n";
        cout << "10. Find maximum\n";
        cout << "11. Calculate average\n";
        cout << "12. Test copy constructor\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a.RandomFill();
            cout << "Array filled!\n";
            break;

        case 2:
            a.Input();
            break;

        case 3:
            a.Show();
            break;

        case 4:
        {
            long value;
            cout << "Enter a number: ";
            cin >> value;
            a.Add(value);
            break;
        }

        case 5:
        {
            int index;
            cout << "Enter index (starting from 0): ";
            cin >> index;
            a.DeleteIndex(index);
            break;
        }

        case 6:
        {
            long value;
            cout << "Enter value: ";
            cin >> value;
            a.DeleteValue(value);
            break;
        }

        case 7:
            a.Sort(true);
            cout << "Array sorted in ascending order!\n";
            break;

        case 8:
            a.Sort(false);
            cout << "Array sorted in descending order!\n";
            break;

        case 9:
            if (a.GetSize() > 0)
                cout << "Minimum: " << a.Min() << endl;
            else
                cout << "Array is empty!\n";
            break;

        case 10:
            if (a.GetSize() > 0)
                cout << "Maximum: " << a.Max() << endl;
            else
                cout << "Array is empty!\n";
            break;

        case 11:
            if (a.GetSize() > 0)
                cout << "Average: " << a.Average() << endl;
            else
                cout << "Array is empty!\n";
            break;

        case 12:
        {
            Array copy(a);

            cout << "Copied array: ";
            copy.Show();

            cout << "Adding 999 to the copy.\n";
            copy.Add(999);

            cout << "Copy: ";
            copy.Show();

            cout << "Original: ";
            a.Show();
            break;
        }

        case 0:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid menu option!\n";
        }

    } while (choice != 0);

    return 0;
}
