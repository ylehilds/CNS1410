#include <iostream>
#include <vector>

using namespace std;

/** 
   A class for keeping money that was placed in the machine
*/
class MoneyBox
{
public:
   /** 
      Returns the amount that has been deposited to buy the current item
      @return the amount deposited
   */
   int getAmount();

   /** 
      Deposits a coin to buy the current item
   */
   void addCoin();

   /** 
      Returns the deposited coins to the user
   */
   void returnCoins();

   /** 
      Moves the deposited coins into the storage area
   */
   void keepCoins();

   /** 
      Takes out all of the deposited coins and the coins in the storage area 
   */
   void removeCoins();
private:
   int keptAmount;
   int holdingAmount;
};

int MoneyBox::getAmount()
{
   return holdingAmount;
}

void MoneyBox::addCoin()
{
   holdingAmount++;
   cout << "You now have " << holdingAmount << " coins.\n";
}

void MoneyBox::returnCoins()
{
   cout << "Returning " << holdingAmount << " coins.\n";
   holdingAmount = 0;
}

void MoneyBox::keepCoins()
{
   keptAmount = keptAmount + holdingAmount;

   cout << "Keeping " << holdingAmount << " coins.\n";
   holdingAmount = 0;
}

void MoneyBox::removeCoins()
{
   keptAmount = keptAmount + holdingAmount;
   holdingAmount = 0;

   cout << "Removing " << keptAmount << " coins from the money box.\n";
   keptAmount = 0;
}

const int RESTOCK_AMOUNT=10;

/**
   An item in the vending machine
*/
class VendingMachineItem
{
public:
   /**
      Construct a VendingMachine object
      @arg name the item's name
      @arg the cost of the item
   */
   VendingMachineItem(string name, int cost);

   /**
      Get the item's name
      @return the name
   */
   string getName();

   /**
      Get the item's cost
      @return the cost
   */
   int getCost();

   /**
      Get the number remaining of the item
      @return the number remaining
   */
   int getQuantity();

   /**
      Restock this item
   */
   void restock();

   /**
      Dispense one of this item
   */
   void dispense();
private:
   string name;
   int cost;
   int quantity;
};


VendingMachineItem::VendingMachineItem(string name, int cost)
{
   this->name = name;
   this->cost = cost;
   this->quantity = RESTOCK_AMOUNT;
}

string VendingMachineItem::getName()
{
   return name;
}

int VendingMachineItem::getCost()
{
   return cost;
}

int VendingMachineItem::getQuantity()
{
   return quantity;
}

void VendingMachineItem::restock()
{
   quantity = RESTOCK_AMOUNT;
}

void VendingMachineItem::dispense()
{
   // Precondition: Quantity > 0
   quantity = quantity - 1;
   cout << "Here is your " << getName() << "\n";
}

/**
   A vending machine with a set of items and a money box
*/
class VendingMachine
{
public:

   /**
      Constructs a vending machine
   */
   VendingMachine();

   /**
      Print the names and costs of all the items in the machine
   */
   void listItems();

   /**
      Check if a selection is valid
      @return whether the selection is valid
   */
   bool isSelectionValid(int i);

   /**
      Take all of the coins out of the moneybox
   */
   void emptyMoneyBox();


   /**
      Add a coin to the money box
   */
   void addCoin();

   /**
      Restock each item in the machine
   */
   void restock();

   /**
      Select an item from the machine
      @arg selection the number of the item to select
   */
   void selectItem(int selection);

private:
   vector<VendingMachineItem*> itemList;
   MoneyBox box;
};

VendingMachine::VendingMachine()
{
   itemList.push_back(new VendingMachineItem("Coke", 2));
   itemList.push_back(new VendingMachineItem("Diet Coke", 2));
   itemList.push_back(new VendingMachineItem("Sprite", 2));
   itemList.push_back(new VendingMachineItem("Ginger Ale", 4));
   itemList.push_back(new VendingMachineItem("Water", 1));
}

void VendingMachine::listItems(){
   cout << "\n";
   for (int i=0; i<itemList.size(); i++)
   {
      cout << "Item " << (i+1) << ": " << itemList[i]->getName()
	 << ", Cost: " << itemList[i]->getCost() << " coins"
	 << ", Quantity: " << itemList[i]->getQuantity() << ".\n";
   }
   cout << "\n";
   cout << "You have deposited " << box.getAmount() << " coins\n";
   cout << "\n";
}

bool VendingMachine::isSelectionValid(int i)
{
   return 1 <= i && i <= itemList.size();
}

void VendingMachine::emptyMoneyBox()
{
   box.removeCoins();
}

void VendingMachine::addCoin()
{
   box.addCoin();
}

void VendingMachine::restock()
{
   for (int i=0; i<itemList.size(); i++)
   {
      itemList[i]->restock();
   }
   cout << "All items have been restocked!\n";
}

void VendingMachine::selectItem(int selection)
{
   if (selection >= 1 & selection <= itemList.size())
   {
      VendingMachineItem* i = itemList[selection-1];
      if (box.getAmount() < i->getCost())
      {
	 cout << "You have no entered enough coins!\n";
         box.returnCoins();
      }
      else if (i->getQuantity() == 0)
      {
	 cout << "This item is out of stock!\n";
         box.returnCoins();
      }
      else
      {
         box.keepCoins();
         i->dispense();
      }
   }
                       
   else
      cout << "Invalid selection\n";
       
   cout << "\n";
}

/**
   A class for accessing a VendingMachine 
*/
class MachineUI
{
public:
   /**
       Constructs a console user interface for the vending machine
       @param machine the vending machine to access
   */
   MachineUI(VendingMachine* machine);

   /**
      Display and process the main menu commands
   */
   void doMainMenu();

   void addCoin();

   void listItems();

private:
   void selectItem();
   VendingMachine* machine;
};

MachineUI::MachineUI(VendingMachine* machine)
{
    this->machine = machine;
}

void MachineUI::doMainMenu()
{
   cout << "Welcome to the vending machine program!\n";
   cout << "Please enter your command:\n";
   while (true)
   {
      cout << 
       "A)dd coin, L)ist items, S)elect item, E)mpty, R)estock, or Q)uit:\n";
      char command;
      cin >> command;
      if (command == 'A')
         addCoin();
      else if (command == 'L')
         listItems();
      else if (command == 'S')
         selectItem();
      else if (command == 'E')
         machine->emptyMoneyBox();
      else if (command == 'R')
         machine->restock();
      else if (command == 'Q')
      {
	 cout << "Goodbye\n";
         exit(0);
      }
      else
	 cout << "Invalid command\n";
   }
}

void MachineUI::addCoin()
{   
   machine->addCoin();
}

void MachineUI::listItems() 
{
   machine->listItems();
}

void MachineUI::selectItem() 
{
   bool done = false;
   int itemNum=-1;
   while (!done)
   {
      cout << "Enter number of item you would like:\n";
      cin >> itemNum;
      if (machine->isSelectionValid(itemNum))
         done = true;
      else
	 cout << "Invalid input. Try again.\n";
   }
   machine->selectItem(itemNum);
}

int main()
{
   VendingMachine* machine = new VendingMachine();
   MachineUI u(machine);
   u.doMainMenu();
   return 0;
}
