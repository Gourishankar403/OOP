#include <iostream>
#include <string>
using namespace std;
class HR;
class Employee{
 protected:
	int id;
	string name;
    float salary;
    static int employeecount;
    
    public:
    	Employee() {}
    	Employee(int id,string name,float salary){
    		this->id=id;
    		this->name=name;
    		this->salary=salary;
    		employeecount++;
    		
		}
		Employee(const Employee &p){
		        name=p.name;
		        id=p.id;
		        salary=p.salary;
		        
		        
		}
		~Employee(){
			employeecount--;
		}
		void static getemployeedetails(){
			cout<<"Employee Num:"<<employeecount<<endl;
			
		}
		
		friend class HR;
		
		
		
};

class HR{
	void change_salary(Employee &e,float salary1){
		e.salary=salary1;
		
		
	}
	
	
	
	
};



class Manager:public Employee{
	float bonus;
	
	public:
		Manager(int id,string name,float salary,float bon)
		:Employee(id, name, salary) { // Call base class constructor
        this->bonus = bon;
    }

		

	~Manager(){
		cout<<"Destructor called for manager:"<<endl;
}

	public:
	void displaymanagerdetails(){
		cout<<"\nid:"<<id<<endl;
		cout<<"\nName: "<<name<<endl;
		cout<<"\nSalary: "<<salary<<endl;
		cout<<"\nBonus: "<<bonus<<endl;
	}
};
int Employee::employeecount = 0;

int main(){
	Manager m1(1234,"Gorui",1234567,34555);
	Employee::getemployeedetails(); 
	m1.displaymanagerdetails();
	
	return 0;
	
	
	
}
