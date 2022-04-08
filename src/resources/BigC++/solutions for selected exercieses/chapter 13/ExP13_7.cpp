#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Coin
{
public:
   /**
      Constructs a coin with a given name and value
      @param n the coin name
      @param v the coin value
   */
   Coin(string n, double v);
   /**
      Gets the coin name.
      @return the name
   */
   string get_name() const;
   /**
      Gets the coin value
      @return the value
   */
   double get_value() const;
private:
   string name;
   double value;
};

Coin::Coin(string n, double v)
{
   name = n;
   value = v;
}

string Coin::get_name() const
{
   return name;
}

double Coin::get_value() const
{
   return value;
}

class Product
{
public:
   /**
      Constructs a product with a given name, price and quantity
      @param n the product name
      @param p the price
      @param q the quantity
   */
   Product(string n, double p, int q);
   /**
      Gets the product name
      @return the name
   */
   string get_name() const;
   /**
      Gets the product price
      @return the price
   */
   double get_price() const;
   /**
      Gets the product quantity
      @return the quantity
   */
   int get_quantity() const;
   /**
      Adds to the product quantity
      @param amount the amount to add
   */
   void add_quantity(int amount);
private:
   string name;
   double price;
   int quantity;
};

Product::Product(string n, double p, int q)
{
   name = n;
   price = p;
   quantity = q;
}

string Product::get_name() const
{
   return name;
}

double Product::get_price() const
{
   return price;
}

int Product::get_quantity() const
{
   return quantity;
}

void Product::add_quantity(int amount)
{
   quantity = quantity + amount;
}

class VendingMachine
{
public:
   /**
      Constructs a vending machine with no current
      product selection.
   */
   VendingMachine();
   /**
      Adds product to the machine.
      @param p the product to add
   */
   void add_product(Product p);
   /**
      Sets the currently selected product
      @param name the product name
      @return true if the machine has a product with the given
      name
   */
   bool select_product(string name);
   /**
      Adds a coin to pay for the currently selected product.
      @param c the coin to add
      @return true if sufficient coins have been added to pay
      for the selected product.
   */
   bool add_coin(Coin c);
   /**
      Removes all coins that were added to pay for the current
      product.
      @return the value of the returned coins
   */
   double return_coins();
   /**
      Removes all money that was paid for products.
      @return the value of the money
   */
   double remove_money();
private:
   vector<Product> products;
   int current_product;
   vector<Coin> current_payment;
   vector<Coin> coins;
};

VendingMachine::VendingMachine()
{
   current_product = -1;
}

void VendingMachine::add_product(Product p)
{
   for (int i = 0; i < products.size(); i++)
   {
      if (products[i].get_name() == p.get_name() && products[i].get_price() == p.get_price())
      {
         products[i].add_quantity(p.get_quantity());
         return;
      }
   }
   products.push_back(p);
}

bool VendingMachine::select_product(string name)
{
   for (int i = 0; i < products.size(); i++)
   {
      if (products[i].get_name() == name && products[i].get_quantity() > 0)
      {
         current_product = i;
         return true;
      }
   }
   return false;
}

bool VendingMachine::add_coin(Coin c)
{
   current_payment.push_back(c);
   if (current_product == -1) return false;
   double total = 0;
   for (int i = 0; i < current_payment.size(); i++)
   {
      total = total + current_payment[i].get_value();
   }
   if (total >= products[current_product].get_price())
   {
      for (int i = current_payment.size() - 1; i >= 0; i--)
      {
         coins.push_back(current_payment[i]);
         current_payment.pop_back();
      }
      products[current_product].add_quantity(-1);
      current_product = -1;
      return true;
   }
   else return false;
}

double VendingMachine::return_coins()
{
   double total = 0;
   for (int i = current_payment.size() - 1; i >= 0; i--)
   {
      total = total + current_payment[i].get_value();
      current_payment.pop_back();
   }
   return total;
}

double VendingMachine::remove_money()
{
   double total = 0;
   for (int i = coins.size() - 1; i >= 0; i--)
   {
      total = total + coins[i].get_value();
      coins.pop_back();
   }
   return total;
}

int main()
{
   vector<Coin> coins;
   coins.push_back(Coin("nickel", 0.05));
   coins.push_back(Coin("dime", 0.1));
   coins.push_back(Coin("quarter", 0.25));

   VendingMachine machine;
   bool more = true;
   while (more)
   {
      cout << "a)dd product s)elect p)ay c)ancel r)emove money  q)uit: ";
      string command;
      getline(cin, command);
      if (command == "a")
      {
         cout << "Product name: ";
         string name;
         getline(cin, name);
         cout << "Price: ";
         double price;
         cin >> price;
         string dummy;
         getline(cin, dummy);
         cout << "Quantity: ";
         int quantity;
         cin >> quantity;
         getline(cin, dummy);
         machine.add_product(Product(name, price, quantity)); 
      }
      else if (command == "s")
      {
         cout << "Product name: ";
         string name;
         getline(cin, name);
         if (!machine.select_product(name))
            cout << "No such product.\n";
      }
      else if (command == "p")
      {
         cout << "Coin name: ";
         string name;
         getline(cin, name);
         bool found = false;
         for (int i = 0; !found && i < coins.size(); i++)
         {
            if (coins[i].get_name() == name)
            {
               if (machine.add_coin(coins[i]))
                  cout << "Product purchased.\n";
               found = true;
            }
         }
         if (!found) cout << "No such coin.\n";
      }
      else if (command == "c")
         cout << "Returned " << machine.return_coins() << "\n";
      else if (command == "r")
         cout << "Removed " << machine.remove_money() << "\n";
      else if (command == "q")
         more = false;
   }
}


