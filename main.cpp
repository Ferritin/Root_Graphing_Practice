#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include <cmath>
#include <vector>
#include <algorithm>

void populateXAxis(std::vector<double> &xValues, double minX, double maxX, double xStep)
{
  for (double x = minX; x < maxX; x += xStep)
  {
    xValues.push_back(x);
  }
}

void polynomialEquation(std::vector<double> &xValues, std::vector<double> &yValues, double minX, double maxX, double xStep)
{
  double currentY;
  populateXAxis(xValues, minX, maxX, xStep);
  for(int i = 0; i < xValues.size(); i++)
  {
    currentY = std::pow(xValues[i],2);
    yValues.push_back(currentY);
  }

}


//Fourier Series Function, fills out xValues arrays with x values and yValues array with y values
//xValues is calculated depending on the amount of points you want, which is calculated by getting the range between minX and maxX and then dividing it by xStep, or how much we are changing x by.
//NOTE: Just to be safe, Dont put rational numbers for minX and maxX, it may lead to some funky values and messing up the drawing (Especially if you let -pi and pi to be you domain)
//yValues is calculated through a series summation, inside the for loop is the same "Algorithm" you would use mathematically to calculate a fourier series.
//NOTE: The nested for loop can be modified to fit whatever series summation you want.
void fourierSineSeries(std::vector<double> &xValues, std::vector<double> &yValues , double minX, double maxX, int iterations, double xStep)
{

  //Sets up auxiliary variables to help with calculation
  double top, bottom, sum = 0.0;
  //Iterates through all desired points
  for (double x = minX; x < maxX; x += xStep)
  {
    //Inserts current x value into the Array.
    xValues.push_back(x);
    //Nested for loop that calculates fourier series summation, as you increase the number of iterations, y values get more Accurate.
    //You may change
    for(int n = 1; n <= iterations; n++)
    {
      top = (-2)*(std::pow(-1,n))*std::sin(n*x);
      bottom = n;
      sum += top/bottom;
    }
    //Inserts current y value to yValues array, note that the position of this value matches up with the position of the corresponding x value (Just like any mathematical function would)
    yValues.push_back(sum);

    //Resets variables for the next iteration
    top = 0.0;
    bottom = 0.0;
    sum = 0.0;
  }
}

int main()
{

  //This creates a canvas, with name "c", title "something", with window width 800 and window height 600
  TCanvas* c = new TCanvas("c", "Something", 0, 0, 800, 600);

  //Setting up the x and y vectors for the fourierSineSeries
  std::vector<double>x;
  std::vector<double>y;

  //Calculates fourier Series depending on the range, iteration number and xStep values desired.
  //fourierSineSeries(x, y, -12.0, 12.0, 150, 0.001);

  //Calculates polynomial graph on the range and xStep values desired
  polynomialEquation(x, y, -10, 10, .01);

  //The following transforms the vectors into arrays so that they can be inserted into the TGraph constructor
  double xArray[x.size()];
  double yArray[y.size()];

  for(int i = 0; i < x.size(); i++)
  {
    xArray[i] = x[i];
    yArray[i] = y[i];
  }

  //Constructs a graph with the inputed amount of points, the array of x values and the array of y values
  TGraph *FourierGraph = new TGraph(x.size(), xArray, yArray);

  //Sets line color to blue
  FourierGraph->SetLineColor(kBlue+1);

  //Sets the title of the function
  FourierGraph->SetTitle("Graph of f(t) = t^2 | -10 < t < 10 ;x; f(t)");

  //Draws graph
  FourierGraph->Draw();

  //Prints result to a pdf
  c->Print("demo1.pdf");


  return 0;

}
