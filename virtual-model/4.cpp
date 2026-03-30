#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() {}
};

class Serializable {
public:
    virtual string serialize() const = 0;
    virtual ~Serializable() {}
};

class Circle : public Drawable, public Serializable {
    double x, y, r;
public:
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}
    
    void draw() const override {
        cout << "Circle at (" << x << "," << y << ") radius " << r << endl;
    }
    
    string serialize() const override {
        return "Circle " + to_string(x) + " " + to_string(y) + " " + to_string(r);
    }
};

class Rectangle : public Drawable, public Serializable {
    double x, y, w, h;
public:
    Rectangle(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {}
    
    void draw() const override {
        cout << "Rectangle at (" << x << "," << y << ") " << w << "x" << h << endl;
    }
    
    string serialize() const override {
        return "Rectangle " + to_string(x) + " " + to_string(y) + " " + to_string(w) + " " + to_string(h);
    }
};

int main() {
    vector<Drawable*> shapes;
    Circle* c = new Circle(10, 20, 5);
    Rectangle* r = new Rectangle(0, 0, 30, 15);
    
    shapes.push_back(c);
    shapes.push_back(r);
    
    for (auto s : shapes) s->draw();
    
    cout << "Serialized: " << c->serialize() << endl;
    cout << "Serialized: " << r->serialize() << endl;
    
    delete c;
    delete r;
    return 0;
}
