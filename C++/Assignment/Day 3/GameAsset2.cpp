#include <iostream>
#include <string>
#include <memory>
using namespace std;

class AudioClip {
    private:
    string name;
    double duration;

    public:
    AudioClip(string n, double d) {
        name = n;
        duration = d;
        cout << "AudioClip Loaded! " << endl;
    
    }
    ~AudioClip() {
        cout << "AudioClip Destroyed! " << endl;
    }

  void display() const {
    cout << "Name: " << name << endl;
    cout << "Duration: " << duration << " Sec " << endl;
  }  
};

int main() {
    shared_ptr<AudioClip> audio = make_shared<AudioClip>("explosion", 3.5);
    weak_ptr<AudioClip> observer = audio;

    if(auto clip = observer.lock()) {
        cout << "Clip Alive: " << endl;
        clip->display();
    }
    audio.reset();

    if(observer.expired()) {
        cout << "Clip already unloaded. " << endl;
    }
}