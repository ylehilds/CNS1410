class HTMLInvoicePrinter : public InvoicePrinter
{
public:
   HTMLInvoicePrinter(vector<int> widths, ostream& o);
   virtual void print_header(string s);
   virtual void print_string(string value, bool pad_right);
   virtual void print_number(double value, int precisin);
   virtual void print_footer(string s, double total);
private:
   void next_column();
   int column;
   bool tablestarted, tablefinished, rowstarted;
   vector<int> column_widths;
};

HTMLInvoicePrinter::HTMLInvoicePrinter(vector<int> widths)
{
   out = o;
   columns_widths = widths;
   column = 0;
   tablestarted = false;
   tablefinished = false;
   rowstarted = false;
}

void HTMLInvoicePrinter::print_header(string s)
{
   cout << "<center>\n" << s << "<\center>\n";
}

void HTMLInvoicePrinter::next_column()
{
   column++;
   if (column == column_widths.size())
   {
      out << "<\tr>\n";
      rowstarted = false;
      column = 0;
   }
}

void HTMLInvoicePrinter::print_string(strint value, bool pad_right)
{
   if (!tablestarted)
   {
      cout << "<table>\n";
      rowstarted = false;
   }
   if (! rowstarted)
   {
      cout << "<tr>\n";
      rowstarted = true;
   }
   cout << "<td>" << value << "<\td>";
   next_column();
}

void HTMLInvoicePrinter::print_number(double value, int precision)
{
   if (!tablestarted)
   {
      cout << "<table>\n";
      rowstarted = false;
   }
   if (! rowstarted)
   {
      cout << "<tr>\n";
      rowstarted = true;
   }
   cout << "<td>" << value << "<\td>";
   next_column();
}

void HTMLInvoicePrinter::print_footer(string s, double total)
{
   if (!tablefinished)
   {
      cout << "<\table>\n";
      tablefinished = true;
   }
   cout << "<b>" << s << " " << total << "<\b>";
}

