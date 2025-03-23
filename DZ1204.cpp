#include <iostream>
 #include <vector>
 #include <conio.h>
 
 using namespace std;
 
 class UIElement {
 public:
     static int count;
     virtual void draw() {};
 };
 
 int UIElement::count = 0;
 
 int resultAgeConfirm = 1;
 
 class UIElementButtons : public UIElement {
 public:
     bool isFocused;
 
     void draw() override {
 
     }
 };
 
 class UIElementComposable : public UIElement {
 public:
 
     void draw() override {
 
     }
 };
 
 class Button;
 
 vector<Button> listt;
 
 bool check = false;
 
 class Button : public UIElementButtons {
 public:
     int size_x;
     int size_y;
     string text;
     int padding_horizontal;
     bool checkVal = false;
     bool target = false;
     string horizontalAlign; 
     string verticalAlign;
 
     bool checktarget()
     {
         return this->target;
     }
 
     void swapTarget()
     {
         (this->target) ? this->target = false : this->target = true;
     }
 
     Button() {
         size_x = 10;
         size_y = 3;
         text = "Button";
         padding_horizontal = 1;
         checkVal = false;
         horizontalAlign = "left";
         verticalAlign = "top";
     }
 
     Button(int size_x, int size_y, string text, int padding_horizontal = 1, string horizontalAlign = "left", string verticalAlign = "top") {
         this->size_x = size_x + padding_horizontal;
         this->size_y = size_y;
         this->text = text;
         this->padding_horizontal = padding_horizontal;
         this->checkVal = checkVal;
         this->horizontalAlign = horizontalAlign;
         this->verticalAlign = verticalAlign;
 
         if (text.size() + padding_horizontal > size_x) {
             this->size_x = text.size() + 3 + padding_horizontal;
         }
     }
 
     void draw() override {
         string textBuffer = this->text;
 
         
         int textLength = text.size();
         int totalPadding = size_x - textLength - 2; 
         int leftPadding = 0;
         int rightPadding = 0;
 
         if (horizontalAlign == "center") {
             leftPadding = totalPadding / 2;
             rightPadding = totalPadding - leftPadding;
         }
         else if (horizontalAlign == "right") {
             leftPadding = totalPadding;
         }
         else {
             rightPadding = totalPadding;
         }
 
         
         int totalVerticalPadding = size_y - 1; 
         int topPadding = 0;
         int bottomPadding = 0;
 
         if (verticalAlign == "center") {
             topPadding = totalVerticalPadding / 2;
             bottomPadding = totalVerticalPadding - topPadding;
         }
         else if (verticalAlign == "bottom") {
             topPadding = totalVerticalPadding;
         }
         else {
             bottomPadding = totalVerticalPadding;
         }
 
        
         for (int i = 0; i < size_y; i++) {
             for (int j = 0; j < size_x; j++) {
                 if (i == 0 || i == size_y - 1) {
                     cout << '*';
                     continue;
                 }
 
                 if ((i == size_y / 2 && j == size_y - 1) && (text == listt[resultAgeConfirm - 1].text))
                 {
                     std::cout << " *\t<<================";
                     continue;
                 }
 
                 if (j == 0 || j == size_x - 1) {
                     cout << '*';
                     continue;
                 }
 
                 if (i == topPadding + 1 && j > leftPadding + 1 && textBuffer.size() > 0) {
                     cout << textBuffer[0];
                     textBuffer.erase(0, 1);
                     continue;
                 }
 
                 cout << " ";
             }
             cout << endl;
         }
     }
 };
 
 class Column : public UIElementComposable {
 public:
     vector<UIElement*> components;
     string horizontalAlign;
     string verticalAlign; 
 
     Column(vector<UIElement*> components, string horizontalAlign = "left", string verticalAlign = "top") {
         for (int i = 0; i < components.size(); i++) {
             this->components.push_back(components[i]);
         }
         this->horizontalAlign = horizontalAlign;
         this->verticalAlign = verticalAlign;
     }
 
     void draw() override {
         for (auto& component : components) {
             component->draw();
         }
     }
 };
 
 class Window {
 public:
     int size_x;
     int size_y;
     UIElement* component;
 
     Window(int size_x, int size_y, UIElement* component) {
         this->size_x = size_x;
         this->size_y = size_y;
         this->component = component;
     }
 
     void draw() {
         component->draw();
     }
 };
 
 int main() {
     setlocale(LC_ALL, "rus");
     bool sert = false;
     do
     {
         int valueAge = 0;
 
         if (!sert)
         {
             Button checkAgeList = Button(30, 15, "Are u over 18 years old????", false, "center", "center");
             Button valueResultTrue = Button(10, 10, "Yes", true, "center", "center");
             Button valueResultFalse = Button(10, 10, "No", true, "center", "center");
 
             Column ageCheck({ &checkAgeList, &valueResultTrue, &valueResultFalse }, "center", "center");
 
             listt.push_back(valueResultTrue);
             listt.push_back(valueResultFalse);
 
             Window screen1(100, 100, &ageCheck);
             screen1.draw();
         }
         if (!sert)
         {
             valueAge = _getch();
 
             switch (valueAge)
             {
             case 13:
                 if (resultAgeConfirm != 2)
                     sert = true;
                 break;
             case 72:
                 if (resultAgeConfirm > 1)
                 {
                     resultAgeConfirm--;
                 }
                 break;
             case 75:
                 if (resultAgeConfirm > 1)
                 {
                     resultAgeConfirm--;
                 }
                 break;
             case 80:
                 if (resultAgeConfirm < 2)
                     resultAgeConfirm++;
                 break;
             case 77:
                 if (resultAgeConfirm < 2)
                     resultAgeConfirm++;
                 break;
             default:
                 break;
             }
         }
         else
         {
             Button button1 = Button(7, 5, "First Button", false, "center", "center");
             Button button2 = Button(9, 5, "Second Button", false, "center", "center");
             Button button3 = Button(11, 5, "Third Button", false, "center", "center");
 
             Column column({ &button1, &button2, &button3 }, "center", "center");
 
             Window screen(100, 100, &column);
             screen.draw();
             break;
         }
         system("CLS");
     } while (true);
 }
