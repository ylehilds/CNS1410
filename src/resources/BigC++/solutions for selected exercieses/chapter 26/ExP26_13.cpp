void Invoice::print(InvoicePrinter& printer)
{
   const int TAX_RATE = 0.07; 
   ...
   double tax = amount_due * TAX_RATE;
   printer.print_footer("TAX:", tax);
   amount_due = amount_due + tax;
   printer.print_footer("AMOUNT DUE:", amount_due);
}
