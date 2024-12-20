#include <iostream> 
 
using namespace std; 
 
 
struct pryam 
{ 
    int height; 
    int width; 
    pryam* next = nullptr; 
 
 
    pryam& operator +(pryam& result1) 
    { 
        result1.height = this->height + result1.height; 
        result1.width = this->width + result1.width; 
         
        return result1; 
    } 
 
    pryam& operator -(pryam& result1) 
    { 
        result1.height = this->height - result1.height; 
        result1.width = this->width - result1.width; 
 
        return result1; 
    } 
 
    pryam& operator *(pryam& result1) 
    { 
        result1.height = this->height * result1.height; 
        result1.width = this->width * result1.width; 
 
        return result1; 
    } 
 
    pryam& operator /(pryam& result1) 
    { 
        result1.height = this->height / result1.height; 
        result1.width = this->width / result1.width; 
 
        return result1; 
    } 
 
}; 
 
int main() 
{ 
    int ds = 0; 
 
    cout << "1: +\n2: -\n3:*\n4:/" << endl; 
    cin >> ds; 
 
    pryam Figure; 
    Figure.height = 5; 
    Figure.width = 10; 
 
    pryam* current = &Figure; 
    current->next = new pryam(); 
    current = current->next; 
    current->height = 3; 
    current->width = 2; 
 
    cout << Figure.height << " - " << current->height << endl; 
    cout << Figure.width << " - " << current->width << endl; 
    pryam value; 
    switch (ds) 
    { 
    case 1: 
        value = Figure + *current; 
        break; 
    case 2: 
        value = Figure - *current; 
        break; 
    case 3: 
        value = Figure * *current; 
        break; 
    case 4: 
        value = Figure / *current; 
        break; 
 
    default:
        break; 
    } 
    cout << "__________" << endl; 
    cout << "height = " << value.height << " ||  width = " << value.width << endl; 
 
     
}
