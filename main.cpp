#include "TF1.h"
#include "TCanvas.h"

int main()
{
  //This creates a canvas, with name "c", title "something", with window width 800 and window height 600
  TCanvas* c = new TCanvas("c", "Something", 0, 0, 800, 600);

  //This creates a 1 dimensional function defined between lower and upper limit
  TF1 *f1 = new TF1("f1","(sin(x))/(x+1)", -5, 5);

  //Sets line color to blue
  f1->SetLineColor(kBlue+1);

  //Sets the title of the function
  f1->SetTitle("My graph;x; sin(x)");

  //Draws function
  f1->Draw();

  //Prints result to a pdf
  c->Print("demo1.pdf");
  return 0;

}
