#ifndef TODO_H
#define TODO_H

#include "TodoListInterface.h"
#include <iostream>
#include <string>

using namespace std;

class TodoList:TodoListInterface  {
private:
    vector<string> thingsToDo;
public:
    TodoList() {}
    virtual ~TodoList() {}
    /*
    *   Adds an item to the todo list with the data specified by the string 
"_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task)
    {
        //open the file
        ofstream output;
        output.open("toDoList.txt", ios::app);

        //write to the file
        output << _duedate << endl << _task << endl;

        //close the file
        output.close();
    }
    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task)
    {
            string thing;
            //open the file
            ifstream input;
            input.open("toDoList.txt");
            
            //put list into vector of strings
            vector<string> thingsToDo;
            while (!input.eof())
            {
                //puts a line into the vector of strings
                getline(input, thing);
                if (thing.length() > 2)
                    thingsToDo.push_back(thing);
            }
            input.close();

            //remove the thing from the vector
            for (int i = 0; i < thingsToDo.size(); i++)
            {
                if (thingsToDo[i].find(_task) != string::npos)
                {
                    thingsToDo.erase(thingsToDo.begin() + i);
                    thingsToDo.erase(thingsToDo.begin() + (i-1));
                }
            }

            //output the new vector list to the file
            ofstream output;
            output.open("toDoList.txt");
            for (int i = 0; thingsToDo.size() > i; i++)
            {
                output << thingsToDo[i] << endl;
                //cout << thingsToDo[i] << endl;
            }
            output.close();

            return 0;
    }
    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList()
    {
        //define things, open file
        string thing;
        ifstream input;
        input.open("toDoList.txt");

        //create vector of strings
        vector<string> thingsToDo;

        while (!input.eof())
        {
            //puts a line into the vector of strings
            getline(input, thing);

            //cout << thing << endl;
            if (thing.length() > 2)
                thingsToDo.push_back(thing);
        }
        input.close();

        //print out the vector
        for (int i = 0; i < thingsToDo.size(); i++)
        {
            cout << thingsToDo[i] << endl;
        }
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified 
by _duedate)
    */
    virtual void printDaysTasks(string _date)
    {
        //define things, open file
        string thing;
        string task = _date;
        ifstream input;
        input.open("toDoList.txt");

        //create vector of strings
        vector<string> thingsToDo;
        while (!input.eof())
        {
            //puts a line into the vector of strings
            getline(input, thing);
            if (thing.length() > 2)
                thingsToDo.push_back(thing);
        }
        input.close();

        for (int i = 0; i < thingsToDo.size(); i++)
        {
            if (thingsToDo[i].find(task) != string::npos)
            {
                cout << thingsToDo[i+1] << endl;
                return;
            }
        }
        cout << "No tasks for that day!";
    }

};

#endif