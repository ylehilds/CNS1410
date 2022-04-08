#include <vector>

using namespace std;

double sum(vector<double> v)
{
   if (v.size() == 0) return 0;
   vector<double> w = v;
   w.pop_back();
   return v[v.size() - 1] + sum(w);
}

int main()
{
   vector<double> v;
   v.push_back(4);
   v.push_back(-4);
   v.push_back(14);
   v.push_back(8);
   cout << sum(v) << "\n";
}
