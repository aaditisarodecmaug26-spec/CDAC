#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Shader {
    private:
    string name;
    string type;

    public:
    Shader(string n, string t) {
        name = n;
        type = t;
        cout << "Shared compiled! " << endl;
    }
    ~Shader(){
       cout << "Shared Destroyed! " << endl;
    }

};

int main() {
shared_ptr<Shader> shader = make_shared<Shader>("main_vert", "vertex");   
cout << "Ref count: " << shader.use_count() << endl;

    {
        shared_ptr<Shader> renderedRef = shader;
        cout << "Ref count: " << shader.use_count() << endl;

        shared_ptr<Shader> editorRef = shader;
        cout << "Ref count: " << shader.use_count() << endl;

    }
          cout << "Ref count: " << shader.use_count() << endl;
    return 0;
}