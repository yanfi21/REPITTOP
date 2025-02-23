#include<iostream>
#include<string>
using namespace std;

class Task {
private:
    string _title;
    string _description;
    string _timeDeadline;
    int _priority; // 0..2, 0 - зеленый, 2 - красный
    bool _isActive; //false -> в архив

public:
    string getTitle() {
        return _title;
    }
    void setTitle(string title) {
        _title = title;
    }
    string getDescription() {
        return _description;
    }
    void setDescription(string description) {
        _description = description;
    }
    string getTimeDeadline() {
        return _timeDeadline;
    }
    void setTimeDeadline(string timeDeadline) {
        _timeDeadline = timeDeadline;
    }
    int getPriority() {
        return _priority;
    }
    void setPriority(int priority) {
        _priority = priority;
    }
    bool getIsActive() {
        return _isActive;
    }
    void setIsActive(bool isActive) {
        _isActive = isActive;
    }

    Task() {
        _title = "Undefined";
        _description = "Undefined";
        _timeDeadline = "Undefined";
        _priority = 0;
        _isActive = true;
    }

    Task(string title,
        string description,
        string timeDeadline,
        int priority,
        bool isActive)
    {
        _title = title;
        _description = description;
        _timeDeadline = timeDeadline;
        _priority = priority;
        _isActive = isActive;
    }

    void display() {
        switch (_priority) {
        case 0:
            cout << "\033[32m"; //Зеленый
            break;
        case 1:
            cout << "\033[33m"; //Желтый
            break;
        case 2:
            cout << "\033[31m"; //Красный
            break;
        default:
            cout << "\033[37"; //Серый
            break;
        }
        cout << _title << endl << _description << endl << _timeDeadline << endl;
        cout << "\033[0m";
    }

    void pushToArchive() {
        _timeDeadline = "Бессрочно";
        _priority = 3;
        _isActive = false;
    }
};

class TaskManager {
private:

    Task* _tasks;
    int _sizeTasks;

public:
    TaskManager() {
        _tasks = new Task[0];
        _sizeTasks = 0;
    }
    /*TaskManager(Task* task, int size) {
        _sizeTasks = size;
        _tasks = task[_sizeTasks];
    }*/

    void pushTask(Task task) {
        Task* newTasks = new Task[_sizeTasks + 1];

        for (int i = 0; i < _sizeTasks; i++) {
            newTasks[i] = _tasks[i];
        }
        newTasks[_sizeTasks] = task;
        _sizeTasks++;
        delete[] _tasks;
        _tasks = newTasks;
    }

    void displayActiveTasks() {
        for (int i = 0; i < _sizeTasks; i++) {
            if (_tasks[i].getIsActive())
                _tasks[i].display();
        }
    }

    void displayArchiveTasks() {
        for (int i = 0; i < _sizeTasks; i++) {
            if (!_tasks[i].getIsActive())
                _tasks[i].display();
        }
    }

    void addTaskFromKeyboard() {
        string title;
        string description;
        string timeDeadline;

        cout << "Введите название" << endl;
        cin >> title;
        cout << "Введите описание" << endl;
        cin >> description;
        cout << "Введите время дедлайна" << endl;
        cin >> timeDeadline;


        Task newTask = Task(title, description, timeDeadline, 0, true);
        pushTask(newTask);
    }
    void addToArchive() {
        _tasks[-_sizeTasks].setIsActive(false);
    }
    void sortOfPriority() {
        Task task = Task();
        
        //TaskManager* men = _tasks;
        for (int i = 0; i < _sizeTasks;i++) {
            for (int j = 0;j < _sizeTasks - 1;j++) {
                if (_tasks[j].getPriority() > _tasks[j + 1].getPriority());
                task = _tasks[j];
                _tasks[j] = _tasks[j + 1];
                _tasks[j + 1] = task;
            }
        }
        
        
    }
    /*void sortOfPriority() {
        Task task = Task();
        for (int i = 0; i < _sizeTasks;i++) {
            bool flag = true;
            for (int k = 0;k < _sizeTasks - (i + 1);k++) {
                if (_tasks[k].getPriority() > _tasks[k + 1].getPriority()) {
                    flag = false;
                    swap(_tasks[k].getPriority(), _tasks[k + 1].getPriority())
                }
            }
        }
    }*/

    void startManager() {
        bool flag = true;
        while (flag) {
            system("cls"); // Работает только на windows
            int choice;
            cout << "Введите действие: " << endl;
            cout << "1. Вывести активные задачи" << endl;
            cout << "2. Вывести архивные задачи" << endl;
            cout << "3. Добавить задачу" << endl;
            cout << "4. Выйти из программы" << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                displayActiveTasks();
                break;

            case 2:
                displayArchiveTasks();
                break;
            case 3:
                addTaskFromKeyboard();
                break;
            case 4:
                flag = false;
                break;
            default:
                break;
            }
        }
    }
};
int main() {
    Task task = Task("g", "fgfg", "20434", 0, true);
    Task task1 = Task("h", "fdfgdfgdfgg", "20434", 2, true);
    Task task2 = Task("t", "fergergfg", "2034", 1, true);
    Task task3 = Task("e", "ffdgdgrg", "434", 2, true);
    TaskManager taskManager = TaskManager();
    taskManager.pushTask(task);
    taskManager.pushTask(task1);
    taskManager.pushTask(task2);
    taskManager.pushTask(task3);
    taskManager.sortOfPriority();
    taskManager.displayActiveTasks();
    

}
