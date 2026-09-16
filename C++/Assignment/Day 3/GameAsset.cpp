#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Texture {
    private:
    string name;
    int width;
    int height;

    public:
    Texture(string n, int w, int h) {
        name = n;
        width = w;
        height = h;

        cout << "[Texture Loaded]" << endl;

    }
    ~Texture() {
        cout << "[Texture Released]" << endl;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
    }


};

int main() {
    unique_ptr<Texture> tex1 = make_unique<Texture>("Player_sprite", 512, 512);
    tex1 -> display();
    unique_ptr<Texture> tex2 = move (tex1);
    if(tex1 == nullptr) {
        cout << "Tex1 is now empty" << endl;
    }
    cout << "Tex2 is Owner" << endl;
    tex2 -> display();
    return 0;
}