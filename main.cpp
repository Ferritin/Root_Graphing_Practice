#include "TF1.h"
#include "TCanvas.h"

int main()
{
  //Prints sin(x) between -5 and 5
  TCanvas* c = new TCanvas("c", "Something", 0, 0, 800, 600);
  TF1 *f1 = new TF1("f1","(sin(x))/(x+1)", -5, 5);
  f1->SetLineColor(kBlue+1);
  f1->SetTitle("My graph;x; sin(x)");
  f1->Draw();
  c->Print("demo1.pdf");
  return 0;

}
