#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159

using namespace std;

void programHeader();
void tableHeader();
void tableRow(double, double, double, double, double, double, double, double);
double calcHeightTrngl(double, double);
double calcAreaTrngl(double, double);
double calcAreaRect(double, double);
double calcAreaDike(double, double);
double calcDegreesInRadian(double);
double calcBaseTrngl(double, double);

int main()
{
    double base, vertex;
    double height_Trngl, angle_Rads, area_rect, area_trngl, base_trngl, total_area;
    double max_area = 0, max_angle = 0;
    char answer = ' ';

    do
    {
        system("cls");
        
        //Prints description of program
        programHeader();

        cout << "Please enter the base:" << endl;
        cout << "> ";
        cin >> base;
        cout << "Please enter the vertex:" << endl;
        cout << "> ";
        cin >> vertex;

        //Prints header
        tableHeader();

        //Calculates everything for every angle
        for (double angleInDegrees = 90.0; angleInDegrees >= 0.0; angleInDegrees--)
        {
            angle_Rads = calcDegreesInRadian(angleInDegrees);
            base_trngl = calcBaseTrngl(angle_Rads, vertex);
            height_Trngl = calcHeightTrngl(vertex, angle_Rads);
            area_rect = calcAreaRect(base, height_Trngl);
            area_trngl = calcAreaTrngl(height_Trngl, base_trngl);
            total_area = calcAreaDike(area_rect, area_trngl);

            //Prints a result of an angle for each row
            tableRow(base, vertex, angleInDegrees, base_trngl, height_Trngl, area_rect, area_trngl, total_area);

            if (total_area > max_area)
            {
                max_area = total_area;
                max_angle = angleInDegrees;
            }
        }

        for (int i = 0; i < 90; i++)
            cout << "-";
        cout << endl;

        cout << "- According to the base of " << static_cast<int>(base) << " with a vertex of " << static_cast<int>(vertex) << ":" << endl;
        cout << "  - Max area = " << max_area << endl;
        cout << "  - Correspondent angle = " << max_angle << endl;
        cout << endl;
        
        //Allows user to re-attempt program if desired with response evaluation
        do 
        {
            cout << "Would you like re-attempt the program? [Y/y/N/n]" << endl;
            cout << "> ";
            cin >> answer;
        } while (answer != 'N' && answer != 'n' && answer != 'Y' && answer != 'y');
    } while (answer == 'Y' || answer == 'y');

    return EXIT_SUCCESS;
}

//Calculates the degree in radian
double calcDegreesInRadian(double angleInDegrees)
{
    double radian;
    radian = angleInDegrees * (PI / 180);
    return radian;
}

//Calculates base of triangle
double calcBaseTrngl(double radians, double hipotenuse)
{
    double opposite;
    opposite = hipotenuse * cos(radians);
    return opposite;
}

//Calculates height of triangle
double calcHeightTrngl(double hipotenuse, double radians)
{
    double baseTrngl;
    baseTrngl = hipotenuse * sin(radians);
    return baseTrngl;
}

//Calculates area of rectangle
double calcAreaRect(double Base, double alturaTrngl)
{
    double areaRect;
    areaRect = Base * alturaTrngl;
    return areaRect;
}

//Calculates area of triangle
double calcAreaTrngl(double Height, double Base)
{
    double areaTrngl;
    areaTrngl = (0.5) * Height * Base;
    return areaTrngl;
}

//Calculates area of dike
double calcAreaDike(double rectangle, double triangle)
{
    double areaDam;
    areaDam = (2 * triangle) + rectangle;
    return areaDam;
}
void tableHeader()
{
    cout << endl;
    cout << "Base       Vertex    Angle       Base T    Height    Area Rect   Area Tr   Total Area" << endl;
    for (int i = 0; i < 90; i++)
        cout << "-";
    cout << endl;
}
void programHeader()
{
    cout << "Gustavo A. Rassi Fuentes          C++         CCOM 3002-MA5" << endl;
    cout << endl;
    cout << "This program is designed to calculate the area of a dike." << endl;
    cout << "That said, the program calculates it, given the base and vertex" << endl;
    cout << "by the user." << endl;
    cout << endl;
}
void tableRow(double Base, double Vertex, double Angle, double base_Trngl, double height_trngl, double area_Rect, double area_Trngl, double total_Area)
{
    cout << setw(5);
    cout << fixed;
    cout << setprecision(2);
    cout << Base;
    cout << setw(11);
    cout << Vertex;
    cout << setw(10);
    cout << Angle;
    cout << setw(12);
    cout << base_Trngl;
    cout << setw(10);
    cout << height_trngl;
    cout << setw(11);
    cout << area_Rect;
    cout << setw(10);
    cout << area_Trngl;
    cout << setw(12);
    cout << total_Area;
    cout << endl;
}