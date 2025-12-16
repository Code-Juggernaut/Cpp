/**
 * TORUN:cmake -S . -B build 
    cmake --build build
 */

#define DEBUG
#ifdef DEBUG
#include<iostream>
#endif

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <filesystem>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <deque>
#include <math.h>
#include "Libs/Licence_checker.h"
#include "Libs/Autosave.h"

#define _font_path "../SRC/Monocraft.ttf"
#define _License_path "../SRC/License.txt"
#define _Music_path "../SRC/Music/"
#define _Shader_path "../SRC/Shaders/"
#define _Texture_path "../SRC/Textures/"
#define _Save_path "../Saves/"

using namespace std;

float size_x = 0.00;
float size_y = 0.00;
class Timer{
    private:
        chrono::high_resolution_clock::time_point prev;
        float _delay;
    public:
        Timer(const float &delay):_delay(delay){

        }
        Timer():_delay(0){

        }
        bool is_timer_IRQ(){
            auto now = chrono::high_resolution_clock::now();
            chrono::duration<double>duration = std::chrono::duration_cast<chrono::seconds>(now-prev);
            if(duration.count() >= _delay){
                prev = now;
                return true;
            }
            return false;
        }
        void set_delay(const float &delay){
            _delay = delay;
        }
        int get_time()const{
            auto now = chrono::high_resolution_clock::now();
            chrono::duration<double>duration = std::chrono::duration_cast<chrono::seconds>(now-prev);
            return _delay - duration.count();
        }
        string get_time_str()const{
            return to_string(get_time());
        }
        void reset_timer(){
            prev = chrono::high_resolution_clock::now();
        }
};
class Music_processor:public sf::Music{
    private:
        vector<string> _music_data;
        string _path;
        //sf::Music music;
        int pos;
        bool _is_changed;
    public:
        Music_processor(const string &path):_path(path),Music(),pos(0){
            for(const auto &entry : std::filesystem::directory_iterator(_path)){
                if(entry.is_regular_file()){
                    _music_data.push_back(entry.path().filename().string());
                    
                }
                for(string i : _music_data){
                    cout<<i<<endl;
                }
            }
        }
        void Play(){
            if(_music_data.size() == 0){
                return;
            }
            if(Music::getStatus() != sf::SoundSource::Status::Playing){
                if(Music::openFromFile(_Music_path+_music_data[pos])){
                    Music::play();
                    pos++;
                    if(pos == _music_data.size()){
                        pos = 0;
                    }
                    _is_changed = true;
                }else{
                    cout<<"error can't load musicfile";
                }
            }
        }
        void Next(){
            pos++;
            if(pos == _music_data.size()){
                pos = 0;
            }
        }
        string getname(){
            return _music_data[pos];
        }
        bool is_changed()const{
            return _is_changed;
        }
        void reset_flag(){
            _is_changed = false;
        }
};
class Button{
    private:
        float _bound_x1;
        float _bound_y1;
        float _bound_x2;
        float _bound_y2;
        string _title;
        bool state;
    public:
        Button(const float bound_x1,const float bound_y1,const float bound_x2,const float bound_y2,const string title):
        _bound_x1(bound_x1),_bound_y1(bound_y1),_bound_x2(bound_x2),_bound_y2(bound_y2),_title(title),state(false){

        }
        void is_press_detected(sf::RenderWindow &window){
            auto pos = sf::Mouse::getPosition(window); // позиция относительно окна
            if (pos.x >= _bound_x1 && pos.y >= _bound_y1 &&
                pos.x <= _bound_x2 && pos.y <= _bound_y2) {
                if(state == true){
                    state = false;
                }else{
                    state =  true;
                }
            }else{
                return;   
            }
        }
        bool is_pressed() {
            return state;
        }
        void clear(){
            state = false;
        }
        string get_title()const{
            return _title;
        }
        void draw_button(sf::RenderWindow &window,sf::Text &text, sf::Shader &shader){
            sf::RectangleShape rect({(_bound_x2-_bound_x1)/4 ,(_bound_y2 - _bound_y1)/4});
            rect.setPosition({_bound_x2,_bound_y2});
            //shader.setUniform("textColor", sf::Glsl::Vec4(color));
            text.setPosition({_bound_x1+5 ,_bound_y1+5});
            text.setString(_title);
            
            window.draw(rect,&shader);
            rect.setPosition({_bound_x1 ,_bound_y1});
            rect.setSize({_bound_x2-_bound_x1+text.getCharacterSize(),_bound_y2 - _bound_y1});
            rect.setFillColor(sf::Color(0,0,0,0));
            rect.setOutlineColor(sf::Color(0,50,0));
            rect.setOutlineThickness(5);
            window.draw(rect);
            window.draw(text,&shader);
        }
};

class Battery_manager:public Timer{
    private:
        float _charge;
        float _consumption;
        bool _is_electricity;
        sf::Texture Elec_on;
        sf::Texture Elec_off;
        string _path;
        sf::Sprite battery;
        bool is_changed_status;
    public:
        Battery_manager(const string &path):_path(path),
        _charge(100.0),_consumption(0.001),_is_electricity(1),battery(Elec_on){
            if(!Elec_on.loadFromFile(_path+"Elec.png")){
                cout<<"cant'load from file"<<endl;
            }
            if(!Elec_off.loadFromFile(_path+"No_elec.png")){
                cout<<"cant'load from file"<<endl;
            }
            battery = sf::Sprite(Elec_on);
            battery.setTexture(Elec_on);
            battery.setPosition({size_x *0.180f, size_y * 0.005f});
            battery.setScale({size_y*0.00005f,size_y*0.00005f});
        }
        string get_consumption_str()const{
            std::stringstream float_to_str;
            float_to_str<<std::fixed<<std::setprecision(2)<<_consumption<<"%";
            return float_to_str.str();
        }
        float get_consumption()const{
            return _consumption;
        }
        void set_consumption(float consumption){
            _consumption = consumption;
        }
        string get_Charge_str()const{
            std::stringstream float_to_str;
            float_to_str<<std::fixed<<std::setprecision(2)<<_charge<<"%";
            return float_to_str.str();
        }
        float get_Charge_float()const{
            return _charge;
        }
        int get_Charge_int()const{
            return round(_charge);
        }
        void set_Charge(int charge){
            _charge  = charge;
        }
        void reduce_charge(){
            //if(is_timer_IRQ()){
                _charge-= (_charge > 0.00?(_consumption*0.0001):(0.00));
            //}
        }
        void add_charge(){
            //if(is_timer_IRQ()){
                _charge+= (_charge < 100.00?((1-_consumption*0.0001)*0.01):(0.00));
            //}
        }
        
        void electricity_shutdown(){
            _is_electricity = 0;
            
        }
        void electricity_restore(){
            _is_electricity = 1;
        }
        void electricity_scheduler(){
            
            if(_is_electricity == 1){
                if(is_timer_IRQ()){
                    set_delay(rand()%100);
                    _is_electricity = 0;
                    is_changed_status = 1;
                }
            }else{
                if(is_timer_IRQ()){
                    set_delay(rand()%100);
                    _is_electricity = 1;
                    is_changed_status = 1;
                }
            }
            
                
            
        }
        bool get_electricity_state()const{
            return _is_electricity;
        }
        void restore_defaults(){
            _charge = 100;
            _is_electricity = 0;
        }
        bool is_changed()const{
            return is_changed_status;
        }
        void reset_flag(){
            is_changed_status = false;
        }
        void draw_Charge(sf::RenderWindow &window, sf::Shader &shader,sf::Text &text)const{
            sf::RectangleShape rect({size_x*0.105f,size_y *0.05f});
            rect.setPosition({5.f,5.f});
            rect.setFillColor(sf::Color::Black);
            rect.setOutlineColor(sf::Color::Green);
            rect.setOutlineThickness(1);
            window.draw(rect);
            rect.setPosition({size_x *0.109f,size_y*0.012f});
            rect.setSize({size_x *0.004f, size_y * 0.035f});
            rect.setFillColor(sf::Color::Green);
            window.draw(rect);
            
            switch((int)_charge*100){
                case 0 ... 2500:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,0,0)));break;
                case 2501 ... 3000:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,128,0)));break;
                case 3001 ... 5000:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,255,0)));break;
                case 5001 ... 8000:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(0,255,0)));break;
                case 8001 ... 10000:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(0,128,255)));break;
            }
            
            rect.setSize({size_x *0.003f,size_y *0.035f});
            rect.setOutlineColor(sf::Color::Black);
            
            for(int i = 1;i<(int)_charge/5+1;i++){
                rect.setPosition({size_x*i*0.0053f,size_y *0.011f});
                window.draw(rect,&shader);
            }
            
            text.setCharacterSize(size_x*0.01f);
            text.setPosition({size_x * 0.118f,size_y * 0.005f});
            text.setString(get_Charge_str());
            window.draw(text,&shader);
            text.setPosition({size_x * 0.118f,size_y * 0.020f});
            text.setString("wait "+get_time_str()+"s");
            window.draw(text,&shader);
            text.setPosition({size_x * 0.118f,size_y * 0.060f});
            text.setString("Usage: "+get_consumption_str()+"/5s");
            window.draw(text,&shader);
        }

        void draw_electricity_sign(sf::RenderWindow &window){
            if(_is_electricity == 1){
                battery.setTexture(Elec_on);
            }else{
                battery.setTexture(Elec_off);
            }
            
            window.draw(battery);
        }

    
};


struct System_info{
    bool system_state;
    float power_consumption;
};

class Overheat{
    private:
        float _heat;
        bool is_cooling;
    public:
        Overheat():_heat(20),is_cooling(true){

        }
        void set_cooling(bool val){
            is_cooling = val;
        }
        void heat(){
            if(is_cooling == true){
                _heat+=0.0005;
            }else{
                if(_heat >=20){
                    _heat-=0.0001;
                }
            }
        }
        float get_heat_float()const{
            return _heat;
        }
        int get_heat_int()const{
            return round(_heat);
        }
        string get_heat_str()const{
            std::stringstream float_to_str;
            float_to_str<<std::fixed<<std::setprecision(2)<<_heat<<"*C";
            return float_to_str.str();
        }
        void draw_heat(sf::RenderWindow &window, sf::Text &text,sf::Shader &shader){
            text.setPosition({size_x*0.3f,(5.f)});
            text.setString("Terminal heat: "+get_heat_str());
            switch(get_heat_int()){
                case 90 ... 100:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,0,0)));break;
                case 70 ... 89:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,128,0)));break;
                case 60 ... 69:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,255,0)));break;
                case 50 ... 59:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(0,255,0)));break;
                case 0 ... 49:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(0,128,255)));break;
                //default:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,255,255)));break;
            }
            window.draw(text,&shader);
        }
        void reset(){
            _heat = 20.0;
        }
};


class Circuit_manager{
    private:
        vector<struct System_info> system;
        vector<Button> buttons;
        float _consumption;
    public:
    Circuit_manager():_consumption(0.1){
        system.push_back({1,1});
        system.push_back({1,5});
        system.push_back({1,2});
        system.push_back({1,3});
        system.push_back({1,10});
        system.push_back({1,4});
        buttons.push_back({size_x*0.80f,size_y*0.01f,size_x*0.85f,size_y*0.11f,"Terminal\nCooling\nsystem"});
        buttons.push_back({size_x*0.90f,size_y*0.01f,size_x*0.95f,size_y*0.11f,"House\nclimate\ncontrol"});
        buttons.push_back({size_x*0.80f,size_y*0.21f,size_x*0.85f,size_y*0.31f,"Security\ncontrol\nsystem"});
        buttons.push_back({size_x*0.90f,size_y*0.21f,size_x*0.95f,size_y*0.31f,"Lights\ncontrol\nsystem"});
        buttons.push_back({size_x*0.80f,size_y*0.41f,size_x*0.85f,size_y*0.51f,"Fire\ncontrol\nsystem"});
        buttons.push_back({size_x*0.90f,size_y*0.41f,size_x*0.95f,size_y*0.51f,"Network\ncontrol\nsystem"});
        /*system.push_back({1,0.01,"Terminal "});
        system.push_back({1,0.01,"Cooling system"});*/
    }
    void disable_circuit(const int pos){
        system[pos].system_state = 0;
    }
    void enable_circuit(const int pos){
        system[pos].system_state = 1;
    }
    struct System_info get_circuit(const int pos)const {
        return system[pos];
    }
    int get_size()const{
        return system.size();
    }
    string get_title(const int &pos)const{
        return buttons[pos].get_title();
    }
    void draw_circuits(sf::RenderWindow &window,sf::Text &text, sf::Shader &shader){
        sf::Color color(0,255,0);
        for(int i = 0;i<buttons.size();i++){
            
            if(system[i].system_state == 0){
                shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(0,255,0)));
            }else{
                shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,0,0)));
            }
                buttons[i].draw_button(window,text,shader);
                window.draw(text,&shader);
            }
        }
    void check_buttons(sf::RenderWindow &window){
        for(int i = 0;i<buttons.size();i++){
            buttons[i].is_press_detected(window);
            if(buttons[i].is_pressed()){
                if(system[i].system_state == 1){
                    disable_circuit(i);
                    _consumption+=system[i].power_consumption;
                }else{
                    enable_circuit(i);                    
                    _consumption-= system[i].power_consumption;
                }
            }
            buttons[i].clear();
        }
    }
    float get_consumption(){
        return _consumption;
    }
    
};

struct Message{
    string text;
    int alert_level;
};
class Terminal{
    private:
        deque<Message>prev;
        int pos;
    public:
    Terminal():pos(0){
        
    }
    void new_message(const string &message,const int &alert_level){\
        
        switch(alert_level){
            case 0:prev.push_back({"[ INFO ]"+message,alert_level});break;
            case 1:prev.push_back({"[ STATUS ]"+message,alert_level});break;
            case 2:prev.push_back({"[ CAUTION ]"+message,alert_level});break;
            case 3:prev.push_back({"[ WARNING ]"+message,alert_level});break;
            case 4:prev.push_back({"[ ALERT ]"+message,alert_level});break;
            //default:prev.push_back({"[ UNKNOWN ]"+message,alert_level});break;
        }
        
        pos = prev.size();
        if(prev.size()>30){
            prev.pop_front();
            pos = 30;
        }
    }
    void print_info(sf::Text &text,sf::RenderWindow &window,sf::Shader &shader){
        if(pos == 0 ||prev.size() == 0){
            return;
        }
        text.setCharacterSize(size_x*0.01f);

        for(int i = 0;i<prev.size();i++){
            text.setPosition({size_x*0.005f,(size_y*0.1f)+(i+1)*text.getCharacterSize()});
            text.setString(prev[i].text);
            switch(prev[i].alert_level){
                case 0:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(0,128,255)));break;
                case 1:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(0,255,0)));break;
                case 2:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,255,0)));break;
                case 3:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,128,0)));break;
                case 4:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,0,0)));break;
                //default:shader.setUniform("textColor", sf::Glsl::Vec4(sf::Color(255,255,255)));break;
            }
            
            window.draw(text,&shader);
        }
    }
    void clear(){
        prev.clear();
    }
};

enum state{
    MAIN_MENU, GAME, SETTINGS,EXIT
};


int main(){
    state status = MAIN_MENU;
    Music_processor music(_Music_path);
    Licence license_checker(_License_path);
    Autosave saver((string)_Save_path+"save.txt");

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "The terminal");
    size_x = window.getSize().x;
    size_y = window.getSize().y;
    sf::Font font(_font_path);
    sf::Shader shader;
    if(!shader.loadFromFile((string)_Shader_path+"crt.frag",sf::Shader::Type::Fragment)){
        cout<<"Shader Error"<<endl;
    }
    
    sf::Text text(font,license_checker.get_license(),20);
    cout<<license_checker.get_license();

    text.setFillColor(sf::Color::Green);
    text.setPosition({size_x/2.f, size_y/2.f});
    
    
    window.clear();
    window.draw(text);
    window.display();
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    window.clear();

    sf::Clock clock;
    text.setString("The Terminal");
    text.setCharacterSize(72);
    sf::Vector2u size;
    size = window.getSize();
    
    text.setPosition({size.x/2.f-8.f*24.f,size.y/2.f-72.f});

    std::time_t now = (std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    sf::Text time(font,std::ctime(&now),20);
    time.setOutlineColor(sf::Color::Green);
    time.setPosition({0.f,size.y-20.f});

    Battery_manager battery(_Texture_path);
    {
        int batt;
        int time;
        int cash;
        saver.read(&batt,&time,&cash);
        battery.set_Charge(batt);
    }
    
    sf::Text batt_charge(font,battery.get_Charge_str(),20);
    batt_charge.setPosition({110,5});
    bool flag  =0;
    Terminal terminal;
    Circuit_manager manager;
    Overheat heat;

    Timer resident_timer(10);
    Timer sys_tick(1);
    while (window.isOpen()){
        while (std::optional<sf::Event> event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
            if (event->is<sf::Event::MouseButtonPressed>()) {
                if (event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
                    manager.check_buttons(window);
                    
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
            if(status == GAME){
                saver.save(battery.get_Charge_int(),0,0);
            }
            
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){
            switch(status){
                case MAIN_MENU:terminal.new_message("Loading your game...",0);battery.restore_defaults();heat.reset();break;
                case SETTINGS:break;
                default:break;
            }
            status = GAME;
        }

        music.Play();
        now = (std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
        time.setString(std::ctime(&now));
        window.clear(sf::Color(0,20,0,120));
        shader.setUniform("time", clock.getElapsedTime().asSeconds());
        shader.setUniform("resolution", sf::Vector2f(window.getSize()));
        shader.setUniform("textColor", sf::Glsl::Vec4(text.getFillColor()));
        window.draw(time, &shader);
        
        if(status == MAIN_MENU){
            window.draw(text, &shader);
            
            
        }else if(status == GAME){
            if(heat.get_heat_float() >= 100.00){
                batt_charge.setPosition({size_x/2.f, size_y/2.f});
                batt_charge.setCharacterSize(72);
                batt_charge.setString("GAME OVER");
                batt_charge.setFillColor(sf::Color::Red);
                window.draw(batt_charge);
                window.display();
                this_thread::sleep_for(2s);
                saver.clear();
                status = MAIN_MENU;
            }
            if(battery.get_Charge_float() <= 0.00){
                batt_charge.setPosition({size_x/2.f, size_y/2.f});
                batt_charge.setCharacterSize(72);
                batt_charge.setString("GAME OVER");
                batt_charge.setFillColor(sf::Color::Red);
                window.draw(batt_charge);
                window.display();
                this_thread::sleep_for(2s);
                saver.clear();
                status = MAIN_MENU;
            }
            
            /*for(int i = 0;i<manager.get_size();i++){

                if(manager.get_circuit(i).system_state == 0){
                    if(resident_timer.is_timer_IRQ()){
                        terminal.new_message("Turn on the"+manager.get_title(i),3);
                        battery.set_Charge(battery.get_Charge_float()-1);
                    }else{
                        resident_timer.reset_timer();
                    }
                }
                
            }*/


        }   
        if(sys_tick.is_timer_IRQ()){
            if(battery.get_Charge_int()<=25&&battery.get_Charge_int()>23){
                terminal.new_message("Battery level <25%",3);
            }else if(battery.get_Charge_int()<=10 &&battery.get_Charge_int()>8){  
                terminal.new_message("Battery level <10%",4);
            }
            if(heat.get_heat_int()>=80 && heat.get_heat_int()<82){
                terminal.new_message("Heat above 80 *C",3);
            }else if(heat.get_heat_int()>=90 && heat.get_heat_int()<92){
                terminal.new_message("Heat above 90 *C",4);
            }
            if(battery.is_changed() == true){
                terminal.new_message(battery.get_electricity_state() == 1?("Electricity restored"):("Electricity disabled"),(battery.get_electricity_state() == 0?(5):(1)));
                battery.reset_flag();
            }
            if(music.is_changed()){
                terminal.new_message("next is "+music.getname(),0);
                music.reset_flag();
            }
        }
        heat.heat();
        heat.set_cooling(manager.get_circuit(0).system_state);
        heat.draw_heat(window,batt_charge,shader);
        manager.draw_circuits(window,batt_charge,shader);

        battery.electricity_scheduler();
        battery.set_consumption(manager.get_consumption()*5);
        
        if(battery.get_electricity_state() == 0){
            battery.reduce_charge();
        }else{
            battery.add_charge();
        }
        
        battery.draw_electricity_sign(window);
        battery.draw_Charge(window,shader,batt_charge);
        terminal.print_info(batt_charge,window,shader);
        window.display();
    }
}