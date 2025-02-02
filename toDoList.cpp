#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    
    unordered_map<string , bool> tasks;
    
    while(true){
        
        cout<<"\n\n        Menu: \n\n";
        cout<<"1] Add task\n";
        cout<<"2] View tasks\n";
        cout<<"3] Mark task as completed\n";
        cout<<"4] To exit.\n";

        int taskNumber;
        cout<<"\nEnter task number that you want to perform: ";
        cin>>taskNumber;

        if(taskNumber == 1){
            string task;
            cout<<"Enter task: ";
            cin>>task;
            tasks[task] = 0;
        } else if(taskNumber == 2){
            unordered_map<string , bool>:: iterator itr = tasks.begin();
            
            cout<<"Task"<<"             "<<"Status\n\n";
            while(itr != tasks.end()){
                string space = "                 ";
                space.resize(17-(itr->first).size());
                cout<<itr->first<<space;
                if(itr -> second){
                    cout<<"Completed"<<endl;
                } else{
                    cout<<"Pending"<<endl;
                }
                itr++;
            }
        } else if(taskNumber == 3){
            string task;
            cout<<"Enter task: ";
            cin>>task;

            bool add = 0;
            if(tasks.find(task) == tasks.end()){
                cout<<task<<" does not exist in To Do List.\n";
                cout<<"Do you want to do add in To Do List and Mark as completed?";
                cin>>add;
                if(!add){
                    continue;
                }
            }

            tasks[task] = 1;
        } else if(taskNumber == 4){
            break;
        }
    }
    return 0;
}