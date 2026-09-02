#include <iostream>
#include <string>
using namespace std;

class Entity {
    private:
    string name;
    int health;
    int level;
    string type;

    public:
    Entity& setName(const string& name) {
        this->name = name;
        return *this;
    }
    Entity& setHealth(int health) {
        this->health = health;
        return *this;
    }
    Entity& setLevel(int level) {
        this->level = level;
        return *this;
    }
    Entity& setType(const string& type) {
        this->type = type;
        return *this;
    }

    string getName() const {
        return name;
    }
    int getHealth() const {
        return health;
    }
    int getLevel() const {
        return level;
    }
    string getType() const {
        return type;
    }
    void displayInfo() const {
        cout << "\nName: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
        cout << "Type: " << type << endl;
    }

};

namespace Physics {
    double clamp(double val, double min, double max) {
        if(val < min)
        return min;
        if(val > max)
        return max;
    return val;
    }
    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }

 
}

namespace GameMath {
    int clamp(int val, int min, int max){
        if(val < min)
        return min;
        if(val > max)
        return max;
    return val;
    }
    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}

int main() {
    Entity player, enemy, item;
    player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
    enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

    cout << "------------Entities----------" << endl;
    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();

    cout << "\n---------NameSpace-----" << endl;
    cout << "Physics clamp: " << Physics::clamp(120.5,0,100) << endl;
    cout << "GameMath clamp: " << GameMath ::clamp(75,0,100) << endl;
    cout << "Physics lerp: " << Physics::lerp(20,40,0.5) << endl;
    cout << "GameMath lerp: " << GameMath::lerp(20,40,0.5) << endl;

    {
        using namespace GameMath;
        cout << "Limited Scope clamp: " << clamp(150, 0, 100) << endl;
    }

    int R, C;
    cout << "\nEnter rows: ";
    cin >> R;
    cout << "Enter Coloumns: ";
    cin >> C;

    int **map = new int*[R];
    for(int i = 0; i < R; i++) {
        map[i] = new int[C];
    }
    cout << "/nEnter Map Values: " << endl;
    for(int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    cout <<"\n-------Display Map------" << endl;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    } 
 
       int count[5] = {0};
       for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if (map[i][j] >= 0 && map[i][j] <= 4) {
                count[map[i][j]]++;
            }
        }
    }

    cout << "/n-------Tile Count-----" << endl;
    cout << "Grass: " << count[0] << endl;
    cout << "Water: " << count[1] << endl;
    cout << "Mountain: " << count[2] << endl;
    cout << "Forest: " << count[3] << endl;
    cout << "Dungeon: " << count[4] << endl;

    for(int i = 0; i < R; i++) {
        delete[] map[i];
    }
    delete[] map;
    return 0;


    
}