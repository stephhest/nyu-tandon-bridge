// sh7245 - Stephanie Hestilow
//
// HOMEWORK 10 - EMPLOYEE DATA SYSTEM
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <class T> class LinkedList;
template <class T> class Node;
class Employee;

template <class T>
class Node
{
friend class LinkedList<T>;
friend class Employee;
private:
    T data; // data of a class stored in Node
    Node* nextPtr; // pointer to the next node in a list
public:
    Node() {data = T(); nextPtr = nullptr;}
    Node(T new_data) {data = new_data; nextPtr = nullptr;}

    T get_data() {return data;}
    Node<T>* get_nextPtr() {return nextPtr;}

    void set_data(T new_data) {data = new_data;}
    void set_nextPtr(Node<T>* new_nextPtr) {nextPtr = new_nextPtr;}
};

template <class T>
class LinkedList
{
friend class Node<T>;
friend class Employee;
private:
    Node<T>* headPtr;
public:
    LinkedList() {headPtr = nullptr;}
    ~LinkedList();

    Node<T>* getHeadPtr() {return headPtr;}
    bool isEmpty();
    void insertAtEnd(T new_data);
    int listSize() const;
    void printListData();

    Node<Employee>* searchID(Node<Employee>* headPtr, string ID); // EMPLOYEE DATA TYPE ONLY
    Node<Employee>* searchNetPay(Node<Employee>* headPtr, float net_pay); // EMPLOYEE DATA TYPE ONLY
};

class Employee
{
public:
    Employee();
    Employee(string new_ID, string new_name) : ID_Number(new_ID), name(new_name), hours_worked(0) {}
    Employee(string new_ID, string new_name, float new_hourly_rate);
    Employee(string new_ID, string new_name, float new_hourly_rate, int initial_hours_worked);

    void operator=(const Employee& newEmp);

    string get_ID() {return ID_Number;}
    string get_name() {return name;}
    float get_hourly_rate() {return hourly_rate;}
    int get_hours_worked() {return hours_worked;}
    float get_net_pay();

    void set_name(string new_name) {name = new_name;}
    void set_ID(string new_ID) {ID_Number = new_ID;}
    void set_hourly_rate(float new_hourly_rate) {hourly_rate = new_hourly_rate;}
    void set_hours_worked(int new_hours_worked) {hours_worked = new_hours_worked;}
    void add_hours_worked(int next_hours_worked) {hours_worked += next_hours_worked;}

    void print_data();
    void printEmpPayroll(); 

    void clear();

private:
    string ID_Number;
    string name;
    float hourly_rate;
    float net_pay;
    int hours_worked;
};

void openInputFile(ifstream &inFile);

template <class T>
void insertionSortAsc(vector<T>& v);

template <class T>
void insertionSortDesc(vector<T>& v);

//******************************************************************
//*************************  MAIN PROGRAM  *************************
//******************************************************************

int main () 
{
    LinkedList<Employee> EmployeeList; // new empty list for capturing employee data
    Employee temp;
    Node<Employee>* tempPtr = nullptr;
    ifstream inFile1, inFile2;

// READ IN FILE 1
    string ID, name;
    float rate;
    char blank;

    openInputFile(inFile1);
    while (inFile1 >> ID >> rate)
    {
        temp.set_ID(ID);
        temp.set_hourly_rate(rate);
        inFile1.get(blank); // does this help???
        getline(inFile1, name);
        temp.set_name(name);
        EmployeeList.insertAtEnd(temp);
    }
    cout<<"Reading and data storage complete. ";
    inFile1.close();
    cout<<"File closed."<<endl;


// READ IN FILE 2
    int shift_hours;
    bool tempSet;

    openInputFile(inFile2);
    while (inFile2 >> ID >> shift_hours)
    {
        tempSet = false;
        tempPtr = EmployeeList.searchID(EmployeeList.getHeadPtr(), ID);
        while(tempSet == false)
        {
            temp.set_ID(tempPtr->get_data().get_ID());
            temp.set_name(tempPtr->get_data().get_name()); 
            temp.set_hourly_rate(tempPtr->get_data().get_hourly_rate());
            temp.set_hours_worked(tempPtr->get_data().get_hours_worked());
            tempSet = true;
        }
        temp.add_hours_worked(shift_hours);
        tempPtr->set_data(temp);
        temp.clear();
        tempPtr = nullptr;
    }

    cout<<"Reading and data storage complete. ";
    inFile2.close();
    cout<<"File closed."<<endl;

// Build vector of net pay values
    vector<float> emp_net_pay;
    tempPtr = EmployeeList.getHeadPtr();
    while (tempPtr != nullptr)
    {
        for (int i=0; i < EmployeeList.listSize(); i++)
        {
            emp_net_pay.push_back(tempPtr->get_data().get_net_pay());
            tempPtr = tempPtr->get_nextPtr();
        }
    }

// Sort vector
    insertionSortDesc(emp_net_pay);

    cout<<endl;
    cout<<"********* Payroll Information *******"<<endl;
    for (int i=0; i<emp_net_pay.size(); i++)
    {
        tempPtr = EmployeeList.searchNetPay(EmployeeList.getHeadPtr(), emp_net_pay[i]);
        tempPtr->get_data().printEmpPayroll();
        cout<<endl;
    }
    cout<<"************* End Payroll ***********"<<endl;
    cout<<endl;

    return 0;
    
}

//******************************************************************
//************************  IMPLEMENTATION  ************************
//******************************************************************

//***** GENERAL FUNCTIONS *****

void openInputFile(ifstream &inFile)
{
    string filename;
    
    cout<<endl;
    cout<<"What file would you like to open? ";
    cin>>filename;

    inFile.open(filename);

    while (!inFile)
    {
        cout<<"File FAILED to open. Try again."<<endl;
        cout<<"What file would you like to open? ";
        cin>>filename;
        inFile.clear();
        inFile.open(filename);
    }

    cout<<"File opened."<<endl;
}

template <class T>
void insertionSortAsc(vector<T>& v) 
{
    for (int i=1; i<v.size(); i++) 
    {
        int j = i; 
        int currVal = v[i]; 

        while ((j>0) && (v[j-1]>currVal)) 
        {                                
            v[j] = v[j-1]; 
            j--;
        }
        v[j] = currVal; 
    }
}

template <class T>
void insertionSortDesc(vector<T>& v) 
{
    for (int i=1; i<v.size(); i++) 
    {
        int j = i; 
        int currVal = v[i]; 

        while ((j>0) && (v[j-1]<currVal)) 
        {                                
            v[j] = v[j-1]; 
            j--;
        }
        v[j] = currVal; 
    }
}

//***** EMPLOYEE CLASS *****

Employee::Employee()
{
    ID_Number = "0";
    name = "No name yet";
    hourly_rate = 0.0;
    hours_worked = 0;
}


Employee::Employee(string new_ID, string new_name, float new_hourly_rate)
{
    ID_Number = new_ID;
    name = new_name;
    hourly_rate = new_hourly_rate;
    hours_worked = 0;
}

Employee::Employee(string new_ID, string new_name, float new_hourly_rate, int initial_hours_worked)
{
    ID_Number = new_ID;
    name = new_name;
    hourly_rate = new_hourly_rate;
    hours_worked = initial_hours_worked;
}

void Employee::operator=(const Employee& newEmp)
{
    ID_Number = newEmp.ID_Number;
    name = newEmp.name;
    hourly_rate = newEmp.hourly_rate;
    hours_worked = newEmp.hours_worked;
}

float Employee::get_net_pay()
{
    int net_pay = 0;

    net_pay = hours_worked * hourly_rate;

    return net_pay;
}


void Employee::print_data()
{
    cout<<"Employee ID: "<<ID_Number<<endl;
    cout<<"\tName: "<<name<<endl;
    cout<<"\tHourly Rate: "<<hourly_rate<<endl;
    cout<<"\tHours Worked: "<<hours_worked<<endl;
    cout<<"\tTotal Net Pay: $"<<get_net_pay()<<endl;
    cout<<endl;
}

void Employee::printEmpPayroll()
{
    cout<<name<<", $"<<get_net_pay();
}

void Employee::clear()
{
    ID_Number = "0";
    name = "No name yet";
    hourly_rate = 0.0;
    hours_worked = 0;    
}

//***** LINKED LIST CLASSES *****

template <class T>
bool LinkedList<T>::isEmpty()
{
    if (headPtr == nullptr)
        return 1; // return true of headPtr is pointing to nothing
    else
        return 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    if (!isEmpty())
    {
        Node<T>* currPtr = headPtr;
        Node<T>* tempPtr = nullptr;

        while (currPtr != nullptr)
        {
            tempPtr = currPtr;
            currPtr = currPtr->nextPtr;
            delete tempPtr;
        }
    }
}

template <class T>
void LinkedList<T>::insertAtEnd(T new_data)
{
    if (isEmpty())
    {
        Node<T>* newNodePtr = new Node<T>(new_data);
        headPtr = newNodePtr;
        return;
    }
    else
    {
        Node<T>* tempPtr = new Node<T>(new_data);
        Node<T>* itr = headPtr;
        while (itr->nextPtr!=nullptr)
            itr = itr->nextPtr;
        itr->nextPtr = tempPtr;
    }
}

template <class T>
int LinkedList<T>::listSize() const
{
    int count = 0;
    Node<T>* tempPtr = headPtr;
    while (tempPtr != nullptr)
    {
        count++;
        tempPtr = tempPtr->nextPtr;
    }
    return count;
}

template <class T>
void LinkedList<T>::printListData()
{
    cout<<endl;
    cout<<"LINKED LIST DATA: "<<endl;
    cout<<endl;

    if (isEmpty())
    {
        cout<<"Empty List - Nothing to print.";
        return;
    }
    else
    {
        Node<T>* tempPtr = headPtr;
        for (int i=0; i < listSize(); i++)
        {
            tempPtr->data.print_data();
            tempPtr = tempPtr->nextPtr;
        }
    }    
    cout<<"END OF LIST."<<endl;

}

template <class T>
Node<Employee>* LinkedList<T>::searchID(Node<Employee>* headPtr, string ID)
{
    Node<Employee>* here = headPtr;

    if (here == nullptr)
    {
        cout<<"Search Error - Empty List.";
        return NULL;
    }
    else
    {
        string currEmpID;
        currEmpID = here->get_data().get_ID();
        while ((currEmpID != ID) && (here->nextPtr != nullptr))
        {
            here = here->nextPtr;
            currEmpID = here->get_data().get_ID();
        }
        if (currEmpID == ID)
        {
            return here;
        }
        else
        {
            cout<<"No match found."<<endl;
            return NULL;
        }
    }        
}

template <class T>
Node<Employee>* LinkedList<T>::searchNetPay(Node<Employee>* headPtr, float net_pay)
{
    Node<Employee>* here = headPtr;

    if (here == nullptr)
    {
        cout<<"Search Error - Empty List.";
        return NULL;
    }
    else
    {
        float currEmpPay;
        currEmpPay = here->get_data().get_net_pay();
        while ((currEmpPay != net_pay) && (here->nextPtr != nullptr))
        {
            here = here->nextPtr;
            currEmpPay = here->get_data().get_net_pay();
        }
        if (currEmpPay == net_pay)
        {
            return here;
        }
        else
        {
            cout<<"No match found."<<endl;
            return NULL;
        }
    }        
}