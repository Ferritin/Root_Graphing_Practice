#include "TF1.h"
#include "TCanvas.h"
#include "TGraph.h"
#include <cmath>
#include <vector>
#include <algorithm>



void fourierSineSeries(std::vector<double> &xValues, std::vector<double> &yValues , double minX, double maxX, int iterations, double xStep)
{

  double top, bottom, sum = 0.0;
  for (double x = minX; x < maxX; x += xStep)
  {
    xValues.push_back(x);
    for(int n = 1; n <= iterations; n++)
    {
      top = (-2)*(std::pow(-1,n))*std::sin(n*x);
      bottom = n;
      sum += top/bottom;
    }
    yValues.push_back(sum);
    top = 0.0;
    bottom = 0.0;
    sum = 0.0;
  }
}

int main()
{

  //This creates a canvas, with name "c", title "something", with window width 800 and window height 600
  TCanvas* c = new TCanvas("c", "Something", 0, 0, 800, 600);

  std::vector<double>x;
  std::vector<double>y;

  fourierSineSeries(x, y, -4.0, 4.0, 50, 0.01);

  double xArray[x.size()];
  double yArray[y.size()];


  for(int i = 0; i < x.size(); i++)
  {
    xArray[i] = x[i];
    yArray[i] = y[i];

    std::cout << '\n' << xArray[i] << " " << yArray[i] << '\n';

  }

  TGraph *FourierGraph = new TGraph(x.size(), xArray, yArray);


  //Sets line color to blue
  FourierGraph->SetLineColor(kBlue+1);

  //Sets the title of the function
  FourierGraph->SetTitle("Fourier Series of f(t) = t;x; f(t)");

  //Draws function
  FourierGraph->Draw();

  //Prints result to a pdf
  c->Print("demo1.pdf");
  return 0;

}
