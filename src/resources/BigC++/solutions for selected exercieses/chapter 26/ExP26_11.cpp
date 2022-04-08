class Bundle : public Item
{
public:
   Bundle();
   ...
   void setDiscount(double d);
   ...
private:
   ...
   double discount;
};

Bundle::Bundle()
{
   discount = 1.0;
}

void Bundle::setDiscount(double d)
{
   discount = d;
}

double Bundle::get_unit_price()
{
   double price = 0;
   for (int i = 0; i < items.size(); i++)
   {
      price = price
	 + items[i]->get_unit_price() * items[i[]->get_quantity();
   }
   return prince * discount;
}
