//Here is a Program to Implement a To do list
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//Task Class
class Task{
    private:
        string name; //Task name
        bool completed;

    public:
        //Constructor to initialize a task
        Task(const string& name)
        : name(name)
        {

        }

        string getName() const {
            return name;
        }

        bool isCompleted() const {
            return completed;
        }

        void setName(const string& name){
            this->name = name;
        }

        void markCompleted(){
            completed = false;
        }

        //Display Task Details
        void display() const {
            cout << name << " (" <<( completed ? "Pending" : "Completed") << ")" <<endl;
        }

};

//To do List class
class ToDoList{
    private:
        vector<Task>tasks; // List of Tasks
    
    public:
        //Display menu
        void displayMenu()
        {
            cout << "\n\n\n----------------To-Do List Menu--------------------\n";
            cout << "1. Add Task\n";
            cout << "2. Delete Task\n";
            cout << "3. Display Tasks\n";
            cout << "4. Mark Task as Completed\n";
            cout << "5. Exit\n";
            cout << "-----------------------------------------------------------\n";

        }

        //Add a new Task
        void addTask()
        {
            string name;
            cout << "Enter Task Name : ";
            cin.ignore();
            getline(cin,name);

            tasks.emplace_back(name);
            cout << "Task Added Successfully!!!" << endl;
        }

        //Delete a Task

        void deleteTask()
        {
            if(tasks.empty()){
                cout << "No Tasks to Delete!" << endl;
            }
            cout << "Tasks :" << endl;
            for(int i = 0; i < tasks.size(); ++i){
                cout << i + 1 << ". " << tasks[i].getName() << endl;
            }
            cout << "Enter the Task number to Delete : ";
            int taskNumber;
            cin >> taskNumber;
            if(taskNumber >= 1 && taskNumber <= tasks.size()){
                tasks.erase(tasks.begin() + taskNumber - 1);
                cout << "Task deleted Successfully!" << endl;
            }
            else{
                cout << "Invalid Task Number! " << endl;
            }
        }

        //Display all Tasks

        void displayTasks()
        {
            if(tasks.empty()){
                cout << "No Tasks to Display!" << endl;
                return;
            }
            cout << "Tasks :" <<endl;
            for(int i = 0; i < tasks.size(); ++i){
                tasks[i].display();
            }
        }

        //Mark a task as Completed

        void markTaskCompleted(){
            if(tasks.empty()){
                cout << "NO Tasks to Mark as completed!" << endl;
                return;
            }
            cout << "Tasks :"<<endl;
            for(int i = 0; i < tasks.size(); ++i){
                cout << i+1 <<". " <<tasks[i].getName() <<endl;
            }
            cout << "Enter the task number to mark as completed!" <<endl;
            int taskNumber;
            cin >> taskNumber;
            if(taskNumber >= 1 && taskNumber <= tasks.size()){
                tasks[taskNumber -1].markCompleted();
                cout << "Task marked as Completed!" << endl;
            }else{
                cout << "Invalid Task Number :" << endl;
            }
        }

        //Run the to-do list manager
        void run()
        {
            int choice;
            do{
                displayMenu();
                cout << "Enter your choice :";
                cin >> choice;
                
                switch(choice){
                    case 1:
                        addTask();
                        break;
                    case 2:
                        deleteTask();
                        break;
                    case 3:
                        displayTasks();
                        break;
                    case 4:
                        markTaskCompleted();
                        break;
                    case 5:
                        cout<<"Bye Bye, Thanks for visiting To-do List\n";
                        cout<<"Developed by Sahil Khude\n";
                        cout<<endl;
                }
            } while (choice != 5);
        }

};


//Main function

int main()
{
    //Creating a ToDoList object and running the application
    ToDoList toDoList;
    toDoList.run();
    return 0;
}