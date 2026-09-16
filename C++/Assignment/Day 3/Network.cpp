#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum class HttpStatus {
    Ok = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    Servererror = 500,

};

void handleResponse(HttpStatus status, const string& endpoint) {
    switch(static_cast<int>(status)){
        case 200:
        cout << endpoint << "-> 200 OK" << endl;
        break;
        case 201:
        cout << endpoint << "-> 201 Created" << endl;
        break;
        case 400:
        cout << endpoint << "-> 400 BadRequest" << endl;
        break;
        case 401:
        cout << endpoint << "-> 401 Unauthorized" << endl;
        break;
        case 404:
        cout << endpoint << "-> 404 Not Found" << endl;
        break;
        case 500:
        cout << endpoint << "-> 500 Server Error" << endl;
        break;
    }
}

using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers) {
    for(int i = 0; i < headers.size(); i++) {
        cout << headers[i].first << ":" << headers[i].second << endl;
    }
}
 int main() {
    handleResponse(HttpStatus::Ok, "GET /api/users");
    handleResponse(HttpStatus::Unauthorized, "POST /api/login");
    handleResponse(HttpStatus::NotFound, "GET /api/products");
    handleResponse(HttpStatus::Servererror, "POST /api/order");

    HeaderList headers = {
        {"Content-tupe", "application/json"},
        {"Authorization", "Bearer token"},
        {"Accept - Language" , "en-US"}

    };

    Port port = 800;
    RequestId id = 1748293847;

    cout << "\nRequest ID: " << id << endl;
    cout << "Server Port: " << port << endl;

    cout << "Headers: " << endl;
    printHeaders(headers);
    return 0;

 }