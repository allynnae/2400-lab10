/**
 *   @file: lab10.cc
 * @author: Allison McKee
 *   @date: 03-28-2023
 *  @brief: Parts and Prices
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

void loadData(double prices[], string parts[]);
void partPrices(double prices[], string parts[], double& most_expensive_price, string& most_expensive_part, double& least_expensive_price, string& least_expensive_part);

// main
int main(int argc, char const *argv[])
{
    double prices[6];
    string parts[6];
    double most_expensive_price, least_expensive_price;
    string most_expensive_part, least_expensive_part;
    
    cout << fixed << setprecision(2);

    // call functions
    loadData(prices, parts);
    partPrices(prices, parts, most_expensive_price, most_expensive_part, least_expensive_price, least_expensive_part);

    // output
    cout << "The name of the most expensive part is " << most_expensive_part << " ($" << most_expensive_price << ")" << endl;
    cout << "The name of the least expensive part is " << least_expensive_part << " ($" << least_expensive_price << ")" << endl;

    return 0;
}

// function to load the prices and parts 
void loadData(double prices[], string parts[]) 
{
    // Open data1.txt and load prices
    ifstream data1("data1.txt");
    if (data1.fail())
    {
        cout << "Error: data1.txt did not open." << endl;
        exit(0);
    }
    for (int i = 0; i < 6; i++) 
    {
        data1 >> prices[i];
    }
    data1.close();

    // Open data2.txt and load parts
    ifstream data2("data2.txt");
    if (data2.fail())
    {
        cout << "Error: data2.txt did not open." << endl;
        exit(0);
    }
    for (int i = 0; i < 6; i++) 
    {
        getline(data2, parts[i]);
    }
    data2.close();
}

// function to find the most and least expensive parts and their prices
void partPrices(double prices[], string parts[], double& most_expensive_price, string& most_expensive_part, double& least_expensive_price, string& least_expensive_part)
{
    most_expensive_price = prices[0];
    most_expensive_part = parts[0];
    least_expensive_price = prices[0];
    least_expensive_part = parts[0];
    for (int i = 1; i < 6; i++) {
        if (prices[i] > most_expensive_price) 
        {
            most_expensive_price = prices[i];
            most_expensive_part = parts[i];
        }
        if (prices[i] < least_expensive_price) 
        {
            least_expensive_price = prices[i];
            least_expensive_part = parts[i];
        }
    }
}