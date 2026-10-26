
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <limits>
using namespace std;

int main()
{
    char names[5][20];
    int marks[5][3];
    int totals[5];
    double average[5];

    // Input student names and marks
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter name of student " << (i + 1) << ": ";
        cin.getline(names[i], 20);

        cout << "Enter marks for " << names[i] << ": ";

        for (int j = 0; j < 3; j++)
        {
            cin >> marks[i][j];
        }

        // Remove the leftover newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Calculate totals, averages, and top student
    int topStudentIndex = 0;
    double highestAvg = -1.0;

    for (int i = 0; i < 5; i++)
    {
        int sum = 0;

        for (int j = 0; j < 3; j++)
        {
            sum += marks[i][j];
        }

        totals[i] = sum;
        average[i] = static_cast<double>(sum) / 3.0;

        if (average[i] > highestAvg)
        {
            highestAvg = average[i];
            topStudentIndex = i;
        }
    }

    // Display results
    cout << "\n";
    cout << setw(15) << left << "Name"
         << setw(8) << "M1"
         << setw(8) << "M2"
         << setw(8) << "M3"
         << setw(8) << "Total"
         << setw(8) << "Average" << endl;

    cout << string(55, '-') << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << setw(15) << left << names[i]
             << setw(8) << marks[i][0]
             << setw(8) << marks[i][1]
             << setw(8) << marks[i][2]
             << setw(8) << totals[i]
             << fixed << setprecision(1) << average[i]
             << endl;
    }

    cout << "\nTop student: " << names[topStudentIndex] << endl;
    cout << "Highest average: " << fixed << setprecision(1)
         << highestAvg << endl;

    return 0;
}
