#include <iostream>
using namespace std;

getStatusCode(double temperature) {
    if (temperature < 0) 
        return -1;
    
    else if(temperature <= 29) 
        return 0;
    
    else if(temperature <= 44) 
        return 1;
    
    else if(temperature <= 59) 
        return 2;
    
    else 
        return 3;
  
}

 void printAction (int statusCode) {
  switch(statusCode) {
   case -1:
     cout <<"SENSOR_ERROR: Sensor fault - check wiring.";
     break;

    case 0:
      cout <<"NORMAL: No action required.";
      break;

    case 1:
      cout <<"WARNING: Alert sent to supervisor.";
      break;

    case 2:
      cout << "CRITICAL: Cooling system triggered.";
      break;

    case3 :
      cout << "SHUTDOWN: Emergency shutdowm initiated.";
      break;
  }
 }

double toFahrenheit(double temperature) {
 return(temperature * 9 / 5) + 32;
}

int main() {
 double temperature;

 cout << "Enter temperature to Celcsios: ";
 cin >> temperature;

 int statusCode = getStatusCode(temperature);

 cout << "Status Code: " << statusCode << endl;

 printAction(statusCode);

 cout << (temperature > 25 ? "Above Average" : "Below Average") << endl;

 cout << "Tempearture in Fahrenheit: " << toFahrenheit(temperature) << endl;

 return 0;
}