/**
 * @file main.cpp
 * This is the driver file for taking input from the user and showing the output
*/

#include <bits/stdc++.h>
#include "primitives.h"

using namespace std;

/**
 * Driver function for the program
*/
int main() {
    int n;
    double C;
    int choice = 1;

    clock_t start, finish;

    cout << R"(
   _____                                 _             
  / ____|                               | |            
 | (___   ___  __ _ _ __ ___   ___ _ __ | |_ ___  _ __ 
  \___ \ / _ \/ _` | '_ ` _ \ / _ \ '_ \| __/ _ \| '__|
  ____) |  __/ (_| | | | | | |  __/ | | | || (_) | |   
 |_____/ \___|\__, |_| |_| |_|\___|_| |_|\__\___/|_|   
               __/ |                                   
              |___/                                    

 Group Members:
 Sukrit         2018A7PS0205H  
 Sneh Lohia     2018A7PS0171H
 Dhiraaj Desai  2018A7PS0146H
 Purvika        2018A7PS0232H
    )" << endl;
    
    cout << "Choose input method: \n";
    cout << "1. Manual\n" << "2. File\n" << "3. TC Analysis\n" << endl;

    cout << "\nChoice : ";

    cin >> choice;
    
    if(choice == 1) {
        cout << "Number of points: ";
        cin >> n;

        cout << "Enter " << n << " points in (x, y) format: " << endl;

        vector<Point> points(n+1, Point());

        for(int i = 1;i <= n; i++) {
            int a, b;
            cin >> a >> b;

            points[i].setX(a);
            points[i].setY(b);
        }

        cout << "Enter the value of C (multiple segment penalty): ";
        cin >> C;

        start = clock();

        vector<Line> result = FindSegmentedLeastSquares(points, C);

        finish = clock();

        double time = double(finish-start)/CLOCKS_PER_SEC;

        cout << "Time taken : " << time*1000 << " milliseconds";
    } else if(choice == 2){
        ifstream inputFile;
        string fileName;
        vector<Point> points;

        points.push_back(Point());

        cout << "Enter input file name: ";
        cin >> fileName;

        inputFile.open(fileName);

        if(inputFile.is_open()) {
            string s;
            vector <int> tokens;

            cout << "Enter the value of C (multiple segment penalty): ";
            cin >> C;

            while(getline(inputFile, s)) {
                stringstream check1(s);
                string intermediate;

                while(getline(check1, intermediate, ' ')) {
                    tokens.push_back(stoi(intermediate));
                }

                Point *p = new Point(tokens[0], tokens[1]);
                points.push_back((*p));
                tokens.clear();
            }

            inputFile.close();

            start = clock();

            vector<Line> result = FindSegmentedLeastSquares(points, C);

            finish = clock();

            double time = double(finish-start)/CLOCKS_PER_SEC;

            cout << "Time taken : " << time*1000 << " milliseconds";
        } else {
            cout << "Error opening file\n" << endl;
        }
    } else {
        int x = 1, y;
        int n;
        cin >> n;
        int C;
        cin >> C;

        vector<Point> points(n+1, Point());

        for(int i = 1;i <= n; i++) {

            x += 100;
            y = rand()%100;

            points[i].setX(x);
            points[i].setY(y);
        }

        start = clock();

        vector<Line> result = FindSegmentedLeastSquares(points, C);

        finish = clock();

        double time = double(finish-start)/CLOCKS_PER_SEC;

        cout << "Time taken : " << time*1000 << " milliseconds";
    }
    
    return 0;
}