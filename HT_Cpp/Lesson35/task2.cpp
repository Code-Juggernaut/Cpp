#include <iostream>
#include <string>
#include <vector>
#include <memory>

/**
 * NOTE: CHATGPT code
 * 
 */




using namespace std;

class Subscriber {
private:
    string _name;
public:
    Subscriber(const string& name) : _name(name) {}

    void update(const string& message) {
        cout << "Subscriber " << _name << " Got_message: " << message << endl;
    }
};

class Publisher {
private:
    vector<weak_ptr<Subscriber>> subscribers;
public:
    void subscribe(const shared_ptr<Subscriber>& sub) {
        subscribers.push_back(sub);
    }

    void notify(const string& message) {
        cout << "=== Notify subscribers ===" << endl;
        for (auto it = subscribers.begin(); it != subscribers.end(); ) {
            if (auto spt = it->lock()) { 
                spt->update(message);
                ++it;
            } else {
                it = subscribers.erase(it);
            }
        }
    }
};

int main() {
    Publisher pub;

    {
        auto sub1 = make_shared<Subscriber>("Alice");
        auto sub2 = make_shared<Subscriber>("Bob");
        auto sub3 = make_shared<Subscriber>("Charlie");

        pub.subscribe(sub1);
        pub.subscribe(sub2);
        pub.subscribe(sub3);

        pub.notify("message");

    }

    
    pub.notify("Message");

    return 0;
}
