#ifndef TABLE_H_
#define TABLE_H_

#include <vector>
#include "Customer.h"
#include "Dish.h"

typedef std::pair<int, Dish> OrderPair;

class Table{
public:
    Table(int t_capacity); //done
    int getCapacity() const; // done
    void addCustomer(Customer* customer);  //done
    void removeCustomer(int id);    // done
    Customer* getCustomer(int id);  // done
    std::vector<Customer*>& getCustomers();
    std::vector<OrderPair>& getOrders();
    void order(const std::vector<Dish> &menu);
    void openTable();
    void closeTable();
    int getBill();
    bool isOpen();

private:
    int capacity;
    bool open;
    std::vector<Customer*> customersList;
    std::vector<OrderPair> orderList; //A list of pairs for each order in a table - (customer_id, Dish)
};

// initialize capacity of the table
Table::Table(int t_capacity){
    capacity=t_capacity;
}
//get capacity of the table
int Table::getCapacity() const{
    return capacity;
}
 //add customer to the table
 void Table::addCustomer(Customer* Customer){
     customersList.push_back(Customer);
 }

 // remove customer
 void Table::removeCustomer(int id){
     customersList.erase(customersList.begin()+id);     // remove element assuming it is using index
 }

 // get customer
 Customer* Table::getCustomer(int id){
     return customersList.at(id);   // assuming the id is an index
 }




#endif
